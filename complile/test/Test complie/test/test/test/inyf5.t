/* 
  文件inyf5.t测试if整数越界
*/  
{ 
  int a;
int b;
  a=123;
read a;
  if(a>100)a=a*a*a*a;
    else { a=a/10; b=a/100;write b; }
  write a;
  
}

