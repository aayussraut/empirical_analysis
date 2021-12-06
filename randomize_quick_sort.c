#include<stdio.h>
#include<stdbool.h>
#include<time.h>


void quickSort(int *arr,int left,int right);
int partition(int *arr,int left,int right);
void swap(int *a,int *b);


int main()
{
    int arr[1000],i=0,n=1000;
    double a,b,timetaken_quicksort;  
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
    
    quickSort(arr,0,n-1); //calls the function quickSort
    
    b=clock(); //stops the timer
    timetaken_quicksort=(b-a)/CLOCKS_PER_SEC; //calculates the time taken by the function
    printf("Sorted Array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]); //prints the sorted array
    }
    printf("\nTime taken by quicksort: %f\n",timetaken_quicksort); //prints the time taken by the function
    

}

void quickSort(int *arr, int lowerBound, int upperBound)
{
    if (lowerBound < upperBound) //checks if the array is empty
    {
        int location = partition(arr, lowerBound, upperBound); 
        quickSort(arr, lowerBound, location - 1);
        quickSort(arr, location + 1, upperBound);
    }
}

int randomPortion(int lowerbound, int upperbound) //generates a random number for pivot
{
    srand(0);
    int random = lowerbound+ (rand() % (upperbound - lowerbound + 1));
    return random;
}

int partition(int *arr,int lowerbound,int upperbound){
    //pivot is the first element of the array
    int start=lowerbound;
    int end=upperbound;
    int pivotPosition=randomPortion(lowerbound,upperbound);
    int pivot=arr[pivotPosition];
    while(start<end){//loop while start is less than end
        while(arr[start]<=pivot && (start<end)){ //loop while the element at start is less than the pivot
            start++;
        }
        while(arr[end]>pivot ){//loop while the element at end is greater than the pivot
            end--;
        }
        if(start<end){ //checks if start is less than end ,if yes then swap the elements
            swap(&arr[start],&arr[end]);
        }
        
    }
    swap(&arr[pivotPosition],&arr[end]); //swap the pivot with the element at end
    return end;
}
void swap(int *a,int *b){ //swaps the elements
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}