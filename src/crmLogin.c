#include<macros.h>
#include<validate.h>
#include<functions.h>

void crmLogin()
{    
    printf("---CRM Login---");
    printf("\nEnter Password: ");
    char pass[SIZE];
    fgets(pass,SIZE,stdin);
    if(validatePass(pass)){
        while(1){
            printf("\n1. Manage Customer\n2. Manage request\n3. Reports\n4. Exit\nEnter Choice... ");
            int choice;
            scanf("%d",choice);

            switch (choice)
            {
                case 1: manageCustomer();
                    break;
                case 2: manageRequest();
                    break;
                case 3: reports();
                    break;
                case 4: exit(0);
                default: printf("\nInvalid choice");            
            }
        }    

    }
    else
        printf("Try Again");      
    

}