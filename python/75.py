class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # sweep red to left, blue to right
        # also use two variable, but it does less swap action. Really?
        red, blue = 0, len(nums) - 1
        i = 0
        while i <= blue:
            if nums[i] == 0:
                nums[i], nums[red] = nums[red], nums[i]
                red += 1
                i += 1
            elif nums[i] == 2:
                nums[i], nums[blue] = nums[blue], nums[i]
                blue -= 1
            else:
                i += 1
        # return nums

        # readable and concise c++ code
        # int i = 0, j = n-1;
        # for(int k=0; k <= j; )
        # {
        #     if(A[k]==0)  swap(A[i++], A[k++]);
        #     else if(A[k]==2)  swap(A[j--], A[k]);
        #     else k++;
        # }

        # my thought, use red and white as a record at its change, but there exists unnecessary swap
        red, white = 0, 0  # end
        for i in xrange(len(nums)):
            if nums[i] == 0:
                nums[white], nums[i] = nums[i], nums[white]
                nums[red], nums[white] = nums[white], nums[red]
                red += 1
                white += 1
            elif nums[i] == 1:
                nums[white], nums[i] = nums[i], nums[white]
                white += 1
            # print nums
        # return nums

s = Solution()
print s.sortColors([1,0,2,0])
print s.sortColors([0,0,2,0])
print s.sortColors([0,0,2,0,1,2,0,0,0,0,0,0,1,1,1,1,1,1,0,2,0,0,2,0,2,2,1,2,1,1])
