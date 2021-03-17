// Binary Search
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int key)
{
    if(low > high) return -1;
    int mid = low + (high-low) / 2;
    if(arr[mid] == key){
        return mid;
    }
    else if(key < arr[mid]){
        return binarySearch(arr, low, mid - 1, key);
    }
    else {
        return binarySearch(arr, mid + 1, high, key);
    }
}

int main()
{
    cout << "Enter value of n : ";
    int n, key;
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " numbers : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Enter key to search : ";
    cin >> key;
    int index = binarySearch(arr, 0, n-1, key);
    if(index == -1){
        cout << "Element not found." << endl;
    }
    else {
        cout << "Element found at index " << index << endl;
    }

    return 0;
}
/**
5
-10 21 34 65 107
65
Element found at index 3
*/
