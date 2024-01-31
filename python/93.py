# -*- coding: utf-8 -*-
class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        Given a string containing only digits, restore it by returning all possible valid IP address combinations.
        """
        def mysplit(s, n):  # 一次性写对递归，神奇！
            if not s:
                return []
            if n == 1:
                if s == '0' or (s[0] != '0' and int(s) < 256):
                    return [s]
                else:
                    return []
            res = []
            for item in mysplit(s[1:], n - 1):
                res.append('%s.%s' % (s[:1], item))
            if int(s[:2]) > 9:
                for item in mysplit(s[2:], n - 1):
                    res.append('%s.%s' % (s[:2], item))
                if 99 < int(s[:3]) < 256:
                    for item in mysplit(s[3:], n - 1):
                        res.append('%s.%s' % (s[:3], item))
            return res
        return mysplit(s, 4)

s = Solution()
print s.restoreIpAddresses('010010')
print s.restoreIpAddresses('25525511135')
print s.restoreIpAddresses('2552511135')
