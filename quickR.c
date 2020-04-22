#include <time.h>
#include <stdlib.h>
long long int n3;
int partition2(int arr[], int low, int high)  
{  
    int temp;
    time_t t;
    srand((unsigned) time(&t));
    int random = low + rand() % (high - low); 
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
	n3++;
    }  
      	    temp=arr[i+1];  
            arr[i+1]=arr[high];
    	    arr[high]=temp; 
    return (i + 1);  
}  

long long int quickRSort(int arr[], int l, int h) 
{ 
    if (l < h) { 
  
        int p= partition2(arr, l, h ); 
        quickRSort(arr, l, p - 1); 
        quickRSort(arr, p + 1, h); 
    } 
    return n3;
} 

