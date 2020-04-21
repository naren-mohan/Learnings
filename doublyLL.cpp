#include <iostream>

using namespace std;

class doubleLL{
public:
	struct node{
		int data;
		node* prev;
		node* next;
	};

	node* head=NULL;
	int num;

	doubleLL(){
		int datatemp;
		cout << "Enter the number of nodes : ";
		cin >> num;
		for(int i=0;i<num;i++){
			cout << "Enter data : ";
			cin >> datatemp;
			InsertatHead(datatemp);
			ForwardPrinter();
		}
	}

	void InsertatHead(int insdata){
		node* temp = new node();
		temp->data = insdata;
		temp->prev = NULL;
		if(head == NULL){
			temp->next = NULL;
			head = temp;
			return;
		}
		head->prev = temp;
		temp->next = head;
		head = temp;
	}

	void InsertatTail(int insdata){
		node* newNode = new node();
		newNode->data = insdata;
		newNode->next = NULL;
		node* temp = head;

		while(temp->next != NULL){
			temp = temp->next;
		}

		temp->next = newNode;
		newNode->prev = temp;
	}

	void ForwardPrinter(){
		node* temp = head;
		while(temp != NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}

	void ReversePrinter(){
		node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}

		while(temp != NULL){
			cout << temp->data << " ";
			temp = temp->prev;
		}
		cout << "\n";
	}
};

int main(){
	doubleLL list1;
	list1.InsertatTail(69);
	cout << "Inserting 69 at the tail\n";
	list1.ForwardPrinter();
	cout << "Reverse Printing\n";
	list1.ReversePrinter();
}