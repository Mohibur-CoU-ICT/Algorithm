// insertion sort algorithm

#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
	for(int i=1; i<n; i++){
        int value = arr[i];
        int j = i;
        while(j>0 && arr[j-1]>value){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = value;
	}
}

int main(){
	int arr[] = {200, -10, 20, 500, 100};
	int n = sizeof(arr)/sizeof(arr[0]);
	insertionSort(arr, n);
	for(int i=0; i<n; i++){
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return 0;
}
