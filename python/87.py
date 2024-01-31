import collections
class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        # use flag to avoid repetitive calculation, why slower than
        # https://discuss.leetcode.com/topic/31560/60-ms-recursive-python-solution-faster-than-100-of-python-solutions-with-comments
        # test is unstable, remove n = len(w1) give 8ms faster!
        def sub(w1, w2, flag):  # flag=True means character count has been checked
            if w1 == w2:
                return True
            if not flag:
                # check character count
                counter1 = collections.defaultdict(int)
                counter2 = collections.defaultdict(int)
                for c1, c2 in zip(w1, w2):
                    counter1[c1] += 1
                    counter2[c2] += 1
                if counter1 != counter2:
                    return False
            if len(w1) < 4:
                return True
            c1_left = collections.defaultdict(int)
            c2_left = collections.defaultdict(int)
            c2_right = collections.defaultdict(int)
            for i in xrange(1, len(w1)):
                c1_left[w1[i - 1]] += 1
                c2_left[w2[i - 1]] += 1
                c2_right[w2[-i]] += 1
                if c1_left == c2_left:
                    if sub(w1[:i], w2[:i], True) and sub(w1[i:], w2[i:], False):
                        return True
                if c1_left == c2_right:
                    if sub(w1[:i], w2[-i:], True) and sub(w1[i:], w2[:-i], False):
                        return True
            return False
        return sub(s1, s2, False)

s = Solution()
print s.isScramble('a', 'a')
print s.isScramble('abcde', 'beacd')
print s.isScramble('rgeat', 'great')
print s.isScramble('rgtae', 'great')
print s.isScramble('abcd', 'bdac')
