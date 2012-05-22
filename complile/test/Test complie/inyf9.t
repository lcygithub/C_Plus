/* 
  文件inyf9.t计算两个正整数m和n的最大共因子。
  (1)输入两个正整数m和n(设m大于n);
  (2)计算m和n的余数r;
  (3)若r!=0,则m=n,n=r,返回第2步;
  (4)输出n即位最大共因子;
  (5)算法结束。

测试数据：
输入     输出
27 9      9
9 27      9
27 27    27
1  9      1
0  9     error
9  0     error
-1 -1    error
-1 9     error
*/  
{ 
int m;
int n;
int r;

n=0;
while(n!=1)
{
read m;
read n;
r=m%n;
while(r!=0)
{
m=n;
n=r;
r=m%n;
}
write n;
}
}
