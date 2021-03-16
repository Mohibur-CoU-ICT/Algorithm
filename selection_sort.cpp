// selection sort algorithm

#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
	for(int i=0; i<n-1; i++){
        int minIndex = i;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[minIndex]){
			    minIndex = j;
			}
		}
        swap(arr[minIndex], arr[i]);
	}
}

int main(){
	int arr[] = {200, -10, 20, -50, 100};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);
	for(int i=0; i<n; i++){
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return 0;
}
