class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        close = 0
        open = 0
        for char in s:
            if char == ')':
                if open > 0:
                    open -= 1
                else:
                    close += 1
            elif char == '(':
                open += 1
        return close + open