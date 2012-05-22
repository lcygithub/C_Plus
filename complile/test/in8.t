{
	int i;
	int j;
	int sum;
	sum = 0;
	read i;
	read j;
	if(i>1)j=i;
	for(i=1;i<j;i=i+1)
	{
		sum = sum + i;
		write sum;
	}
}