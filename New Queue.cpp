#include <iostream>
using namespace std;
int glob=10;
const int SIZE = 5;
struct myQueue{
	private:
		int QUEUE[SIZE];
        int head = 0;
        int tail = 0;
        
    public:
    	bool isEmpty(){
		return (head == tail);
		}
		
		bool isFull(){		
		return (tail==SIZE);
		}
		
		bool EnQueue(int value){
		if(isFull())
		return false;
		QUEUE[tail++] = value;
		return true;
		}
		int DeQueue(){
		if(isEmpty())
		return -999;
		return QUEUE[head++];
		}
		
		bool Display() {
			if(head==tail) {
				cout<<"Queue is empty"<<endl;
				return false;
			}
			while(head<tail) {
				cout<<QUEUE[head++]<<" ";
			}
			return true;
		}
};


int main() {
	cout<<"Golb= "<<glob<<endl;
	glob=20;
	cout<<"Glob = "<<glob<<endl;
	int size=0, val=0;
	myQueue A;
	
	cout<<"1. For Insertion: "<<endl;
	cout<<"2. For Deletion: "<<endl;
	cout<<"3. For Display: "<<endl;
	cout<<"4. For Exit: "<<endl;
	
	char ch;
	do {
		cout<<"\nEnter Choice: ";
		cin>>ch;
		switch(ch) {
			case '1':
				cout<<"Enter val: ";
				cin>>val;
				A.EnQueue(val);
				break;
				
			case '2':
				A.DeQueue();
				break;
				
			case '3':
				A.Display();
				break;
				
			case '4':
				cout<<"Exit"<<endl;
				break;
				
			default: cout<<"Invalid choice"<<endl;
				
		}
	}while(ch != '4');
	
	return 0;
}
