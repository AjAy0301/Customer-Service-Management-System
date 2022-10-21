#include<macros.h>

typedef struct Date{
    int d;         //date
    int m;         //month
    int y;        //year
}date;

typedef struct Requests{
	int requestID;
    int customerID;
    date requestDate;
    char description[SIZE];
    char requestStatus[SIZE];         
}request;

typedef struct Customer {
	int custID;
	int phoneNum;
	char firstName[SIZE];
    char lastName[SIZE];
    char address[BIGSIZE];
    char custType[SIZE];
}customer;
