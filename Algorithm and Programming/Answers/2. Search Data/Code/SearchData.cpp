#include<stdio.h>
#include<string.h>
#define SIZEPANJANG 50
#define SIZEBANYAK 3939

struct kategori{
	char location1[SIZEBANYAK][SIZEPANJANG], location2[SIZEBANYAK][SIZEPANJANG], type[SIZEBANYAK][SIZEPANJANG], furnish[SIZEBANYAK][SIZEPANJANG], rooms[SIZEBANYAK][SIZEPANJANG], bathrooms[SIZEBANYAK][SIZEPANJANG], carparks[SIZEBANYAK][SIZEPANJANG];
	long long int price[SIZEBANYAK], area[SIZEBANYAK];
}categori;

char searching(char data[][SIZEPANJANG], char search[]){
	int kondisi = 0;
	for(int i = 0; i < SIZEBANYAK; i++){
		if(strstr(data[i], search) != NULL){
			printf("%-30s| %-15s| %-15lld| %-15s| %-15s| %-15s| %-15s| %-15lld| %-15s\n", categori.location1[i], categori.location2[i], categori.price[i], categori.rooms[i], categori.bathrooms[i], categori.carparks[i], categori.type[i], categori.area[i], categori.furnish[i]);
			kondisi = 1;
		}
	}
	if(kondisi == 0) printf("Pencarian tidak ditemukan!\n");
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
	
	char dataX[SIZEPANJANG], columnName[SIZEPANJANG];
	
	printf("Searching : ");
	scanf("%s in %s", dataX, columnName); getchar();
	
	if(strcmp(columnName, "loc1") == 0){
		searching(categori.location1, dataX);
	} else if(strcmp(columnName, "loc2") == 0){
		searching(categori.location2, dataX);
	} else if(strcmp(columnName, "room") == 0){
		searching(categori.rooms, dataX);
	}  else if(strcmp(columnName, "bathrooms") == 0){
		searching(categori.bathrooms, dataX);
	}  else if(strcmp(columnName, "carparks") == 0){
		searching(categori.carparks, dataX);
	}  else if(strcmp(columnName, "type") == 0){
		searching(categori.type, dataX);
	}  else if(strcmp(columnName, "furnish") == 0){
		searching(categori.furnish, dataX);
	} 
	
	return 0;
}
