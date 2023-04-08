#include<bits/stdc++.h>
using namespace std;
//void swapping(int &a, int &b)
//{
//   int temp;
//   temp = a;
//   a = b;
//   b = temp;
//}
void merge(int *array, int l, int m, int r) {
   int i, j, k, left, right;
   left = m-l+1;
   right = r-m;

   int leftarr[left], rightarr[right];

   for(i = 0; i<left; i++)
   {
       leftarr[i] = array[l+i];
   }

   for(j = 0; j<right; j++)
   {
       rightarr[j] = array[m+1+j];
   }

   i = 0; j = 0; k = l;
   while(i < left && j < right)
   {
      if(leftarr[i] <= rightarr[j])
      {
         array[k] = leftarr[i];
         i++;
      }
      else
      {
         array[k] = rightarr[j];
         j++;
      }
      k++;
   }
   while(i<left)
   {
      array[k] = leftarr[i];
      i++;
      k++;
   }
   while(j<right)
   {
      array[k] = rightarr[j];
      j++;
      k++;
   }
}
void mergeSort(int *array, int l, int r)
{
   int mid;
   if(l < r)
   {
      int mid = l+(r-l)/2;
      mergeSort(array, l, mid);
      mergeSort(array, mid+1, r);
      merge(array, l, mid, r);
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   mergeSort(arr, 0, n-1);
   for(int i = 0; i<n; i++) {
      cout<< arr[i]<<" ";
   }
   cout<<endl;
}
