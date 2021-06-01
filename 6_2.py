class Solution:
    def convert(self, s: str, numRows: int) -> str:
        l = len(s)
        if numRows == 1 or l == 1:
            return s
        
        period = numRows * 2 - 2
        output = [[] for _ in range(numRows)]
        for i in range(l):
            if i % period == 0:
                if i + period <= l:
                    for j in range(numRows):
                        output[j].append(s[i + j])
                        if 0< j < numRows - 1:
                            output[j].append(s[i + period - j])
                else:
                    for j in range(i, l):
                        for k in range(numRows):
                            if j % period == k or j % period == period - k:
                                output[k].append(s[j])
                
                    
        str = ''
        for k in range(numRows):
            str += ''.join(output[k])
        return str
            
            
