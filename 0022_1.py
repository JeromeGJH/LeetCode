class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dp = [[] for _ in range(n+1)]         
        dp[0] = [""]                         
        for i in range(1, n+1):              
            for p in range(i):             
                for k1 in dp[p]:
                    for k2 in dp[i-1-p]:
                        dp[i].append("({0}){1}".format(k1, k2))
            
        return dp[n]
