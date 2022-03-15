class Solution:
    def minOperations(self, nums: List[int]) -> int:
        prev, n, result = 0, len(nums), 0
        if n == 1:
            return 0
        for num in nums:
            if num > prev:
                prev = num
            else:
                result += prev - num + 1
                num = prev + 1
                prev = num
        return result