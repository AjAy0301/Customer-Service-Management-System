#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <header.h>

int manage_request()
{
    char ch;
    do
    {
        system("clear");

        printf("\t\t\t\t-----Ruquest Database-----\t\t\t\t");
        
        printf("\n\n1. Add Request");
        printf("\n2. Update Request");
        printf("\n3. Delete request");
        printf("\n4. Back to Main Menu");
        printf("\n5. Exit Application");

    enter_choice:
        printf("\nChoice- ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_request();
            break;
        case 2:
            update_request();
            break;
        case 3:
            delete_request();
            break;
        case 4:
            CRM_login();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice...");
            goto enter_choice;
        }
        printf("\ndo you want to continue manage request...(Y/N): ");
        getchar();
        scanf("%c",&ch);
    } while (ch == 'Y' || ch == 'y');

    return EXIT_SUCCESS;
}

/***********************Funtion to generate Request ID*************************/

int generate_requestID()
{

    int requestID;
    FILE *f = fopen("../data/requestIDgenerate.txt", "r");
    FILE *t = fopen("../data/temp.txt", "a");

    fscanf(f, "%d", &requestID);

    requestID = requestID + 1;

    fprintf(t, "%d", requestID);
    fclose(f);
    fclose(t);
    remove("../data/requestIDgenerate.txt");
    rename("../data/temp.txt", "../data/requestIDgenerate.txt");
    return requestID;
}

/***********************Funtion to add a request*************************/

int add_request()
{
    system("clear");
    printf("\nEnter the details for creating new request :- ");

    request *r = (request *)calloc(1, sizeof(request));
    r->requestID = generate_requestID();

enter_id:
    printf("\nEnter Customer ID: ");
    scanf("%d", &r->customerID);
    if (!isValidCustID(r->customerID))
    {
        printf("\nInvalid Customer ID ");
        goto enter_id;
    }

enter_date:
    printf("\nRequest Date (DD-MM-YY): ");
    scanf("%d-%d-%d", &r->requestDate.d, &r->requestDate.m, &r->requestDate.y);
    if (!isValidDate(r->requestDate.d, r->requestDate.m, r->requestDate.y))
    {
        printf("Invalid Date...Enter again");
        goto enter_date;
    }

    char *req_type = (char *)calloc(sizeof(char), SIZE);

    printf("\nPlease select the type of Request you have -");
    printf("\n1. Demo Request");
    printf("\n2. Service Request");
    printf("\n3. Complaint");

enter_choice:
    printf("\nEnter your choice: ");
    getchar();
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        strcpy(r->description, "demo");
        demo(r->requestID);
        break;
    case 2:
        strcpy(r->description, "service");
        service(r->requestID);
        break;
    case 3:
        strcpy(r->description, "complaint");
        complaint(r->requestID);
        break;

    default:
        printf("\nInvalid Choice..");
        goto enter_choice;
    }

    strcpy(r->requestStatus, "open");

    FILE *fp = fopen("../data/requests.txt", "a");
    fprintf(fp, "%d | %d | %d-%d-%d | %s | %s\n", r->requestID, r->customerID, r->requestDate.d, r->requestDate.m, r->requestDate.y, r->requestStatus, r->description);
    fclose(fp);
    return EXIT_SUCCESS;
}

/***********************Funtion to delete a request*************************/

int delete_request()
{
    system("clear");

    request *r = (request *)calloc(1, sizeof(request));

    int reqID;

    printf("\nEnter the request Id for the request to be deleted: ");
    scanf("%d", &reqID);

    if (!isValidRequestID(reqID))
    {
        printf("\nNo request in the database with this request ID");
        return EXIT_SUCCESS;
    }

    FILE *fp = fopen("../data/requests.txt", "r");
    FILE *tp = fopen("../data/temp.txt", "a+");

    while (!feof(fp))
    {
        fscanf(fp, "%d | %d | %d-%d-%d | %s | %s", &r->requestID, &r->customerID, &r->requestDate.d, &r->requestDate.m, &r->requestDate.y, r->requestStatus, r->description);
        if (r->requestID != reqID)
        {
            fprintf(tp, "%d | %d | %d-%d-%d | %s | %s\n", r->requestID, r->customerID, r->requestDate.d, r->requestDate.m, r->requestDate.y, r->requestStatus, r->description);
        }
        
    }

    fclose(fp);
    fclose(tp);
    
    remove("../data/requests.txt");
    rename("../data/temp.txt", "../data/requests.txt");

    printf("\nrequest with request ID %d is deleted successfully", reqID);

    free(r);
    return EXIT_SUCCESS;
}

/***********************Funtion to update details of existing request*************************/

int update_request()
{

    system("clear");

    int reqID;
    printf("\nEnter the Request ID for the request to be update: ");
    scanf("%d", &reqID);

    if (isValidRequestID(reqID))
    {
        request *r = (request *)calloc(1, sizeof(request));

        FILE *fp = fopen("../data/requests.txt", "r");
        FILE *tp = fopen("../data/temp.txt", "a+");

        while (!feof(fp))
        {
            fscanf(fp, "%d | %d | %d-%d-%d | %s | %s\n", &r->requestID, &r->customerID, &r->requestDate.d, &r->requestDate.m, &r->requestDate.y, r->requestStatus, r->description);

            if (r->requestID == reqID)
            {
                printf("\nSelect what you want update in the request: ");
                printf("\n1. Update request description");
                printf("\n2. Request Status");
                printf("\n3. Return Back");

            enter_choice:
                printf("\nEnter your choice: ");
                int opt;
                scanf("%d", &opt);

                switch (opt)
                {
                case 1:
                    printf("\nPlease select the type of Request you have -");
                    printf("\n1. Demo Request");
                    printf("\n2. Service Request");
                    printf("\n3. Complaint");

                entr_choice:
                    printf("\nEnter your choice: ");
                    getchar();
                    int choice;
                    scanf("%d", &choice);

                    char *desc = (char *)calloc(sizeof(char), SIZE);

                    switch (choice)
                    {
                    case 1:
                        strcpy(desc, "demo");
                        demo(reqID);
                        break;
                    case 2:
                        strcpy(desc, "service");
                        service(reqID);
                        break;
                    case 3:
                        strcpy(desc, "complaint");
                        complaint(reqID);
                        break;
                    default:
                        printf("\nInvalid Choice..");
                        goto enter_choice;
                    }

                    del_req_desc(r->requestID, r->description);
                    strcpy(r->description, desc);

                    break;

                case 2:

                    if (strcmp(r->requestStatus, "open")==0)
                        strcpy(r->requestStatus, "close");
                    else
                        strcpy(r->requestStatus, "open");

                    printf("\nRequest status changed successfully");
                    break;
                case 3:
                    return EXIT_SUCCESS;
                default:
                    printf("\nInvalid Choice...");
                    goto enter_choice;
                }
            }

            fprintf(tp, "%d | %d | %d-%d-%d | %s | %s\n", r->requestID, r->customerID, r->requestDate.d, r->requestDate.m, r->requestDate.y, r->requestStatus, r->description);
        }
        fclose(fp);
        fclose(tp);
        remove("../data/requests.txt");
        rename("../data/temp.txt", "../data/requests.txt");

        printf("\nrequest with request ID %d is updated successfully", reqID);

        free(r);
    }
    else
        printf("\nNo request with this Request ID in database...");

    return EXIT_SUCCESS;
}
