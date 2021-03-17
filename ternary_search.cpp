// Ternary Search
#include <bits/stdc++.h>
using namespace std;

int ternarySearch(int arr[], int low, int high, int key)
{
    while(low <= high)
    {
        int mid1 = low + (high-low) / 3;
        int mid2 = mid1 + (high-mid1) / 2;
        if(arr[mid1] == key){
            return mid1;
        }
        else if(arr[mid2] == key){
            return mid2;
        }
        else if(key < arr[mid1]){
            high = mid1 - 1;
        }
        else if(key > arr[mid2]) {
            low = mid2 + 1;
        }
        else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    return -1;
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
