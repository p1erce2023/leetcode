class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        cs = '0' + s[:-1]
        w = [0, 0]
        for l, c in zip(cs, s):
            t = int(l + c)
            if t == 0:
                return 0
            elif t < 10:
                w.append(w[-1] or 1)
            elif t == 10 or t == 20:
                w.append(w[-2] or 1)
            elif t < 27:
                if not w[-1]:
                    w.append(1)
                else:
                    w.append(w[-1] + int(w[-2] or 1))
            elif not t % 10:
                return 0
            else:
                w.append(w[-1])
            # print w
        return w[-1]


s = Solution()
# print s.numDecodings('12')  # 1,2|12
# print s.numDecodings('123')  # 1,2,3|12,3|1,23
# print s.numDecodings('1223')  # 1,2,2,3|12,2,3|1,22,3|1,2,23|12,23
# print s.numDecodings('1234')  # 1,2,3,4|12,3,4|1,23,4
# print s.numDecodings('12211221')
# print s.numDecodings('0')
# print s.numDecodings('0001')
# print s.numDecodings('00012')
# print s.numDecodings('')
# print s.numDecodings('10')
# print s.numDecodings('202')  # 20,2
# print s.numDecodings('110')
# print s.numDecodings('1102')
# print s.numDecodings('11011')
print s.numDecodings('230')
