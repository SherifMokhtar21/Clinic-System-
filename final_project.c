#include <stdio.h>
#include <stdlib.h>


typedef struct nodetype
{
    int ID;
    int age;
    char name[10];
    char gender[7];
    int reservation[5];
    struct nodetype *next;
} node;

void IS_ID_THERE(node *head, int ID);
void add_paiant(node *head, int ID, int first_add_patiant);
int ID_Check(node *head, int ID);
void Patiant_edit(node *head, int ID);
void ADD_RESEVATION(node *head, int ID, int reservation);
void CLEAR_RESEVATION(node *head, int ID);
void PATIANT_INFORMATION(node *head, int ID);
void REVIEW_RESERVATIONS(node *head, int ID);

void IS_ID_THERE(node *head, int ID)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr = head;

    while (ptr != NULL)
    {
        if (ptr->ID != ID)
        {
            ptr = ptr->next;

            if (ptr == NULL)
            {
                printf("incorrect ID\n");
                scanf("%d", &ID);
            }
        }
        else
        {

            ptr = NULL;
        }
    }
}

int ID_Check(node *head, int ID)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->ID == ID)
        {
            printf("thise id is already exect \nType new ID\n");
            scanf("%d", &ID);
            ptr = head;
        }
        else
            ptr = ptr->next;
    }
    return ID;
}

void add_paiant(node *head, int ID, int first_add_patiant)
{
    int age;
    char name[10];
    char gender[7];
    int k;
	
  node *ptr = (node *)malloc(sizeof(node));
    node *new = (node *)malloc(sizeof(node));
	
    printf("enter the patiant name \n");
    scanf("%s", name);

    printf("enter the patiant age \n");
    scanf("%d", &age);

    printf("enter the patiant gender \n");
    scanf("%s", gender);
  
    if (first_add_patiant == 0)
    {
        for (k = 0; k < 10; k++)
        {
            head->name[k] = name[k];
        }
        head->ID = ID;
        head->age = age;
        for (k = 0; k < 7; k++)
        {
            head->gender[k] = gender[k];
        }
        head->reservation[0] = 5;
        head->reservation[1] = 5;
        head->reservation[2] = 5;
        head->reservation[3] = 5;
        head->reservation[4] = 5;
        first_add_patiant = 1;
        head->next = NULL;
    }
    else
    {
        ptr = head;
        new->ID = ID;
        for (k = 0; k < 10; k++)
        {
            new->name[k] = name[k];
        }
        new->age = age;
        for (k = 0; k < 7; k++)
        {
            new->gender[k] = gender[k];
        }
        new->reservation[0] = 5;
        new->reservation[1] = 5;
        new->reservation[2] = 5;
        new->reservation[3] = 5; 
        new->reservation[4] = 5;
        new->next = NULL;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
}

void Patiant_edit(node *head, int ID)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr = head;

    while (ptr != NULL)
    {
        if (ptr->ID == ID)
        {
            int k;
            int age;
            char name[10];
            char gender[7];
            printf("enter the new patiant name \n");
            scanf("%s", &name);

            printf("enter the new patiant age \n");
            scanf("%d", &age);

            printf("enter the new patiant gender \n");
            scanf("%s", &gender);

            for (k = 0; k < 10; k++)
            {
                name[k] = ptr->name[k];
            }
            ptr->age = age;
            for (k = 0; k < 7; k++)
            {
                gender[k] = ptr->gender[k];
            }
            ptr = NULL;
        }
        else
        {
            ptr = ptr->next;
        }
    }
}

void ADD_RESEVATION(node *head, int ID, int reservation)
{
	int j=0;
    node *ptr = (node *)malloc(sizeof(node));
    ptr = head;
	
    while (ptr != NULL)
    {
        if (ptr->ID == ID)
        {
            for ( j=0; j<5; j++)
            {
                if (ptr->reservation[j] == 5)
                {
                    printf("To choose slot 2pm to 2:30pm press '0'\nTo choose slot  2:30pm to 3pm press '1'\nTo choose slot  3pm to 3:30pm press '2'\nTo choose slot 4pm to 4:30pm press '3'\nTo choose slot 4:30pm to 5pm press '4'\n");
                    scanf("%d", &reservation);
                    ptr->reservation[j] = reservation;
                    j = 5;
                    ptr = NULL;
                }
            }
        }
        else
        {
            ptr = ptr->next;
        }
    }
}

void CLEAR_RESEVATION(node *head, int ID)
{
    int j = 0;
	node *ptr = (node *)malloc(sizeof(node));
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->ID == ID)
        {
            for (j=0; j < 5; j++)
            {
                if (ptr->reservation[j] != 5)
                {
                    ptr->reservation[j] = 6; 
                    printf("reservation canceled \n");
                    ptr = NULL;
                }
            }
        }

        else
        {
            ptr = ptr->next;
        }
    }
}

void PATIANT_INFORMATION(node *head, int ID)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr = head;

    while (ptr != NULL)
    {
        if (ptr->ID == ID)
        {
            printf(" the patiant name is %s \n", ptr->name);
            printf(" the patiant age is %d \n", ptr->age);
            printf(" the patiant gender is %s \n", ptr->gender);
            printf(" the patiant ID is %d \n", ptr->ID);
            ptr = NULL;
        }
        else
            ptr = ptr->next;
    }
}

