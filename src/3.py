# -*- coding: utf-8 -*-
class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLongestSubstring(self, s):

        # script 5: 验证了下，思路的确是这样的，就是把index查找换成之前存储的值，注意优化思路。
        # 5和4代码都极其像了。88ms
        if not s:
            return 0
        p1 = -1
        l = 0
        end_dict = {}
        for i in xrange(0, len(s)):
            if s[i] in end_dict and end_dict[s[i]] > p1:
                p1 = end_dict[s[i]]
            else:
                if i - p1 > l:
                    l = i - p1
            end_dict[s[i]] = i
        return l

        # script 4: 之前一直用的是set，思路其实是一样的，额外的时间花在了index上，其实只要记录每个字符上次出现的位置
        # 即此处的h就不能查找了，从O(m*n)变成了O(n)
        if not s:
            return 0
        h = {}
        max_len, last_repeat = 0, -1
        for i in xrange(len(s)):
            if s[i] in h and h[s[i]] > last_repeat:
                last_repeat = h[s[i]]
            if i - last_repeat > max_len:
                max_len = i - last_repeat
            h[s[i]] = i
        return max_len


        # script 3: still slow, 268ms
        if not s:
            return 0
        p1, i = 0, 1
        l = [1]
        end_set = set(s[0])
        for i in xrange(1, len(s)):
            if s[i] in end_set:
                p1 += s[p1:i].index(s[i]) + 1
                end_set = set(s[p1:i + 1])
            else:
                end_set.add(s[i])
                l.append(i + 1 - p1)
        return max(l)


        # script 2: very slow, 600ms
        if not s:
            return 0
        l, st, i, end_set_len = 1, 0, 1, 1
        end_set = set(s[0])
        while i < len(s):
            if s[i] not in end_set:
                if i - st + 1 > l:
                    l = i - st + 1
                end_set.add(s[i])
                end_set_len += 1
            else:
                for j in range(i - 1, i - end_set_len - 1, -1):
                    if s[j] == s[i]:
                        st = j + 1
                        break
                end_set = set(s[st:i + 1])
                end_set_len = i - st + 1
            i += 1
        return l

        # script 1: slow, 300ms
        if not s:
            return 0
        l, st, i, end_set_len = 1, 0, 1, 1
        end_set = set(s[0])
        while i < len(s):
            if s[i] not in end_set:
                l = max(i - st + 1, l)
                end_set.add(s[i])
                end_set_len += 1
            else:
                offset = s[i - end_set_len:i].index(s[i])
                st += offset + 1
                end_set = set(s[st:i + 1])
                end_set_len = i - st + 1
            i += 1
        return l

s = Solution()

assert s.lengthOfLongestSubstring("abcabcab") == 3
assert s.lengthOfLongestSubstring("abcddcbaef") == 6
assert s.lengthOfLongestSubstring("abcddddddddcbae") == 5
assert s.lengthOfLongestSubstring("aab") == 2
assert s.lengthOfLongestSubstring("abcbbcad") == 4
assert s.lengthOfLongestSubstring("aacbrtyrbcabde") == 6
assert s.lengthOfLongestSubstring("aacbbcade") == 5
assert s.lengthOfLongestSubstring("bbbbb") == 1
assert s.lengthOfLongestSubstring("") == 0
assert s.lengthOfLongestSubstring("ab") == 2
assert s.lengthOfLongestSubstring("abb") == 2
assert s.lengthOfLongestSubstring("aba") == 2
