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