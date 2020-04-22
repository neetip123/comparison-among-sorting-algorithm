int no;
  
  void Heapify(int a[], int n, int i) 
  {
	   int largest,left,right,temp; 
	  largest = i;
    	  left = 2 * i + 1;
   	  right = 2 * i + 2;
          no++;
    if (left < n && a[left] > a[largest])
      largest = left;
  	no++;
    if (right < n && a[right] > a[largest])
      largest = right;
	no++;
    if (largest != i) {
        
	temp=a[i]; 
	a[i]=a[largest];
	a[largest]=temp;
      Heapify(a, n, largest);
    }
  }
  int heapSort(int a[], int n) 
  {
	
	int temp;
    	 for (int i = n / 2 - 1; i >= 0; i--)
      	   Heapify(a, n, i);
         for (int i = n - 1; i >= 0; i--) 
	{
        	temp=a[0];
		a[0]=a[i];
	        a[i]=temp;
               Heapify(a, i, 0);
    	}
	return no;
  }
