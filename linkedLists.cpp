#include <iostream>

//using namespace as std;
using namespace std;
//Defining the linked list
class linkLists{
public: 
	struct node
	{
		int data;
		node* link;
	};

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
		
		return;
	}

	void Printer(){
		node* t2 = a;

		while(t2 != NULL){
			cout << t2->data << " ";
			t2 = t2->link;
		}
		cout << "\n";
	}
};


int main(){
	
	linkLists list1;
	int datatemp,n;

	cout << "Enter the nth position to delete: ";
	cin >> n;

	if(n>list1.num || n<1){
		cout << "Invalid";
		exit(0);
	}
	

	list1.Deletenth(n);
	list1.Printer();

	return 0;
}



