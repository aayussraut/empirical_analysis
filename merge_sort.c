#include<stdio.h>
#include<stdbool.h>
#include<time.h>


void mergeSort(int *arr, int left, int right);
void merge(int *arr, int left, int mid, int right);


int main()
{
    int arr[1000],i=0,n=1000;
    double a,b,timetaken_mergesort;  
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
    mergeSort(arr,0,n-1); //calls the function mergeSort
    b=clock(); //stops the timer
    timetaken_mergesort=(b-a)/CLOCKS_PER_SEC; //calculates the time taken by the function
    printf("Sorted Array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]); //prints the sorted array
    }
    printf("\nTime taken by mergesort: %f\n",timetaken_mergesort); //prints the time taken by the function
    

}



void mergeSort(int *arr,int left,int right){
    int m;
    if(left<right){
        m=(left+right)/2; //finds the middle of the array
        mergeSort(arr,left,m); //calls the function mergeSort
        mergeSort(arr,m+1,right);
        merge(arr,left,m,right); //calls the function merge
    }
}

void merge(int *arr,int left,int mid,int right){
    int B[right-left+1]; 
    int i=left,j=mid+1,k=0;

    while(i<=mid && j<=right)//appends the smaller element of the two arrays to the new array(B)
    B[k++]=arr[i]<=arr[j]?arr[i++]:arr[j++];

    while(i<=mid)//appends the remaining elements of the first array to the new array(B)
    B[k++]=arr[i++];

    while(j<=right)//appends the remaining elements of the second array to the new array(B)
    B[k++]=arr[j++];

    for(i=left;i<=right;i++)//copies the elements of the new array(B) to the original array(A)
    arr[i]=B[i-left];
}