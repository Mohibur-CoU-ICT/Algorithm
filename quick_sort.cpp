/// Quick Sort Algorithm
#include <bits/stdc++.h>
using namespace std;

int _partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int pIndex = l;
    for(int i=l; i<r; i++){
        if(arr[i] < pivot){
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[r]);
    return pIndex;
}

void quickSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int pIndex = _partition(arr, l, r);
        quickSort(arr, l, pIndex-1);
        quickSort(arr, pIndex+1, r);
    }
}

int main()
{
    cout << "How many elements: ";
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}
/**
7
10 5 46 26 12 9 15
*/
