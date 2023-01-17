#include<iostream>
using namespace std;
int Q_for=0, Q_if=0;
int in=0;
int LS_Count=0;
int BS_Count=0;
void insertinArray(int data[], int val, int N, int &current) {
	
	if(N<=-1) {
		cout<<"Array is empty"<<endl;
		return;
	}
	if(in<N) {
		data[in]=val;
	    in++;
	    current++;
	    cout<<"Value inserted successfully."<<endl;
	    return;
	} else {
		cout<<"SORRY! Array is full."<<endl;
		return;
	}
	
}
void displayArray(int arr[], int n) {
	if(n==-1) {
		cout<<"Array is empty."<<endl;
		return;
	}
	for(int i=0; i<=n; i++) {
		cout<<arr[i]<<" ";
	}
}

void selectionSort(int Data[], int N) {
	if(N==-1) {
		cout<<"Array is empty."<<endl;
		return;
	}
	int for1=0, for2=0;
	for(int i=0; i<=N; i++) {
		for1++;
		int min=i;
		for(int j=i+1; j<=N; j++) {
			for2++;
			if(Data[j]<Data[min])
			min=j;
		}
		int temp=Data[i];
		Data[i]=Data[min];
		Data[min]=temp;
	}
	cout<<"Array is sorted successfully."<<endl;
	cout<<"Time complexity of Selection Sort: "<<endl;
	cout<<"Number of itration of ForLoop01: "<<for1<<" times and ForLoop02: "<<for2<<" times."<<endl;
	return;
}

void bubleSort(int data[], int N) {
	if(N==-1) {
		cout<<"Array is empty."<<endl;
		return;
	}
	int for1=0, for2=0;
	for(int p=1; p<=N; p++) {
		for1++;
		for(int i=0; i<=N-p; i++) {
			for2++;
			if(data[i]>data[i+1]) {
				int temp=data[i];
				data[i]=data[i+1];
				data[i+1]=temp;
			}
		}
	}
	cout<<"Buble Sort completed successfully."<<endl;
	cout<<"Time Complexity of Buble Sorte: "<<endl;
	cout<<"Number of itration of ForLoop01: "<<for1<<" times and ForLoop02: "<<for2<<" times."<<endl;
	return;
}

// Quick Sort
void swap(int a[], int b[]) {
	int i=0, j=0;
	int temp = a[0];
	a[0]=b[0];
	b[0]=temp;
}


int partition(int data[],int l, int r) {
	int p = data[r];
	int i = l-1;
	for(int j=l; j<r; j++) {
		Q_for++;
		if(data[j]<=p) {
			i++;
			swap(data[j], data[i]);
		}
	}
	swap(data[i+1], data[r]);
	return (i+1);
}


int quickSort(int data[], int l, int r) {
	if(r<=-1) {
		cout<<"Array is empty."<<endl;
		return -999;
	}
	if(l<=r) {
		Q_if++;
	    int p = partition(data, l, r);
	    quickSort(data,l,p-1);
	    quickSort(data,p+1, r);
	}
}
// End Quick Sort

void LinearSearch(int DATA[], int item, int N) {
	if(N==-1) {
		cout<<"Array is empty."<<endl;
		return;
	}
	int num=DATA[0];
	int count=0;
	for(int i=0; i<N; i++) {
		LS_Count++;
		if(DATA[i]==item) {
			cout<<"Congratulation! element is found at inded: "<<i<<endl;
			return;
		}
	}
	cout<<"Sorry! element is not found"<<endl;
	return;
}

void BinarySearch(int DATA[], int item, int N) {
	if(N==-1) {
		cout<<"Array is empty."<<endl;
		return;
	}
	int low=0;
	int hi=N-1;
	int mid=-1;
	while(low<hi) {
		BS_Count++;
		mid=(low+hi)/2;
		if(DATA[mid]== item) {
			cout<<"Congratulation! item is found at index: "<<mid<<endl;
			return;
		} else if(DATA[mid]<item) {
			low=mid+1;
		}else {
			hi=mid-1;
		}
	}
	cout<<"SORRY! item not found."<<endl;
	return;
}

int main() {
	int size=-1;
	cout<<"Enter size of the Array: ";
	cin>>size;
	int Array[size];
	int value;
	int now=-1;
	
	cout<<"=========  Select an option:  =========="<<endl;
	cout<<"1. For Insert a new element in Array: "<<endl;
	cout<<"2. For Displaying Array elements: "<<endl;
	cout<<"3. For selection Sort: "<<endl;
	cout<<"4. For Buble Sort: "<<endl;
	cout<<"5. For Quick Sort: "<<endl;
	cout<<"6. For Linear Search: "<<endl;
	cout<<"7. For Binary Search: "<<endl;
	cout<<"8. For Quit: "<<endl;
	char option;
	do {
		cout<<"\nEnter choice: ";
		cin>>option;
		
		switch(option) {
			case '1':
				cout<<"Enter value: ";
				cin>>value;
				insertinArray(Array, value, size, now);
				break;
				
			case '2':
				cout<<"Displaying Array elements: "<<endl;
				displayArray(Array, now);
				break;
				
			case '3':
				selectionSort(Array, now);
				break;
				
			case '4':
				bubleSort(Array, now);
				break;
				
			case '5':
				quickSort(Array, 0, now-1);
				if(now>=0) {
					cout<<"Array sorted successfully."<<endl;
				    cout<<"Time complexity of Quick Sort: "<<endl;
				    cout<<"Number fo exicution of if statement: "<<Q_if<<" times and ForLoop: "<<Q_for<<" times."<<endl;
				    Q_if=Q_for=0;
				}
				
				break;
				
			case '6':
				cout<<"Enter value to search: ";
				cin>>value;
				LinearSearch(Array,value,now);
				if(now>=0) {
					cout<<"Time Complexity of Linear Search: "<<endl;
				    cout<<"Number of execution of for Loop: "<<LS_Count<<endl;
				    LS_Count=0;
				}
				
				break;
				
			case '7':
				cout<<"Enter value to search: ";
				cin>>value;
				BinarySearch(Array,value,now);
				if(now>=0) {
					cout<<"Time Complexity of Binary Search: "<<endl;
				    cout<<"Number of execution of while Loop: "<<BS_Count<<endl;
				    BS_Count=0;
				}
				
				break;
				
			case '8':
				cout<<"Exit"<<endl;
				break;
				
			default: cout<<"SORRY! Invalid choice."<<endl;
		}
	}while(option != '8');
	
	return 0;
}
