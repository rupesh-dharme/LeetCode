class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        m, n = len(rowSum), len(colSum)
        result = [[0 for i in range(n)] for j in range(m)]
        for r in range(m):
            for c in range(n):
                result[r][c] = min(rowSum[r], colSum[c])
                rowSum[r] -= result[r][c]
                colSum[c] -= result[r][c]
        return result;