class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        peak = 0
        current = 0
        for inc in gain:
            current += inc
            peak = max(peak, current)
        return peak