class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        if(x < 10){
            return true;
        }
        int res = x;
        int count = 0;
        while(res != 0){
            res = res/10;
            count += 1;
        }
        
        int tmp1 = 0, tmp2 = 0;
        int j = count -1;
        while(1 <= j){
            tmp1 = x % 10;
            tmp2 = x / (int)Math.pow(10, j);
            if(tmp1 != tmp2){
                return false;
            }
            else{
                if(j == 1 || j == 2)
                    return true;
            }
            x %= (int)Math.pow(10, j);
            x /= 10;
            j -= 2;
            
        }
        return false;
    }
}
