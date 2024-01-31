# -*- coding: utf-8 -*-
class Solution:
    # @param {integer[]} nums1
    # @param {integer[]} nums2
    # @return {float}
    def findMedianSortedArrays(self, nums1, nums2):
        # script.3 O(log(m+n)) 120ms
        # 自己的思路往这边靠过，中位数，就是(默认升序)左边小右边大，且两边数量相等，但左、右内部的顺序不需要保证！
        # 于是就想到了堆。但没想清楚堆到底怎么做。看了讨论区的详尽解释，终于弄懂
        # 主要没想到log的特性是出在二分查找上
        import sys
        n1, n2 = len(nums1), len(nums2)
        if n1 < n2:
            return self.findMedianSortedArrays(nums2, nums1)

        if not nums2:
            return (nums1[(n1-1)/2] + nums1[n1/2]) / 2.0

        n = n1 + n2
        lo, hi = 0, 2*n2
        while lo <= hi:
            c2 = (lo + hi) / 2
            c1 = n - c2

            l1 = nums1[(c1 - 1) / 2] if c1 else -sys.maxint-1
            r1 = nums1[c1 / 2] if c1 / 2 < n1 else sys.maxint
            l2 = nums2[(c2 - 1) / 2] if c2 else -sys.maxint-1
            r2 = nums2[c2 / 2] if c2 / 2 < n2 else sys.maxint

            if r2 >= l1 and l2 <= r1:
                return (max(l1, l2) + min(r1, r2)) / 2.0
            elif r2 < l1:
                lo = c2 + 1
            else:
                hi = c2 - 1

        return -1.0

        # script.2 just use built-in function, 172ms
        from heapq import merge
        nums = list(merge(nums1, nums2))
        n = len(nums1) + len(nums2)
        if n % 2:
            return nums[(n-1)/2] * 1.0
        else:
            return (nums[n/2] + nums[n/2-1]) / 2.0      

        # script.1 merge + bisect, 200ms, 竟然比自带方法还慢，这时间复杂度到底是多少？
        n = len(nums1) + len(nums2)
        nums = [None]* n
        p1 = p2 = p = 0
        from bisect import bisect
        while p1 < len(nums1) and p2 < len(nums2):
            idx = bisect(nums1[p1:], nums2[p2])
            nums[p:p+idx] = nums1[p1:p1+idx]
            nums[p+idx] = nums2[p2]
            p1 += idx
            p2 += 1
            p += idx + 1
        if p1 < len(nums1):
            nums[p:] = nums1[p1:]
        else:
            nums[p:] = nums2[p2:]
        if n % 2:
            return nums[(n-1)/2] * 1.0
        else:
            return (nums[n/2] + nums[n/2-1]) / 2.0


s = Solution()
print s.findMedianSortedArrays([1], [2,3])
print s.findMedianSortedArrays([], [2,3])
print s.findMedianSortedArrays([100001], [100000])
print s.findMedianSortedArrays([1, 3, 5], [12, 14, 16])
print s.findMedianSortedArrays([1, 3, 5, 7, 9, 11], [2, 4, 6])
print s.findMedianSortedArrays([1, 3, 5, 7, 9, 11], [8])

