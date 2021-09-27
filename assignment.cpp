
#include<bits/stdc++.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
#define MAX_NUM 3000

//print the random numbers
vector<int> random_no(){
	int random;
	vector<int>v;
	srand(time(NULL));
	for(int i=0;i<MAX_NUM;i++){
		random=rand()%MAX_NUM;
		v.push_back(random);
	}
	return v;
}
//bubble sort
void bubble_sort(int arr[],int n){
	
    if (n == 1)
        return;
 
    for (int i=0; i<n-1; i++){
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
              
    }
 
    bubble_sort(arr, n-1);
 
}
//merge sort
void merge(int arr[],int l,int mid,int r){
	int n1=mid-l+1;
	int n2=r-mid;
	int a[n1];
	int b[n2];
	for(int i=0;i<n1;i++){
		a[i]=arr[i+l];
	}
	for(int i=0;i<n2;i++){
		b[i]=arr[i+mid+1];
	}
	int i=0,j=0,k=l;
	while(i<n1 && j<n2){
		if(a[i]<b[j]){
			arr[k]=a[i];
			k++;i++;
		}else{
			arr[k]=b[j];
			j++;k++;
		}
	}

	while(i<n1){
		arr[k]=a[i];
		k++;i++;
	}
	while(j<n2){
		arr[k]=b[j];
		j++;k++;
	}
	
}
void mergesort(int arr[],int l,int r){
	if(l<r){
		int mid=(l+r)/2;

		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);


		merge(arr,l,mid,r);
		
	}
}
//insertion sort
void insertionSort(int arr[], int n)
{
    if (n <= 1)
        return;
    insertionSort( arr, n-1 );
 
    int last = arr[n-1];
    int j = n-2;
 
    while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}
// print the array
void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++){
    	cout<<arr[i]<<" ";
    }
}


int main()
{
	vector<int>v1;
	v1=random_no();
	int n=v1.size();
	int l=0,r=n-1;
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i]=v1[i];
	}
	bubble_sort(arr,n);
	mergesort(arr,l,r);
	insertionSort(arr,n);

	printArray(arr,n);
	
	return 0;
} 