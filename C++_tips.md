# C++

string比较大小时，会对每个字符进行比较，然后再比较长度  
abc aacd abcd -> aacd abc abcd 

```
int a = 3
```

不能用变量来初始化数组，数组在堆中；

二维vector初始化，r行，c列：
```
vector<vector<int>> dp(r, vector<int>(c, 0));
```
sort（）
标准库里已经有现成的了，就在functional里，include进来就行了。functional提供了一堆基于模板的比较函数对象。它们是（看名字就知道意思了）：equal_to<Type>、not_equal_to<Type>、greater<Type>、greater_equal<Type>、less<Type>、less_equal<Type>。对于这个问题来说，greater和less就足够了，直接拿过来用：

升序：sort(begin,end,less<data-type>());
降序：sort(begin,end,greater<data-type>()).
