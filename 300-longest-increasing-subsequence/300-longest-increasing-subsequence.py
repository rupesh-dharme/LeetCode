class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        l = [1 for i in range(n)]
        for i in range(1, n):
            for j in range(0, i):
                if nums[i] > nums[j] and l[j] >= l[i]:
                    l[i] = l[j] + 1
        return max(l);