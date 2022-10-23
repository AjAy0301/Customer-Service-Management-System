#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <header.h>

int demo(int req_ID)
{
    demo_req *d = (demo_req *)calloc(1, sizeof(demo_req));

    d->requestID = req_ID;

    printf("\nEnter the date for the demo in dd-mm-yyy format");

enter_date:
    scanf("%d-%d-%d", &d->demoDate.d, &d->demoDate.m, &d->demoDate.y);
    if (!isValidDate(d->demoDate.d, d->demoDate.m, &d->demoDate.y))
    {
        printf("\nInvalid date enter again ");
        goto enter_date;
    }

    printf("\nEnter the address:");
    fgets(d->address, SIZE, stdin);

    printf("\nEnter a suitable time(HH:MM) ");
    fgets(d->suitableTime, SIZE, stdin);

    FILE *fp = fopen("../data/demos.txt", "a");
    fprintf(fp, "%d|%d-%d-%d|%s|%s\n", d->requestID, d->demoDate.d, d->demoDate.m, d->demoDate.y, d->address, d->suitableTime);
    fclose(fp);

    return EXIT_SUCCESS;
}

int complaint(int req_ID)
{
    complaint_req *c = (complaint_req *)calloc(1, sizeof(complaint_req));

    c->requestID = req_ID;

    printf("\nEnter category: ");
    fgets(c->category, SIZE, stdin);

    printf("\nEnter sub-category: ");
    fgets(c->sub_category, SIZE, stdin);

    printf("\nEnter description: ");
    fgets(c->description, SIZE, stdin);

    FILE *fp = fopen("../data/complaints.txt", "a");
    fprintf(fp, "%d|%s|%s|%s\n", c->requestID, c->category, c->sub_category, c->description);
    fclose(fp);

    return EXIT_SUCCESS;
}

int service(int req_ID)
{
    service_req *s = (service_req *)calloc(1, sizeof(service_req));

    s->requestID = req_ID;

    printf("\nEnter the details of your service request ");

    printf("\nAMC Date (in dd-mm-yyy): ");
amc_date:
    scanf("%d-%d-%d", &s->AMCdate.d, &s->AMCdate.m, &s->AMCdate.y);
    if (!isValidDate(s->AMCdate.d, s->AMCdate.m, s->AMCdate.y))
    {
        printf("\nInvalid date enter again ");
        goto amc_date;
    }

    printf("\nAMC Duration (in months):");
    scanf("%d", &s->AMCduration);

    printf("\nProduct purchased date (in dd-mm-yyy): ");
enter_date:
    scanf("%d-%d-%d", &s->purchasedDate.d, &s->purchasedDate.m, &s->purchasedDate.y);
    if (!isValidDate(s->purchasedDate.d, s->purchasedDate.m, s->purchasedDate.y))
    {
        printf("\nInvalid date enter again ");
        goto enter_date;
    }

    printf("\nProduct Name:");
    fgets(s->productName, SIZE, stdin);

    FILE *fp = fopen("../data/services.txt", "a");
    fprintf(fp, "%d|%d-%d-%d|%d|%d-%d-%d|%s\n", s->requestID, s->AMCdate.d, s->AMCdate.m, s->AMCdate.y, s->AMCduration, s->purchasedDate.m, s->purchasedDate.m, s->purchasedDate.y, s->productName);
    fclose(fp);

    return EXIT_SUCCESS;
}

int del_req_desc(int req_ID, char desc)
{
    FILE *tp = fopen("../data/temp.txt", "a+");
    FILE *fp;

    if (strcmp(desc, "demo"))
    {
        //deleting demo for the request ID
        fp = fopen("../data/demos.txt", "a+");

        demo_req *d = (demo_req *)calloc(1, sizeof(demo_req));

        while (fscanf(fp, "%d|%d-%d-%d|%s|%s\n", &d->requestID, &d->demoDate.d, &d->demoDate.m, &d->demoDate.y, d->address, d->suitableTime) != EOF)
        {
            if (!d->requestID == req_ID)
                fprintf(fp, "%d|%d-%d-%d|%s|%s\n", d->requestID, d->demoDate.d, d->demoDate.m, d->demoDate.y, d->address, d->suitableTime);
        }

        rewind(fp);
        rewind(tp);

        while (fscanf(fp, "%d|%d-%d-%d|%s|%s\n", &d->requestID, &d->demoDate.d, &d->demoDate.m, &d->demoDate.y, d->address, d->suitableTime) != EOF)
            fprintf(fp, "%d|%d-%d-%d|%s|%s\n", d->requestID, d->demoDate.d, d->demoDate.m, d->demoDate.y, d->address, d->suitableTime);
    }
    else if (strcmp(desc, "service"))
    {
        //deleting service for the request ID
        fp = fopen("../data/services.txt", "a+");

        service_req *s = (service_req *)calloc(1, sizeof(service_req));

        while (fscanf(fp, "%d|%d-%d-%d|%d|%d-%d-%d|%s\n", &s->requestID, &s->AMCdate.d, &s->AMCdate.m, &s->AMCdate.y, &s->AMCduration, &s->purchasedDate.m, &s->purchasedDate.m, &s->purchasedDate.y, s->productName) != EOF)
        {
            if (!s->requestID == req_ID)
                fprintf(fp, "%d|%d-%d-%d|%d|%d-%d-%d|%s\n", s->requestID, s->AMCdate.d, s->AMCdate.m, s->AMCdate.y, s->AMCduration, s->purchasedDate.m, s->purchasedDate.m, s->purchasedDate.y, s->productName);
        }

        rewind(fp);
        rewind(tp);

        while (fscanf(fp, "%d|%d-%d-%d|%d|%d-%d-%d|%s\n", &s->requestID, &s->AMCdate.d, &s->AMCdate.m, &s->AMCdate.y, &s->AMCduration, &s->purchasedDate.m, &s->purchasedDate.m, &s->purchasedDate.y, s->productName) != EOF)
            fprintf(fp, "%d|%d-%d-%d|%d|%d-%d-%d|%s\n", s->requestID, s->AMCdate.d, s->AMCdate.m, s->AMCdate.y, s->AMCduration, s->purchasedDate.m, s->purchasedDate.m, s->purchasedDate.y, s->productName);
    }
    else
    {
        //deleting complaint for the request ID
        fp = fopen("../data/complaints.txt", "a+");

        complaint_req *c = (complaint_req *)calloc(1, sizeof(complaint_req));

        while (fscanf(fp, "%d|%s|%s|%s\n", &c->requestID, c->category, c->sub_category, c->description) != EOF)
        {
            if (!c->requestID == req_ID)
                fprintf(fp, "%d|%s|%s|%s\n", c->requestID, c->category, c->sub_category, c->description);
        }

        rewind(fp);
        rewind(tp);

        while (fscanf(fp, "%d|%s|%s|%s\n", &c->requestID, c->category, c->sub_category, c->description) != EOF)
            fprintf(fp, "%d|%s|%s|%s\n", c->requestID, c->category, c->sub_category, c->description);
    }
    fclose(fp);
    fclose(tp);
    remove("../data/temp.txt");

    return EXIT_SUCCESS;
}
