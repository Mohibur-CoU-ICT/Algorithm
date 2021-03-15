// bubble sort algorithm

#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
	for(int i=0; i<n-1; i++){
        bool swapped = false;
		for(int j=0; j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
                swapped = true;
			}
		}
		if(!swapped){
            break;
		}
//		for(int j=0; j<n; j++){
//            cout << arr[j] << ' ';
//		}
//		cout << '\n';
	}
}

int main(){
	int arr[] = {200, -10, 20, 500, 100};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, n);
	for(int i=0; i<n; i++){
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return 0;
}
