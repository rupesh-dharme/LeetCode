class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        sum = 0
        n = len(mat)
        for i in range(n):
            sum += (mat[i][i] + mat[i][n-i-1])
        if n%2:
            sum -= mat[n//2][n//2]
        return sum