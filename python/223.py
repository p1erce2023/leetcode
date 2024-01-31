class Solution:
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        if A > E:
            A, B, C, D, E, F, G, H = E, F, G, H, A, B, C, D
        area_sum = (C-A)*(D-B) + (G-E)*(H-F)
        if E >= C or F >= D or B >= H:
            overlay = 0
        else:
            overlay = (min(C, G)-max(A, E))*(min(D, H)-max(B, F))
        return area_sum - overlay
