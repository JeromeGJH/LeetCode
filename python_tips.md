# Python Tips
### Python 位运算
a = 0011 1100
b = 0000 1101
(a & b)
按位与运算符：参与运算的两个值，如果两个相应位都为 1，则该位的结果为 1，否则为 0 。
输出结果 12 ，二进制解释： 0000 1100

(a | b)
按位或运算符：只要对应的二个二进位有一个为1时，结果位就为1。
输出结果 61 ，二进制解释： 0011 1101

(a ^ b)
按位异或运算符：当两对应的二进位相异时，结果为 1
输出结果 49 ，二进制解释： 0011 0001

(~a )
按位取反运算符：对数据的每个二进制位取反，即把 1 变为 0，把 0 变为 1 。~x 类似于 -x-1
输出结果 -61 ，二进制解释： 1100 0011，在一个有符号二进制数的补码形式。

a << 2
左移动运算符：运算数的各二进位全部左移若干位，由 << 右边的数字指定了移动的位数，高位丢弃，低位补 0。
输出结果 240 ，二进制解释： 1111 0000

a >> 2
右移动运算符：把 ">>" 左边的运算数的各二进位全部右移若干位，>> 右边的数字指定了移动的位数
输出结果 15 ，二进制解释： 0000 1111

python整数范围无限制，（1<31 = 2 ** 32）不会溢出

list[i:j:k], 当k为正数时，取值范围为[i , j);当k为负数时，取值范围为[j, i)。k的绝对值为步长，正负为方向。

### sort
sort 与 sorted 区别：

- sort 是应用在 list 上的方法，属于列表的成员方法，sorted 可以对所有可迭代的对象进行排序操作。  

- list 的 sort 方法返回的是对已经存在的列表进行操作，而内建函数 sorted 方法返回的是一个新的 list，而不是在原来的基础上进行的操作。  

- sort使用方法为ls.sort()，而`sorted`使用方法为`sorted(ls)`  
`sorted(list, key = lamda x: (x[0], -x[1])， reverse)`reverse = True倒序排列。

`sorted(list, key = lamda x: (x[0], -x[1]))` 以列表元素的第一个元素正序，第二个元素倒叙排列。



