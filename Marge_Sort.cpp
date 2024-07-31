#include<bits/stdc++.h>
using namespace std;
void marge(int arr[],int l,int mid,int h)
{
    int i=0,j=0,k=l,n1,n2;
    n1=mid-l+1;
    n2=h-mid;
    int a[n1];
    int b[n2];//temp array
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        k++;
        j++;
    }

}
void margesort(int arr[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        margesort(arr,l,mid);
        margesort(arr,mid+1,h);
        marge(arr,l,mid,h);
    }
}
int main()
{
    int arr[100],n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    margesort(arr,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
