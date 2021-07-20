class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        if (matrix == null || matrix.length == 0) return 0;
        int m = matrix.length, n = matrix[0].length, max = Integer.MIN_VALUE;
        int old, now = 0;
        for (int i1 = 1; i1 <= m; i1++) {
            for (int j1 = 1; j1 <= n; j1++) {
                int[][] f = new int[2][n + 1];
                for (int i2 = i1; i2 <= m; i2++) {
                    old = now;
                    now = 1 - now;
                    for (int j2 = j1; j2 <= n; j2++) {
                        f[now][j2] = f[old][j2] + f[now][j2 - 1] - f[old][j2 - 1] + matrix[i2 - 1][j2 - 1];
                        if (f[now][j2] == k) return k;
                        if (f[now][j2] < k) max = Math.max(max, f[now][j2]);
                    }
                }
            }
        }
        return max; 
    }
};
