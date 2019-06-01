#include <iostream>
#include <conio.h>

using namespace std;
int data[9999999999];
int n,i,search,hapus,j;
bool swapped;

void input(){
	cout<<"===PROGRAM INPUT DATA==="<<endl;
 	cout<<"Masukan Jumlah Data: ";
 	cin>>n;
 	cout<<endl;
 	for(i=1;i<=n;i++){
  		cout<<"Masukkan data ke "<<i<< " : ";
  		cin>>data[i];
 	}	
}
void view(){
	cout<<"Data yang tersimpan : ";
 	cout<<endl;
 	for( i=1; i<=n; i++){
  		cout<<" "<<data[i]<<endl;
 	}
}
void cari(){
	cout<<"Elemen yang anda cari = ";
    cin>>search;
	for (i=1;i<=n;i++)
    {
		if(data[i]==search)
		{
			cout<<"Pencarian ditemukan. Elemen terletak pada posisi : "<< (i+1) <<" \n";
			break;
		}
		if(i ==n-1)
		{
			cout<<"Pencarian elemen tidak ada pada array.\n";
		}
    }    
}
void hapusmen(){
	cout << "\n\nMasukkan elemen data yang akan dihapus = "; 
	cin >> hapus;
	for (int i=1;1<=n;i++)
	{
		if (hapus == data[i])
		{
			for (int k=i; k<=n; k++)
			{
				data[k]=data[k+1];
			}
			n -= 1;
			break;
		}
	}
	cout << "\n\nData Baru :";
	for (int p=1; p<=n; p++)
	{
		cout <<"\ndata[" <<p<< "]= " <<data[p];
	}
}
void tukar(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}
void pengurut(int data[], int n){
   for (i=1;i<=n-1;i++) 
   { 
     swapped = false; 
     for(j=1;j<=n-i;j++){ 
        if(data[j]>data[j+1]){ 
           tukar(&data[j],&data[j+1]); 
           swapped=true; 
        } 
     } 
     if (swapped==false) 
        break; 
   } 
} 
int main(){
	
	int pilihan ;
	do {
		system("cls");
		cout<<"MENU PROGRAM"<<endl;
		cout<<"---------------------"<<endl;
		cout<<" 1 : Masukan Elemen Data"<<endl;
		cout<<" 2 : Lihat Elemen Data"<<endl;
		cout<<" 3 : Cari Elemen Data"<<endl;
		cout<<" 4 : Hapus Elemen Data"<<endl;		
		cout<<" 5 : Urutkan Elemen Data"<<endl;
		cout<<" 0 : Keluar Program"<<endl;
		cout<<"---------------------"<<endl;
		cout<<" Pilih Menu : " ; cin >>pilihan;
		cout<<"---------------------"<<endl;
		switch(pilihan){
			case 1: system("cls");
					input();
					break;					
			case 2: system("cls");
					view();
					break;
			case 3: system("cls");
					cari();
					break;
			case 4: system("cls");
					hapusmen();
					break;
			case 5: system("cls");
					pengurut(data,n);
					view();
					break;
		}getch();
	}while (pilihan!=0);
return 0;
}
