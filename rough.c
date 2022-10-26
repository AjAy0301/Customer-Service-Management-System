#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"include/header.h"

int del_req_desc(int req_ID, char* desc)
{
    FILE *tp = fopen("data/temp.txt", "a+");
    FILE *fp;

    if (strcmp(desc, "demo")==0)
    {
        //deleting demo for the request ID
        fp = fopen("data/demos.txt", "r");

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
        rename("data/temp.txt", "data/demos.txt");
        free(d);
    }
    else if (strcmp(desc, "service")==0)
    {
        //deleting service for the request ID
        fp = fopen("data/services.txt", "r");

        service_req *s = (service_req *)calloc(1, sizeof(service_req));

        while (!feof(fp))
        {
            fscanf(fp, "%d | %d-%d-%d | %d | %d-%d-%d | %[^\n]s", &s->requestID, &s->AMCdate.d, &s->AMCdate.m, &s->AMCdate.y, &s->AMCduration, &s->purchasedDate.m, &s->purchasedDate.m, &s->purchasedDate.y, s->productName);
            if (s->requestID != req_ID)
                fprintf(tp, "%d | %d-%d-%d | %d | %d-%d-%d | %s\n", s->requestID, s->AMCdate.d, s->AMCdate.m, s->AMCdate.y, s->AMCduration, s->purchasedDate.m, s->purchasedDate.m, s->purchasedDate.y, s->productName);
        }


        fclose(fp);
        fclose(tp);
        remove("data/services.txt");
        rename("data/temp.txt", "data/services.txt");
        free(s);
    }
    else
    {
        //deleting complaint for the request ID
        fp = fopen("data/complaints.txt", "r");

        complaint_req *c = (complaint_req *)calloc(1, sizeof(complaint_req));

        while (!feof(fp))
        {
            fscanf(fp, "%d | %s | %s | %[^\n]s", &c->requestID, c->category, c->sub_category, c->description);
            if (c->requestID != req_ID)
                fprintf(tp, "%d|%s|%s|%s\n", c->requestID, c->category, c->sub_category, c->description);
        }

        fclose(fp);
        fclose(tp);
        remove("data/complaints.txt");
        rename("data/temp.txt", "data/complaints.txt");
        free(c);
		
    }
	printf("hello");
   
    return EXIT_SUCCESS;
}

int main(){
    del_req_desc(105,"demo");
    return 0;
}