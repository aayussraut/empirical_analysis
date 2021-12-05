#include<stdio.h>
#include<stdbool.h>
#include<time.h>

void insertionSort(int *arr,int n);


int main()
{
    int arr[1000],i=0,n=1000;
    double a,b,timetaken_insertionsort;  
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
    insertionSort(arr,n); //calls the function insertionSort
    b=clock(); //stops the timer
    timetaken_insertionsort=(b-a)/CLOCKS_PER_SEC; //calculates the time taken by the function
    printf("Sorted Array:\n");

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]); //prints the sorted array
    }
    printf("\nTime taken by insertionsort: %f\n",timetaken_insertionsort); //prints the time taken by the function
    

}

void insertionSort(int *arr,int n){
    int j,key;
    for(int i=1;i<n;i++)
    {
        key=arr[i]; //stores the value of the current element
        
        for(j=i-1;j>=0 && arr[j]>key;j--) //compares the current element with the previous elements
        {
            arr[j+1]=arr[j];//shifts the elements to the right
        }
        arr[j+1]=key; //inserts the current element
    } 

}

