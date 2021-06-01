class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)

        if l <= 1:
            return s
        if  l == 2:
            if s[0] == s[1]:
                return s
            else:
                return s[0]

        start = 0
        end = l-1
        count  = 0
        maxLength = 1
        ret = []

        while(start < l-1):
            i = start
            end = l-1
            j = end
            count = 0
            while(i < j):
                if s[i] == s[j]:
                    if j - i <= 2:
                        count += j-i+1
                        if count > maxLength:
                            maxLength = count
                            ret = s[start:end+1]
                        break
                    else:
                        i += 1
                        j -= 1
                        count += 2
                else:
                    end -= 1
                    count = 0
                    i = start
                    j = end
            start += 1

        if maxLength == 1:
            return s[0]
        else:
            return ret
        


        
