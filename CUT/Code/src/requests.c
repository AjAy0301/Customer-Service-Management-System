/*****************************************************************************************************************************************
 ** FILENAME  :  customers.c
 **
 ** DESCRIPTION : This File defines the function which are used to manage all the requests in database
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

int manage_request()
{
    char ch;
    do
    {
        system("clear");
        printf("\n*******************************************************\n");
        printf("*                  Request Database                       *");
        printf("\n*******************************************************\n");

        printf("\n\n1. Add Request");
        printf("\n\n2. Update Request");
        printf("\n\n3. Delete request");
        printf("\n\n4. View all Requests");
        printf("\n\n5. Back to previous Menu");
        printf("\n\n6. Exit Application");

    enter_choice:
        printf("\n\n\nChoice- ");
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
            display_request();
            break;
        case 5:
            crm_menu();
        case 6:
            exit(0);
        default:
            printf("Invalid Choice...");
            goto enter_choice;
        }
        printf("\ndo you want to continue manage request...(Y/N): ");
        getchar();
        ch = getchar();
    } while (ch == 'Y' || ch == 'y');

    return EXIT_SUCCESS;
}

/****************************************************************************************************************************************
 **FUNCTION NAME   :    generate_requestID
 **
 **DESCRIPTION     :    This function is used to auto generate the Request ID.
 ***************************************************************************************************************************************/

int generate_requestID()
{

    int requestID;

    if (!isFileExists("../data/requestIDgenerate.txt"))
    {
        printf("\n\nData File missing....");
        return EXIT_SUCCESS;
    }

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

/****************************************************************************************************************************************
 **FUNCTION NAME   :    add_request
 **
 **DESCRIPTION     :    This function is used to add a request in the database.
 ***************************************************************************************************************************************/

int add_request()
{
    system("clear");
    printf("\nEnter the details for creating new request :- ");

    request *r = (request *)calloc(1, sizeof(request));
    r->requestID = generate_requestID();

enter_id:
    printf("\n\n\nEnter Customer ID: ");
    scanf("%d", &r->customerID);
    if (!isValidCustID(r->customerID))
    {
        printf("\nInvalid Customer ID ");
        goto enter_id;
    }

enter_date:
    printf("\n\nRequest Date (DD-MM-YY): ");
    scanf("%d-%d-%d", &r->requestDate.d, &r->requestDate.m, &r->requestDate.y);
    if (!isValidDate(r->requestDate.d, r->requestDate.m, r->requestDate.y))
    {
        printf("Invalid Date...Enter again");
        goto enter_date;
    }

    char *req_type = (char *)calloc(sizeof(char), SIZE);

    printf("\n\nPlease select the type of Request you have -");
    printf("\n1. Demo Request");
    printf("\n2. Service Request");
    printf("\n3. Complaint");

enter_choice:
    printf("\n\nEnter your choice: ");
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
        printf("\n\nInvalid Choice..");
        goto enter_choice;
    }

    strcpy(r->requestStatus, "open");

    if (!isFileExists("../data/requests.txt"))
    {
        printf("\n\nData File missing....");
        return EXIT_SUCCESS;
    }

    FILE *fp = fopen("../data/requests.txt", "a");
    fprintf(fp, "%d | %d | %d-%d-%d | %s | %s\n", r->requestID, r->customerID, r->requestDate.d, r->requestDate.m, r->requestDate.y, r->requestStatus, r->description);
    fclose(fp);
    return EXIT_SUCCESS;
}

/****************************************************************************************************************************************
 **FUNCTION NAME   :    delete_request
 **
 **DESCRIPTION     :    This function is used to delete requests from database.
 ***************************************************************************************************************************************/

int delete_request()
{
    system("clear");

    request *r = (request *)calloc(1, sizeof(request));

    if (!isFileExists("../data/requests.txt"))
    {
        printf("\n\nData File missing....");
        return EXIT_SUCCESS;
    }

    int reqID;

    printf("\nEnter the request Id for the request to be deleted: ");
    scanf("%d", &reqID);

    if (!isValidRequestID(reqID))
    {
        printf("\n\nNo request in the database with this request ID");
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
        else
            del_req_desc(reqID, r->description);
    }

    fclose(fp);
    fclose(tp);

    remove("../data/requests.txt");
    rename("../data/temp.txt", "../data/requests.txt");

    printf("\n\nrequest with request ID %d is deleted successfully", reqID);

    free(r);
    return EXIT_SUCCESS;
}

/****************************************************************************************************************************************
 **FUNCTION NAME   :    update_request
 **
 **DESCRIPTION     :    This function is used to update an existing request details in the databse
 ***************************************************************************************************************************************/

int update_request()
{

    system("clear");

    int reqID;
    printf("\nEnter the Request ID for the request to be update: ");
    scanf("%d", &reqID);

    if (isValidRequestID(reqID))
    {
        request *r = (request *)calloc(1, sizeof(request));

        if (!isFileExists("../data/requests.txt"))
        {
            printf("\n\nData File missing....");
            return EXIT_SUCCESS;
        }

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
                char opt;
                scanf("%s", &opt);

                switch (opt)
                {
                case '1':
                    printf("\nPlease select the type of Request you have -");
                    printf("\n1. Demo Request");
                    printf("\n2. Service Request");
                    printf("\n3. Complaint");

                entr_choice:
                    printf("\nEnter your choice: ");

                    char choice;
                    scanf("%s", &choice);

                    char *desc = (char *)calloc(sizeof(char), SIZE);

                    switch (choice)
                    {
                    case '1':
                        strcpy(desc, "demo");
                        demo(reqID);
                        break;
                    case '2':
                        strcpy(desc, "service");
                        service(reqID);
                        break;
                    case '3':
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

                case '2':

                    if (strcmp(r->requestStatus, "open") == 0)
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

/****************************************************************************************************************************************
 **FUNCTION NAME   :    display_request
 **
 **DESCRIPTION     :    This function is used to for displaying all the customer in database.
 ***************************************************************************************************************************************/

int display_request()
{
    request *r = (request *)calloc(1, sizeof(request));

    if (!isFileExists("../data/requests.txt"))
    {
        printf("\n\nData File missing....");
        return EXIT_SUCCESS;
    }

    FILE *fp = fopen("../data/requests.txt", "r");

    printf("%-10s%-20s%-20s%-20s%s\n\n", "Request_ID", "Customer_ID", "Request_Date", "Request_Status", "Request_Description");

    while (!feof(fp))
    {
        fscanf(fp, "%d | %d | %d-%d-%d | %s | %s\n", &r->requestID, &r->customerID, &r->requestDate.d, &r->requestDate.m, &r->requestDate.y, r->requestStatus, r->description);
        printf("%-20d%-20d%d/%d/%-20d%-20s%s\n", r->requestID, r->customerID, r->requestDate.d, r->requestDate.m, r->requestDate.y, r->requestStatus, r->description);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
