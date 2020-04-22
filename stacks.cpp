#include <iostream>
#define ARRAYSIZE 10
using namespace std;

class intStackArray{
public:
	int top=-1;
	int sta[ARRAYSIZE];

	void push(int insdata){
		if(top>=ARRAYSIZE-1){
			cout << "Error : Reached Max size of the array for stack\n";
			return;
		}
		sta[++top] = insdata;
		for(int i=0;i<=top;i++)
			cout << sta[i] << " ";
		cout << "\n";
	}

	void pop(){
		if(isEmpty()){
			cout << "Error : Stack is empty!\n";
			return;
		}
		top--;
		for(int i=0;i<=top;i++)
			cout << sta[i] << " ";
		cout << "\n";
	}

	int topVal(){
		return top;
	}

	bool isEmpty(){
		if(top<0)	return true;
		else 	return false;
	}
};

int main(){
	intStackArray list1;
	list1.push(2);
	list1.push(4);
	list1.push(6);
	list1.push(2);
	
	list1.pop();
	list1.pop();
	list1.pop();
	list1.pop();
	list1.pop();
	list1.pop();
	cout << list1.topVal();

	return 0;

}