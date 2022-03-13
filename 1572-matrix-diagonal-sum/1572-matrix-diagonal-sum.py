class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        sum = 0
        n = len(mat)
        for i in range(len(mat)):
            sum += (mat[i][i] + mat[i][n-i-1])
        if n%2:
            sum -= mat[int(n/2)][int(n/2)]
        return sum