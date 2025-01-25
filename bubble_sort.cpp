#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int* a,int n)
{
    int swapped=0;
 
    for(int i=0;i<n-1;i++)                //keep swaping adjacent elements untill a[j+1]>a[j]
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
            swapped=1;
        }
        if(swapped==0)                   //if no swap occurred in first iteration means array already sorted
        break;
    }
}

void initialise(int a[], int size)
{

    // Initialize the array with random values
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 1000 + 1;
    }
}

int main()
{
    ofstream outfile("sorting_time.csv");
    outfile<<"Array Size,Time\n";
    int arr[60000];
    int size=1000;
        while(size<=10000)
    {
        initialise(arr,size);
        clock_t start,end;
        start=clock();
        for(int j=0;j<=10;j++)
        {
            bubbleSort(arr,size);
        }
        end=clock();
        double duration=((double)(end - start))/10;
        pair<int ,double>store(size,duration);
        cout<<"("<<store.first<<","<<store.second<<") "<<endl;
        size+=1000;
        outfile<<size<<","<<duration<<"\n";
    }
    outfile.close();
}