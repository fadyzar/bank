#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FOREVER for(;;)

//fpr1 - read bank
//fpr2 - read transactions
//fpw1 - write bank
//fpw2 - write transactions
FILE* fpr1, * fpr2, * fpw1, * fpw2;
int counter=0;
struct bank Banks[10];

struct bank {
	char name[20];
	int accountNumber;
	double money;
};

struct transaction {
	int counter;
	int accountnumber;
	char details[50];
	double amount;
};

struct bank accounts(){
	struct bank NewBank;
	printf("Enter your name:");
	scanf("%s",&NewBank.name);
	//fgets(NewBank.name,20 , __stdinp);
	char ch=getchar();
	printf("Enter your AccountNumber:");
	scanf("%d",&NewBank.accountNumber);
	printf("Enter your money:");
	scanf("%lf",&NewBank.money);

	return NewBank;
}



void newBankAccount() {
	fpr1= fopen("bankwrite.bin","ab");
    struct bank NewBank;
	NewBank=accounts();
	Banks[counter++]=NewBank;
	
	fwrite(&Banks,sizeof(struct bank),1,fpr1);

fclose(fpr1);
}

void updateBankAcount(struct bank update) {

}
void createFile(){
    fpw1= fopen("bankwrite.bin","wb");
    fpw2= fopen("bankwrite2.bin","wb");
 fclose(fpw1);
fclose(fpw2);
}



int main() {
	int option;
	
    createFile();
	FOREVER{
		printf("1. New account\n");
		printf("2. Make a transaction\n");
		printf("3. Show all account details\n");
		printf("4. Show all transactions\n");
		printf("5. Show all transactions for a specific client\n");
		printf("6. Show all problematic clients\n");
		printf("7. Money transfer from one account to another\n");
		printf("9. exit\n");
		scanf("%d", &option);
		
	}
    switch(option){
        case 1: newBankAccount();

        break;
         case 2: 
        break;
         case 3: 
        break;
         case 4: 
        break;
         case 5: 
        break;
         case 6: 
        break;
         case 7: 
        break;
         case 9: return 0; 
       
    }
return 0;
}