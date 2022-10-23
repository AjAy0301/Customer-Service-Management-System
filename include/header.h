#ifndef HEADER_H
#define HEADER_H

#pragma once

/*-----Macros-----*/

#define SIZE 30
#define BIGSIZE 80
#define VALID 1
#define INVALID 0

/*-----Structures Defination-----*/

typedef struct Customer
{
    int custID;
    char phoneNum[SIZE];
    char firstName[SIZE];
    char lastName[SIZE];
    char address[BIGSIZE];
    char custType[SIZE];
} customer;

typedef struct Date
{
    int d;
    int m;
    int y;
} date;

typedef struct Requests
{
    int requestID;
    int customerID;
    date requestDate;
    char description[SIZE];
    char requestStatus[SIZE];
} request;

typedef struct Demo_requests
{
    int requestID;
    date demoDate;
    char address[SIZE];
    char suitableTime[SIZE];
} demo_req;

typedef struct Service_requests
{
    int requestID;
    int AMCduration;
    date AMCdate;
    date purchasedDate;
    char productName[SIZE];
} service_req;

typedef struct Complaint_requests
{
    int requestID;
    char category[SIZE];
    char sub_category[SIZE];
    char description[SIZE];
} complaint_req;

/*-----Funtions Declaration-----*/

extern int CRM_login();
extern int customer_login();

// funtions to manage customers
extern int manage_customer();
extern int generate_custID();
extern int add_customer();
extern int update_customer();
extern int delete_customer();

// funtions to manage requests
extern int manage_request();
extern int generate_requestID();
extern int add_request();
extern int update_request();
extern int delete_request();

// funtions for managing demo, service and complaints
extern int service(int);
extern int demo(int);
extern int complaint(int);
extern int del_req_desc(int, char);

// funtions to view and generate reports
extern int totalreports();
extern int view_reports();

// funtions for validations
extern int isValidDate(int, int, int);
extern int isValidPass(char *);
extern int isValidCustID(int);
extern int isValidRequestID(int);
extern int isPhoneValid(char *);
extern int isNameValid(char *);

#endif