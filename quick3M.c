#include <time.h>
#include <stdlib.h>
long long int n5;
int randoms(int arr[] ,int low ,int high)
{
	time_t t;
    srand((unsigned) time(&t));
    int random = low + rand() % (high - low); 
	return random;
}
int partition3(int arr[], int low, int high)  
{  
    int temp,random;
    int r1=randoms(arr,low,high);
    int r2=randoms(arr,low,high);
    int r3=randoms(arr,low,high);
	n5++;
	if(arr[r1] <= arr[r2])
	{
		n5++;
		if(arr[r1]>=arr[r3])
		random =r1;
		else if(arr[r3]<=arr[r2])
		{
		 random =r3;
		  n5++;
	       }
	}
	else
	{
		n5++;
		if(arr[r2]>=arr[r3])
		random=r2;
		else if(arr[r3]<=arr[r1])
		{
			n5++;
			random=r3;
		}
	}
    temp=arr[random];
    arr[random]=arr[high];
    arr[high]=temp;
    int pivot = arr[high]; 
    int i = (low - 1);   
  
    for (int j = low; j <= high - 1; j++)  
    {    
        if (arr[j] < pivot)  
        {  
            i++;
	    temp=arr[i];  
            arr[i]=arr[j];
    	    arr[j]=temp;  
        }  
	n5++;
    }  
      	    temp=arr[i+1];  
            arr[i+1]=arr[high];
    	    arr[high]=temp; 
    return (i + 1);  
}  

long long int quick3MSort(int arr[], int l, int h) 
{ 
    if (l < h) { 
  
        int p= partition3(arr, l, h ); 
        quick3MSort(arr, l, p - 1); 
        quick3MSort(arr, p + 1, h); 
    } 
    return n5;
} 

