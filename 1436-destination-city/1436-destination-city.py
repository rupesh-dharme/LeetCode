class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        dist = {}
        for path in paths:
            dist[path[0]] = 1
        for path in paths:
            if path[1] not in dist.keys():
                return path[1]