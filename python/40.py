class Solution:
    # @param {integer[]} candidates
    # @param {integer} target
    # @return {integer[][]}
    def combinationSum2(self, candidates, target):
        # 84ms, good, with reference to discussion
        # the same? seems like so. 72ms. change loops to recursive
        n = len(candidates)
        candidates.sort()
        re = []

        def dfs(target, idx, onlist):
            if idx >= n or candidates[idx] > target :
                return
            if target == candidates[idx]:
                onlist.append(target)
                re.append(onlist[:])
                onlist.pop()
                return

            onlist.append(candidates[idx])
            dfs(target - candidates[idx], idx + 1, onlist)
            onlist.pop()

            idx2 = idx + 1
            while idx2 < n and candidates[idx2] == candidates[idx]:
                idx2 += 1  # this remove the duplication
            dfs(target, idx2, onlist)
            return
        dfs(target, 0, [])
        return re


        # other's dfs, 76ms
        candidates.sort()
        ans = []
        l = len(candidates)

        def combinationSum(i, t, res):
            if t == 0:
                ans.append(list(res))
                return
            for j in xrange(i, l):
                v = candidates[j]
                # No duplicate in iteration. They have been handled during recursion.
                if j > i and v == candidates[j - 1]:
                    continue
                # Fail fast
                if t < v:
                    break
                res.append(v)
                combinationSum(j + 1, t - v, res)
                res.pop()
        combinationSum(0, target, [])
        return ans


        # still has duplication, leads to 128ms
        def cs2(candidates, target, onlist):
            if not candidates or candidates[0] > target:
                return []
            if candidates[0] == target:
                if not onlist:
                    onlist2 = [[target]]
                else:
                    onlist2 = [l + [candidates[0]] for l in onlist]
                return onlist2
            a = cs2(candidates[1:], target, onlist)
            if not onlist:
                onlist2 = [[candidates[0]]]
            else:
                onlist2 = [l + [candidates[0]] for l in onlist]
            b = cs2(candidates[1:], target - candidates[0], onlist2)
            return a + b

        candidates.sort()
        re = set(tuple(r) for r in cs2(candidates, target, []))
        return [list(r) for r in re]


s = Solution()
print s.combinationSum2([1], 1)
print s.combinationSum2([10,1,2,7,6,1,5], 8)
