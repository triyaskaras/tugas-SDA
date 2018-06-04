#include <iostream>
#define MAX 10
using namespace std;

struct node {
	int data;
	node *next;
};
node *n, *temp, *pre;
node *head = NULL;
node *tail = NULL;

bool isEmpty(){
	if(head == NULL){
		return true;
	}
	else{
		return false;
	}
}

bool isFull(){
	int count;
	temp = head;
	while(temp != NULL){
		count++;
		pre = temp;
		temp = temp->next;
	}
	if(count == 10){
		return true;
	}
	else{
		return false;
	}
}

void enqueue(){
	int data;
	if(isFull()){
		cout << "\n Antrian penuh" << endl;
	}
	else if(head == NULL){
		n = new node;
		cout << "\n Masukkan data = ";
		cin >> n->data;
		n->next = NULL;
		
		head = n;
		tail = n;
	}
	else{
		n = new node;
		cout << "\n Masukkan data = ";
		cin >> n->data;
		tail->next = n;
		tail = n;
		n->next = NULL;
	}
}

void dequeue(){
	if(isEmpty()){
		cout << "\n Antrian kosong" << endl;
	}
	else if(head == tail){
		cout << " Data " << head->data << " sudah terambil";
		head = NULL;
		tail = NULL;
	}
	else{
		temp = head->next;
		cout << " Data " << head->data << " sudah terambil";
		head = NULL;
		head = temp;
	}
}

void print(){
	temp = head;
	if(isEmpty()){
		cout << " Antrian kosong";
	}
	else{
		cout << "\n Antrian : ";
		while (temp!=NULL){
			cout << temp->data << " -> ";
			temp = temp->next;
		}
	}
}

void clear(){
	head = NULL;
	tail = NULL;
	cout << " Data telah berhasil di kosongkan";
}

int main(){
	int pilihan;
	char ulang;
	
	do{
		system("cls");
		cout << "============================\n";
		cout << " Program Queue (Linked List)\n";
		cout << "============================\n";
		
		cout<<" Menu : "<<endl;
		cout<<" 1. Input data"<<endl;
		cout<<" 2. Ambil data"<<endl;
		cout<<" 3. Cetak Data"<<endl;
		cout<<" 4. Kosongkan Data"<<endl;
		cout<<"\n Masukkan pilihan Anda : ";
		cin >> pilihan;
		
		switch(pilihan){
			case 1 :
				enqueue();
				break;
			case 2 :
				dequeue();
				break;
			case 3 :
				print();
				break;
			case 4 :
				clear();
				break;
		}
		cout<<"\n Kembali ke menu?(y/n) : ";
		cin>>ulang;
	}
	while(ulang=='y' || ulang=='Y');
}
