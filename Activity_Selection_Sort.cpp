#include<bits/stdc++.h>
using namespace std;
void selection(int f[],int s[],int n)
{
    int i,j,min;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(f[j]<f[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            swap(f[min],f[i]);
            swap(s[min],s[i]);
        }
    }
}
void activity(int f[],int s[],int n)
{
    int i,j;
    i=0;
    cout<<i<<" ";
    for(j=1;j<n;j++)
    {
        if(s[j]>=f[i])
        {
            cout<<j<<" ";
            i=j;
        }
    }
}
void printarray(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int f[100],s[100],n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>f[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>f[i];
    }
    selection(f,s,n);
    activity(f,s,n);
    //printarray(t,n);
}
