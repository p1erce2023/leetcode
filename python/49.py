class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        # script 3, difference with 1 in using ('a', 'a', 'b') as key, not "a2b1"
        dic = {}
        for s in strs:
            x = tuple(sorted(s))
            if x in dic:
                dic[x].append(s)
            else:
                dic[x] = [s]
        return [sorted(item) for item in dic.itervalues()]
        
        # script 2, slow
        alphabet = "abcdefghijklmnopqrstuvwxyz"
        t = dict((x, 0) for x in alphabet)
        category = {}
        for w in strs:
            tt = t.copy()
            for c in w:
                tt[c] += 1
            r = "".join(str(i) for i in tt.itervalues())
            if r in category:
                category[r].append(w)
            else:
                category[r] = [w]
        return [sorted(x) for x in category.itervalues()]
        
        # script 1, very slow
        from collections import defaultdict, Counter
        category = defaultdict(list)
        for w in strs:
            c = Counter(w)
            d = "".join("%s%s" % (k, c[k]) for k in sorted(c.keys()))
            category[d].append(w)
        return [sorted(x) for x in category.values()]

s = Solution()
print s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
print s.groupAnagrams(["cab","pug","pei","nay","ron","rae","ems","ida","mes"])
