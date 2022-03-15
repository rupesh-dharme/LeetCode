class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        l = [0 for i in range(n)]
        for edge in edges:
            l[edge[1]] = 1
        result = []
        for i in range(n):
            if l[i] == 0:
                result.append(i)
        return result