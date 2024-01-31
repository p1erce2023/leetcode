class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: Set[str]
        :rtype: int
        """
        # bi-directional bfs
        if beginWord == endWord:
            return 0
        alphabet_set = set('abcdefghijklmnopqrstuvwxyz')
        paths, frontiers = [{beginWord: 0}, {endWord: 0}], [[beginWord], [endWord]]
        dir = 0

        def generate(word):
            for i in xrange(len(word)):
                for x in alphabet_set - set(word[i]):
                    xx = word[:i] + x + word[i + 1:]
                    if xx in wordList:
                        yield xx
        while frontiers[dir]:
            nxt = []
            for node in frontiers[dir]:
                for word in generate(node):  # iterate wordList will cause TLE
                    if word not in paths[dir]:
                        paths[dir][word] = paths[dir][node] + 1
                        if word in paths[1 - dir]:
                            return paths[dir][word] + paths[1 - dir][word] + 1
                        nxt.append(word)
            frontiers[dir] = nxt
            # not begin->end->begin->end iterate, but short first!
            dir = 0 if len(frontiers[0]) < len(frontiers[1]) else 1
        return 0

s = Solution()
print s.ladderLength("hit", "cog", {"hot", "dot", "dog", "lot", "log"})
