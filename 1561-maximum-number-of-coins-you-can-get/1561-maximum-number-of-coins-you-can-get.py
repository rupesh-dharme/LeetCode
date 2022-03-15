class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        n, l, r, coins = len(piles), 1, len(piles)-1, 0
        piles.sort(reverse = True)
        while l < r:
            coins += piles[l]
            l += 2
            r -= 1
        return coins