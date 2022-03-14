class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        xr, sum = 0, 0
        xr, sum = self.recurse(nums, 0, len(nums), xr, sum)
        return sum
    def recurse(self, nums, i, n, xr, sum) :
        if i == n:
            sum += xr
            return xr, sum
        xr ^= nums[i]
        xr, sum = self.recurse(nums, i+1, n, xr, sum)
        xr ^= nums[i]
        xr, sum = self.recurse(nums, i+1, n, xr, sum)
        return xr, sum