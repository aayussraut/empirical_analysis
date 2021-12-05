#include<stdio.h>
#include<stdbool.h>
#include<time.h>

void bubbleSort(int *arr,int n);
void swap(int *a,int *b);


int main()
{
    int arr[1000],i=0,n=10;
    double a,b,timetaken_bubblesort;  
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
    bubbleSort(arr,n); //calls the function bubbleSort
    b=clock(); //stops the timer
    timetaken_bubblesort=(b-a)/CLOCKS_PER_SEC; //calculates the time taken by the function
    printf("Sorted Array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]); //prints the sorted array
    }
    printf("\nTime taken by bubblesort: %f\n",timetaken_bubblesort); //prints the time taken by the function
    

}

void bubbleSort(int *arr,int n) //adaptive bubble sort function
{
     int switched=true;//checks if any items are switched in array

    for(int pass=0;pass<n-1 &&switched;pass++) //loops until all items are sorted or until no items are switched
    {
        switched=false;

        for(int i=0;i<n-1;i++) 
        {
           //  printf("%d\n",arr[i]);
            if(arr[i]>arr[i+1]) //checks if the item at index i is greater than the item at index i+1
            {
                switched=true; //states that items are switched
                swap(&arr[i],&arr[i+1]); //swaps the items
            }
        }
    }
}

void swap(int *a,int *b) //swap function
{
    int temp=*a;
    *a=*b;
    *b=temp;
}



            
        