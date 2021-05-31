class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        if l == 1:
            return s
        dp = [[False] * l for j in range(l)]

        maxLength = 1
        ret = []
        curLength =  0

        for j in range(1,l):
            for i in range(j):
                if s[i] == s[j]:
                    curLength = j - i + 1
                    if curLength <= 3 or (curLength > 3 and dp[i+1][j-1]):
                        dp[i][j] = True
                if curLength > maxLength and dp[i][j]:
                    maxLength = curLength
                    ret = s[i:j+1]
        if maxLength == 1:
            return s[0]
        return ret
                
