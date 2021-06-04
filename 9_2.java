class Solution {
    public boolean isPalindrome(int x) {
        int revertedNum = 0;
        if (x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }
        while(x > revertedNum){
            revertedNum = revertedNum * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNum || x == revertedNum / 10;
    }
}
