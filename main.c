#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "myheader.h"
long long int count;
int main(int argc ,char* argv[])
{
	int i,j,a,avg=1,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,flag6=0;
	long long int step_size=10000,min_size=50000,max_size=100000,s;
	char pattern[7][10];
	char output[20],myplot[20];
	FILE *fp2,*fp3,*fp4,*fp5,*fp6,*fp7,*fp8,*fp9;
	for(i=1;i<argc;i++)
	{
		if(strcmp(argv[i],"-i")==0)
			min_size =atol(argv[i+1]);
		else if (strcmp(argv[i],"-x")==0)
			max_size =atol(argv[i+1]);
		else if (strcmp(argv[i],"-s")==0)
			step_size =atoi(argv[i+1]);
		else if (strcmp(argv[i],"-a")==0)
			avg =atoi(argv[i+1]);
		else if (strcmp(argv[i],"-o")==0)
			{
				strcpy(output,argv[i+1]);
				fp2 =fopen(output,"a+");
			}
		else if (strcmp(argv[i],"-g")==0)
			strcpy(myplot , argv[i+1]);
		else if (strcmp(argv[i], "-t")==0)
		{
			j=0;
			i=i+2;
			
			while(strcmp(argv[i], "]")!=0)
			{
			
				strcpy(pattern[j],argv[i]);
				i++;
				j++;
			}
			
			
			
		}
	}

	count =min_size;
	
	while(count<=max_size)
	{
		long long int total1=0,total2=0,total3=0,total4=0,total5=0,total6=0;
		double ti1,ti2,ti3,ti4,ti5,ti6;
		double avg_time1,avg_time2,avg_time3,avg_time4,avg_time5,avg_time6;
		long long int avg1,avg2,avg3,avg4,avg5,avg6;
		FILE *fp1;
		a = avg ;
		while(a>0)
		{
			int arr[count];
			int k=0;
			char r1[]="shuf -i 1-500000 -n";
			char r2[100];
			sprintf(r2,"%Ld",count);
			strcat(r1,r2);
			strcat(r1,"> a.txt");
			system(r1);
			fp1 =fopen("a.txt","r");
			if(fp1!=NULL)
			{
				while(fscanf(fp1,"%d\n",&arr[k])!=EOF)
				k++;
			}
			fclose(fp1);
			
		
	
			for(i=0;i<6;i++)
			{
				
				if(strcmp(pattern[i],"bubble")==0)
				{	flag1=1;
					clock_t start,end;
					start=clock();
					total1+= bubbleSort(arr,count);
					end =clock();
					ti1+= ((double)(end-start))/CLOCKS_PER_SEC;
				}
				else if(strcmp(pattern[i],"merge")==0)
				{
					flag2=1;
					clock_t start,end;
					start=clock();
					total2+=mergeSort(arr,0,count-1);
					end =clock();
					ti2+= ((double)(end-start))/CLOCKS_PER_SEC;
				}
				else if(strcmp(pattern[i],"quickR")==0)
				{
					flag3=1;
					clock_t start,end;
					start=clock();
					total3+=quickRSort(arr,0,count-1);
					end =clock();
					ti3+= ((double)(end-start))/CLOCKS_PER_SEC;
				}
				else if(strcmp(pattern[i],"quickM")==0)
				{
					flag4=1;
					clock_t start,end;
					start=clock();
					total4+=quickMSort(arr,0,count-1);
					end =clock();
					ti4+=((double)(end-start))/CLOCKS_PER_SEC;
				}
				else if(strcmp(pattern[i],"quick3M")==0)
				{
					flag5=1;
					clock_t start,end;
					start=clock();
					total5+=quick3MSort(arr,0,count-1);
					end =clock();
					ti5+= ((double)(end-start))/CLOCKS_PER_SEC;
				}
				else if(strcmp(pattern[i],"heap")==0)
				{
					flag6=1;
					clock_t start,end;
					start=clock();
					total6+=heapSort(arr,count);
					end =clock();
					ti6+= ((double)(end-start))/CLOCKS_PER_SEC;
				}
			}
			a--;
		 }
			if(fp2!=NULL)
			fprintf(fp2,"INPUT SIZE %Ld\n",count);
			if(flag1==1)
			{
				
				fp3=fopen("bubble.dat","a+");
				avg1=total1/avg;
				avg_time1 =ti1/avg;
				if(fp2!=NULL)
				{
					fprintf(fp2,"Bubble Sort\n");
					fprintf(fp2,"No_of_comparisons :\t%Ld\n",avg1);
					fprintf(fp2,"Running Time :\t %.2lf\n",avg_time1);
					
					
				}
				if(fp3 !=NULL)
				fprintf(fp3,"%Ld\t%Ld\t%.2lf\n",count,avg1,avg_time1);
				fclose(fp3);
			}
			if(flag2==1)
			{
				fp4=fopen("merge.dat","a+");
				avg2=total2/avg;
				avg_time2 =ti2/avg;
			
				if(fp2!=NULL)
				{
					fprintf(fp2,"Merge Sort\n");
					fprintf(fp2,"No_of_comparisons :\t%Ld\n",avg2);
					fprintf(fp2,"Running Time :\t %.2lf\n",avg_time2);
				}
				if(fp4 !=NULL)
				fprintf(fp4,"%Ld\t%Ld\t%.2lf\n",count,avg2,avg_time2);
				fclose(fp4);
			}
			if(flag3==1)
			{
				fp5=fopen("quickr.dat","a+");
				avg3=total3/avg;
				avg_time3 =ti3/avg;
				if(fp2!=NULL)
				{
					fprintf(fp2,"Quick Random Sort\n");
					fprintf(fp2,"No_of_comparisons :\t%Ld\n",avg3);
					fprintf(fp2,"Running Time :\t %.2lf\n",avg_time3);
				}
				if(fp5 !=NULL)
				fprintf(fp5,"%Ld\t%Ld\t%.2lf\n",count,avg3,avg_time3);
				fclose(fp5);
			}
			if(flag4==1)
			{
				fp6=fopen("quickM.dat","a+");
				avg4=total4/avg;
				avg_time4 =ti4/avg;
				if(fp2!=NULL)
				{
					fprintf(fp2,"Quick Median Sort\n");
					fprintf(fp2,"No_of_comparisons :\t%Ld\n",avg4);
					fprintf(fp2,"Running Time :\t %.2lf\n",avg_time4);
					
				}
				if(fp6 !=NULL)
				fprintf(fp6,"%Ld\t%Ld\t%.2lf\n",count,avg4,avg_time4);
				fclose(fp6);
			}
			
			if(flag5==1)
			{
				fp7=fopen("quick3M.dat","a+");
				avg5=total5/avg;
				avg_time5 =ti5/avg;
				if(fp2!=NULL)
				{
					fprintf(fp2,"Quick 3 Median Sort\n");
					fprintf(fp2,"No_of_comparisons :\t%Ld\n",avg5);
					fprintf(fp2,"Running Time :\t %.2lf\n",avg_time5);
					
				}
				if(fp7 !=NULL)
				fprintf(fp7,"%Ld\t%Ld\t%.2lf\n",count,avg5,avg_time5);
				fclose(fp7);
			}
			if(flag6==1)
			{
				fp8=fopen("heap.dat","a+");
				avg6=total6/avg;
				avg_time6 =ti6/avg;
				if(fp2!=NULL)
				{
					fprintf(fp2,"Heap Sort\n");
					fprintf(fp2,"No_of_comparisons :\t%Ld\n",avg6);
					fprintf(fp2,"Running Time :\t %.2lf\n",avg_time6);
					
				}
				if(fp8 !=NULL)
				fprintf(fp8,"%Ld\t%Ld\t%.2lf\n",count,avg6,avg_time6);
				fclose(fp8);
			}
		count=count + step_size;
		
	}

	fclose(fp2);	
	fp9=fopen(myplot,"a+");
	fprintf(fp9,"set terminal png\n");
	fprintf(fp9,"set output 'comparison.png'\n");
	fprintf(fp9,"set title \"SORTING NUMBER OF COMPARISONS\"\n");
	fprintf(fp9,"set xlabel \"Input size\"\n");
	fprintf(fp9,"set ylabel \"No Of Comparisons\"\n");
	fprintf(fp9,"set autoscale\n");
	fprintf(fp9,"set key reverse left outside\n");
	fprintf(fp9,"set grid\n");
	fprintf(fp9,"plot ");
	if(flag1==1)
	{
		fprintf(fp9,"\"bubble.dat\" using 1:2 title \"Bubble_sort\" with linespoints,\ ");
	}
	if(flag2==1)
	{
		fprintf(fp9,"\"merge.dat\" using 1:2 title \"Merge_sort\" with linespoints,\ ");
	}
	if(flag3==1)
	{
		fprintf(fp9,"\"quickr.dat\" using 1:2 title \"QuickR_sort\" with linespoints,\ ");

	}
	if(flag4==1)
	{
		fprintf(fp9,"\"quickM.dat\" using 1:2 title  \"QuickM_sort\" with linespoints,\ ");
	}
	if(flag5==1)
	{
		fprintf(fp9,"\"quick3M.dat\" using 1:2 title \"Quick3M_sort\" with linespoints,\ ");
	}
	if(flag6==1)
	{
		fprintf(fp9,"\"heap.dat\" using 1:2 title \"Heap_sort\" with linespoints,\ ");
	}
	fprintf(fp9,"\n\nset terminal png\n");
	fprintf(fp9,"set output 'exe_time.png'\n");
	fprintf(fp9,"set title \"SORTING EXECUTION TIME \"\n");
	fprintf(fp9,"set xlabel \"Input size\"\n");
	fprintf(fp9,"set ylabel \"execution time\"\n");
	fprintf(fp9,"set autoscale\n");
	fprintf(fp9,"set key reverse left outside\n");
	fprintf(fp9,"set grid\n");
	fprintf(fp9,"plot ");
	if(flag1==1)
	{
		fprintf(fp9,"\"bubble.dat\" using 1:3 title \"Bubble_sort\" with linespoints,\ ");
	}
	if(flag2==1)
	{
		fprintf(fp9,"\"merge.dat\" using 1:3 title \"Merge_sort\" with linespoints,\ ");
	}
	if(flag3==1)
	{
		fprintf(fp9,"\"quickr.dat\" using 1:3 title \"QuickR_sort\" with linespoints,\ ");

	}
	if(flag4==1)
	{
		fprintf(fp9,"\"quickM.dat\" using 1:3 title  \"QuickM_sort\" with linespoints,\ ");
	}
	if(flag5==1)
	{
		fprintf(fp9,"\"quick3M.dat\" using 1:3 title \"Quick3M_sort\" with linespoints,\ ");
	}
	if(flag6==1)
	{
		fprintf(fp9,"\"heap.dat\" using 1:3 title \"Heap_sort\" with linespoints,\ ");
	}


	fclose(fp9);
	 
	
return 0;
}
