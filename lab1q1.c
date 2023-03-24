#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int l1,l2,i,j,flag=1,pass,temp,size;
	int *arr1, *arr2, merged[l1+l2];
	
	printf("Enter length of first array: ");
	scanf(" %d",&l1);
	
	arr1 = (int*) calloc(l1, sizeof(int));
	
	printf("\nEnter %d numbers: ",l1);
	for(i=0;i<l1;i++)
		scanf(" %d",&arr1[i]);
		
	printf("\nEnter length of second array: ");
	scanf(" %d",&l2);
	
	arr2 = (int*) calloc(l2, sizeof(int));
	
	printf("\nEnter %d numbers: ",l2);
	for(i=0;i<l2;i++)
		scanf(" %d",&arr2[i]);
	//merged
	for(i=0;i<l1;i++)
		merged[i]= arr1[i];
	for(j=0;j<l2;j++)
	{
		merged[i] = arr2[j];
		i++;
	}
	//Sorting merged array
	size= l1+l2;
	for(pass=0;pass<size && flag==1; pass++)
	{
	flag=0;
		for(i=0;i<size-1-pass;i++)
		{
			if(merged[i]>merged[i+1])
			{
				temp = merged[i];
                merged[i] = merged[i+1];
                merged[i+1] = temp;
                flag=1;
			}
		}			
	}	
	printf("\nMerged array is : ");
	for(i=0;i<size;i++)
	{
		printf("%d ",merged[i]);
	}
	free(arr1);
	free(arr2);	
	return(0);
}
