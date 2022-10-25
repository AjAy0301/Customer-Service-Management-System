#include<stdio.h>
#include"include/header.h"

int generate_requestID()
{
    int requestID;
	FILE *f= fopen("data/requestIDgenerate.txt","r+");
    FILE *t = fopen("data/temp.txt", "a+");
	fscanf(f,"%d",&requestID);
	requestID=requestID+1;
    rewind(f);
	fprintf(f,"%d",requestID);
	fclose(f);
	return requestID;
}

int main(){
    generate_requestID();
    return 0;
}