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


struct bank {
	char name[20];
	int accountNumber;
	double money;
};

 struct bank Banks[10];

struct transaction {
	int accountnumber;
	char details[50];
	double amount;
};
struct transaction update[10];

struct bank accounts(){
	struct bank NewBank;
	printf("Enter your name:\n");
	//fgets(NewBank.name,20,stdin);
	scanf("%s",NewBank.name);
	char ch=getchar();
	printf("Enter your AccountNumber:\n");
	scanf("%d",&NewBank.accountNumber);
	printf("Enter your money: \n");
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

struct transaction newTransaction() {
	struct transaction newupdate;
	printf("Enter your Accountnumber: \n");
	scanf("%d",&newupdate.accountnumber);
	printf("Enter details of the transaction:\n");
	//fgets(newupdate.details,50,stdin);
	int i=0;
	getchar();
	char c=' ';
	scanf("%c",&c);
	while(c!='\n'&& i<50){
    
	newupdate.details[i]=c;
	i++;
	c=getchar();
	}
	printf("Enter your amount transaction: \n");
	scanf("%lf",&newupdate.amount);

	return newupdate;
}





void updateBankAcount() {
fpr2= fopen("bankwrite.bin","ab");
struct transaction newupdate;
 newupdate = newTransaction();
update[counter++]= newupdate;

fwrite(&update,sizeof(struct transaction),1,fpr2);


fclose(fpr2);
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
		switch(option){
        case 1: newBankAccount();

        break;
         case 2: newTransaction();
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
}
    
return 0;
}