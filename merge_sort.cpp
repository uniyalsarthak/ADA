#include<bits/stdc++.h>
using namespace std;
void merge(int* arr,int s,int mid,int e)
{
    int len1=mid-s+1;
    int len2=e-mid;
    int* arr1=new int[len1];
    int* arr2=new int[len2];
    for(int i=0;i<len1;i++)
    {
        arr1[i]=arr[s+i];
    }
    for(int j=0;j<len2;j++)
    {
        arr2[j]=arr[mid+1+j];
    }
    int i=0,j=0;
    int k=s;
    while(i<len1 && j<len2)
    {
        if(arr1[i]<arr2[j])
        arr[k++]=arr1[i++];
        else
        arr[k++]=arr2[j++];
    }
    while(i<len1)
    arr[k++]=arr1[i++];
    while(j<len2)
    arr[k++]=arr2[j++];
}
 void mergesort(int* arr,int s,int e)
{
    if(s>=e)
    return;
    int mid=s+ (e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,mid,e);
}

void initialise(int a[], int size)
{
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
        while(size<=20000)
    {
        initialise(arr,size);
        clock_t start,end;
        start=clock();
        for(int j=0;j<=100;j++)
        {
            mergesort(arr,0,size-1);
        }
        end=clock();
        //cout<<"end:"<<end<<endl;
        double duration=(((double) (end - start)))/100;
        pair<int ,double>store(size,duration);
        cout<<"("<<store.first<<","<<store.second<<") "<<endl;
        size+=1000;
        outfile<<size<<","<<duration<<"\n";
    }
    outfile.close();
}
