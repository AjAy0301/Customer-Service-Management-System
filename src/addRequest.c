#include<macros.h>
#include<struct.h>


void add_request(){

    request r;
    while (1)
    {    
        printf("\nRequest Date:");
        scanf("%d%d%d",&r.requestDate.d,&r.requestDate.m,&r.requestDate.y);
        if(isValidDate(r.requestDate))
            break;
        else
            printf("Invalid Date...Enter again");
    }

            

   
   
    
}