class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        mx = 0
        for [l, b] in rectangles:
            mx = max(mx, min(l, b))
        count = 0
        for [l, b] in rectangles:
            if min(l, b) >= mx:
                count += 1
        return count