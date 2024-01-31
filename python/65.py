# -*- coding: utf-8 -*-
import re
class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # use (?(id/name)yes-pattern|no-pattern)
        # pattern = re.compile("^(?:[+-]?)(\d+)?(?(1)(?:\.\d*)?|(?:\.\d+))(?:e(?:[+-]?)\d+)?$", re.I)

        # faster, use OR, discard re.I
        pattern = re.compile("^(?:[+-]?)(?:\d+(?:\.\d*)?|\.\d+)(?:(?:e|E)(?:[+-]?)\d+)?$")
        if s.strip() and pattern.match(s.strip()):
            return True
        else:
            return False

        # 网友的叼爆方法。什么叫想象力！什么轮子最好用！
        try: float(s)
        except ValueError: return False
        else: return True


s = Solution()
assert s.isNumber("0") == True
assert s.isNumber("11  ") == True
assert s.isNumber("0.1") == True
assert s.isNumber(".123") == True
assert s.isNumber("3.") == True
assert s.isNumber("2e10") == True
assert s.isNumber("abc") == False
assert s.isNumber("  ") == False
assert s.isNumber("  .") == False
assert s.isNumber("1 a") == False
assert s.isNumber("e9") == False
