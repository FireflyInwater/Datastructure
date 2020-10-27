//字符串：：序列
//Pattern Matching : 子串去匹配字符串，得到第一次出现的位置

//朴素算法： 每次失配，S串的索引i定位的本次尝试匹配的第一个字符的后一个。P串的索引j定位到1；T(n)=O(n*m)

//KMP算法： 每次失配，S串的索引i不动，P串的索引j定位到某个数。T(n)=O(n+m)，时间效率明显提高

#include<iostream>
#include<string>
#include<vector>
//vector<type> array;