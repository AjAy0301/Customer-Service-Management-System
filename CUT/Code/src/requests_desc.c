/*****************************************************************************************************************************************
 ** FILENAME  :  request_desc.c
 **
 ** DESCRIPTION : This File defines the all the request description funtions
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

/****************************************************************************************************************************************
 **FUNCTION NAME   :    demo
 **
 **DESCRIPTION     :    This function is used to adding a demo request description in the demos.txt file
 ***************************************************************************************************************************************/

int demo(int req_ID)
{
    demo_req *d = (demo_req *)calloc(1, sizeof(demo_req));

    d->requestID = req_ID;

    printf("\nEnter the date for the demo in dd-mm-yyyy format: ");

enter_date:
    scanf("%d-%d-%d", &d->demoDate.d, &d->demoDate.m, &d->demoDate.y);
    if (!isValidDate(d->demoDate.d, d->demoDate.m, d->demoDate.y))
    {
        printf("\nInvalid date enter again ");
        goto enter_date;
    }

    getchar();
    printf("\nEnter the address:");
    fgets(d->address, SIZE, stdin);
    d->address[strlen(d->address) - 1] = '\0';

    printf("\nEnter a suitable time(HH:MM) ");
    fgets(d->suitableTime, SIZE, stdin);
    d->suitableTime[strlen(d->suitableTime) - 1] = '\0';

    if (!isFileExists("../data/demos.txt"))
    {
        printf("\n\nData File missing....");
        return EXIT_SUCCESS;
    }

    FILE *fp = fopen("../data/demos.txt", "a");
    fprintf(fp, "%d | %d-%d-%d | %s | %s\n", d->requestID, d->demoDate.d, d->demoDate.m, d->demoDate.y, d->suitableTime, d->address);
    fclose(fp);

    free(d);

    return EXIT_SUCCESS;
}

/****************************************************************************************************************************************
 **FUNCTION NAME   :    complaint
 **
 **DESCRIPTION     :    This function is used to adding a complaint request description in the complaints.txt file
 ***************************************************************************************************************************************/

int complaint(int req_ID)
{
    complaint_req *c = (complaint_req *)calloc(1, sizeof(complaint_req));

    c->requestID = req_ID;

    getchar();
    printf("\nEnter category: ");
    fgets(c->category, SIZE, stdin);
    c->category[strlen(c->category) - 1] = '\0';

    printf("\nEnter sub-category: ");
    fgets(c->sub_category, SIZE, stdin);
    c->sub_category[strlen(c->sub_category) - 1] = '\0';

    printf("\nEnter description: ");
    fgets(c->description, SIZE, stdin);
    c->description[strlen(c->description) - 1] = '\0';

    if (!isFileExists("../data/complaints.txt"))
    {
        printf("\n\nData File missing....");
        return EXIT_SUCCESS;
    }

    FILE *fp = fopen("../data/complaints.txt", "a");
    fprintf(fp, "%d | %s | %s | %s\n", c->requestID, c->category, c->sub_category, c->description);
    fclose(fp);

    free(c);

    return EXIT_SUCCESS;
}

/****************************************************************************************************************************************
 **FUNCTION NAME   :    service
 **
 **DESCRIPTION     :    This function is used to adding a service request description in the services.txt file
 ***************************************************************************************************************************************/

