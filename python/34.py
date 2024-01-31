class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def searchRange(self, nums, target):
        if not nums:
            return [-1, -1]

        def find_left(nums, target):
            # print "find_left"
            st, ed = 0, len(nums) - 1
            finding = -1
            while st < ed:
                mid = (st & ed) + ((st ^ ed) >> 1)
                # print st, mid, ed
                if target == nums[mid]:
                    finding = mid
                    ed = mid - 1
                elif target < nums[mid]:
                    ed = mid - 1
                else:
                    st = mid + 1
            # print st, ed
            if nums[st] == target:
                return st
            return finding

        def find_right(nums, target):
            # print "find_right"
            st, ed = 0, len(nums) - 1
            finding = -1
            while st < ed:
                mid = (st & ed) + ((st ^ ed) >> 1)
                # print st, mid, ed
                if nums[mid] == target:
                    finding = mid
                    st = mid + 1
                elif nums[mid] < target:
                    st = mid + 1
                else:
                    ed = mid - 1
            # print st, ed
            if nums[st] == target:
                return st
            return finding

        st, ed = 0, len(nums) - 1
        if nums[st] == target:
            left = st
            right = find_right(nums, target)
            return [left, right]

        if nums[ed] == target:
            right = ed
            left = find_left(nums, target)
            return [left, right]

        left = find_left(nums, target)
        right = find_right(nums, target)
        return [left, right]


s = Solution()
print s.searchRange([5, 7, 7, 8, 8, 10], 8)  # [3, 4]
print s.searchRange([5, 7, 7, 8, 8, 10], 7)  # [1, 2]
print s.searchRange([5, 7, 7, 8, 8, 10], 5)  # [0, 0]
print s.searchRange([5, 7, 7, 8, 8, 10], 10)  # [5, 5]
print s.searchRange([5, 7, 7, 8, 8, 10], 11)  # [-1, -1]
print s.searchRange([5, 7, 7, 8, 8, 10], 4)  # [-1, -1]
