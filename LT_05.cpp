#include<iostream>
using namespace std;

int hashNum(int num, int size ){
	int result=num%size;
	return result;
}

int main() {
	int SIZE=0, value=0;
	cout<<"Enter SIZE of the Array: ";
	cin>>SIZE;
	int DATA[SIZE];
	cout<<"Enter Number: ";
	cin>>value;
	int output=hashNum(value, SIZE);
	cout<<"Result of function hashNum() = "<<output<<endl;
	return 0;
}
