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

	int InsertNth(int insdata, int n){
		int i=1;
		node* temp = a;
		node* t1;
		node* newnode = new node();
		newnode->data = insdata;
		num++;
		if(n==1){
			newnode->link = a;
			a = newnode;
			return 0;
		}

		while(i<n-1){
			temp = temp->link;
			i++;
		}
		//I have traversed thru the data and landed on the n-1th data.
		newnode->link = temp->link;
		temp->link = newnode;
		
		return 0;
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

	cout << "Enter the nth position : ";
	cin >> n;

	if(n>list1.num +1 || n<1){
		cout << "Invalid";
		exit(0);
	}
	
	cout << "Enter the data : ";
	cin >> datatemp;

	list1.InsertNth(datatemp,n);
	list1.Printer();

	return 0;
}



