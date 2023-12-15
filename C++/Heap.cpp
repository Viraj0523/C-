#include <iostream>
using namespace std;
void heap(int a[], int n, int i) 
{
    int largest = i;
    int left = 2 * i + 1; 
    int right = 2 * i + 2;
    
    if (left < n && a[left] > a[largest]) 
        largest = left;
    
    if (right < n && a[right] > a[largest]) 
        largest = right;
    
    if (largest != i) 
    {
        int temp = a[i]; 
        a[i] = a[largest]; 
        a[largest] = temp;
        heap(a, n, largest);
    } 
}

void heapSort(int a[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--) 
        heap(a, n, i);

    for (int i = n - 1; i >= 0; i--) 
    { 
        int temp = a[0];
        a[0] = a[i]; 
        a[i] = temp;
        heap(a, i, 0); 
    }
}


void printArr(int arr[], int n) 
{
for (int i = 0; i < n; ++i) 
    {
        cout<<arr[i];
        cout<<" "; 
    }
}



int main() {
    int a[] = {48, 10, 23, 43, 28, 26, 1};
    int n = sizeof(a) / sizeof(a[0]);
    cout<<"Before sorting array elements are - \n"; 
    printArr(a, n);
    heapSort(a, n);

    cout<<"\nAfter sorting array elements are -\n"; 
    printArr(a, n);
return 0;
}
