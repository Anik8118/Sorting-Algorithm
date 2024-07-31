#include<iostream>
using namespace std;
void selection(int A[],int n)
{
    int i,j,mini;
    for(i=0;i<n-1;i++)
    {
        mini=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[mini])
            {
                mini=j;
            }
        }
        swap(A[i],A[mini]);
    }
}
void printarray(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
int main()
{
    int i,n;
    cin>>n;
    int A[n];
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    selection(A,n);
    printarray(A,n);
}
