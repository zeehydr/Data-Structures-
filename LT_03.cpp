#include<iostream>
#include<cmath>
using namespace std;

struct Node {
	private:
		int data;
	    Node *next;
	    Node *prev;
	public:
		void insertatEnd(Node *&head, int val) {
			Node *node = new Node;
			node->data=val;
			node->next=NULL;
			node->prev=NULL;
			if(head==NULL) {
				head=node;
				cout<<"First Node inserted successfuly."<<endl;
				return;
			}
			Node *current=head;
			while(current->next != NULL) {
				current=current->next;
			}
			current->next=node;
			node->prev=current;
		}
		
		void displayNode(Node *head) {
			if(head==NULL) {
				cout<<"Linked List is empty."<<endl;
				return;
			}
			Node *current=head;
			cout<<"Displaying List elements: "<<endl;
			while(current != NULL) {
				cout<<current->data<<" ";
				current=current->next;
			}
			current=head;
			while(current->next != NULL) {
				current=current->next;
			}
			cout<<"\nDisplaying in reverse order: "<<endl;
			Node *now=current;
			while(now != NULL) {
				cout<<now->data<<" ";
				now=now->prev;
			}
			return;
		}
		
		void insertAfterVal(Node *&head, int val, int targ) {
			Node *node = new Node;
			node->data=val;
			node->next=NULL;
			node->prev=NULL;
			if(head==NULL) {
				head=node;
				cout<<"Value inserted at first Node."<<endl;
				return;
			}
			Node *current=head;
			Node *ptr;
			while(current != NULL) {
				if(current->data==targ) {
					ptr=current->next;
					current->next=node;
					node->prev=current;
					node->next=ptr;
					ptr->prev=node;
					cout<<"Node inserted successfuly."<<endl;
					return;
				}
				current=current->next;
			}
			cout<<"Element not found."<<endl;
			return;
		}
		
		void deleteNode(Node *&Head, int item) {
			if(Head==NULL) {
				cout<<"List is empty! So deletion is not possible."<<endl;
				return;
			}
			if(Head->data==item) {
				Head=Head->next;
				cout<<"First Node is deleted."<<endl;
				return;
			}
			Node *current=Head;
			Node *ptrNext;
			Node *ptrPrev;
			while(current != NULL) {
				if(current->data==item) {
					ptrNext=current->next;
					ptrPrev=current->prev;
					ptrNext->prev=ptrPrev;
					ptrPrev->next=ptrNext;
					cout<<"Element deleted successfully."<<endl;
					return;
				}
				current=current->next;
			}
			
			cout<<"Element not found! So deletion is not possible."<<endl;
			return;
		}
		
		void searchNode(Node *head, int item) {
			if(head == NULL) {
				cout<<"List is empty."<<endl;
				return;
			}
			Node *current=head;
			while(current != NULL) {
				if(current->data == item) {
					cout<<"\"SUCCESSFUL SEARCH\" Element is found and Address is: "<<current<<endl;
					return;
				}
				current=current->next;
			}
			cout<<"\"UNSUCCESSFUL SEARCH\" element is not found."<<endl;
			return;
		}
		
		void Report_Statistics(Node *head) {
			if(head==NULL) {
				cout<<"There is nod Node in the Linked List."<<endl;
				return;
			}
			Node *current=head;
			double MAX=0, MIN=0, SUM=0, AVR=0;
			int count=0;
			MAX=MIN=current->data;
			while(current != NULL) {
				if(current->data > MAX) MAX=current->data;
				if(current->data < MIN) MIN=current->data;
				SUM +=current->data;
				count++;
				current=current->next;
			}
			AVR=SUM/count;
			cout<<"Maximum value in the Linked List: "<<MAX<<endl;
			cout<<"Minimum value in the Linked List: "<<MIN<<endl;
			cout<<"Average/ mean in the Linked List: "<<AVR<<endl;
			cout<<"Sum of all value in  Linked List: "<<SUM<<endl;
			cout<<"Total  Nodes in  the Linked List: "<<count<<endl;
			
			// Standard deviation
			double SD_SUM=0, power=0, avrMV=0;
			Node *now=head;
			while(now != NULL ) {
				avrMV=now->data - AVR;
				power=avrMV*avrMV;
				SD_SUM= SD_SUM + power;
				now=now->next;
			}
			double dividbyN=SD_SUM/--count;
			double underRootofSD= sqrt(dividbyN);
			cout<<"Standard Deviation in Linked List: "<<underRootofSD<<endl;
			return;
		}
		
		void displayinRange(Node *HEAD, int start, int stop) {
			if(HEAD == NULL) {
				cout<<"Linked List is zero."<<endl;
				return;
			}
			Node *current=HEAD;
			
			while(current != NULL) {
				if(current->data>=start && current->data<=stop) {
					cout<<current->data<<" ";
				}
				if(current->data<=start && current->data>=stop) {
					cout<<current->data<<" ";
				}
				current=current->next;
			}
			cout<<endl;
			return;
		}
};

int main() {
	Node Run_Func;
	Node *head=NULL;
	int value=0, target=0;
	cout<<"------- Choose any option  --------"<<endl;
	cout<<"1. Display all the elements of the list: "<<endl;
	cout<<"2. Insert a node at the End: "<<endl;
	cout<<"3. Insert a node after a given value: "<<endl;
	cout<<"4. Delete a Node: "<<endl;
	cout<<"5. Search for an element: "<<endl;
	cout<<"6. Report Statistics(Min,Max,Average,Standard Deviation: "<<endl;
	cout<<"7. Display elements that fall in a given range: "<<endl;
	cout<<"8. Quit: "<<endl;
	
	char choice;
	do {
		cout<<"\nEnter choice: ";
		cin>>choice;
		
		switch(choice) {
			case '1':
				Run_Func.displayNode(head);
				break;
				
			case '2':
				cout<<"Enter value: ";
				cin>>value;
				Run_Func.insertatEnd(head,value);
				break;
				
			case '3':
				cout<<"Enter target value to input after the value: ";
				cin>>target;
				cout<<"Enter value: ";
				cin>>value;
				Run_Func.insertAfterVal(head,value,target);
				break;
				
			case '4':
				cout<<"Enter vlaue delete from DLL: ";
				cin>>target;
				Run_Func.deleteNode(head,target);
				break;
				
			case '5':
				cout<<"Enter value to search: ";
				cin>>target;
				Run_Func.searchNode(head,target);
				break;
				
			case '6':
				Run_Func.Report_Statistics(head);
				break;
				
			case '7':
				cout<<"Enter starting point: ";
				cin>>value;
				cout<<"Enter  ending  point: ";
				cin>>target;
				Run_Func.displayinRange(head,value,target);
				break;
				
			case '8':
				cout<<"Exit"<<endl;
				break;
				
			default: cout<<"Sorry! In-valid choice."<<endl;
		}
	}while(choice != '8');
	
	return 0;
	
}