int service(int req_ID)
{
    service_req *s = (service_req *)calloc(1, sizeof(service_req));

    s->requestID = req_ID;

    printf("\nEnter the details of your service request: ");

    printf("\nAMC Date (in dd-mm-yyyy): ");
amc_date:
    scanf("%d-%d-%d", &s->AMCdate.d, &s->AMCdate.m, &s->AMCdate.y);
    if (!isValidDate(s->AMCdate.d, s->AMCdate.m, s->AMCdate.y))
    {
        printf("\nInvalid date enter again ");
        goto amc_date;
    }

    printf("\nAMC Duration (in months): ");
    scanf("%d", &s->AMCduration);

    printf("\nProduct purchased date (in dd-mm-yyy): ");
enter_date:
    scanf("%d-%d-%d", &s->purchasedDate.d, &s->purchasedDate.m, &s->purchasedDate.y);
    if (!isValidDate(s->purchasedDate.d, s->purchasedDate.m, s->purchasedDate.y))
    {
        printf("\nInvalid date enter again ");
        goto enter_date;
    }

    getchar();
    printf("\nProduct Name: ");
    scanf("%s", s->productName);

    if (!isFileExists("../data/services.txt"))
    {
        printf("\n\nData File missing....");
        return EXIT_SUCCESS;
    }

    FILE *fp = fopen("../data/services.txt", "a");
    fprintf(fp, "%d | %d-%d-%d | %d | %d-%d-%d | %s\n", s->requestID, s->AMCdate.d, s->AMCdate.m, s->AMCdate.y, s->AMCduration, s->purchasedDate.m, s->purchasedDate.m, s->purchasedDate.y, s->productName);
    fclose(fp);

    free(s);

    return EXIT_SUCCESS;
}

/****************************************************************************************************************************************
 **FUNCTION NAME   :    del_req_desc
 **
 **DESCRIPTION     :    This function is used to deleting the request description from the respective desc type data file
 ***************************************************************************************************************************************/

int del_req_desc(int req_ID, char *desc)
{
    FILE *tp = fopen("../data/temp.txt", "a+");
    FILE *fp;

    if (strcmp(desc, "demo") == 0)
    {
        // deleting demo for the request ID

        if (!isFileExists("../data/demos.txt"))
        {
            printf("\n\nData File missing....");
            return EXIT_SUCCESS;
        }
        fp = fopen("../data/demos.txt", "r");

        demo_req *d = (demo_req *)calloc(1, sizeof(demo_req));

        while (fscanf(fp, "%d | %d-%d-%d | %s | %[^\n]s", &d->requestID, &d->demoDate.d, &d->demoDate.m, &d->demoDate.y, d->suitableTime, d->address) == 6)
        {
            if (d->requestID != req_ID)
                fprintf(tp, "%d | %d-%d-%d | %s | %s\n", d->requestID, d->demoDate.d, d->demoDate.m, d->demoDate.y, d->suitableTime, d->address);
        }

        fclose(fp);
        fclose(tp);
        remove("../data/demos.txt");
        rename("../data/temp.txt", "../data/demos.txt");
        free(d);
    }
    else if (strcmp(desc, "service") == 0)
    {
        // deleting service for the request ID

        if (!isFileExists("../data/services.txt"))
        {
            printf("\n\nData File missing....");
            return EXIT_SUCCESS;
        }
        fp = fopen("../data/services.txt", "r");

        service_req *s = (service_req *)calloc(1, sizeof(service_req));

        while (fscanf(fp, "%d | %d-%d-%d | %d | %d-%d-%d | %[^\n]s", &s->requestID, &s->AMCdate.d, &s->AMCdate.m, &s->AMCdate.y, &s->AMCduration, &s->purchasedDate.m, &s->purchasedDate.m, &s->purchasedDate.y, s->productName) == 9)
        {
            if (s->requestID != req_ID)
                fprintf(tp, "%d | %d-%d-%d | %d | %d-%d-%d | %s\n", s->requestID, s->AMCdate.d, s->AMCdate.m, s->AMCdate.y, s->AMCduration, s->purchasedDate.m, s->purchasedDate.m, s->purchasedDate.y, s->productName);
        }

        fclose(fp);
        fclose(tp);
        remove("../data/services.txt");
        rename("../data/temp.txt", "../data/services.txt");
        free(s);
    }
    else
    {
        // deleting complaint for the request ID

        if (!isFileExists("../data/complaints.txt"))
        {
            printf("\n\nData File missing....");
            return EXIT_SUCCESS;
        }
        fp = fopen("data/complaints.txt", "r");

        complaint_req *c = (complaint_req *)calloc(1, sizeof(complaint_req));

        while (fscanf(fp, "%d | %s | %s | %[^\n]s", &c->requestID, c->category, c->sub_category, c->description) == 4)
        {
            if (c->requestID != req_ID)
                fprintf(tp, "%d | %s | %s | %s\n", c->requestID, c->category, c->sub_category, c->description);
        }

        fclose(fp);
        fclose(tp);
        remove("../data/complaints.txt");
        rename("../data/temp.txt", "../data/complaints.txt");
        free(c);
    }

    return EXIT_SUCCESS;
}

