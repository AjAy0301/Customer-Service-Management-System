#include<macros.h>
#include<struct.h>


void addRequest(){

    request r;
    while (1)
    {    
        printf("\nRequest Date:");
        scanf("%d%d%d",&r.requestDate.day,&r.requestDate.month,&r.requestDate.year);
        if(isValid(r.requestDate))
            break;
        else
            printf("Invalid Date...Enter again");
        
            
    }

            

   
   
    
}