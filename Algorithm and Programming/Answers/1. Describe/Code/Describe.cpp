#include<stdio.h>
#include<string.h>

int main(){
	
	FILE *fp = fopen("file.csv", "r");
	
	if(fp == NULL){
		printf("File tidak ditemukan!\n");
		return 1;
	}
	
	int sizeBanyak = 3939, sizePanjang = 50;
	
	char location1[sizeBanyak][sizePanjang], location2[sizeBanyak][sizePanjang], type[sizeBanyak][sizePanjang], furnish[sizeBanyak][sizePanjang], rooms[sizeBanyak][sizePanjang], bathrooms[sizeBanyak][sizePanjang], carparks[sizeBanyak][sizePanjang];
	long long int price[sizeBanyak], area[sizeBanyak];

	for(int index = -1; index < sizeBanyak; index++){
		if(index == -1) {
			fscanf(fp, "%*[^\n]\n");
		} else {
			fscanf(fp, "\"%[^,],%[^,],%lld,%[^,],%[^,],%[^,],%[^,],%lld,%[^\"]\"\n", location1[index], location2[index], &price[index], rooms[index], bathrooms[index], carparks[index], type[index], &area[index], furnish[index]); fflush(stdin);
		}
	}
	
	fclose(fp);
	
	char kategori[sizeBanyak][sizePanjang], nameColumn[sizePanjang];
	long long int total[sizeBanyak], kategoriInt[sizeBanyak], index1 = 0, index2 = 0, kondisi = 0;
	
	printf("Name of column want to display: ");
	scanf("%s", nameColumn); getchar();
	
	if(strcmp(nameColumn, "loc1") == 0){
		for(int i = 0; i < sizeBanyak; i++)	{
			if(i == 0){
				strcpy(kategori[i], location1[i]);
				total[i]++;
				index1++;
				index2++;
				continue;
			} else {
				for(int j = 0; j < index1; j++){
					if(strcmp(kategori[j], location1[i]) == 0){
						total[j]++;
						kondisi = 1;
						break;
					}
				}
				if(kondisi == 0){
					strcpy(kategori[index2], location1[i]);
					total[index2]++;
					index1++;
					index2++;
				}
				kondisi = 0;
			}
		}
		
		int indexMaxFreq = 0;
		int indexMinFreq = 0;	
		long long int maximumFreq = total[indexMaxFreq];
		long long int minimumFreq = total[indexMinFreq];
		
		for(int i = 0; i < index2; i++){
			if(maximumFreq < total[i]) {
				maximumFreq = total[i];
				indexMaxFreq = i;
			} if (minimumFreq > total[i]) {
				minimumFreq = total[i];
				indexMinFreq = i;
			}
			printf("%s : %lld\n", kategori[i], total[i]);
		}
		printf("Maximum value: %s with frequency: %lld\n", kategori[indexMaxFreq], total[indexMaxFreq]);
		printf("Minimum value: %s with frequency: %lld\n", kategori[indexMinFreq], total[indexMinFreq]);
	}
	else if(strcmp(nameColumn, "loc2") == 0){
		for(int i = 0; i < sizeBanyak; i++)	{
			if(i == 0){
				strcpy(kategori[i], location2[i]);
				total[i]++;
				index1++;
				index2++;
				continue;
			} else {
				for(int j = 0; j < index1; j++){
					if(strcmp(kategori[j], location2[i]) == 0){
						total[j]++;
						kondisi = 1;
						break;
					}
				}
				if(kondisi == 0){
					strcpy(kategori[index2], location2[i]);
					total[index2]++;
					index1++;
					index2++;
				}
				kondisi = 0;
			}
		}
		
		int indexMaxFreq = 0;
		int indexMinFreq = 0;	
		long long int maximumFreq = total[indexMaxFreq];
		long long int minimumFreq = total[indexMinFreq];
		
		for(int i = 0; i < index2; i++){
			if(maximumFreq < total[i]) {
				maximumFreq = total[i];
				indexMaxFreq = i;
			} if (minimumFreq > total[i]) {
				minimumFreq = total[i];
				indexMinFreq = i;
			}
			printf("%s : %lld\n", kategori[i], total[i]);
		}
		printf("Maximum value: %s with frequency: %lld\n", kategori[indexMaxFreq], total[indexMaxFreq]);
		printf("Minimum value: %s with frequency: %lld\n", kategori[indexMinFreq], total[indexMinFreq]);
	}
	else if(strcmp(nameColumn, "room") == 0){
		for(int i = 0; i < sizeBanyak; i++)	{
			if(i == 0){
				strcpy(kategori[i], rooms[i]);
				total[i]++;
				index1++;
				index2++;
				continue;
			} else {
				for(int j = 0; j < index1; j++){
					if(strcmp(kategori[j], rooms[i]) == 0){
						total[j]++;
						kondisi = 1;
						break;
					}
				}
				if(kondisi == 0){
					strcpy(kategori[index2], rooms[i]);
					total[index2]++;
					index1++;
					index2++;
				}
				kondisi = 0;
			}
		}
		
		int indexMaxFreq = 0;
		int indexMinFreq = 0;	
		long long int maximumFreq = total[indexMaxFreq];
		long long int minimumFreq = total[indexMinFreq];
		
		for(int i = 0; i < index2; i++){
			if(maximumFreq < total[i]) {
				maximumFreq = total[i];
				indexMaxFreq = i;
			} if (minimumFreq > total[i]) {
				minimumFreq = total[i];
				indexMinFreq = i;
			}
			printf("%s : %lld\n", kategori[i], total[i]);
		}
		printf("Maximum value: %s with frequency: %lld\n", kategori[indexMaxFreq], total[indexMaxFreq]);
		printf("Minimum value: %s with frequency: %lld\n", kategori[indexMinFreq], total[indexMinFreq]);
	}
	else if(strcmp(nameColumn, "bathrooms") == 0){
		for(int i = 0; i < sizeBanyak; i++)	{
			if(i == 0){
				strcpy(kategori[i], bathrooms[i]);
				total[i]++;
				index1++;
				index2++;
				continue;
			} else {
				for(int j = 0; j < index1; j++){
					if(strcmp(kategori[j], bathrooms[i]) == 0){
						total[j]++;
						kondisi = 1;
						break;
					}
				}
				if(kondisi == 0){
					strcpy(kategori[index2], bathrooms[i]);
					total[index2]++;
					index1++;
					index2++;
				}
				kondisi = 0;
			}
		}
		
		int indexMaxFreq = 0;
		int indexMinFreq = 0;	
		long long int maximumFreq = total[indexMaxFreq];
		long long int minimumFreq = total[indexMinFreq];
		
		for(int i = 0; i < index2; i++){
			if(maximumFreq < total[i]) {
				maximumFreq = total[i];
				indexMaxFreq = i;
			} if (minimumFreq > total[i]) {
				minimumFreq = total[i];
				indexMinFreq = i;
			}
			printf("%s : %lld\n", kategori[i], total[i]);
		}
		printf("Maximum value: %s with frequency: %lld\n", kategori[indexMaxFreq], total[indexMaxFreq]);
		printf("Minimum value: %s with frequency: %lld\n", kategori[indexMinFreq], total[indexMinFreq]);
	}
	else if(strcmp(nameColumn, "carparks") == 0){
		for(int i = 0; i < sizeBanyak; i++)	{
			if(i == 0){
				strcpy(kategori[i], carparks[i]);
				total[i]++;
				index1++;
				index2++;
				continue;
			} else {
				for(int j = 0; j < index1; j++){
					if(strcmp(kategori[j], carparks[i]) == 0){
						total[j]++;
						kondisi = 1;
						break;
					}
				}
				if(kondisi == 0){
					strcpy(kategori[index2], carparks[i]);
					total[index2]++;
					index1++;
					index2++;
				}
				kondisi = 0;
			}
		}
		
		int indexMaxFreq = 0;
		int indexMinFreq = 0;	
		long long int maximumFreq = total[indexMaxFreq];
		long long int minimumFreq = total[indexMinFreq];
		
		for(int i = 0; i < index2; i++){
			if(maximumFreq < total[i]) {
				maximumFreq = total[i];
				indexMaxFreq = i;
			} if (minimumFreq > total[i]) {
				minimumFreq = total[i];
				indexMinFreq = i;
			}
			printf("%s : %lld\n", kategori[i], total[i]);
		}
		printf("Maximum value: %s with frequency: %lld\n", kategori[indexMaxFreq], total[indexMaxFreq]);
		printf("Minimum value: %s with frequency: %lld\n", kategori[indexMinFreq], total[indexMinFreq]);
	}
	else if(strcmp(nameColumn, "type") == 0){
		for(int i = 0; i < sizeBanyak; i++)	{
			if(i == 0){
				strcpy(kategori[i], type[i]);
				total[i]++;
				index1++;
				index2++;
				continue;
			} else {
				for(int j = 0; j < index1; j++){
					if(strcmp(kategori[j], type[i]) == 0){
						total[j]++;
						kondisi = 1;
						break;
					}
				}
				if(kondisi == 0){
					strcpy(kategori[index2], type[i]);
					total[index2]++;
					index1++;
					index2++;
				}
				kondisi = 0;
			}
		}
		
		int indexMaxFreq = 0;
		int indexMinFreq = 0;	
		long long int maximumFreq = total[indexMaxFreq];
		long long int minimumFreq = total[indexMinFreq];
		
		for(int i = 0; i < index2; i++){
			if(maximumFreq < total[i]) {
				maximumFreq = total[i];
				indexMaxFreq = i;
			} if (minimumFreq > total[i]) {
				minimumFreq = total[i];
				indexMinFreq = i;
			}
			printf("%s : %lld\n", kategori[i], total[i]);
		}
		printf("Maximum value: %s with frequency: %lld\n", kategori[indexMaxFreq], total[indexMaxFreq]);
		printf("Minimum value: %s with frequency: %lld\n", kategori[indexMinFreq], total[indexMinFreq]);
	}
	else if(strcmp(nameColumn, "furnish") == 0){
		for(int i = 0; i < sizeBanyak; i++)	{
			if(i == 0){
				strcpy(kategori[i], furnish[i]);
				total[i]++;
				index1++;
				index2++;
				continue;
			} else {
				for(int j = 0; j < index1; j++){
					if(strcmp(kategori[j], furnish[i]) == 0){
						total[j]++;
						kondisi = 1;
						break;
					}
				}
				if(kondisi == 0){
					strcpy(kategori[index2], furnish[i]);
					total[index2]++;
					index1++;
					index2++;
				}
				kondisi = 0;
			}
		}
		
		int indexMaxFreq = 0;
		int indexMinFreq = 0;	
		long long int maximumFreq = total[indexMaxFreq];
		long long int minimumFreq = total[indexMinFreq];
		
		for(int i = 0; i < index2; i++){
			if(maximumFreq < total[i]) {
				maximumFreq = total[i];
				indexMaxFreq = i;
			} if (minimumFreq > total[i]) {
				minimumFreq = total[i];
				indexMinFreq = i;
			}
			printf("%s : %lld\n", kategori[i], total[i]);
		}
		printf("Maximum value: %s with frequency: %lld\n", kategori[indexMaxFreq], total[indexMaxFreq]);
		printf("Minimum value: %s with frequency: %lld\n", kategori[indexMinFreq], total[indexMinFreq]);
	}
	else if(strcmp(nameColumn, "area") == 0){
		
		unsigned long long totalData = 0;
		
		for(int i = 0; i < sizeBanyak; i++)	{
			if(i == 0){
				kategoriInt[i] = area[i];
				totalData += area[i];
				total[i]++;
				index1++;
				index2++;
				continue;
			} else {
				for(int j = 0; j < index1; j++){
					if(kategoriInt[j] == area[i]){
						totalData += area[i];
						total[j]++;
						kondisi = 1;
						break;
					}
				}
				if(kondisi == 0){
					kategoriInt[index2] = area[i];
					totalData += area[i];
					total[index2]++;
					index1++;
					index2++;
				}
				kondisi = 0;
			}
		}
		
		int indexMaxVal = 0, indexMinVal = 0;	
		long long int maximumVal = kategoriInt[indexMaxVal], minimumVal = kategoriInt[indexMinVal];
		unsigned long long aveVal = totalData / sizeBanyak;
		
		for(int i = 0; i < index2; i++){
			if(maximumVal < kategoriInt[i]) {
				maximumVal = kategoriInt[i];
				indexMaxVal = i;
			} if (minimumVal > kategoriInt[i]) {
				minimumVal = kategoriInt[i];
				indexMinVal = i;
			}
		}
		printf("Minimum value: %lld\n", minimumVal);
		printf("Maximum value: %lld\n", maximumVal);
		printf("Average value: %llu\n", aveVal);
	}
	else if(strcmp(nameColumn, "price") == 0){
		
		unsigned long long totalData = 0;
		
		for(int i = 0; i < sizeBanyak; i++)	{
			if(i == 0){
				kategoriInt[i] = price[i];
				totalData += price[i];
				total[i]++;
				index1++;
				index2++;
				continue;
			} else {
				for(int j = 0; j < index1; j++){
					if(kategoriInt[j] == price[i]){
						totalData += price[i];
						total[j]++;
						kondisi = 1;
						break;
					}
				}
				if(kondisi == 0){
					kategoriInt[index2] = price[i];
					totalData += price[i];
					total[index2]++;
					index1++;
					index2++;
				}
				kondisi = 0;
			}
		}
		
		int indexMaxVal = 0, indexMinVal = 0;	
		long long int maximumVal = kategoriInt[indexMaxVal], minimumVal = kategoriInt[indexMinVal];
		unsigned long long aveVal = totalData / sizeBanyak;
		
		for(int i = 0; i < index2; i++){
			if(maximumVal < kategoriInt[i]) {
				maximumVal = kategoriInt[i];
				indexMaxVal = i;
			} if (minimumVal > kategoriInt[i]) {
				minimumVal = kategoriInt[i];
				indexMinVal = i;
			}
		}
		printf("Minimum value: %lld\n", minimumVal);
		printf("Maximum value: %lld\n", maximumVal);
		printf("Average value: %llu\n", aveVal);
	}
	
	return 0;
}
