class Solution:
    def convert(self, s: str, numRows: int) -> str:
        l = len(s)
        if numRows == 1 or l == 1:
            return s
        
        period = numRows * 2 - 2
        numPeriod = l // period
        count = 0
        output = [[] for _ in range(numRows)]
        i = 0
        while(count < numPeriod):
            for j in range(numRows):
                output[j].append(s[i + j])
            for j in range(numRows, period):
                output[period - j].append(s[i + j])
            i += period
            count += 1
        
        for j in range(i, l):
            for k in range(numRows):
                if j % period == k or j % period == period - k:
                    output[k].append(s[j])
                    
        str = ''
        for k in range(numRows):
            str += ''.join(output[k])
        return str
            
            
