#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *myFile;
char filePath[255] = "//Users//fadyzarka//Desktop//workVS//ECS//userData.txt";
char buffer [255][255];
char buf[255];
char arr[50][4][100];
char fileString[255];


void createFile(){
    fileString[255];
   myFile = fopen(filePath,"w");  //create new file
     fputs("This is testing...\n", myFile); // write in the file
   fclose(myFile);// close the file
}// end create file

void printDetails(){
    for(int i=0; i<=3; i++)
     printf("%s",buffer[i]);
}

void addUserDetails(){
    printf("Please enter the name:\n");
    fgets(buffer[0], 255, stdin);
   // fgets(buffer[0], 255, stdin);
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

void WriteToFile(){
    myFile=fopen(filePath,"a");
    for(int i=0;i<=3;i++){
    fputs(buffer[i],myFile);
    }
    fclose(myFile);
    }
    

void readFile(){
    myFile= fopen(filePath, "r");// open the file to read
   while(!feof(myFile))
   {
       char *c= fgets(buf,255,myFile); 
       printf("%s\n",c); //print the message
   }
   fclose(myFile);
}
void searchDetails(){}



void main()
{
    createFile();
    //readFile();
    addUserDetails();
    printDetails();
    //putUserDetailsIntoFile();
    WriteToFile();
}
