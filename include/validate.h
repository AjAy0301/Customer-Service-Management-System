#include<struct.h>

int validatePass(char *str){
    return TRUE;
}

 
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
