#include<iostream>
#include<conio.h>
using namespace std;

int data[5];
const int MAX = 4;
int depan = 0;
int top = -1;
int count;

struct node{
	int data;
	node* next;
};
node *n, *temp, *pre;
node *head = NULL;
node *tail = NULL;

void enqueue(int n){
	if(top == MAX){
		cout << "\nQueue penuh!\n";
	}
	else{
		top++;
		data[top] = n;
		cout << "Data sudah terupdate" << endl;
	}
}

void dequeue(){
	if(top == -1){
		cout << "\nQueue tidak ada!\n";
	}
	else{
		cout << "\nData yang dikeluarkan adalah " << data[0];
		for(int i = 0; i<5; i++){
			data[i] = data[i+1];
		}
		top--;
		cout << "\nData sudah terupdate\n" << endl;
	}
}

void queuelihat(){
	int i =  top;
	if(top == -1){
		cout << "\nQueue tidak ada!\n";
	}
	else{
		cout << "\nData yang ada pada Queue adalah \n";
		cout << "tail->";
		while(i >= 0){
			cout << data[i] << "->";
			i--;
		}
		cout << "head";
	}
}

//linklist
void nodebaru(int data){
	n = new node;
	n->data = data;
	n->next = NULL;	
}

void nodetambahlist(int data){
	if(head == NULL){
		nodebaru(data);
		head = n;
		tail = head;
	}
	else{
		nodebaru(data);
		tail->next = n;
		tail = n;
	}
	cout << "Data sudah terupdate" << endl;
}

void nodehapuslist(){
	if (head == NULL){
		cout << "\nBelum ada data yang dimasukkan\n";
	}
	else{
		temp = head;
		cout << "Data yang dikeluarkan adalah " << temp->data;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
}

void nodelihatist(){
	if (head == NULL){
		cout << "\nBelum ada data yang dimasukkan\n";
	}
	else{
		temp = head;
		cout << "\nData yang ada adalah = " << endl;
		cout << "head<-";
		while (temp!=NULL){
			cout << temp->data << "<-";
			temp = temp->next;
		}
		cout << "Tail" << endl;
	}	
}

void queuearray();
void queuelist();
void menu();

int main(){
	menu();
}

void queuearray(){
	char ulang,pilihan;
	int data;
	do{
		system("cls");
		cout << "========  Program Queue Array  ========\n";
		cout<<"\nMenu : \n"<<endl;
		cout<<"1. Enqueue"<<endl;
		cout<<"2. Dequeue"<<endl;
    	cout<<"3. Cetak data"<<endl;
    	cout<<"4. Kembali ke menu"<<endl;
    	cout<<"\nMasukkan pilihan Anda : "; cin >> pilihan;
    	
    	switch(pilihan){
    		case '1' :
    			cout << "\nMasukkan data = "; cin >> data;
            	enqueue(data);
            	break;
    		case '2' :
    	        dequeue();
        	    break;
      		case '3' :
				queuelihat();
        	    break;
			case '4' :
				menu();
        		break;		       	
      		default :
            	cout<<"\nPilih ulang"<<endl;
      		}
      		
      	cout << "\nKembali ke menu?(y/n)"; cin>>ulang;
	}	
	while(ulang=='y' || ulang=='Y');
}

void queuelist(){
	char ulang,pilihan;
	int data;
	do{
		system("cls");
		cout << "=====  Program Queue Linked List  =====\n";
		cout<<"\nMenu : \n"<<endl;
		cout<<"1. Enqueue"<<endl;
		cout<<"2. Dequeue"<<endl;
    	cout<<"3. Cetak data"<<endl;
    	cout<<"4. Kembali ke menu"<<endl;
    	cout<<"\nMasukkan pilihan Anda : "; cin >> pilihan;
    	
    	switch(pilihan){
    		case '1' :
            	cout << "\nMasukkan data = "; cin >> data;
            	nodetambahlist(data);
            	break;
    		case '2' :
    	        nodehapuslist();
        	    break;
      		case '3' :
				nodelihatist();
        	    break;
        	case '4' :
        		menu();
        		break;
			default :
            	cout<<"\nPilih ulang"<<endl;
      		}
      		
      	cout << "\nKembali ke menu?(y/n)"; cin>>ulang;
	}	
	while(ulang=='y' || ulang=='Y');
}

void menu(){
	char ulang, pilihan;
	int data;
	do{
		ulang = 'n';
		system("cls");
		cout << "========  Menu Program Queue  =========\n";
		cout<<"\nPilih cara : \n";
		cout<<"1. Queue  array\n";
		cout<<"2. Queue linked list\n";
    	cout<<"\nMasukkan pilihan Anda : "; cin >> pilihan;
		
    	switch(pilihan){
			case '1' :
            	queuearray();
            	break;
    		case '2' :
    	        queuelist();
        	    break;        	
      		default :
            	cout<<"\nInput salah\n";
            	getch();
       			ulang = 'y';
    	}
	}
	while(ulang == 'y');
}

