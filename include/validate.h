#include<stdio.h>
#include<stdlib.h>
#include<macros.h>

/*----------------DATE VALIDATION FUNCTION-------------------*/ 
int isValidDate(int dd, int mm, int yy)
{
    if(yy>=1900 && yy<=9999)
    {
        if(mm>=1 && mm<=12)
        {
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                return VALID;
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                return VALID;
            else if((dd>=1 && dd<=28) && (mm==2))
                return VALID;
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
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

/*-------------PASSWORD VALIDATION FUNCTION-----------------*/
int validatePass(char *str)
{
    FILE *fp; 
	fp = fopen("../data/password.txt","r");
	if(fp == NULL)
	{
		printf("\nPASSWORD FILE MISSING...");
		exit(0);
	}
	else
	{
        char ch;
        int i=0, flag=1;
		while(ch = fgetc(fp))
		{
			if(ch == EOF)
				break;
			if(ch!=str[i++])
                flag=0;

		}
        if(str[i]!='\0')
            flag=0;      
		fclose(fp);

        if(flag)
            return VALID;
        else
            return INVALID;
    }                
}



