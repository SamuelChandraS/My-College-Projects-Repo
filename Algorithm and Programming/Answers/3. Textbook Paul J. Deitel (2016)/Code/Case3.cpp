#include<stdio.h>
#include<conio.h>
#include<string.h>
#define SIZEPANJANG 50
#define SIZEBANYAK 3939

struct kategori{
	char location1[SIZEBANYAK][SIZEPANJANG], location2[SIZEBANYAK][SIZEPANJANG], type[SIZEBANYAK][SIZEPANJANG], furnish[SIZEBANYAK][SIZEPANJANG], rooms[SIZEBANYAK][SIZEPANJANG], bathrooms[SIZEBANYAK][SIZEPANJANG], carparks[SIZEBANYAK][SIZEPANJANG];
	long long int price[SIZEBANYAK], area[SIZEBANYAK];
}categori;

void swap(char dataA[], char dataB[]){
	char temp[SIZEPANJANG];
	strcpy(temp, dataA);
	strcpy(dataA, dataB);
	strcpy(dataB, temp);
}

void swapInt(long long int *a, long long int *b){
	long long int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(char location1[][SIZEPANJANG], char location2[][SIZEPANJANG], long long int price[SIZEBANYAK], char rooms[][SIZEPANJANG], char bathrooms[][SIZEPANJANG], char carparks[][SIZEPANJANG], char type[][SIZEPANJANG], long long int area[SIZEBANYAK], char furnish[][SIZEPANJANG], int low, int high){
	int pivot = high, j = low-1;
	
	for(int i = low; i <= high-1; i++){
		if(strcmp(location1[i], location1[pivot]) == -1){
			j++;
			swap(location1[j], location1[i]);
			swap(location2[j], location2[i]);
			swapInt(&price[j], &price[i]);
			swap(rooms[j], rooms[i]);
			swap(bathrooms[j], bathrooms[i]);
			swap(carparks[j], carparks[i]);
			swap(type[j], type[i]);
			swapInt(&area[j], &area[i]);
			swap(furnish[j], furnish[i]);
		}
	}
	swap(location1[j+1], location1[pivot]);
	swap(location2[j+1], location2[pivot]);
	swapInt(&price[j+1], &price[pivot]);
	swap(rooms[j+1], rooms[pivot]);
	swap(bathrooms[j+1], bathrooms[pivot]);
	swap(carparks[j+1], carparks[pivot]);
	swap(type[j+1], type[pivot]);
	swapInt(&area[j+1], &area[pivot]);
	swap(furnish[j+1], furnish[pivot]);
	return j+1;
}

void quickSort(char location1[][SIZEPANJANG], char location2[][SIZEPANJANG], long long int price[SIZEBANYAK], char rooms[][SIZEPANJANG], char bathrooms[][SIZEPANJANG], char carparks[][SIZEPANJANG], char type[][SIZEPANJANG], long long int area[SIZEBANYAK], char furnish[][SIZEPANJANG], int low, int high){
	if(low <= high){
		int mid = partition(location1, location2, price, rooms, bathrooms, carparks, type, area, furnish, low, high);
		
		quickSort(location1, location2, price, rooms, bathrooms, carparks, type, area, furnish, low, mid-1);
		quickSort(location1, location2, price, rooms, bathrooms, carparks, type, area, furnish, mid+1, high);
	}
}

int main(){
	
	FILE *fp = fopen("file.csv", "r");
	
	if(fp == NULL){
		printf("File tidak ditemukan!\n");
		return 1;
	}

	for(int index = -1; index < SIZEBANYAK; index++){
		if(index == -1) {
			fscanf(fp, "%*[^\n]\n");
		} else {
			fscanf(fp, "\"%[^,],%[^,],%lld,%[^,],%[^,],%[^,],%[^,],%lld,%[^\"]\"\n", categori.location1[index], categori.location2[index], &categori.price[index], categori.rooms[index], categori.bathrooms[index], categori.carparks[index], categori.type[index], &categori.area[index], categori.furnish[index]); fflush(stdin);
		}
	}
	
	fclose(fp);
	
	printf("Tekan apapun untuk mulai mengurutkan:\n"); getch();
	
	quickSort(categori.location1, categori.location2, categori.price, categori.rooms, categori.bathrooms, categori.carparks, categori.type, categori.area, categori.furnish, 0, SIZEBANYAK-1);
	
	for(int i = 0; i < SIZEBANYAK; i++){
		printf("%-30s| %-15s| %-15lld| %-15s| %-15s| %-15s| %-15s| %-15lld| %-15s\n", categori.location1[i], categori.location2[i], categori.price[i], categori.rooms[i], categori.bathrooms[i], categori.carparks[i], categori.type[i], categori.area[i], categori.furnish[i]);
	}
		
	return 0;
}
