class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_, min_, n = nums[0], nums[0], 0
        for i in nums:
            n += 1
            if i > max_:
                max_ = i
            elif i < min_:
                min_ = i
        if n < 2:
            return 0
        if n == 2 or max_ == min_:
            return max_ - min_
        bucket_size = (max_ - min_) // (n - 1) + 1
        buckets = [{} for _ in range(n - 1)]
        for i in nums:
            j = (i - min_) // bucket_size
            if 'min' not in buckets[j] or i < buckets[j]['min']:
                buckets[j]['min'] = i
            if 'max' not in buckets[j] or i > buckets[j]['max']:
                buckets[j]['max'] = i
        buckets = [d for d in buckets if d]
        gap = max(buckets[i + 1]['min'] - buckets[i]['max'] for i in range(len(buckets) - 1))
        return max(bucket_size, gap)


s = Solution()
print(s.maximumGap([3, 6, 9, 1]))
print(s.maximumGap([100, 3, 2, 1]))
print(s.maximumGap([10]))
