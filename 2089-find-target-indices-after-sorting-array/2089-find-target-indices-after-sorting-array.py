class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        lesser, equal = 0, 0
        for num in nums:
            if num < target:
                lesser += 1
            elif num == target:
                equal += 1
        l = []
        for _ in range(equal):
            l.append(lesser)
            lesser += 1
        return l