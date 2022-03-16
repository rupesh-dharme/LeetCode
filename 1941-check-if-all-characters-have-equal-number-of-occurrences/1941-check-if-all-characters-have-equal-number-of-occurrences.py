class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        count = {}
        for ch in s:
            if ch in count.keys():
                count[ch] += 1
            else:
                count[ch] = 0
        freq = count[s[0]]
        for val in count.values():
            if val != freq:
                return False
        return True