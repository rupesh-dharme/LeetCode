class Solution:
    def maximum69Number (self, num: int) -> int:
        i = 0
        ind = -1
        temp = num
        while (temp):
            if temp%10 == 6:
                ind = i
            temp //= 10
            i += 1
        return (num + 3*(10**ind)) if ind!= -1 else num
        