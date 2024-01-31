class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = {}

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        p = self.root
        for c in word:
            if c not in p:
                p[c] = {}
            p = p[c]
        p['stop'] = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        p = self.root
        for c in word:
            if c not in p:
                return False
            p = p[c]
        return p.get('stop', False)

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        p = self.root
        for c in prefix:
            if c not in p:
                return False
            p = p[c]
        return True if p else False


# Your Trie object will be instantiated and called as such:
obj = Trie()
obj.insert('apple')
print(obj.search('app'))
print(obj.search('apple'))
print(obj.startsWith('app'))
obj.insert('app')
print(obj.search('app'))
