class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        l = len(s)
        period = numRows * 2 - 2
        length = l // period + 1
        output = [[] for _ in range(numRows)]
        for i in range(l):
            for j in range(numRows):
                r = i % period
                if r == j or r == period - j:
                    output[j].append(s[i])

        ret = []
        for k in range(numRows):
            for m in output[k]:
                ret.append(m)

        str = ''.join(ret)

        return str
    
#     list to string: ''.join(list)
            
            
