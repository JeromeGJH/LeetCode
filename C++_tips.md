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
  
  
### lamda函数
在一个更为复杂的例子中，返回类型可以被明确的指定如下：

[](int x, int y) -> int { int z = x + y; return z + x; }
本例中，一个临时的参数 z 被创建用来存储中间结果。如同一般的函数，z 的值不会保留到下一次该不具名函数再次被调用时。

如果 lambda 函数没有传回值（例如 void），其返回类型可被完全忽略。

在Lambda表达式内可以访问当前作用域的变量，这是Lambda表达式的闭包（Closure）行为。 与JavaScript闭包不同，C++变量传递有传值和传引用的区别。可以通过前面的[]来指定：
|[capture]|Meaning|
|--------|----------------------------------------------|
|[]      | 沒有定义任何变量。使用未定义变量会引发错误。  |
|[x, &y] | x以传值方式传入（默认），y以引用方式传入。  |
|[&]     | 任何被使用到的外部变量都隐式地以引用方式加以引用。  |
|[=]     | 任何被使用到的外部变量都隐式地以传值方式加以引用。  |
|[&, x]  | x显式地以传值方式加以引用。其余变量以引用方式加以引用。  |
|[=, &z] | z显式地以引用方式加以引用。其余变量以传值方式加以引用。  |
