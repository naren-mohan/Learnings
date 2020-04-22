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

class intStackLL{
public:
	struct node{
		int data;
		node* next;
	};

	node* head = NULL;

	void push(int insdata){
		node* temp = new node();
		temp->data = insdata;
		temp->next = head; 
		head = temp;
		Printer();
	}

	void pop(){
		if(isEmpty()){
			cout << "Error : Stack is empty!\n";
			return;
		}
		node* temp = head;
		head = temp->next;
		delete(temp);
		Printer();
	}

	int top(){
		node* temp = head;
		int i=-1;
		while(temp != NULL){
			temp = temp->next;
			i++;
		}
		return i;
	}

	bool isEmpty(){
		if(head == NULL)	return true;
		else	return false;
	}

	void Printer(){
		node* temp = head;
		while(temp != NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}


};

int main(){
	
	intStackLL list1;
	list1.push(2);
	list1.push(4);
	list1.push(6);
	list1.pop();
	list1.pop();
	list1.pop();
	list1.pop();
	list1.pop();
	cout << "Top: " << list1.top();

	return 0;

}