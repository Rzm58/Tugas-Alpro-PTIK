#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

	//Deklarasi Menu
char biodata();
char pilihMenuUtama(), pilihMenuPerhitungan(), pilihMenuFisika(), pilihPerhitunganMtk();
void garis(char kar, int jum);
	//Deklarasi Matematika
int luasperkbs(int), volumebalok(int,int,int), luasperblk(int,int,int);
void kubus(int), balok(int,int,int);
int rusuk, panjang, lebar, tinggi;
	//Deklarasi Fisika
void menuFisika();
int energipotensial(int, int, int), tekananhidrostatis(int, int), geraklurusberaturan(int,int,int);
int masa, jarijari, kec, t, a, g=10;
	//Deklarasi Statistika
int jumlah=5;
char statistika();
void isidata(int n, char *nm_id[], int ni_id[]);
void tampildata(char *nm_td[], int ni_td[],int n);

int main(){
	char pilih=0;
	char response=0;
	do{
		pilih=pilihMenuUtama();
		if(pilih=='1'){
			biodata();
		}else if(pilih=='2'){
			system("cls");
			garis('=',70);
			printf("\t\t  Anda memasuki laman perhitungan\n");
			garis('=',70);
				//>>tempat submenu perhitungan
			//system("pause");
			char pilih1='0';
			do{
				pilih=pilihMenuPerhitungan();
				if(pilih=='1'){
					system("cls");
					char pilih='0';
					do{
							//>> tempat submenu perhitungan fisika
						char response2='0';
						pilih=pilihMenuFisika();
						if(pilih=='1'){
							do{
								system("cls");
								garis('=',70);
								printf("\t   Anda memasuki laman perhitungan Energi Potensial\n");
								garis('=',70);
								printf("Massa Benda(kg)\t\t: ");scanf(" %d",&masa); 
					     		printf("Ketinggian(m)\t\t: ");scanf(" %d",&tinggi);
					     		printf("Gravitasi(m/s^2)\t: %d\n",g);
					     		garis('=',70);
					     		printf("Energi Potensial \t: %d Joule\n",energipotensial(masa,g,tinggi));
					     		garis('=',70);
					     		printf("Ulangi perhitungan? (Y/N): ");
								response2 = getch();
								system("cls");
							}while((response2=='Y')||(response2=='y'));
						}else if(pilih=='2'){
							do{
								system("cls");
								garis('=',70);
								printf("\t   Anda memasuki laman perhitungan Tekanan Hidrostatis\n");
								garis('=',70);
								printf("Massa Jenis Benda(kg/m^3)\t: ");scanf(" %d",&masa);
								printf("Ketinggian(m)\t\t\t: ");scanf(" %d",&tinggi);
								garis('=',70);
								printf("Tekanan Hidrostatis\t\t: %d Joule\n",tekananhidrostatis(masa,tinggi));
								garis('=',70);
								printf("Ulangi perhitungan? (Y/N): ");
								response2 = getch();
								system("cls");
							}while((response2=='Y')||(response2=='y'));
						}else if(pilih=='3'){
							do{
								system("cls");
								garis('=',70);
								printf("\t   Anda memasuki laman perhitungan Gerak Lurus Beraturan\n");
								garis('=',70);
								printf("Kecepatan Awal      : ");scanf(" %d",&kec);
								printf("Percepatan          : ");scanf(" %d",&a);
								printf("Waktu               : ");scanf(" %d",&t);
								garis('=',70);
								printf("Jarak Yang Ditempuh : %d Joule\n",geraklurusberaturan(kec,a,t));
								garis('=',70);
								printf("Ulangi perhitungan? (Y/N): ");
								response2 = getch();
								system("cls");
							}while((response2=='Y')||(response2=='y'));
						}else if(pilih!='0'){
							system("cls");
							printf("Maaf, Pilhan Anda salah\n");
							system("pause");
						}
					}while(pilih!='0');
				}else if(pilih=='2'){
					system("cls");
					char pilih='0';
					do{
							//>> tempat submenu perhitungan matematika
						char response2='0';
						pilih=pilihPerhitunganMtk();
						if(pilih=='1'){
							system("cls");
							do{
								garis('=',70);
								printf("\t\tAnda memasuki laman Perhitungan Kubus\n");
								garis('=',70);
								printf("Panjang rusuk (m)\t: ");scanf("%d",&rusuk);
								garis('=',70);
								kubus(rusuk);
								garis('=',70);
								printf("Ulangi perhitungan? (Y/N): ");
								response2 = getch();
								system("cls");
							}while((response2=='Y')||(response2=='y'));
						}else if(pilih=='2'){
							do{
								system("cls");
								garis('=',70);
								printf("\t\tAnda memasuki laman perhitungan Balok\n");
								garis('=',70);
								printf("panjang balok (m)\t: ");scanf("%d",&panjang);
								printf("lebar balok (m)\t: ");scanf("%d",&lebar);
								printf("tinggi balok (m)\t: ");scanf("%d",&tinggi);
								garis('=',70);
								balok(panjang, lebar, tinggi);
								garis('=',70);
								printf("Ulangi perhitungan? (Y/N): ");
								response2 = getch();
								system("cls");
							}while((response2=='Y')||(response2=='y'));
						}else if(pilih!='0'){//mengatasi jika salah pilih
							system("cls");
							printf("Maaf, Pilhan Anda salah\n");
							system("pause");
						}
					}while(pilih!='0');
				}
			}while(pilih1!='0');
		}else if(pilih=='3'){
			int st=statistika();
			if((st!='Y')||(st!='y')){
				pilih=pilihMenuUtama();
			}
		}else if(pilih!='0'){//mengatasi jika salah pilih
			system("cls");
			printf("Maaf, Pilhan Anda salah\n");
			system("pause");
		}
	}while(pilih!='0');
}

