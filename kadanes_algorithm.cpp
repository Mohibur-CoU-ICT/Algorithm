// Kadane's Algorithm
// Maximum sub-array sum
#include <bits/stdc++.h>
using namespace std;

int kadanesAlgorithm(int arr[], int n)
{
    int ans = 0, sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum < 0){
            sum = 0;
        }
        else if(sum > ans){
            ans = sum;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = kadanesAlgorithm(arr, n);
    cout << ans << endl;

    return 0;
}
/**
{-2, -3, 4, -1, -2, 1, 5, -3}
8
-2 -3 4 -1 -2 1 5 -3
7
*/
