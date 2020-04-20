#include <iostream>

//using namespace as std;
using namespace std;
//Defining the linked list

struct node
{
	int data;
	node* link;
};

node* a = NULL;	//headnode

//Insert a node at the beginning 
void InsertBegin(int insdata){
	node* temp = new node();
	temp->link = a;
	temp->data = insdata;
	a = temp;		
}

void Printer(){
	node* t2 = a;

	while(t2 != NULL){
		cout << t2->data << " ";
		t2 = t2->link;
	}
	cout << "\n";
}



int main(){
	
	int num, datatemp;
	cout << "Enter the number of nodes : ";
	cin >> num;
	

	for(int i=0; i<num; i++){
		cout << "Enter data : ";
		cin >> datatemp;
		InsertBegin(datatemp);
		Printer();
	}

	return 0;
}



