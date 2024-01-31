class Solution:
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        letterlogs = []
        digitlogs = []
        digit = set('0987654321')
        for log in logs:
            words = log.split(' ')
            if words[1][0] in digit:
                digitlogs.append(log)
            else:
                letterlogs.append((' '.join(words[1:]), words[0]))
        letterlogs.sort(key=lambda item: item[0])
        return ['{} {}'.format(item[1], item[0]) for item in letterlogs] + digitlogs


s = Solution()
print(s.reorderLogFiles(["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]))
