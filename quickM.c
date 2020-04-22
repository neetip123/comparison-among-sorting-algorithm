int partition(int *a, int l, int r, int k); 
long long int n4;
int Median(int a[],int *start, int n) 
{ 
    int i;
	int s=start -a;
	int e= s+n-1;
	for(i=s+1;i<=e;i++)
	{
		int key = a[i];
		int j=i-1;
		n4++;
		while(j>=s && a[j]>key)
		{
				
				a[j+1]=a[j];
				j--;
		}
		a[j+1] =key;
	}		
    return a[n/2]; 

} 

int kth_smallest(int a[],int l,int r, int k) 
{ 
  	int n,i,med,pos;
	n = r-l+1;
	 int median[(n+4)/5];
    if (k > 0 && k <=n) 
    { 
         
  	 for (i=0; i<n/5; i++) 
            median[i] = Median(a,a+l+i*5,5); 
        if (i*5 < n) 
        { 
            median[i] = Median(a,a+l+i*5,n%5); 
            i++; 
        } 
  
       if(i == 1)
	med=median[i-1];
	else
	kth_smallest(median, 0, i-1,i/2);
  
        pos = partition(a,l, r,med);  
        if (pos-l == k-1) 
	 return a[pos]; 
        if (pos-l > k-1)
            return kth_smallest(a, l, pos-1, k); 
        
	return kth_smallest(a, pos+1, r, k-(pos-l+1)); 
    } 
	return -1; 

} 

int partition(int *arr, int l, int r,int x) 
{ 
 
    int i,temp; 
    for (i=l; i<r; i++) 
    {
	  n4++;
	  if (arr[i] == x) 
           break; 
     }
    temp=arr[i];
    arr[i]=arr[r];
    arr[r]=temp;  
    i = l-1; 
    for (int j =l; j<= r-1; j++) 
    { 
	n4++;
        if (arr[j] <= x) 
        { 
		i++;
            temp=arr[i];
	    arr[i]=arr[j];
	    arr[j]=temp; 
            
        } 
    } 
    temp=arr[i+1];
    arr[i+1]=arr[r]; 
    arr[r]=temp;
    return (i+1); 
} 

long long int quickMSort(int arr[],int l,int r) 
{ 
    if (l < r) 
    {  
        int n = r-l+1; 
        int m = kth_smallest(arr,l,r,n/2); 
	if(m==-1)
	return 0; 
        int pi = partition(arr, l,r,m);  
        quickMSort(arr,l, pi - 1); 
        quickMSort(arr, pi + 1, r); 
    }
	return n4; 
} 

