#include<stdio.h>
#include<string.h>
typedef struct
{
  char medi_name[20];
  int medi_ID;
  int quantity;
  char company_name[50];
  char pro_date[15];
  char ex_date[15];
  char measurement[10];
  float price;
}box_t;
void add_record(box_t [], int, FILE *);
void show_record(box_t [], FILE *);
void search_record(box_t [], char, FILE *);
int main()
{
    char id;
    int medicine_num;
    box_t medi[100];
    char str[10];
    char psw[10];
    printf(" Login Menu:-\n");
    printf("******************\n\n");
    printf("Enter Your User Name: ");
    gets(str);
    printf("\n");
    FILE *fp;
    int choice;
    char myfile[50];
    if(strcmp("Dipto", str)==0)
    {
        printf("Enter Password: ");
        gets(psw);
        if(strcmp("dip", psw)==0)
        {
            printf("\n1. ADD RECORD\n2. VIEW/SHOW RECORD\n3. EDIT RECORD\n4. SEARCH RECORD\n5. EXIT\n");
            printf("Enter Choice: ");
            scanf("%d", &choice);
            switch(choice)
            {
            case 1:
                fp=fopen("D://Medicine_Index.txt", "w");
                printf("How many medicines to catalog: ");
                scanf("%d", &medicine_num);
                printf(" Adding Records: \n");
                printf("*****************");
                add_record(medi, medicine_num, fp);
                fclose(fp);
                break;
            case 2:
                fp=fopen("D://Medicine_Index.txt", "r");
                printf(" Showing All Records: \n");
                printf("**********************\n\n");
                show_record(medi,fp);
                fclose(fp);
                break;
            case 3:
                fp=fopen("D://Medicine_Index.txt", "a");
                printf("How many medicines to catalog: ");
                scanf("%d", &medicine_num);
                add_record(medi, medicine_num, fp);
                fclose(fp);
                break;
            case 4:
                fp=fopen("D://Medicine_Index.txt", "r");
                printf("Enter Medicine ID For Search: \n");
                scanf("%c", &id);
                search_record(medi, id, fp);
                fclose(fp);
            default:
                break;
            }
        }
        else
        {
            printf("Incorrect Password.\n");
        }
    }
    else
    {
        printf("Incorrect User Name.\n");
    }
}
void add_record(box_t arr[], int size, FILE *fp)
{
    int c1;
    for(c1=0; c1<size; c1++)
    {
        fflush(stdin);
        printf("Medicine No: %d", c1+1);
        printf("\nMedicine Name: ");

        fgets(arr[c1].medi_name, 20, stdin);
        fprintf(fp,"%s", "Medicine Name:      ");
        fprintf(fp,arr[c1].medi_name);

        printf("Company Name: ");

        fgets(arr[c1].company_name, 20, stdin);
        fprintf(fp,"%s", "Company Name:       ");
        fprintf(fp,arr[c1].company_name);

        fflush(stdin);
        printf("Medicine ID: ");
        scanf("%d", &arr[c1].medi_ID);
        fprintf(fp,"%s", "Medicine ID:        ");
        fprintf(fp,"%d\n", arr[c1].medi_ID);

        printf("Medicine Quantity: ");
        scanf("%d", &arr[c1].quantity);
        fprintf(fp,"%s", "Medicine Quantity:  ");
        fprintf(fp,"%d\n", arr[c1].quantity);

        getc(stdin);
        printf("Production Date[dy.mn.yr]: ");
        gets(arr[c1].pro_date);
        fprintf(fp,"%s", "Production Date:    ");
        fprintf(fp,arr[c1].pro_date);
        fprintf(fp,"\n");

        printf("Expired Date[dy.mn.yr]: ");

        fgets(arr[c1].ex_date, 15, stdin);
        fprintf(fp,"%s", "Expired Date:       ");
        fprintf(fp,arr[c1].ex_date);

        printf("Measurement: ");
        fgets(arr[c1].measurement, 10, stdin);
        fprintf(fp,"%s", "Measurement:        ");
        fprintf(fp,arr[c1].measurement);

        printf("Price: ");
        scanf("%f", &arr[c1].price);
        fprintf(fp,"%s", "Price:              ");
        fprintf(fp,"%f Tk.\n\n", arr[c1].price);

        getc(stdin);
        printf("\n");
    }
}
void show_record(box_t arr[], FILE *fp)
{
    char c;
    while ((c = getc(fp)) != EOF)
    {
          putchar(c);
    }
    fclose(fp);
}
void search_record(box_t arr[], char i, FILE *fp)
{
    char id;
    printf("Enter Medicine ID For Search: \n");
    scanf("%c", &id);
}

