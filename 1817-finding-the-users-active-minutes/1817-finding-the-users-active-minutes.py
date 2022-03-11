class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        d = {}
        res = [0 for i in range(k)]
        for l in logs:
            i, t = l[0], l[1]
            if i not in d.keys():
                d[i] = {t}
            else:
                d[i].add(t)
        for i in d.values():
            res[len(i)-1]+=1
        return res