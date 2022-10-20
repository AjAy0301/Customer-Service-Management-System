#include<macros.h>
typedef struct Date{
    int date, month, year;
}date;
typedef struct Requests
{
	int requestID, customerID;
    date requestDate;
    char description[30];
    bool requestStatus;         // 0 for closed and 1 for the open

}request;

typedef struct Customer 
{
	int custID;
	long int phoneNum;
	char firstName[SIZE],lastName[SIZE],address[BIGSIZE],custType[SIZE];
}customer;
