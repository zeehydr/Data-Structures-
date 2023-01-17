#include<iostream>
#include<cmath>
using namespace std;


int i=-1;
void insertAtEnd(int data[], int val) {
	i++;
	data[i] = val;
	cout<<"Element inserted successfuly!"<<endl;
}

void displayAllEle(int data[]) {
	if(i==-1) {
		cout<<"Array is Empty!"<<endl;
		return;
	}
	for(int j=0; j<=i; j++) {
		cout<<data[j]<<" ";
	}
	cout<<endl;
}


void insertAtTarget(int data[], int Tval, int inValue) {
	if(i==-1) {
		cout<<"Array is Empty! So insertion onlay take place at start!"<<endl;
		data[++i]=inValue;
		return;
	}
	int loc=-1;
	for(int z=0; z<=i; z++) {
		if(data[z]==Tval) loc=z;
	}
	if(loc==-1) {
		cout<<"Location not found! So insertion is not possilbe."<<endl;
		return;
	}
	else {
		i++;
		int range= i;
		for(int a=range; a>loc; a--) {
			data[a]=data[a-1];
		}
		
		data[loc+1] = inValue;
		cout<<"Element is inserted successfuly."<<endl;
		
	}
}

void deleteEle(int data[], int Uval) {
	if(i==-1) {
		cout<<"Array is Empty! So deletion is not possible."<<endl;
		return;
	}
	int index=-1;
	for(int j=0; j<=i; j++) {
		if(Uval==data[j])
		index=j;
	}
	if(index==-1) {
		cout<<"Element not found! So Deletion is not possible."<<endl;
		return;
	} else {
			for(int k=index; k<i; k++) {
				data[k]=data[k+1];
	}
	
		i--;
		cout<<"Element is deleted successfuly."<<endl;
	}

}


void searchforVal(int arr[], int num) {
	if(i==-1) {
		cout<<"Array is empty! So search is not possilbe."<<endl;
		return;
	}
	int loc=-1;
	for(int j=0; j<=i; j++) {
		if(arr[j]==num) loc=j;
	}
	if(loc==-1) {
		cout<<"Element is not found!"<<endl;
		return;
	} else {
		cout<<"The element is at index = "<<loc<<" and value = "<<arr[loc]<<endl;
		return;
	}
}


void Report_Statistics(int Data[]) {
	if(i==-1) {
		cout<<"Array is empty! So No Report Statistics."<<endl;
		return;
	}
	
	int MAX = Data[0];
	for(int j=1; j<=i; j++) {
		if(Data[j]>MAX) MAX=Data[j];
	}
	cout<<"The Maximum value is: "<<MAX<<endl;
	
	int MIN=Data[0];
	for(int j=1; j<=i; j++) {
		if(Data[j]<MIN) MIN=Data[j];
	}
	cout<<"The Minimum value is: "<<MIN<<endl;
	
	double SUM=0;
	int count=0;
	for(int j=0; j<=i; j++) {
		SUM+=Data[j];
		count++;
	}
	cout<<"Total number of elements : "<<count<<endl;
	cout<<"Sum of all elements is : "<<SUM<<endl;
	
	double AVR;
	AVR=SUM/count;
	cout<<"Avrage of all numbers: "<<AVR<<endl;
	
	
	// Standard Deviation
	int n=count;
	double Dev_SUM=0;
	double Dev_Mult=1;
	double Total_SUM=0;
	for(int k=0; k<=i; k++) {
		Dev_SUM=Data[k]-AVR;
		Dev_Mult= Dev_SUM*Dev_SUM;
		Total_SUM=Total_SUM+Dev_Mult;
	}
	
	double SD=Total_SUM/--n;
	double result= sqrt(SD);
	cout<<"The Standerd Deviation is: "<<result<<endl;
	
}

int main() {
	int size=0, val=0 , target=0, uvalue=0;
	cout<<"Enter size of the Array: ";
	cin>>size;
	int Array[size];
	
	
	cout<<"\n=====  Select any choice from below   ====="<<endl;
	cout<<"1. Display all elements of the Array: "<<endl;
	cout<<"2. Insert an element at the end: "<<endl;
	cout<<"3. Insert an element at a user specified location: "<<endl;
	cout<<"4. Delete a user specified element: "<<endl;
	cout<<"5. Search for the user specified element: "<<endl;
	cout<<"6. Report statistics: "<<endl;
	cout<<"7. Quit: "<<endl;
	
	char ch;
	
	do {
		cout<<"\nEnter your choice: ";
		cin>>ch;
		
		switch(ch) {
			case '1':
				cout<<"Elements of the Array: "<<endl;
				displayAllEle(Array);
				break;
				
			case '2':
				cout<<"Enter value: ";
				cin>>val;
				insertAtEnd(Array,val);
				break;
				
			case '3':
				cout<<"Enter target after which to be enterd: ";
				cin>>target;
				cout<<"Enter val: ";
				cin>>val;
				insertAtTarget(Array, target, val);
				break;
				
			case '4':
				cout<<"Enter specified valu: ";
				cin>>uvalue;
				deleteEle(Array, uvalue);
				break;
				
			case '5':
				cout<<"Enter value to find: ";
				cin>>val;
				searchforVal(Array, val);
				break;
				
			case '6':
				Report_Statistics(Array);
				break;
				
			case '7':
				cout<<"Exit"<<endl;
				break;
				
		default: cout<<"In-valid choice..."<<endl;
		}
	}while(ch != '7');
	
	return 0;
}
