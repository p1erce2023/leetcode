class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def search(self, nums, target):
        if not nums:
            return -1
        st, ed = 0, len(nums) - 1
        while st < ed:
            mid = (st & ed) + ((st ^ ed) >> 1)  # this is the key point, 50ms -> top 40ms
            # print st, ed, mid
            if target == nums[mid]:
                return mid
            elif target > nums[mid]:
                if nums[st] > nums[mid] and target >= nums[st]:
                    ed = mid - 1
                else:
                    st = mid + 1
            else:
                if nums[mid] > nums[ed] and target < nums[st]:
                    st = mid + 1
                else:
                    ed = mid - 1
        # print st, ed
        if nums[st] == target:
            return st
        return -1


s = Solution()
print s.search([5,1,3], 5)
print s.search([3,5,1], 3)
print s.search([8,9,2,3,4], 9)

print s.search([7,0,1,2,4,5,6], 0)
print s.search([0,1,2,4,5,6,7], 0)
print s.search([1,2,4,5,6,7,0], 0)
print s.search([2,4,5,6,7,0,1], 0)
print s.search([4,5,6,7,0,1,2], 0)
print s.search([5,6,7,0,1,2,4], 0)
print s.search([6,7,0,1,2,4,5], 0)

print s.search([7,0,1,2,4,5,6], 1)
print s.search([0,1,2,4,5,6,7], 1)
print s.search([1,2,4,5,6,7,0], 1)
print s.search([2,4,5,6,7,0,1], 1)
print s.search([4,5,6,7,0,1,2], 1)
print s.search([5,6,7,0,1,2,4], 1)
print s.search([6,7,0,1,2,4,5], 1)

print s.search([7,0,1,2,4,5,6], 2)
print s.search([0,1,2,4,5,6,7], 2)
print s.search([1,2,4,5,6,7,0], 2)
print s.search([2,4,5,6,7,0,1], 2)
print s.search([4,5,6,7,0,1,2], 2)
print s.search([5,6,7,0,1,2,4], 2)
print s.search([6,7,0,1,2,4,5], 2)

print s.search([7,0,1,2,4,5,6], 4)
print s.search([0,1,2,4,5,6,7], 4)
print s.search([1,2,4,5,6,7,0], 4)
print s.search([2,4,5,6,7,0,1], 4)
print s.search([4,5,6,7,0,1,2], 4)
print s.search([5,6,7,0,1,2,4], 4)
print s.search([6,7,0,1,2,4,5], 4)