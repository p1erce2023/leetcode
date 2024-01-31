class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1, v2, i = version1.split('.'), version2.split('.'), 0
        l1, l2 = len(v1), len(v2)
        while i < l1 or i < l2:
            d1 = int(v1[i]) if i < l1 else 0
            d2 = int(v2[i]) if i < l2 else 0
            if d1 == d2:
                i += 1
            else:
                return 1 if d1 > d2 else -1
        return 0


s = Solution()
vs = ['01', '1', '1.0']
# vs = ['0.1', '3.3', '1.1', '7.8', '1.2', '13.37']
for i in vs:
    for j in vs:
        print(i, j, s.compareVersion(i, j))
