#include<stdio.h>
#include"include/header.h"

int main(){
    customer C;
    FILE * fp = fopen("data/customers.txt", "a+");
    printf("Working \t");
    while(!feof(fp)){
        fscanf(fp, "%d | %s | %s | %s | %s | %[^\n]s", &C.custID, C.firstName, C.lastName, C.phoneNum, C.custType, C.address);
        printf("Working \t");
        printf("%d | %s | %s | %s | %s | %s\n", C.custID, C.firstName, C.lastName, C.phoneNum, C.custType, C.address);
    }
}