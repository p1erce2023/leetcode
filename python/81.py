class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def search(self, nums, target):
        if not nums:
            return False
        st, ed = 0, len(nums) - 1
        while st < ed:
            mid = (st & ed)  + ((st ^ ed) >> 1)
            # print st, mid, ed
            if nums[mid] == target:
                return True
            if nums[mid] < nums[st]:
                if nums[mid] < target <= nums[ed]:
                    st = mid + 1
                else:
                    ed = mid - 1
            elif nums[mid] > nums[st]:
                if nums[st] <= target < nums[mid]:
                    ed = mid - 1
                else:
                    st = mid + 1
            else:  # nums[st] == nums[mid]
                if nums[mid] == nums[ed]:
                    flag = True
                    i = 1
                    while st+i < mid or ed-i > mid:
                        if st+i < mid and nums[st+i-1] != nums[st+i]:
                            st = st + i
                            ed = mid - 1
                            flag = False
                            break
                        if ed-i > mid and nums[ed-i] != nums[ed+1-i]:
                            ed = ed - i
                            st = mid + 1
                            flag = False
                            break
                        i += 1
                    if flag:
                        return False
                else:
                    st = mid + 1
        if nums[st] == target:
            return True
        return False

s = Solution()
print s.search([1,1,3,1], 3)
print s.search([1,3,1,1,1], 3)
