#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int jumlah=3;
void garis(char kar, int jum);
void statistika();
void isidata(int n, char *nm_id[], int ni_id[]);
void tampildata(char *nm_td[], int ni_td[],int n);

int main(){
	statistika();
}

void garis(char kar, int jum){
	int i;
	for(i=0;i<jum;i++){
		printf("%c",kar);
	}
	printf("\n");
}

void statistika(){
	system("cls");
	char *nm_st[jumlah];
	int ni_st[jumlah];
	char c;
	do{
	isidata(jumlah,nm_st,ni_st);
	tampildata(nm_st,ni_st,jumlah);
	printf("Masukan data baru?(Y/N): ");
	c = getch();
	system("cls");
	}while((c=='Y')||(c=='y'));
	
}

void isidata(int n, char *nm_id[], int *ni_id){
	int i;
	char tes[20]="";
	for(i=1;i<=n;i++){
		printf("Peserta ke - %2d\n",i);
		printf("  Nama  : "); 
		gets(tes);
		nm_id[i-1] = (char*)malloc(sizeof(char)*10);
		strcpy(nm_id[i-1],tes);
		printf("  Nilai : ");scanf(" %d",&ni_id[i-1]);
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
		printf("%3d.| %-20s|%3d \n",i,nm_td[i],ni_td[i]);
	}
	garis('=',32);
}
