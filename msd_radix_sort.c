/**
 * MSD Radix Sort"
 * name / ID Yoon Hyowon / 20120195
  **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CLOCKS_PER_MSEC CLOCKS_PER_SEC*1000

int main (int argc, char* argv[]) {
	if(argc!=3){
		puts("command line input error");
		return -1;
	}//command line input error
	
	FILE *src=fopen(argv[1], "rt");//file directory, name
	char *end;
	int size=strtol(argv[2],&end,10);//size of array(input)+start idx
	int idx=0;//index: start of the array
	int*arr=(int*)malloc(sizeof(int)*size);
	int check;
	int N;
	double duration;
	
	if(src==NULL){
		puts("error: failed to open the file");
		return -1;
	}//file open error

	if(*end){
		puts("command line input error: check the input format");
		return -1;
	}//if : input is not in a number format

	while(EOF!=fscanf(src,"%d",&arr[idx])){
		if(size==idx){
			break;
		}//read the first N integers
		idx++;
	}
	
	if(idx!=size){
		size=idx;//actual size of the array;
		arr=(int*)realloc(arr,sizeof(int)*size);
	}

	N=idx;
	duration=clock();
	msd_radix_sort(arr,size);
	duration=(double)((clock()-duration)/CLOCKS_PER_MSEC);
	check=arr[0];
	for(idx=0;idx<size;idx++){
		printf("%d\n",arr[idx]);
		if(check>arr[idx]){
			puts("not sorted");
			break;}
		check=arr[idx];
	}

	free(arr);
	fclose(src);
	return 0;
}
