long long int bubbleSort(int a[],int n)
{

	int i,j,temp;
	long long int n1=0;
	for(i=0;i< n-1; i++)
	{
		for(j=0;j< n-1-i ;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			n1++;
		}
	}
   	return n1;
}
				
