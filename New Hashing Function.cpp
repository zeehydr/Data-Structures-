#include<iostream>
using namespace std;
const int SIZE=10;

struct Node {
	int data;
	Node *next;
};

Node* Array[SIZE];

void insertNode(Node *&head, int val) {
	Node *node = new Node;
	node->data=val;
	node->next = NULL;
	if(head == NULL) {
		head=node;
		return;
	}
	Node *current = head;
	while(current->next != NULL) {
		current=current->next;
	}
	current->next=node;
}

void insertHash(int val) {
	int hashf=val % SIZE;
	Node *HEAD= Array[hashf];
	insertNode(HEAD,val);
	Array[hashf]=HEAD;
	
}

void displayHash() {
	for(int i=0; i<SIZE; i++) {
		cout<<"For i = "<<i<<" : ";
		Node *Head=Array[i];
		while(Head != NULL) {
			cout<<Head->data<<" ";
			Head=Head->next;
		}
		cout<<endl;
	}
}

void deleteHash(int item) {
	
	int hashfunc=item % SIZE;
	Node *Head= Array[hashfunc];
	if(Head == NULL) {
		cout<<"Hash Table is empty! So deletion is not possible"<<endl;
		return;
	}
	if(Head->data == item) {
		Head = Head->next;
		Array[hashfunc]=Head;
		cout<<"Element deleted successfully."<<endl;
		return;
	}
	Node *current=Head->next;
	Node *pred= Head;
	while(current != NULL) {
		if(current->data == item){
			pred->next = current->next;
			cout<<"Element deleted successfully."<<endl;
			return;
		}
		pred=current;
		current=current->next;
	}
	cout<<"Sorry! element not found."<<endl;
	return;
}

void searchHash(int item) {
	bool check=true;
	for(int a=0; a<SIZE; a++) {
		if(Array[a] != NULL) {
			check = false;
			break;
		}
	}
	if(check == true) {
		cout<<"Hash Table is empty"<<endl;
		return;
	}
	int hashfu= item % SIZE;
	Node *HeaD= Array[hashfu];
	while (HeaD != NULL) {
		if(HeaD->data == item) {
			cout<<"Element is found at Location/Address: "<<HeaD<<endl;
			return;
		}
		HeaD = HeaD->next;
	}
	cout<<"Unsuccessful Search! Element is not found! "<<endl;
	return;
}

int main() {
	int value=0, option=0;
	do {
		cout<<"======  Select a choice from below  ======"<<endl;
		cout<<"Enter 0. For Exit: "<<endl;
		cout<<"Enter 1. For Display Hash Table: "<<endl;
		cout<<"Enter 2. For Insertion in Hash Table: "<<endl;
		cout<<"Enter 3. For Delete an element from Hash Table: "<<endl;
		cout<<"Enter 4. For Search an element in Hash Table: "<<endl;
		cout<<"\nEnter a choice: ";
		cin>>option;
		
		switch(option) {
			case 0:
				cout<<"Quit"<<endl;
				break;
				
			case 1:
				displayHash();
				break;
				
			case 2:
				cout<<"Enter value: ";
				cin>>value;
				insertHash(value);
				break;
				
			case 3:
				cout<<"Enter value to delete: ";
				cin>>value;
				deleteHash(value);
				break;
				
			case 4:
				cout<<"Enter value to search: ";
				cin>>value;
				searchHash(value);
				break;
				
			default: cout<<"Please enter a valid choice!"<<endl;
		}
	} while(option != 0);
	return 0;
}
