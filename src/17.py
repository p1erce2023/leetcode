class Solution:
    # @param {string} digits
    # @return {string[]}
    def letterCombinations(self, digits):
        if not digits:
            return []
        mymap = {"0": " ", "2": "abc", "3": "def", "4": "ghi", "5": "jkl", "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
        q1, q2 = [""], []
        for d in digits:
            for c in mymap[d]:                
                q2.extend(q+c for q in q1)
            q1, q2 = q2, []
        return q1


s = Solution()
assert sorted(s.letterCombinations("23")) == sorted(["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"])