/****************************************************************************************************************************************
 **FUNCTION NAME   :    display_request_desc
 **
 **DESCRIPTION     :    This function is used for displaying all the request description file in the database.
 ***************************************************************************************************************************************/

int display_request_desc()
{
    printf("\n\nSelect which request description data to display\n");
    printf("\n\n1. Demo Requests");
    printf("\n\n2. Service Requests");
    printf("\n\n3. Complaints");

    printf("\n\n\nEnter your choice- ");
    char choice;
    scanf("%c", &choice);

    demo_req *d = (demo_req *)calloc(1, sizeof(demo_req));
    service_req *s = (service_req *)calloc(1, sizeof(service_req));
    complaint_req *c = (complaint_req *)calloc(1, sizeof(complaint_req));

    switch (choice)
    {
    case '1':

        if (!isFileExists("data/demos.txt"))
        {
            printf("\n\nData File missing....");
            return EXIT_SUCCESS;
        }

        FILE *fd = fopen("data/demos.txt", "r");

        printf("%-10s%-20s%-20s%s\n\n", "Request_ID", "Demo Date", "Suitable Time", "Address");

        while (!feof(fd))
        {
            fscanf(fd, "%d | %d-%d-%d | %s | %[^\n]s", &d->requestID, &d->demoDate.d, &d->demoDate.m, &d->demoDate.y, d->suitableTime, d->address);
            printf("%-10d%d/%d/%-20d%-20s%s\n", d->requestID, d->demoDate.d, d->demoDate.m, d->demoDate.y, d->suitableTime, d->address);
        }

        fclose(fd);
        break;

    case '2':

        if (!isFileExists("data/services.txt"))
        {
            printf("\n\nData File missing....");
            return EXIT_SUCCESS;
        }

        FILE *fs = fopen("data/services.txt", "r");

        printf("%-20s%-20s%-20s%-20s%s\n\n", "Request ID", "AMC Date", "AMC duration", "Purchased Date", "Product Name");

        while (!feof(fs))
        {
            fscanf(fs, "%d | %d-%d-%d | %d | %d-%d-%d | %[^\n]s", &s->requestID, &s->AMCdate.d, &s->AMCdate.m, &s->AMCdate.y, &s->AMCduration, &s->purchasedDate.d, &s->purchasedDate.m, &s->purchasedDate.y, s->productName);
            printf("%-20d%d/%d/%-20d%-20d/%d/%d/%-20d%s\n", s->requestID, s->AMCdate.d, s->AMCdate.m, s->AMCdate.y, s->AMCduration, s->purchasedDate.d, s->purchasedDate.m, s->purchasedDate.y, s->productName);
        }

        fclose(fs);
        break;

    case '3':

        if (!isFileExists("data/complaints.txt"))
        {
            printf("\n\nData File missing....");
            return EXIT_SUCCESS;
        }

        FILE *fc = fopen("data/complaints.txt", "r");

        printf("%-10s%-20s%-20s%s\n\n", "Request ID", "Category", "Sub-category", "Description");

        while (!feof(fc))
        {
            fscanf(fc, "%d | %s | %s | %[^\n]s", &c->requestID, c->category, c->sub_category, c->description);
            printf("%-10d%-20s%-20s%s\n", c->requestID, c->category, c->sub_category, c->description);
        }

        fclose(fc);
        break;

    default:
        printf("\nInvalid Choice....");
        break;
    }
    return 0;
}