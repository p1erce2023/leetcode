class Solution:
    # @param {string} num1
    # @param {string} num2
    # @return {string}
    def multiply(self, num1, num2):
        # script 4: only calculate / and % in the end, not much improvement over script #3
        if num1 == "0" or num2 == "0":
            return "0"
        if num1 == "1":
            return num2
        if num2 == "1":
            return num1
        l1, l2 = len(num1), len(num2)
        num = [0] * (l1 + l2)
        for j in xrange(l2):
            for i in xrange(l1):
                num[j + i] += int(num2[-1 - j]) * int(num1[-1 - i])
        carry = 0
        for k in xrange(l1 + l2):
            d = num[k] + carry
            carry = d / 10
            num[k] = d % 10
        num.reverse()
        st = 0
        while st < (l1 + l2) and not num[st]:
            st += 1
        return "".join(map(str, num[st:]))

        # script 3: two for loop, hand calculation, easy understanding, 444ms
        if num1 == "0" or num2 == "0":
            return "0"
        if num1 == "1":
            return num2
        if num2 == "1":
            return num1
        l1, l2 = len(num1), len(num2)
        max_len = l1 + l2
        num = [0] * max_len
        for j in xrange(l2):
            carry = 0
            for i in xrange(l1):
                s = num[j + i] + carry + int(num2[-1 - j]) * int(num1[-1 - i])
                carry = s / 10
                num[j + i] = s % 10
            if carry:
                num[j + l1] += carry
        num.reverse()
        st = 0
        while st < max_len and not num[st]:
            st += 1
        return "".join("%s" % n for n in num[st:])

        # script 2: 242ms, better but still not satisfactory
        def digit_multiply(num, d):
            d = int(d)
            if not d:
                return [0]
            n = len(num)
            r = [0] * (n + 1)
            for i in xrange(n):
                r[i] = int(num[-1-i]) * d
            return r

        if num1 == "0" or num2 == "0":
            return "0"
        if num1 == "1":
            return num2
        if num2 == "1":
            return num1
        # 2.2 not using stack, nearly the same as stack
        l1, l2 = len(num1), len(num2)
        num = [0]*(l1+l2)
        for j in xrange(l2):
            t = digit_multiply(num1, num2[-1-j])
            for i in xrange(len(t)):
                num[j+i] += t[i]
        carry = 0
        for k in xrange(l1 + l2):
            d = num[k] + carry
            carry = d / 10
            num[k] = d % 10
        num.reverse()
        st = 0
        while st < l1+l2 and not num[st]:
            st += 1
        return "".join("%s" % n for n in num[st:])

        # 2.1 using stack
        num, stack = [], []
        if len(num1) < len(num2):
            num1, num2 = num2, num1
        stack.append(digit_multiply(num1, num2[-1]))
        i = 1
        while stack:
            s = sum(r.pop() for r in stack)
            stack = filter(None, stack)
            if s >= 10:
                stack.append([int(d) for d in "%s" % (s/10)])
            num.append("%s" % (s % 10))
            if i < len(num2):
                stack.append(digit_multiply(num1, num2[-1-i]))
                i += 1
        return "".join(reversed(num))


        # script 1: very slow, do many unnecessary +, 800ms+
        def single_multiply(num1, n2, i):
            r = []
            n2 = int(n2)
            carry = 0
            for n in num1[::-1]:
                s = n2 * int(n) + carry
                r.append("%d" % (s % 10))
                carry = s / 10
            while carry:
                r.append("%d" % (carry % 10))
                carry = carry / 10
            num = "".join(reversed(r))
            return num + "0" * i

        r = []
        for i, n2 in enumerate(num2[::-1]):
            r.append(single_multiply(num1, n2, i))
        max_len = max(len(s) for s in r)
        for i in xrange(len(r)):
            r[i] = r[i].zfill(max_len)
        carry = 0
        num = []
        for i in xrange(max_len):
            s = sum(int(x[-1-i]) for x in r) + carry
            num.append("%d" % (s % 10))
            carry = s / 10
        while carry:
            num.append("%d" % (carry % 10))
            carry = carry / 10
        n = "".join(reversed(num))
        n = n.lstrip("0")
        if not n:
            n = "0"
        return n


s = Solution()

print s.multiply("123456789", "987654321")  # 121932631112635269
print s.multiply("10001", "12")  # 120012
print s.multiply("12", "5")  # 60
print s.multiply("9", "99")  # 891
print s.multiply("123", "456")  # 56088
print s.multiply("15", "5")  # 75
print s.multiply("115", "4")  # 460
print s.multiply("51", "11")  # 561
print s.multiply("15", "31")  # 465
print s.multiply("154", "0")  # 0
print s.multiply("0", "0")  # 0
