/*****************************************************************************************************************************************
 ** FILENAME  :  reports.c
 **
 ** DESCRIPTION : This File defines the function which are used to manage the customer deatils in database
 **
 ** Revision History :
 ** DATE                         NAME                                         REASON
 ** ---------------------------------------------------------------------------------------
 ** 21 October 2022               Ajay Kumar                                To make main.c file
 ** 25 October 2022               Hrishikesh                                To make changes in file header
 ****************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <header.h>

// variables for storing the count of demo, service and complaints
int demo_count = 0;
int complaint_count = 0;
int service_count = 0;

/****************************************************************************************************************************************
 **FUNCTION NAME   :    total_reports
 **
 **DESCRIPTION     :    This function is used to count the total number demo requests, services requests and complaints
 ***************************************************************************************************************************************/

int total_reports()
{

    FILE *fd = fopen("../data/demos.txt", "r");
    FILE *fc = fopen("../data/complaints.txt", "r");
    FILE *fs = fopen("../data/services.txt", "r");

    demo_req *d = (demo_req *)calloc(1, sizeof(demo_req));
    complaint_req *c = (complaint_req *)calloc(1, sizeof(complaint_req));
    service_req *s = (service_req *)calloc(1, sizeof(service_req));

    // counting number of demos
    while (!feof(fd))
    {
        fscanf(fd, "%d | %d-%d-%d | %s | %[^\n]s", &d->requestID, &d->demoDate.d, &d->demoDate.m, &d->demoDate.y, d->suitableTime, d->address);
        demo_count++;
    }

    // counting number of services
    while (!feof(fs))
    {
        fscanf(fs, "%d | %d-%d-%d | %d | %d-%d-%d | %[^\n]s", &s->requestID, &s->AMCdate.d, &s->AMCdate.m, &s->AMCdate.y, &s->AMCduration, &s->purchasedDate.d, &s->purchasedDate.m, &s->purchasedDate.y, s->productName);
        service_count++;
    }

    // counting number of complaints
    while (!feof(fc))
    {
        fscanf(fc, "%d | %s | %s | %[^\n]s", &c->requestID, c->category, c->sub_category, c->description);
        complaint_count++;
    }

    fclose(fd);
    fclose(fs);
    fclose(fc);

    return EXIT_SUCCESS;
}

/****************************************************************************************************************************************
 **FUNCTION NAME   :    view_report
 **
 **DESCRIPTION     :    This function is used to view the specific report for the given date
 ***************************************************************************************************************************************/

int view_reports()
{

    system("clear");

    printf("\nTotal Demo Requests: %d\t\tTotal Service Requests: %d\t\tTotal Complaints: %d\n\n", demo_count, service_count, complaint_count);
    printf("\n\nSelect which report you want view: ");
    printf("\n\n\n1. Demos scheduled ");
    printf("\n\n2. No of complaints not addressed");
    printf("\n\n3. How many service calls are closed for given customer");
    printf("\n\n4. List of service calls closed last month");
    printf("\n\n\nenter your choice: ");

    char choice;
    scanf("%s", &choice);
   
    int dd, mm, yy;
    int service_call_closed = 0;

    request *r = (request *)calloc(1, sizeof(request));

    FILE *fd = fopen("../data/demos.txt", "r");
    FILE *fc = fopen("../data/complaints.txt", "r");
    FILE *fs = fopen("../data/services.txt", "r");
    FILE *fp = fopen("../data/requests.txt", "r");

    demo_req *d = (demo_req *)calloc(1, sizeof(demo_req));
    complaint_req *c = (complaint_req *)calloc(1, sizeof(complaint_req));
    service_req *s = (service_req *)calloc(1, sizeof(service_req));

    switch (choice)
    {
    case '1':

        printf("\nEnter Date (dd-mm-yyyy): ");
        scanf("%d-%d-%d", &dd, &mm, &yy);

        printf("\nDemos scheduled on %d-%d-%d are-\n", dd, mm, yy);

        while (!feof(fd))
        {
            fscanf(fd, "%d | %d-%d-%d | %s | %[^\n]s", &d->requestID, &d->demoDate.d, &d->demoDate.m, &d->demoDate.y, d->suitableTime, d->address);
            if (dd == d->demoDate.d && mm == d->demoDate.m && yy == d->demoDate.y)
                printf("%d | %d-%d-%d | %s | %s\n", d->requestID, d->demoDate.d, d->demoDate.m, d->demoDate.y, d->suitableTime, d->address);
        }

        fclose(fd);
        break;

    case '2':

        printf("\nEnter Date (dd-mm-yyyy): ");
        scanf("%d-%d-%d", &dd, &mm, &yy);

        request *r = (request *)calloc(1, sizeof(request));

        int not_addressed_complaints = 0;

        while (!feof(fp))
        {
            fscanf(fp, "%d | %d | %d-%d-%d | %s | %s", &r->requestID, &r->customerID, &r->requestDate.d, &r->requestDate.m, &r->requestDate.y, r->requestStatus, r->description);
            if ((dd == r->requestDate.d && mm == r->requestDate.m && yy == r->requestDate.y) && strcmp(r->requestStatus, "open") == 0 && strcmp(r->description, "complaint") == 0)
                not_addressed_complaints++;
        }

        printf("\nNumber of complaints not addressed for %d-%d-%d are- %d\n", dd, mm, yy, not_addressed_complaints);
        fclose(fp);
        break;

    case '3':
        printf("Enter Customer ID of the customer:");
            
        int customerID;
        scanf("%d", &customerID);

        while (!feof(fp))
        {
            fscanf(fp, "%d | %d | %d-%d-%d | %s | %s", &r->requestID, &r->customerID, &r->requestDate.d, &r->requestDate.m, &r->requestDate.y, r->requestStatus, r->description);
            if (r->customerID == customerID && strcmp(r->description, "service") == 0 && strcmp(r->requestStatus, "closed") == 0) // reeor can be while strcmp need check it again
                service_call_closed++;
        }

        printf("\nNumber of service calls closed for customer %d are %d ", customerID, service_call_closed);
        fclose(fp);
        break;

    case '4':
        printf("Enter current month and year in mm-yyyy format: ");
            
        int month, year;    
        scanf("%d-%d", &month, &year);

        while (!feof(fp))
        {
            fscanf(fp, "%d | %d | %d-%d-%d | %s | %s", &r->requestID, &r->customerID, &r->requestDate.d, &r->requestDate.m, &r->requestDate.y, r->requestStatus, r->description);
            if (r->requestDate.y == year && r->requestDate.m == month - 1 && strcmp(r->requestStatus, "closed") == 0) // reeor can be while strcmp need check it again
                service_call_closed++;
        }

        printf("\nNumber of service calls closed last month are %d ", service_call_closed);
        fclose(fp);
        break;

    default:
        printf("\nInvalid Choice...");
        break;
    }

    return EXIT_SUCCESS;
}
