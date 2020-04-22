long long int n2;
int merge(int arr[],int l,int m,int r) 
{ 
    	 
    int i, j,k,b[r-l+1]; 
    i=l;
    k=0;
    j=m +1;		
    while (i<=m && j<=r) 
    { 
        if (arr[i] <=arr[j]) 
        { 
            b[k++]=arr[i++];
	}
	else
        { 
            b[k++] = arr[j++]; 
            
	    
        } 
	n2++;
         
    } 
    while (i<=m) 
    { 
        b[k++] = arr[i++]; 
         
       
    } 
    while (j<=r) 
    { 
        b[k++] = arr[j++]; 
       
    } 
	
	for(i=l,j=0;i<=r;i++,j++)
	{
		arr[i] =b[j];
	}
	
	return n2;
}

long long int mergeSort(int arr[],int l,int h) 
{ 
	int mid;
    if (l < h) 
    { 
        mid = l+(h-l)/2; 
        mergeSort(arr,l,mid); 
        mergeSort(arr,mid+1,h); 
  	merge(arr,l,mid,h); 
    } 
	
    return n2;
} 