void REVIEW_RESERVATIONS(node *head, int ID)
{
	int j = 0;
    node *ptr = (node *)malloc(sizeof(node));
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->ID == ID)
        {
            for (j=0; j < 5; j++)
            {
                if (ptr->reservation[j] != 5 || ptr->reservation[j] != 6)
                {

                    switch (ptr->reservation[j])
                    {
                    case 0:
                        printf("The patiant has a reservation from 2pm to 2:30pm \n");
                        break;

                    case 1:
                        printf("The patiant has a reservation from 2:30pm to 3pm \n");
                        break;

                    case 2:
                        printf("The patiant has a reservation from 3pm to 3:30 \n");
                        break;

                    case 3:
                        printf("The patiant has a reservation from  4pm to 4:30pm \n");
                        break;

                    case 4:
                        printf("The patiant has a reservation from  4:30pm to 5pm \n");
                        break;
                    }
                }
                else
                {
                    printf("there is no resevations to this pataint \n");
                    j = 6;
                }
            }
            ptr = NULL;
        }

        else
        {
            ptr = ptr->next;
        }
    }
}

int main()
{
    int mode, pass, i, mode2, mode3;
    int rightPass = 1234;
    int ID;
    int ID2;
    int reservation;
    int programGoing = 0;
    int adminGoing = 0;
    int usergoing = 0;
    static int first_add_patiant = 0; // to  put the data in the header rathar than new element in the first
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL;

    while (programGoing == 0)
    {
         	printf("\n\n\t\t ********************************************************************");
		printf("\n\t\t                  Clinic Management System                ");
		printf("\n\t\t   *******************************************************************");      
	  printf("\n\n\t\t 0.exit program");      
	   printf("\n\n\t\t 1.admin mode");
		printf("\n\n\t\t 2.user mode");
		printf("\n\n\t\t Enter your choice :");
        scanf("%d", &mode);
        adminGoing = 0;
        usergoing = 0;
        while (mode != 0 && mode != 1 && mode != 2)
        {
            printf("Wrong entery\n Please press for admin mode '0' and for user mode press '1'\n To exit the program press '2'\n");
            scanf("%d", &mode);
        }
        switch (mode)
        {
			case 0:
		{
            printf("the program ended\n");
            programGoing = 1;
            break;
		}

        case 1:{
		 printf("please enter the password for the admin \n");
            scanf("%d", &pass);

            for (i = 2; i > 0; i--)
            {
                if (pass == rightPass)
                    i = 0;
                else
                {
                    printf("Wrong Password \nYou have %d attemps left\nplease enter the password for the admin \n", i);
                    scanf("%d", &pass);
                }
            }

            while (i != 0 && adminGoing == 0)
            {
                	printf("\n\n\t\t ********************************************************************");
		printf("\n\t\t                   welcome to admin mode                 ");
		printf("\n\t\t   *******************************************************************");
		printf("\n\n\n\t\t Please enter your choice from below (0-4):");
		printf("\n\n\t\t 0. exit from admin mode");
		printf("\n\n\t\t 1. Add new patient record");
		printf("\n\n\t\t 2.Edit patient record");
		printf("\n\n\t\t 3.  Reserve a slot with the doctor");
		printf("\n\n\t\t 4. Cancel reservation");
		printf("\n\n\t\t Enter your choice :");
                scanf("%d", &mode2);
                switch (mode2)
                {
					 case 0:
				{
                    printf("admin mode has  ended\n");
                    adminGoing = 1;
                    mode = 4; 
                    break;
				}
                case 1:
				{
                    printf("enter the patiant ID \n");
                    scanf("%d", &ID);
                    ID2 = ID_Check(head, ID);
                    add_paiant(head, ID2, first_add_patiant);
                    first_add_patiant = 1;
                    break;
				}

                case 2:
				{
                    printf("please enter the ID that you will edit\n");
                    scanf("%d", &ID);
                    IS_ID_THERE(head, ID);
                    Patiant_edit(head, ID);
                    break;
				}
               

                case 3:
				{
                    printf("please enter the ID that you will make a reservation to\n");
                    scanf("%d", &ID);
                    IS_ID_THERE(head, ID);
                    ADD_RESEVATION(head, ID, reservation);
				break;
				}

                case 4:
				{
                    printf("please enter the ID that you will cancel the reservation to\n");
                    scanf("%d", &ID);
                    IS_ID_THERE(head, ID);
                    CLEAR_RESEVATION(head, ID);
				break;
				}
                }
            }

            break;
		}

        case 2:{
            while (usergoing == 0)
            {
                printf("\n\n\t\t ********************************************************************");
		printf("\n\t\t                   welcome to user mode                 ");
		printf("\n\t\t   *******************************************************************");
		printf("\n\n\n\t\t Please enter your choice from below (0-2):");
		printf("\n\n\t\t 0. exit from user mode ");
		printf("\n\n\t\t 1. View patient record");
		printf("\n\n\t\t 2. View today’s reservations");
                scanf("%d", &mode3);
                switch (mode3)
                {
                 case 0:
				{
                    printf("user mode has ended\n");
                    usergoing = 1;
                    break;
				}
				case 1:
				{
                    printf("please enter the ID that you want to view \n");
                    scanf("%d", &ID);
                    IS_ID_THERE(head, ID);
                    PATIANT_INFORMATION(head, ID);
				break;
				}

                case 2:
				{
                    printf("please enter the ID that you want to view his reservations\n");
                    scanf("%d", &ID);
                    IS_ID_THERE(head, ID);
                    REVIEW_RESERVATIONS(head, ID);
                    break;
				}

               
                }
            }
            break;
		}

        
        }
    }
    return 0;
}
