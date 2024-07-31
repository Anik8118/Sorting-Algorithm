#include<iostream>
using namespace std;
void insertion(int arr[],int n)
{
    int j,i,x;
    for(i=1;i<n;i++)
    {
        x=arr[i];
        j=i-1;
        while(j>-1 && arr[j]>x)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
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
    int i,N,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertion(arr,n);
    printarray(arr,n);
}
