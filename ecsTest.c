
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fp;
char buffer [255][255];


char productProblem[];
char userAddress[20];

void usersNames(){
char userName [50]={"Fady","Adi","Lina","Anwar","Sameeh","Nasser","Yussi","Ilan","Siwar","Tommy","Itai","Natan","Matan","Oskar","Haim","Noa","Noamy","Uri","Salman","Ameer","Amjad","Ehsan","Basheer","Tameer","Sameer","Miriam","Netta","Koral","Dvir","Shimon","Avi","Moshe","Adn","Adam","Rammy","Yael","Ilina","Talia","Daniel","Omer","Noam","Ariel","Jonathan","Tamar"};

int n = rand()%50;
printf("%s\n", userName[n]);
}
 
void usersProducts(){
    char userProduct[10]={"Dishwasher","kettle","fridge","washing machine","tv","Air-Conditioner","Dryer","microwave","computer","printer"};
     int n = rand()%50;
   printf("%s\n", usersNames[n]);


} 

void printDetails(){
    for(int i=0; i<=3; i++)
     printf("%s",buffer[i]);
}



void addUserDetails(){
    printf("Please enter the name:\n");
    fgets(buffer[0], 255, stdin);
    buffer[0][strlen(buffer[0]) - 1] = ',';
    printf("Please enter the product:\n");
    fgets(buffer[1], 255, stdin);
    buffer[1][strlen(buffer[1]) - 1] = ',';
    printf("Please enter the problem:\n");
    fgets(buffer[2], 255, stdin);
    buffer[2][strlen(buffer[2]) - 1] =',';
    printf("Please enter the address:\n");
    fgets(buffer[3], 255, stdin); 
}
void createFile(){
   
   fp=fopen("//Users//fadyzarka//Desktop//workVS//ECS//ecstest.txt","w");//create a file  
   fputs("im trying to writing a string into the file !!\n",fp);//write into file
    fprintf(fp, "using fprintf test!!! \n");

   fclose (fp);// close a file 
} 
void WriteToFile(){
    fp =fopen("//Users//fadyzarka//Desktop//workVS//ECS//ecstest.txt","a");
    for(int i=0;i<=3;i++){
    fputs(buffer[i],fp);
    }
    fclose(fp);
    }
    

void randomUser(){
      fp =fopen("//Users//fadyzarka//Desktop//workVS//ECS//ecstest.txt","a");
       


    

    fclose(fp);
    }





void main(){
createFile();
addUserDetails();
printDetails();
WriteToFile();
} 
