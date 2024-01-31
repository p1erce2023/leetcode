from typing import List

class Solution:
    mp = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
    def f(self, i: int, s: str) -> List[str]:
        if i == len(s) - 1:
            return [c for c in self.mp[s[-1]]]
        rem = self.f(i+1, s)
        res = []
        for c in self.mp[s[i]]:
            t = [c+ss for ss in rem]
            res += t
        return res

    def letterCombinations(self, s: str) -> List[str]:
        return self.f(0, s)

if __name__ == '__main__':
    sol = Solution()
    # param init
    s = '23'
    print(sol.letterCombinations(s))