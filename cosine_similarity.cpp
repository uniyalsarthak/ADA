#include<bits/stdc++.h>
using namespace std;
float dot_product(vector<int> a,vector<int> b)
{
    float dp=0;
    for(int i=0;i<a.size();i++)
    {
        dp+=a[i]*b[i];
    }
    return dp;
}

float magnitude(vector<int> a)
{
    float sum=0;
    for(int i=0;i<a.size();i++)
    {
        sum+=a[i]*a[i];
    }
    return sqrt(sum);
}

int main()
{
    vector<int> a={2,4,1};
    vector<int> b={5,1,2};
    cout<<dot_product(a,b)<<" "<<magnitude(a)<<" "<<magnitude(b)<<endl;
    float cosine=dot_product(a,b)/(magnitude(a)*magnitude(b));
    cout<<cosine;
}