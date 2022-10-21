#include<macros.h>
#include<validate.h>
#include<functions.h>

void crm_login()
{   
    system("clear");  
    printf("------CRM Login------");

    int attempt=1;

    enter_pass:
    printf("\n\nEnter Password: ");
    char *pass=(char*)calloc(sizeof(char),SIZE);
    scanf("%s",pass);

    if(validatePass(pass))
    {
        printf("\n1. Manage Customer");
        printf("\n2. Manage Requests");
        printf("\n3. Requests Report");
        printf("\n4. Logout");
        printf("\n5. Exit");

        enter_choice:
        printf("\nEnter Choice... ");
        int choice;
        scanf("%d",choice);

        switch (choice)
        {
            case 1: manage_customer();
                break;
            case 2: manage_request();
                break;
            case 3: view_reports();
                break;
            case 4: main();
            case 5: exit(0);
            default: printf("\nInvalid choice");
                goto enter_choice;            
        }             

    }
    else{
        printf("Incorrect Password....\nTry Again");
        attempt++;
        if(attempt>3){
            printf("\n Max Attempts Reached !!!");
            return EXIT_SUCCESS;
        }            
        goto enter_pass;  
    } 

}