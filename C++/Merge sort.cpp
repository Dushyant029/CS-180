#include<iostream>
using namespace std;
void merge(int *,int, int , int );
void mergesort(int *a,int low, int high){
    int mid;
    if(low<high){
       mid= (low + high)/2;
       mergesort(a,low,mid);
       mergesort(a,mid+1,high);
       //merge the sorted arrays
       merge(a,low,high,mid);
     }
    
}

void merge(int *arr, int low, int high, int mid)
{
   int i, j, k, c[50];
   i = low;
   k = low;
   j = mid + 1;
   while (i <= mid && j <= high) {
   if (arr[i] < arr[j]) {
   c[k] = arr[i];
   k++;
   i++;
}
else {
   c[k] = arr[j];
   k++;
   j++;
   }
}
  
while (i <= mid) {
   c[k] = arr[i];
   k++;
   i++;
}
while (j <= high) {
   c[k] = arr[j];
   k++;
   j++;
}
for (i = low; i < k; i++) {
   arr[i] = c[i];
}
}
int main()
{
    int a[12]={21,11,10,30,4,7,9,20,18,1,15,8};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<"Initial array is\n";
    for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
    cout<<endl;
    mergesort(a,0,n-1);
    cout<<"Sorted array is\n";
    for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
}
