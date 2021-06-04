class Solution {
    public int romanToInt(String s) {
        int l = s.length();
        char[] str = s.toCharArray();
        int res = 0;
        for(int i = 0; i< l; ++i){
            if(i < l-1){
                if(str[i] == 'M'){
                    res += 1000;
                    continue;
                }
                if(str[i] == 'D'){
                    res += 500;
                    continue;
                }
                if(str[i] == 'C'){
                    res += 100;
                    if(str[i+1] == 'D'){res += 300; i++;continue;}
                    if(str[i+1] == 'M'){res += 800; i++;continue;}
                }
                if(str[i] == 'L'){
                    res += 50;
                    continue;
                }
                if(str[i] == 'X'){
                    res += 10;
                    if(str[i+1] == 'L'){res += 30; i++;continue;}
                    if(str[i+1] == 'C'){res += 80; i++;continue;}
                }
                if(str[i] == 'V'){
                    res += 5;
                    continue;
                }
                if (str[i] == 'I'){
                    res += 1;
                    if(str[i+1] == 'V'){res += 3; i++;continue;}
                    if(str[i+1] == 'X'){res += 8; i++;continue;}
                }
            } else{
                switch(str[i]){
                    case('M'):
                    res += 1000;
                    break;
                    case('D'):
                    res += 500;
                    break;
                    case('C'):
                    res += 100;
                    break;
                    case('L'):
                    res += 50;
                    break;
                    case('X'):
                    res += 10;
                    break;
                    case('V'):
                    res += 5;
                    break;
                    case('I'):
                    res += 1;
                    break;
                }
            }
        }
        return res;
    }
}
