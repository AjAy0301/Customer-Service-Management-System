#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <header.h>

int total_reports()
{
    FILE *fd = fopen("../data/demos.txt", "r");
    FILE *fc = fopen("../data/complaints.txt", "r");
    FILE *fs = fopen("../data/services.txt", "r");
   

    demo_req *d = (demo_req *)calloc(1, sizeof(demo_req));
    complaint_req *c = (complaint_req *)calloc(1, sizeof(complaint_req));
    service_req *s = (service_req *)calloc(1, sizeof(service_req));

    int demo_count=0;
    int complaint_count=0;
    int service_count=0;

    //counting number of demos
     while (fscanf(fd, "%d|%d-%d-%d|%s|%s\n", &d->requestID, &d->demoDate.d, &d->demoDate.m, &d->demoDate.y, d->address, d->suitableTime) != EOF)
        demo_count++;


    //counting number of services
    while (fscanf(fs, "%d|%d-%d-%d|%d|%d-%d-%d|%s\n", &s->requestID, &s->AMCdate.d, &s->AMCdate.m, &s->AMCdate.y, &s->AMCduration, &s->purchasedDate.m, &s->purchasedDate.m, &s->purchasedDate.y, s->productName) != EOF)
        service_count++;

    //counting number of complaints
    while (fscanf(fs, "%d|%s|%s|%s\n", &c->requestID, c->category, c->sub_category, c->description) != EOF)
       complaint_count++;

    fclose(fd);
    fclose(fs);
    fclose(fc);
        
    return EXIT_SUCCESS;
}

int view_reports()
{
    return EXIT_SUCCESS;
}
