class Solution:
    # @param {integer[][]} matrix
    # @return {void} Do not return anything, modify matrix in-place instead.
    def rotate(self, matrix):
        dim = len(matrix) - 1
        st, ed = 0, dim
        while st < ed:
            for i in xrange(ed - st):
                matrix[st][st+i], matrix[st+i][ed], matrix[ed][ed-i], matrix[ed-i][st] = matrix[ed-i][st], matrix[st][st+i], matrix[st+i][ed], matrix[ed][ed-i]
            st += 1
            ed -= 1
        return


def myprint(matrix):
    print "-----"
    for row in matrix:
        for cell in row:
            print cell,
        print ""
    print "-----\n"


s = Solution()
dim = 6
matrix = [[i]*dim for i in range(1, dim+1)]
myprint(matrix)
for _ in range(4):
    s.rotate(matrix)
    myprint(matrix)
