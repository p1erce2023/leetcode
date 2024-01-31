class Solution(object):
    def kSimilarity(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        a, b, n = [], [], len(A)
        for i in range(n):
            if A[i] != B[i]:
                a.append(A[i])
                b.append(B[i])
        if not a:
            return 0
        return self.func(a, b)

    def func(self, A, B):
        queue = [(A, B, 0)]
        y = len(A)
        while queue:
            a, b, c = queue.pop()
            n = len(a)
            children = []
            swap = []
            for i in range(1, n):
                if b[0] == b[i]:
                    continue
                if a[0] == b[i]:
                    a_, b_ = a[1:], b[1:]
                    b_[i - 1] = b[0]
                    if a_[i - 1] == b_[i - 1]:
                        a_.pop(i - 1)
                        b_.pop(i - 1)
                        swap = [(a_, b_, c + 1)]
                    else:
                        children.append((a_, b_, c + 1))
            if swap:
                if swap[0][0]:
                    queue.extend(swap)
                else:
                    y = min(y, swap[0][2])
            else:
                queue.extend(children)
        return y


s = Solution()
for a, b, c in [
    ("ab", "ba", 1),
    ("abc", "bca", 2),
    ("abac", "baca", 2),
    ("aabc", "abca", 2),
    ("abcbca", "ababcc", 1),
    ("aabbccddee", "edbaeacdcb", 5),
    ("abcdeabcdeabcdeabcde", "aaaabbbbccccddddeeee", 8),
]:
    print(s.kSimilarity(a, b), c)
