#include<bits/stdc++.h>
using namespace std;
void selectionSort(int* arr,int n)
{
    for(int i=0;i<n-1;i++)           //check if there is any element greater than a[i]
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            min=j;
        }
        swap(arr[min],arr[i]);
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
            selectionSort(arr,size);
        }
        end=clock();
        double duration=(((double) (end - start)) / CLOCKS_PER_SEC)/10;
        pair<int ,double>store(size,duration);
        cout<<"("<<store.first<<","<<store.second<<") "<<endl;
        size+=1000;
        outfile<<size<<","<<duration<<"\n";
    }
    outfile.close();
}