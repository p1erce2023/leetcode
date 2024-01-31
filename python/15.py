class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def threeSum(self, nums):
        # since sort use O(nlog(n)) < O(n^2), however slower to 280ms; avoid duplicate -> 200ms
        if len(nums) < 3:
            return []
        count = set()
        triplets = []
        triplets_set = set()
        nums.sort()
        n = len(nums)
        for i in xrange(n):
            if nums[i] in count:  # avoid duplicate
                continue
            count.add(nums[i])
            j, k = i + 1, n - 1
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                if not s:
                    if (nums[i], nums[j], nums[k]) not in triplets_set:
                        triplets.append((nums[i], nums[j], nums[k]))
                        triplets_set.add((nums[i], nums[j], nums[k]))
                    j += 1
                    while nums[j] == nums[j-1] and j < k:  # avoid duplicate
                        j += 1
                    k -= 1
                    while nums[k] == nums[k+1] and j < k:  # avoid duplicate
                        k -= 1
                elif s > 0:
                    k -= 1
                else:
                    j += 1
        return triplets
    
        # O(n^2), 260ms
        if len(nums) < 3:
            return []
        count = {}
        triplets = []
        has = set()
        for n in nums:
            if n in count:
                count[n] += 1
            else:
                count[n] = 1
        if 0 in count and count[0] > 2:
            triplets.append([0, 0, 0])
        
        for i in count:
            for j in count:
                if i != j:
                    k = -i - j
                    if ((i == k or j == k) and count[k] > 1) or (i != k and j != k and k in count):    
                        triplet = sorted([i, j, k])
                        if tuple(triplet) not in has:
                            triplets.append(tuple(triplet))
                            has.add(tuple(triplet))
        return triplets


s = Solution()
print s.threeSum([-1, 0, 1, 2, -1, -4])
print s.threeSum([6, -6, 0, -12])
print s.threeSum([-12,4,12,-4,3,2,-3,14,-14,3,-12,-7,2,14,-11,3,-6,6,4,-2,-7,8,8,10,1,3,10,-9,8,5,11,3,-6,0,6,12,-13,-11,12,10,-1,-15,-12,-14,6,-15,-3,-14,6,8,-9,6,1,7,1,10,-5,-4,-14,-12,-14,4,-2,-5,-11,-10,-7,14,-6,12,1,8,4,5,1,-13,-3,5,10,10,-1,-13,1,-15,9,-13,2,11,-2,3,6,-9,14,-11,1,11,-6,1,10,3,-10,-4,-12,9,8,-3,12,12,-13,7,7,1,1,-7,-6,-13,-13,11,13,-8])
