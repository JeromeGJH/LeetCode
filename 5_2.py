class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        if l == 1:
            return s[0]

        count = 0
        maxLength = 1
        ret = []

        for start in range(l-1):
            count = 1
            for i in range(1, l):
                if start + i == l or start - i < 0:
                    break
                else:
                    if s[start - i] == s[start + i]:
                        count += 2
                        if start + i == l-1 or start - i == 0:
                            if count > maxLength:
                                maxLength = count
                                ret = s[start - i: start + i + 1]
                            break
                        # print('start:', start, count)
                    else:
                        if count > maxLength:
                            print('start:', start, count)
                            maxLength = count
                            ret = s[start - i + 1: start + i]
                            print(ret)
                        break
        
        for start in range(l-1):
            count = 0
            for i in range(1, l):
                if start + i == l or start - i + 1 < 0:
                    break
                else:
                    if s[start - i + 1] == s[start + i]:
                        count += 2
                        if start + i == l-1 or start - i + 1 == 0:
                            if count > maxLength:
                                maxLength = count
                                ret = s[start - i + 1: start + i+1]
                            break
                    else:
                        if count > maxLength:
                            maxLength = count
                            ret = s[start - i + 2: start + i]
                        break

        if maxLength == 1:
            return s[0]
        return ret


                
