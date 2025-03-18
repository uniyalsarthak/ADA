#include<bits/stdc++.h>
using namespace std;
int partition(int* a,int s,int e)
{
    int pivot=a[s];
    int i=s,j=e;
    while(i<=j)
    {
        while(a[i]<=pivot)
        i++;
        while(a[j]>pivot)
        j--;
        if(i<j)
        swap(a[i],a[j]);
    }
    swap(a[j],a[s]);
    return j;
}

void quickSort(int* a,int s,int e)
{
    if(s>=e)
    return;
    int p=partition(a,s,e); 
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}

void print(int* arr,int n)
{
    cout<<"Sorted array:";
    for(int k=0;k<n;k++)
    {
        cout<<arr[k]<<" ";
    }
}

void initialise_for_decreasing(int a[], int size)
{
    srand(time(0));
    // Initialize the array with random values
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 1000 + 1;
    }
    sort(a, a + size,greater<int>());

}

void initialise_for_increasing(int a[], int size)
{
    srand(time(0));
    // Initialize the array with random values
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 1000 + 1;
    }
    sort(a, a + size);

}

int main()
{
    ofstream outfile("sorting_time.csv");
    outfile<<"Array Size,Time\n";
    int arr[60000];
    int size=1000;
        while(size<=12000)
    {
        clock_t start,end;
        start=clock();
        //cout<<"start:"<<start<<endl;
        for(int j=0;j<=5;j++)
        {
            initialise_for_increasing(arr,size);
            quickSort(arr,0,size-1);
        }

        for(int j=0;j<=5;j++)
        {
            initialise_for_decreasing(arr,size);
            quickSort(arr,0,size-1);
        }
        end=clock();
        //cout<<"end:"<<end<<endl;
        double duration=(((double) (end - start)))/10;
        //cout<<"duration:"<<duration<<endl;
        pair<int ,double>store(size,duration);
        cout<<"("<<store.first<<","<<store.second<<") "<<endl;
        size+=1000;
        outfile<<size<<","<<duration<<"\n";
    }
    outfile.close();
}