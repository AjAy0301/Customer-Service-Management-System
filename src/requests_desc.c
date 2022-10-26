#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <header.h>


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
    d->address[strlen(d->address)-1]='\0';

    printf("\nEnter a suitable time(HH:MM) ");
    fgets(d->suitableTime, SIZE, stdin);
    d->suitableTime[strlen(d->suitableTime)-1]='\0';


    FILE *fp = fopen("../data/demos.txt", "a");
    fprintf(fp, "%d | %d-%d-%d | %s | %s\n", d->requestID, d->demoDate.d, d->demoDate.m, d->demoDate.y, d->suitableTime, d->address);
    fclose(fp);

    free(d);

    return EXIT_SUCCESS;
}

int complaint(int req_ID)
{
    complaint_req *c = (complaint_req *)calloc(1, sizeof(complaint_req));

    c->requestID = req_ID;

    getchar();
    printf("\nEnter category: ");
    fgets(c->category, SIZE, stdin);
    c->category[strlen(c->category)-1] = '\0';

    printf("\nEnter sub-category: ");
    fgets(c->sub_category, SIZE, stdin);
    c->sub_category[strlen(c->sub_category)-1] = '\0';

    printf("\nEnter description: ");
    fgets(c->description, SIZE, stdin);
    c->description[strlen(c->description)-1] = '\0';

    FILE *fp = fopen("../data/complaints.txt", "a");
    fprintf(fp, "%d | %s | %s | %s\n", c->requestID, c->category, c->sub_category, c->description);
    fclose(fp);

    free(c);

    return EXIT_SUCCESS;
}

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
    scanf("%s",s->productName);

    FILE *fp = fopen("../data/services.txt", "a");
    fprintf(fp, "%d | %d-%d-%d | %d | %d-%d-%d | %s\n", s->requestID, s->AMCdate.d, s->AMCdate.m, s->AMCdate.y, s->AMCduration, s->purchasedDate.m, s->purchasedDate.m, s->purchasedDate.y, s->productName);
    fclose(fp);

    free(s);

    return EXIT_SUCCESS;
}

int del_req_desc(int req_ID, char* desc)
{
    FILE *tp = fopen("../data/temp.txt", "a+");
    FILE *fp;

    if (strcmp(desc, "demo")==0)
    {
        //deleting demo for the request ID
        fp = fopen("../data/demos.txt", "r");

        demo_req *d = (demo_req *)calloc(1, sizeof(demo_req));

        while (!feof(fp))
        {
            fscanf(fp, "%d | %d-%d-%d | %s | %[^\n]s", &d->requestID, &d->demoDate.d, &d->demoDate.m, &d->demoDate.y, d->suitableTime, d->address);
            if (d->requestID != req_ID)
                fprintf(tp, "%d | %d-%d-%d | %s | %s\n", d->requestID, d->demoDate.d, d->demoDate.m, d->demoDate.y, d->suitableTime, d->address);
        }

        fclose(fp);
        fclose(tp);
        remove("..data/demos.txt");
        rename("../data/temp.txt", "../data/demos.txt");
        free(d);
    }
    else if (strcmp(desc, "service")==0)
    {
        //deleting service for the request ID
        fp = fopen("../data/services.txt", "r");

        service_req *s = (service_req *)calloc(1, sizeof(service_req));

        while (!feof(fp))
        {
            fscanf(fp, "%d | %d-%d-%d | %d | %d-%d-%d | %[^\n]s", &s->requestID, &s->AMCdate.d, &s->AMCdate.m, &s->AMCdate.y, &s->AMCduration, &s->purchasedDate.m, &s->purchasedDate.m, &s->purchasedDate.y, s->productName);
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
        //deleting complaint for the request ID
        fp = fopen("../data/complaints.txt", "r");

        complaint_req *c = (complaint_req *)calloc(1, sizeof(complaint_req));

        while (!feof(fp))
        {
            fscanf(fp, "%d | %s | %s | %[^\n]s", &c->requestID, c->category, c->sub_category, c->description);
            if (c->requestID != req_ID)
                fprintf(tp, "%d|%s|%s|%s\n", c->requestID, c->category, c->sub_category, c->description);
        }

        fclose(fp);
        fclose(tp);
        remove("../data/complaints.txt");
        rename("../data/temp.txt", "../data/complaints.txt");
        free(c);
    }
   
    return EXIT_SUCCESS;
}