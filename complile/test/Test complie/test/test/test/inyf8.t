/* 
  文件inyf8.t测试read\write\for
*/  
{ 
  int i;
  int j;
int sum;
sum=0;
  read i;
  read j;
  if(i>j) j=i;
  for(i=1;i<j;i=i+1) 
{ 
sum=sum+i;
  write sum;
}
}

