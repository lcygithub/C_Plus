/* 
  文件inyf7.t测试dowhile
*/  
{ 
  int i;int sum;
  sum=0;
  i=1;
  do
  {
   sum=sum+i;
   i=i+1;
  }while(i<=10);
  write 10;
  write sum;
}

