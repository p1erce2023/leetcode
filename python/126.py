class Solution(object):
    def findLadders(self, beginWord, endWord, wordlist):
        """
        :type beginWord: str
        :type endWord: str
        :type wordlist: Set[str]
        :rtype: List[List[int]]
        """
        # bi-directional bfs
        import collections
        alphabet_set = set('abcdefghijklmnopqrstuvwxyz')
        paths, frontiers = [{beginWord}, {endWord}], [{beginWord}, {endWord}]
        wordlist.update([beginWord, endWord])
        pointers = [collections.defaultdict(list), collections.defaultdict(list)]
        d, l = 0, len(beginWord)
        junction = set()  # nodes that front meet back
        while frontiers[d]:
            wordlist -= frontiers[d]
            nxt = set()
            for word in frontiers[d]:
                for w in {word[:i] + ch + word[i + 1:] for i in xrange(l) for ch in alphabet_set} & wordlist:
                    paths[d].add(w)
                    pointers[d][w].append(word)
                    if w in paths[1 - d]:
                        junction.add(w)
                    nxt.add(w)
            if junction:  # two frontier meet
                seqs = [[x] for x in junction]
                while seqs[0][0] != beginWord:
                    seqs = [[p] + seq for seq in seqs for p in pointers[0][seq[0]]]
                while seqs[0][-1] != endWord:
                    seqs = [seq + [p] for seq in seqs for p in pointers[1][seq[-1]]]
                return seqs
            frontiers[d] = nxt
            # not begin->end->begin->end iterate, but short first!
            d = 0 if len(frontiers[0]) < len(frontiers[1]) else 1
        return []

s = Solution()
print s.findLadders("hit", "cog", {"hot", "dot", "dog", "lot", "log"})
print s.findLadders("hit", "cog", {"hot", "dot"})
print s.findLadders("a", "c", {"a", "b", "c"})
print s.findLadders("red", "tax", {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"})
