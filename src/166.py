class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        map_, r = {}, []
        f = True
        if not numerator:
            return '0'
        if numerator < 0:
            numerator = -numerator
            f = not f
        if denominator < 0:
            denominator = -denominator
            f = not f
        a = int(numerator / denominator)
        b = numerator - a * denominator
        int_part = str(a)
        idx = 0
        if b:
            map_[b] = idx
            idx += 1
        else:
            return int_part if f else '-' + int_part
        while b:
            a = int(b * 10 / denominator)
            b = b * 10 - a * denominator
            r.append(str(a))
            if b in map_:
                r.insert(map_[b], '(')
                break
            map_[b] = idx
            idx += 1
        if b:
            x = int_part + '.' + ''.join(r) + ')'
        else:
            x = int_part + '.' + ''.join(r)
        return x if f else '-' + x


s = Solution()
q = [(1, 3), (1, 2), (2, 1), (7, 4), (4, 7), (5, 6), (5, 13), (1, 6), (-50, 8), (-2147483648, 1), (0, -5)]
for numerator, denominator in q:
    print(numerator, '/', denominator, '=', s.fractionToDecimal(numerator, denominator))