void garis(char kar, int jum){
	int i;
	for(i=0;i<jum;i++){
		printf("%c",kar);
	}
	printf("\n");
}

char pilihMenuUtama(){
	char tpilih=0;
	system("cls");
	garis('=',70);
	printf("\t      Selamat datang di Program perhitungan khusus\n");
	garis('=',70);
	printf("Pilihan menu \n");
	printf("1. Menu 1 - BIODATA\n");
	printf("2. Menu 2 - PERHITUNGAN\n");
	printf("3. Menu 3 - STATISTIKA\n");
	printf("0. Exit \n");
	printf("Pilihan Anda : "); tpilih=getchar();
	return tpilih;
}

char biodata(){
	system("cls");
	garis('=',70);
	printf("\t\tAnda memasuki laman biodata\n");
			//>> tempat biodata
	garis('=',70);
	printf("Achmad Ahlar Ridha - 5235155571\n\n");
	printf("Febrianto Widyoutomo - 5235152263\n\n");
	printf("Ferdinand Louis\n\n");
	printf("Riza Maulana Halim\n\n");
	printf("Setya Achsanul Arief - 5235150721\n\n");
	garis('=',70);
	system("pause");
}

char pilihMenuPerhitungan(){// fungsi menampilkan menu dan mengembalikan pilihan user
	char tpilih=0;
	//system("cls");
	printf("Pilihan menu Perhitugan\n");
	printf("1. Menu 1 - FISIKA\n");
	printf("2. Menu 2 - MATEMATIKA\n");
	printf("3. Menu 3 - STATISTIKA\n");
	printf("0. Exit \n");
	printf("Pilihan Anda : ");scanf(" %c",&tpilih);
	return tpilih;
}

