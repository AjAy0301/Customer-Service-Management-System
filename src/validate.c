#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <header.h>

/***********************Date validation funtion**************************/

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


/***********************Password validation function**************************/

int isValidPass(char *str)
{
    FILE *fp;
    fp = fopen("../data/password.txt", "r");
    if (fp == NULL)
    {
        printf("\nPASSWORD FILE MISSING...");
        exit(0);
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


/***********************Name validation function**************************/

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


/***********************Phone Number validation funtion**************************/

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


/***********************Customer ID validation function**************************/

int isValidCustID(int custID)
{
    // code for validating custID.
    return VALID;
}


/***********************Request ID validation function**************************/

extern int isValidRequestID(int requestID)
{
    // code for validating requestID
    return VALID;
}

