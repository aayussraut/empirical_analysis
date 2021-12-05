#include<stdio.h>
#include<stdbool.h>
#include<time.h>

void bubbleSort(int *arr,int n);
void selectionSort(int *arr,int n);
void insertionSort(int *arr,int n);
void swap(int *a,int *b);


int main()
{
    int arr[1000],i=0,n=10;;
    FILE *fp;
    printf("1. Sorted Items\n2. Random Items\n");
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
     case 1:
        {
            fp=fopen("sorted_data.txt","r");
            break;
        }
    case 2:
        {
            fp=fopen("unsorted_data.txt","r");
            break;
        }
    default:
        {
            printf("Invalid Choice");
            return 0;
        }
    }


    if(fp==NULL)
    {
        printf("File not found");
        return 1;
    }

    while (fscanf(fp,"%d",&arr[i])==1)
    {
       i++;
    }

    printf("\tn\t\tBubble_Sort\t\tSelection_Sort\t\tInsertion_Sort\n");
    for(int i=0;i<3;i++)
    {
        
         double a,b,c,d,timetaken_bubblesort,timetaken_insertionsort,timetaken_selectionsort;
        
        
            a=clock();
            bubbleSort(arr,n);
            b=clock();
            selectionSort(arr,n);
            c=clock();
            insertionSort(arr,n);
            d=clock();
            timetaken_bubblesort=(b-a)/CLOCKS_PER_SEC;
            timetaken_selectionsort=(c-b)/CLOCKS_PER_SEC;
            timetaken_insertionsort=(d-c)/CLOCKS_PER_SEC;
             printf("\t%d\t\t %f\t\t %f\t\t %f\n",n,timetaken_bubblesort,timetaken_selectionsort,timetaken_insertionsort);
          
        n=n*10;
    }

}

void bubbleSort(int *arr,int n)
{
     int switched=true;

    for(int pass=0;pass<n-1 &&switched;pass++)
    {
        switched=false;

        for(int i=0;i<n-1;i++)
        {
           //  printf("%d\n",arr[i]);
            if(arr[i]>arr[i+1])
            {
                switched=true;
                swap(&arr[i],&arr[i+1]);
            }
        }
    }
}

void selectionSort(int *arr,int n)
{
    int least,jMin;
    for(int i=0;i<n;i++)
    {
        least=arr[i];
        jMin=i;

        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<least)
            {
                least=arr[j];
                jMin=j;
            }
        }
        arr[jMin]=arr[i];
        arr[i]=least;
    }
}

void insertionSort(int *arr,int n){
    int j,key;
    for(int i=1;i<n;i++)
    {
        key=arr[i];
        
        for(j=i-1;j>=0 && arr[j]>key;j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    } 

    // for(int i=0;i<n;i++)
    // {
    //     printf("%d\n",arr[i]);
    // }
}


void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}



            
        