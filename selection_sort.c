#include<stdio.h>
#include<stdbool.h>
#include<time.h>

void selectionSort(int *arr,int n);
void swap(int *a,int *b);

int main()
{
    int arr[1000],i=0,n=1000;
    double a,b,timetaken_selectionsort;  
    FILE *fp; //creating a file pointer
    printf("1. Sorted Items\n2. Random Items\n");

    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
     case 1:
        {
            fp=fopen("sorted_data.txt","r"); //opens the file with sorted data
            break;
        }
    case 2:
        {
            fp=fopen("unsorted_data.txt","r"); //opens the file with unsorted data
            break;
        }
    default:
        {
            printf("Invalid Choice");
            return 0;
        }
    }


    if(fp==NULL) //checks if the file is empty
    {
        printf("File not found");
        return 1;
    }

    while (fscanf(fp,"%d",&arr[i])==1) //reads the file and stores the data in the array
    {
        i++;
    }
      
  
    a=clock(); //starts the timer
    selectionSort(arr,n); //calls the function selectionSort
    b=clock(); //stops the timer
    timetaken_selectionsort=(b-a)/CLOCKS_PER_SEC; //calculates the time taken by the function
    printf("Sorted Array:\n");

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]); //prints the sorted array
    }
    printf("\nTime taken by selectionsort: %f\n",timetaken_selectionsort); //prints the time taken by the function
    

}



void selectionSort(int *arr,int n)
{
    int imin,i,j,temp; //declaring the variables
    for(i=0;i<n-1;i++)
    {
        imin=i; //initialising the minimum index
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[imin]) //checks if the element at the current index is less that the element at the minimum index.
            {
                imin=j; //if yes, then the minmum index is updated
            }
            swap(&arr[imin],&arr[i]); //swaps the elements at the minimum index and the current index
        }   
    }
}

void swap(int *a,int *b) //swaps the elements at the two pointers
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

            
        