#include <conio.h>
#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct Node{
	int data;
	Node *kiri;
	Node *kanan;
}Node;

void tambah(Node **root, int databaru) {
	if 	((*root) == NULL) {
		Node *baru;
		baru = new Node;
		baru->data = databaru;
		baru->kiri = NULL;
		baru->kanan = NULL;
		(*root) = baru;
		(*root)->kiri = NULL;
		(*root)->kanan = NULL;
		cout<<"Data Telah Masukkan!";
	}
	else if (databaru<(*root)->data) {
		tambah(&(*root)->kiri, databaru);
	}
	else if (databaru>(*root)->data) {
		tambah(&(*root)->kanan, databaru);
	}
	else if (databaru == (*root)->data) {
		cout<<"Data Sudah ADA !!!?@#$";
	}
}
				
void preOrder(Node *root) {
	if (root != NULL) {
	    cout<< root->data; cout<< " ";
	    preOrder(root->kiri);
	    preOrder(root->kanan);
	}
}
void inOrder(Node *root) {
	if (root != NULL) {
		inOrder(root->kiri);
		cout<< root->data; cout<< " ";
		inOrder(root->kanan);
	}
}

void postOrder(Node *root) {
	if(root != NULL) {
		postOrder(root->kiri);
		postOrder(root->kanan);
		cout<< root->data; cout<< " ";
	}
}

int count(Node *root) {				// Kalkulasi Penjumlahan Jumlah Node (#1)
	if (root == NULL) return 0;
	return count(root->kiri) + count(root->kanan) + 1;
}

Node *FindMin(Node *root) { 		//Cari Node Minimum/ Terkecil (#3)
	if (root == NULL)
	    return NULL;
	else if (root->kiri == NULL)
	    return root;
	else
	    return FindMin(root->kiri);
}

void leaf(Node *root){
	if(root == NULL)
		printf("Data masih kosong");
		if(root->kiri!=NULL)
			leaf(root->kiri);
			if(root->kanan!=NULL)
				leaf(root->kanan);
				if(root->kanan == NULL && root->kiri == NULL)
					printf("%d ",root->data);
}

int main() {
	int pil;
	Node *pohon;
	pohon = NULL;
	do {
		system("cls"); //Bersihkan layar
		int data;
		cout<< "___________MENU__________\n";
		cout<< "1. Tambah Node\n";
		cout<< "2. Lihat Pre-Order\n";
		cout<< "3. Lihat In-Order\n";
		cout<< "4. Lihat Post Order\n";
		cout<< "5. Hitung Jumlah Node \n";
		cout<< "6. Cari Node Terkecil\n";
		cout<< "7. Cetak Leaf\n";
		cout<< "8. Exit\n\n";
		cout<< "Pilih--> : "; 
		cin>>pil;
		switch (pil) {
		case 1: cout<< "\nMasukan data baru :";
			cin>> data;
			tambah(&pohon, data);
			break;
		case 2: if(pohon != NULL)
		    preOrder(pohon);
		    else cout<< "Data masih kosong!";
		    break;
		case 3: if(pohon !=NULL)inOrder(pohon);
		        else cout<< "Data masih kosong!";
		        break;
		case 4: if(pohon !=NULL)
			postOrder(pohon);
				else cout<< "Data masih kosong!";
				break;
		case 5: if(pohon !=NULL)
			cout<< "Jumlah data : " << count(pohon);
				else cout<< "Data masih kosong!";
				break;
		case 6: if (pohon !=NULL) {
			Node *t = FindMin(pohon);
			cout<< "Node terkecil / Minimum : " << t->data;}
			else cout<< "Data masih kosong!";
			break;
		case 7: if (pohon !=NULL)
			leaf(pohon);			
		}
		getch();
	}while (pil != 8);
	return 0;
}
