/*****************************************************************************************************************************************
 ** FILENAME  :  customers.c
 **
 ** DESCRIPTION : This File defines all the validation functions used in the project
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
#include <ctype.h>
#include <header.h>

/****************************************************************************************************************************************
 **FUNCTION NAME   :    isValidDate
 **
 **DESCRIPTION     :    This function is used to validate the date.
 ***************************************************************************************************************************************/

int isValidDate(int dd, int mm, int yy)
{
    if (yy >= 1900 && yy <= 9999)
    {
        if (mm >= 1 && mm <= 12)
        {
            if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                return VALID;
            else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                return VALID;
            else if ((dd >= 1 && dd <= 28) && (mm == 2))
                return VALID;
            else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
                return VALID;
            else
                return INVALID;
        }
        else
            return INVALID;
    }
    else
        return INVALID;
}

/****************************************************************************************************************************************
 **FUNCTION NAME   :    isValidDate
 **
 **DESCRIPTION     :    This function is used to validate the password.
 ***************************************************************************************************************************************/

int isValidPass(char *str)
{
    FILE *fp;
    fp = fopen("../data/password.txt", "r");
    if (fp == NULL)
    {
        printf("\nPASSWORD FILE MISSING...");
        return EXIT_SUCCESS;
    }
    else
    {
        char pass[SIZE];
        fscanf(fp, "%s", pass);

        if (strcmp(pass, str) == 0)
            return VALID;
        else
            return INVALID;
    }
}

/****************************************************************************************************************************************
 **FUNCTION NAME   :    isValidDate
 **
 **DESCRIPTION     :    This function is used to validate the name.
 ***************************************************************************************************************************************/

int isNameValid(char *name)
{
    long len = strlen(name);

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(name[i]))
            return INVALID;
    }

    return VALID;
}

/****************************************************************************************************************************************
 **FUNCTION NAME   :    isValidDate
 **
 **DESCRIPTION     :    This function is used to validate the phone number.
 ***************************************************************************************************************************************/

int isPhoneValid(char *pnum)
{
    long len = strlen(pnum);

    if (len != 10)
        return INVALID;

    for (int i = 0; i < len; i++)
    {
        if (pnum[i] < 48 && pnum[i] > 57)
            return INVALID;
    }
    return VALID;
}

/****************************************************************************************************************************************
 **FUNCTION NAME   :    isValidDate
 **
 **DESCRIPTION     :    This function is used to validate the caustomer ID.
 ***************************************************************************************************************************************/

int isValidCustID(int customerID)
{
    FILE *fp = fopen("../data/customers.txt", "r");

    customer *c = (customer *)calloc(1, sizeof(customer));

    while (!feof(fp))
    {
        fscanf(fp, "%d | %s | %s | %s | %s | %[^\n]s", &c->custID, c->firstName, c->lastName, c->phoneNum, c->custType, c->address);
        if (c->custID == customerID)
            return VALID;
    }
    fclose(fp);

    free(c);

    return INVALID;
}

/****************************************************************************************************************************************
 **FUNCTION NAME   :    isValidDate
 **
 **DESCRIPTION     :    This function is used to validate the Request ID.
 ***************************************************************************************************************************************/

int isValidRequestID(int requestID)
{
    FILE *fp = fopen("../data/requests.txt", "r");

    request *r = (request *)calloc(1, sizeof(request));

    while (!feof(fp))
    {
        fscanf(fp, "%d | %d | %d-%d-%d | %s | %s", &r->requestID, &r->customerID, &r->requestDate.d, &r->requestDate.m, &r->requestDate.y, r->requestStatus, r->description);
        if (r->requestID == requestID)
            return VALID;
    }
    fclose(fp);

    free(r);

    return INVALID;
}

/****************************************************************************************************************************************
 **FUNCTION NAME   :    isValidDate
 **
 **DESCRIPTION     :    This function is used to validate the presence of file.
 ***************************************************************************************************************************************/

int isFileExists(const char *path)
{
    // Try to open file
    FILE *fp = fopen(path, "rb");
    int status = 0; // If file does not exists
    if (fp != NULL)
    {
        status = 1; // File exists hence close file
        fclose(fp);
    }
    return status;
}
