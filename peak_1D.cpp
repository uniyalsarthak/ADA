#include<bits/stdc++.h>
using namespace std;
int peak_element(int* a,int s,int e)
{
    while(s<e)
    {
        int mid=(s+e)/2;
        if(a[mid+1]<a[mid])
        e=mid;
        else
        s=mid+1;
    }
    return s;
}

int main()
{
    int arr[5]={30,25,20,15,10};
    int x=peak_element(arr,0,4);
    cout<<x;

}