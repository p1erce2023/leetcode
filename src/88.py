class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        if not m:
            for i in xrange(n):
                nums1[i] = nums2[i]
        m, n, l = m - 1, n - 1, m + n - 1
        while m > -1 and n > -1:
            if nums1[m] >= nums2[n]:
                nums1[l] = nums1[m]
                m -= 1
            else:
                nums1[l] = nums2[n]
                n -= 1
            l -= 1
        while n > -1:
            nums1[n] = nums2[n]
            n -= 1


s = Solution()
a = [1,3,5,6,8,13,13,13,13,15]
s.merge(a, 5, [2,6,9,11], 4)
print a

a = [0]
s.merge(a, 0, [1], 1)
print a

a = [2,0]
s.merge(a, 1, [1], 1)
print a
