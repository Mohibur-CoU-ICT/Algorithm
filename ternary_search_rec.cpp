// Ternary Search
#include <bits/stdc++.h>
using namespace std;

int ternarySearch(int arr[], int low, int high, int key)
{
    if(low > high) return -1;
    int mid1 = low + (high-low) / 3;
    int mid2 = mid1 + (high-mid1) / 2;
    if(arr[mid1] == key){
        return mid1;
    }
    else if(arr[mid2] == key){
        return mid2;
    }
    else if(key < arr[mid1]){
        return ternarySearch(arr, low, mid1 - 1, key);
    }
    else if(key > arr[mid2]) {
        return ternarySearch(arr, mid1 + 1, high, key);
    }
    else {
        return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
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
    int index = ternarySearch(arr, 0, n-1, key);
    if(index == -1){
        cout << "Element not found." << endl;
    }
    else {
        cout << "Element found at index " << index << endl;
    }

    return 0;
}
/**
10
-10 21 34 47 65 89 107 164 187 219
65
Element found at index 4
*/
