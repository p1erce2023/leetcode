class Solution:
    # @param {integer[]} candidates
    # @param {integer} target
    # @return {integer[][]}
    def combinationSum(self, candidates, target):

        # fast, 92ms, reason? recursive and no need for unique and sort
        # interesting recursive
        candidates.sort()
        return self._combinationSum(candidates, target, [])

    def _combinationSum(self, candidates, target, item):
        if not candidates:
            return []

        c = candidates[0]
        if c > target:
            return []
        if c == target:
            return [item + [c]]

        return self._combinationSum(candidates[1:], target, item) + self._combinationSum(candidates, target - c, item + [c])


        # other's solution, 96ms. use python yield keyword, same logic with the above
        def combSum(candidates, target):
            if candidates == [] or target < candidates[0]:
                return
            elif target == candidates[0]:
                yield [target]
            else:
                for comb in combSum(candidates, target - candidates[0]):
                    yield [candidates[0]] + comb
                for comb in combSum(candidates[1:], target):
                    yield comb

        return list(combSum(sorted(set(candidates)), target))


        # 176ms, dp bottom up
        candidates.sort()
        candidates_set = set(candidates)
        from collections import defaultdict
        r = defaultdict(list)
        _min = candidates[0]
        for i in xrange(_min, target + 1):
            if i in candidates_set:
                r[i].append([i])

            for d in xrange(_min, i):
                if d in candidates_set and r[i-d]:
                    for l in r[i-d]:
                        t = l + [d]
                        r[i].append(t)
            if r[i]:
                t = set(tuple(sorted(l)) for l in r[i])
                r[i] = [list(l) for l in t]
        return r[target]


        # script 1: too slow, 600ms
        candidates.sort()

        def combinationSum2(candidates, target):
            r = []
            for i in candidates:
                if i < target:
                    s = self.combinationSum(candidates, target - i)
                    for l in s:
                        l.append(i)
                    r.extend(s)
                elif i == target:
                    r.append([i])
                else:
                    break
            return r

        r = combinationSum2(candidates, target)
        r = set(tuple(sorted(l)) for l in r)
        r = [list(l) for l in r]
        return r


s = Solution()
print s.combinationSum([2, 3, 6, 7], 7)
