#include<bits/stdc++.h>
using namespace std;
int partition(int* arr,int s,int e)
{
    int pivot=arr[s];
    int i=s,j=e;
    while(i<j)
    {
        while(arr[i]<=pivot)
        i++;
        while(arr[j]>pivot)
        j--;
        if(i<j)
        swap(arr[j],arr[i]);
    }
    swap(arr[j],arr[s]);
    return j;
}

void quicksort(int* arr,int s,int e)
{
    stack<pair<int,int>> st;
    st.push({s,e});
    while(!st.empty())
    {
        s=st.top().first;
        e=st.top().second;
        st.pop();
        if(s<e)
        {
            int p=partition(arr,s,e);
            st.push({s,p-1});
            st.push({p+1,e});
        }
    }
}

void print(int* arr,int size)
{
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
}

int main()
{
    int arr[5]={3,8,2,6,4};
    quicksort(arr,0,4);
    print(arr,5);
}