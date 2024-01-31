class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        # two pointers
        from collections import defaultdict
        count = defaultdict(int)
        for c in t:
            count[c] -= 1
        st, ed = 0, 0
        min_len = len(s) + 1
        answer = ""
        negative = len(set(t))
        while ed < len(s) or not negative:
            if not negative:
                if ed - st < min_len:
                    min_len = ed - st
                    answer = s[st:ed]
                count[s[st]] -= 1
                if count[s[st]] == -1:
                    negative += 1
                st += 1
            else:
                count[s[ed]] += 1
                if count[s[ed]] == 0:
                    negative -= 1
                ed += 1
        return answer


s = Solution()
print s.minWindow("cabwefgewcwaefgcf", "cae")  # cwae
print s.minWindow("aabcb", "bb")  # bcb
print s.minWindow("axzxbzxzc", "abc")  # axzxbzxzc
print s.minWindow("axzxbzxzcra", "abc")  # bzxzcra
print s.minWindow("axzxbzxzcrab", "abc")  # crab
print s.minWindow("axzxbzxzcrabc", "abc")  # abc
print s.minWindow("axzxbzxzcrba", "abc")  # crab
print s.minWindow("axzxbzxzcrab", "abcp")  #
print s.minWindow("aaxzxbzxazc", "aabc")  # axzxbzxazc
