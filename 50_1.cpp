class Solution {
public:
    	double myPow( double x, int n )
	{
        int64_t exp = n;   
		if( exp < 0 )
		{
			x = 1 / x;
			exp = -exp;
		}

		double ans = 1;
		while( exp )
		{
			if( exp & 1 )
				ans *= x;
			x *= x;
			exp >>= 1;
		}
		return ans;
	}
};
