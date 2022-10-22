#ifndef HEADER_H
#define HEADER_H

#pragma once

/*-----macros declaration-----*/

#define SIZE 30
#define BIGSIZE 80
#define VALID 1
#define INVALID 0

/*------structures defination----------*/
typedef struct Date
{
    int d;        
    int m;        
    int y;        
}date;

typedef struct Requests
{
	int requestID;
    int customerID;
    date requestDate;
    char description[SIZE];
    char requestStatus[SIZE];                 
}request;

typedef struct Customer {
	int custID;
	char phoneNum[SIZE];
	char firstName[SIZE];
    char lastName[SIZE];
    char address[BIGSIZE];
    char custType[SIZE];
}customer;

/*-----funtions------*/


extern void CRM_login();
extern void customer_login();
extern void manage_customer();
extern int generate_custID();
extern void add_customer();
extern void update_customer();
extern void delete_customer();
extern void manage_request();
extern int generate_requestID();
extern void add_request();
extern void update_request();
extern void delete_request();
extern void service_request();
extern void demo_request();
extern void complaint_request();
extern void report1();
extern void report2();
extern void report3();
extern void report4();
extern void totalreports();
extern void view_reports();

//funtions to validate
extern int isValidDate(int,int,int);
extern int isValidPass(char*);
extern int isValidCustID(int);
extern int isValidRequestID(int);
extern int isPhoneValid(char*);
extern int isNameValid(char*);



// Functions to update Customer Details
extern int changeNumber(int num);
extern int changeName(char* firstName, char* lastName);
extern int changeAddress(char* address);
extern int changeCustType(char* custType);

#endif