class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        eset = set()
        for x in emails:
            xx = x.split('@')
            a, b = xx[0], xx[1]
            a = a.split('+', 1)[0]
            eset.add((a.replace('.', ''), b))
        return len(eset)
