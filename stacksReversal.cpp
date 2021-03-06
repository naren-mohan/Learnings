#include <iostream>
#include <stack>

using namespace std;

struct node{
	int data;
	node* link;
};

class linkLists{
public:
	node* a = NULL;	//headnode
	int num;

	linkLists(){

		int datatemp;
		cout << "Enter the number of nodes : ";
		cin >> num;
		
		for(int i=0; i<num; i++){
			cout << "Enter data : ";
			cin >> datatemp;
			InsertBegin(datatemp);
			Printer();
		}
	}

	//Insert a node at the beginning 
	void InsertBegin(int insdata){
		node* temp = new node();
		temp->link = a;
		temp->data = insdata;
		a = temp;		
	}

	void InsertNth(int insdata, int n){
		int i=1;
		node* temp = a;
		node* t1;
		node* newnode = new node();
		newnode->data = insdata;
		num++;
		if(n==1){
			newnode->link = a;
			a = newnode;
			return;
		}

		while(i<n-1){
			temp = temp->link;
			i++;
		}
		//I have traversed thru the data and landed on the n-1th data.
		newnode->link = temp->link;
		temp->link = newnode;
		
		return;
	}

	void Deletenth(int n){
		node* temp = a;
		node* t1;

		if(n==1){
			a = temp->link;
			return;
		}

		int i=0;

		while(i<n-2){
			temp = temp->link;
			i++;
		}

		t1 = temp->link;
		temp->link = t1->link;
		delete(t1);
	}

	void Reverselist(){
		node* temp = a; 
		node* prev=NULL;
		node* next=a;

		while(temp!=NULL){
			next = temp->link;
			temp->link = prev;
			prev = temp;
			temp = next; 
		}
		a = prev;
	}

	void ReverselistRecursion(node* temp,node* prev){
		if(temp == NULL){
			a = prev;
			return;
		}
		node* next = temp->link;
		temp->link = prev;
		prev = temp; 
		ReverselistRecursion(next,prev);
	}

	void Printer(){
		node* t2 = a;
		while(t2 != NULL){
			cout << t2->data << " ";
			t2 = t2->link;
		}
		cout << "\n";
	}

	void PrinterRecursion(node* temp){
		if(temp == NULL){
			cout << "\n";
			return;
		}
		cout << temp->data << " ";
		PrinterRecursion(temp->link);
	}
	
	void ReversePrinterRecursion(node* temp){
		if(temp == NULL) return;
		ReversePrinterRecursion(temp->link);
		cout << temp->data << " ";
	}
};


void ReverseStr(char *str,int n){
	stack<char> sta;
	for(int i=0;i<n;i++){
		sta.push(str[i]);
	}
	for(int i=0;i<n;i++){
		str[i]=sta.top();
		sta.pop();
	}
}

node* ReverseLL(linkLists list){
	stack<node*> sta;
	node* temp;
	temp = list.a;

	while(temp != NULL){
		sta.push(temp);
		cout << "Pushing " << temp << "\n";
		temp = temp-> link;
	}

	temp = sta.top();
	node* head = temp;
	sta.pop();
	while(!sta.empty()){
		temp->link = sta.top();
		cout << "Popping " << sta.top() << "\n";
		sta.pop();
		temp = temp->link;
	}
	temp->link = NULL;
	return head;
}

int main(){

	linkLists list1;
	//cout << list1.a;
	cout << "Reversing the list using stack\n";
	node* head = ReverseLL(list1);

	while(head != NULL){
		cout << head->data << " ";
		head = head->link;
	}
	
	return 0;
}
