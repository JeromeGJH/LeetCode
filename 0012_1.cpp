class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        for(int i = num /1000; i > 0; --i)
            res += "M";
        num %= 1000;
        if(num >= 900){
            res += "CM";
            num -= 900;
        }
        if(num >= 500){
            res += "D";
            num -= 500;
        }
        if(num >= 400){
            res += "CD";
            num -= 400;
        }
        for(int i = num/100; i> 0; --i){
            res += "C";
        }
        num %= 100;

        
        if(num >= 90){
            res += "XC";
            num -= 90;
        }
        if(num >= 50){
            res += "L";
            num -= 50;
        }
        if(num >= 40){
            res += "XL";
            num -= 40;
        }
        
        for(int i = num/10; i> 0; --i){
            res += "X";
        }
        num %= 10;
        


        if(num == 9){
            res += "IX";
            return res;
        }
        if(num >= 5){
            res += "V";
            num -= 5;
        }
        if(num == 4){
            res += "IV";
            return res;
        }
        for(int i = num; i > 0; --i){
            res += "I";
        }
        return res;
    }
};