char pilihMenuFisika(){
	char tpilih=0;
	garis('=',70);
	printf("\t\t  Anda memasuki laman perhitungan FISIKA\n");
	garis('=',70);
	//system("cls");
	printf("Pilihan menu \n");
	printf("1. Menu 1 - Energi Potensial\n");
	printf("2. Menu 2 - Tekanan Hidrostatis\n");
	printf("3. Menu 3 - Gerak Lurus Beraturan\n");
	printf("0. Exit \n");
	printf("Pilihan Anda : ");scanf(" %c",&tpilih);
	return tpilih;
}

int energipotensial(int m, int g, int dh){
    return m*g*dh; //nilai yang akan dikembalikan adalah m*g*dh
    }
    
int tekananhidrostatis(int pro, int dh){
	return pro*g*dh;
	}
	
int geraklurusberaturan(int v, int a,int t){
	return ((v*t)+(0.5*a*t*t));
	}

char pilihPerhitunganMtk(){
	char tpilih=0;
	//system("cls");
	garis('=',70);
	printf("\t\t Anda memasuki laman perhitungan MATEMATIKA\n");
 	garis('=',70);
	printf("Pilihan menu \n");
	printf("1. Menu 1 - Kubus\n");
	printf("2. Menu 2 - Balok\n");
	printf("0. Exit \n");
	printf("Pilihan Anda : ");scanf(" %c",&tpilih);
	return tpilih;
}

void kubus(int x){
	printf("Luas permukaan kubus\t: %dm^2\n",x*x*6);
	printf("Volume kubus\t\t: %dm^3\n",x*x*x);
}

void balok(int p, int l, int t){
	printf("luas permukaan balok\t: %dm^2\n",2*(p*l+p*t+l*t));
	printf("volume balok\t\t: %dm^3\n",p*l*t);
}
char statistika(){
	system("cls");
	garis('=',70);
	printf("\t\t   Silahkan isi data\n");
 	garis('=',70);
	int n;
	int nm_st[jumlah][20];
	int ni_st[jumlah];
	char c;
	do{
		int i;
		for(i=1;i<=jumlah;i++){
			printf("Nama ke - %d: ",i); scanf(" %s",&nm_st[i-1]);
			printf("Nilai : ");scanf(" %d",&ni_st[i-1]);
		}
		printf("\n");
		garis('=',32);
		printf("%4s|%-21s|%5s","No.","Nama","Nilai\n");
		garis('=',32);
		for(i=0;i<jumlah;i++){
			printf("%3d.| %-20s|%3d \n",i+1,nm_st[i],ni_st[i]);
		}
		garis('=',32);
		printf("Masukan data baru?(Y/N): ");
		c = getch();
		system("cls");
	}while((c=='Y')||(c=='y'));
	return c;
}

void isidata(int n, char *nm_id[], int *ni_id){
	int i;
	char tes[20]="";
	for(i=1;i<=n;i++){
		printf("Nama ke - %d: ",i);
		gets(tes);
		nm_id[i-1] = (char*)malloc(sizeof(char)*10);
		strcpy(nm_id[i-1],tes);
		printf("Nilai : ");scanf(" %d",&ni_id[i-1]);
		getchar();
	}
}
/*
void isidata(char *nm_id[],int *ni_id, int n){   
    int i;
    char tes[20]="";
    for(i=0;i<n;i++){
    	printf("Peserta ke - %2d\n",i+1);
		printf("  Nama  : ");
		gets(tes);
		nm_id[i-1] = (char*)malloc(sizeof(char)*10);
		strcpy(nm_id[i],tes);
	    printf("  Nilai : ");scanf(" %d",&ni_id[i]);
	    getchar();//untuk menghapus pengaruh newline 
	}
}*/

void tampildata(char *nm_td[], int *ni_td, int n){
	int i;
	garis('=',32);
	printf("%4s|%-21s|%5s","No.","Nama","Nilai\n");
	garis('=',32);
	for(i=0;i<n;i++){
		printf("%3d.| %-20s|%3d \n",i+1,nm_td[i],ni_td[i]);
	}
	garis('=',32);
}
