class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, new Comparator<int[]>(){
            public int compare(int[] arr1, int[] arr2){
                if(arr1[0] == arr2[0]){
                    return arr2[1] - arr1[1];
                }else{
                    return arr1[0] - arr2[0];
                }
            }
        });
        int l = envelopes.length;
        int i = 0, j = 0;
        int max = 1;
        int[] dp = new int[l];
        for(j = 0; j < l ; ++j){
            dp[j] = 1;
            for(i = 0; i < j; ++i){
                if(envelopes[j][0] > envelopes[i][0] && envelopes[j][1] > envelopes[i][1]){
                    dp[j] = Math.max(dp[j], dp[i] + 1);
                }
            }
        }
        for(int e: dp){
            max = Math.max(max, e);
        }
        return max;
    }
} 
