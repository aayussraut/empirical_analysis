#include<stdio.h>
#include<stdbool.h>
#include<time.h>


void bubbleSort(int *arr,int n);
void selectionSort(int *arr,int n);
void insertionSort(int *arr,int n);

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

    for(int i=0;i<3;i++)
    {
        
         double a,b,c,timetaken_bubblesort,timetaken_insertionsort,timetaken_selectionsort;
        
        
            a=clock();
            bubble_sort(arr,n);
            b=clock();
            selection_sort(arr,n);
            c=clock();
            timetaken_bubblesort=(b-a)/CLOCKS_PER_SEC;
            timetaken_selectionsort=(c-b)/CLOCKS_PER_SEC;
            printf("%f\n",timetaken_bubblesort);
            printf("%f\n",timetaken_selectionsort);
           // insertion_sort(a,n);
        n=n*10;
    }

}

bubble_sort(int *arr,int n)
{
     int switched=true,temp;

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

selection_sort(int *arr,int n)
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


void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}



            
        