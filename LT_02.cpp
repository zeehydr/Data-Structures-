#include<iostream>
#include<cmath>
using namespace std;

struct Node {
	private:
		int data;
		Node *next;
		
	public:
		void insertNode(Node *&head, int val) {
			Node *node = new Node;
			node->data=val;
			node->next=NULL;
			if(head==NULL) {
				head=node;
				cout<<"Node inserted at first."<<endl;
				return;
			}
			Node *current=head;
			while(current->next != NULL) {
				current=current->next;
			}
			current->next=node;
			cout<<"Node inserted successfuly."<<endl;
			return;
		}
		
		void displayAllNode(Node *head) {
			if(head==NULL) {
				cout<<"Linked List is Empty!"<<endl;
				return;
			}
			Node *current=head;
			cout<<"Displaying Linked List Elements: "<<endl;
			while(current != NULL) {
				cout<<current->data<<" ";
				current=current->next;
			}
			return;
		}
		
	void insertAfter(Node *&head, int val, int target) {

		if(head==NULL) {
			Node *node = new Node;
			node->data=val;
			node->next=NULL;
			head=node;
			cout<<"List is Empty! So Insertion is possilbe only at start."<<endl;
			return;
		}
			
			Node *node = new Node;
			node->data=val;
			Node *current = head;
			Node *store;
			while(current != NULL ) {
				if(current->data==target) {
					store=current->next;
					current->next=node;
					node->next=store;
					cout<<"Node inserted successfuly."<<endl;
					return;
				}
				current=current->next;
			}
			cout<<"Target is not found so Insertion not possible!"<<endl;
			return;
	}
	
	void deleteNode(Node *&head, int val) {
		if(head==NULL) {
			cout<<"List is empty! So deletion is not possible."<<endl;
			return;
		}
		
		if(head != NULL) {
			if(head->data==val) {
				head=head->next;
				cout<<"First Node is deleted."<<endl;
				return;
			}
		}
		
		Node *current= head;
		Node *pred=head;
		current=current->next;
		while(current != NULL) {
			if(current->data==val) {
				pred->next=current->next;
				cout<<"Node deleted successfully."<<endl;
				return;
			}
			pred=current;
			current=current->next;
		}
		cout<<"Sorry! Element is not found."<<endl;
		return;
	}
	
	void searchNode(Node *head, int val) {
		if(head==NULL) {
			cout<<"Linked List is empty."<<endl;
			return;
		}
		Node *current = head;
		while(current != NULL) {
			if(current->data==val) {
				cout<<"Congratulations! element is founded."<<endl;
				return;
			}
			current=current->next;
		}
		cout<<"Sorry! element is not founded."<<endl;
	}
	
	void displayinRange(Node *head, int start, int end) {
		if(head==NULL) {
			cout<<"Linked List is empty."<<endl;
			return;
		}
		Node *current=head;
		while(current != NULL) {
			if(current->data>=start && current->data<=end) {
				cout<<current->data<<" ";
			}
			current=current->next;
		}
	}
	
	void Report_Statistics(Node *head) {
		if(head==NULL) {
			cout<<"List is empty! So no report statistics."<<endl;
			return;
		}
		Node *current=head;
		double MAX= current->data;
		double MIN= current->data;
		double SUM=current->data;
		int count=1;
		current=current->next;
		while(current != NULL) {
			if(current->data>MAX) MAX=current->data;
			if(current->data<MIN) MIN=current->data;
			SUM=SUM+current->data;
			count++;
			current=current->next;
		}
		cout<<"Maximum in the Linked List: "<<MAX<<endl;
		cout<<"Minimum in the Linked List: "<<MIN<<endl;
		cout<<"Sum of all elements inList: "<<SUM<<endl;
		cout<<"Total Nodes in the  L.List:  "<<count<<endl;
		double AVR=SUM/count;
		cout<<"Average in the Linked List: "<<AVR<<endl;
		
		double SD_SUM=0, SQR=0, Minus=0;
		Node *now = head;
		while(now != NULL ) {
			Minus=now->data - AVR;
			SQR=Minus*Minus;
			SD_SUM=SD_SUM + SQR;
			now=now->next;
		}
		double Standard_Deviation=SD_SUM/--count;
		double result = sqrt(Standard_Deviation);
		cout<<"Standard Deviation in List: "<<result<<endl;
		
	}
};


int main() {
	Node run;
	Node *head=NULL;
	int M_value=0, M_target=0;
	cout<<"=====   Select a choice of your interest   ====="<<endl;
	cout<<"1. Display all the elements of the list: "<<endl;
	cout<<"2. Insert a node at the end: "<<endl;
	cout<<"3. Insert a node after a given value: "<<endl;
	cout<<"4. Delete a node: "<<endl;
	cout<<"5. Search for an element: "<<endl;
	cout<<"6. Report Statistics: "<<endl;
	cout<<"7. Display elements that fall in a given range: "<<endl;
	cout<<"8. For Quit: "<<endl;
	
	char option;
	do {
		cout<<"\nEnter a choice: ";
		cin>>option;
		
		switch(option) {
			case '1':
				run.displayAllNode(head);
				break;
				
			case '2':
				cout<<"Enter value: ";
				cin>>M_value;
				run.insertNode(head, M_value);
				break;
				
			case '3':
				cout<<"Enter target after which value is to be enterd: ";
				cin>>M_target;
				cout<<"Enter value: ";
				cin>>M_value;
				run.insertAfter(head, M_value, M_target);
				break;
				
			case '4':
				cout<<"Enter value to delete from Linked List: ";
				cin>>M_target;
				run.deleteNode(head, M_target);
				break;
				
			case '5':
				cout<<"Enter element to search: ";
				cin>>M_value;
				run.searchNode(head, M_value);
				break;
				
			case '6':
				run.Report_Statistics(head);
				break;
				
			case '7':
				cout<<"Enter Starting Range: ";
				int S_point;
				cin>>S_point;
				cout<<"Enter ending Range: ";
				int E_point;
				cin>>E_point;
				run.displayinRange(head, S_point, E_point);
				break;
				
			case '8':
				cout<<"Exit";
				break;
				
			default: cout<<"In-valid! Choice?"<<endl;
		}
		
	}while(option != '8');
	
	return 0;
}

