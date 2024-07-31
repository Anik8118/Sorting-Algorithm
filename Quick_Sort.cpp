
#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int lb,int ub){
    int pivot=arr[lb];
    int start=lb, end=ub;
    while(start<end){
        while(start<=ub && arr[start]<=pivot)
        {
            start++;
        }
        while(end>lb && arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[lb],arr[end]);
    return end;
}
void quicksort(int arr[],int lb,int ub){
    if(lb<ub){
        int loc=partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
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
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    printarray(arr,n);
    return 0;
}
