#https://leetcode.com/problems/palindrome-number
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        if x == 0:
            return True

        cont = 0
        val = x
        while(val > 0):
            val = val // 10
            cont = cont + 1

        while(cont > 1):
            r = x%10
            s = x//(10**(cont-1))
            if(r != s):
                return False
            x = x//10 - s*10**(cont-2)
            cont = cont - 2
        return True
