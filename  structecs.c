#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct threeNum
{
    int n1, n2, n3;
    char name[20];
};

struct Students {
    char name[20];
    int yearOfBirth;
};

int main()
{
    int n;
    struct threeNum num;
    struct Students sArray[10];
    FILE* fptr, * fptr1;

    //Open file to write and check if you succeed
    fopen( "ECS.bin", "wb");
    if (fptr == NULL) return  0;
    
    //Read data into array of struct (Name, year) - 5 elements
    for (n = 0; n < 5; n++) {
        printf("Get the name and year");
        fgets(sArray[n].name, 20, stdin);
        scanf("%d", &sArray[n].yearOfBirth);
        //Clean buffer
        char ch = getchar();
    }

    //sort
    struct Students temp;
    //compare the year and swap the intire struct
    for (int i = 0;i<5;i++) {
        for (int j = i + 1; j < 5;j++) { 
            if (sArray[i].yearOfBirth < sArray[j].yearOfBirth) {
                temp = sArray[i];
                sArray[i] = sArray[j];
                sArray[j] = temp;
            }
        }
    }
    //Put into file
    fwrite(sizeof(struct Students), 5, fptr);
    fclose(fptr);
    //Open the file to read
    fopen( "ECS.bin", "rb");
    if (fptr1 == NULL) return  0;
    //Read all the structs from the file (5 structs)
    fread(&sArray, sizeof(struct Students), 5, fptr1);


    for (n = 0; n < 5; ++n)
    {
        //num.n1 = n;// 1, 2, 3, 4, 5
        //num.n2 = 5 * n;//5, 10, 15, 20, 25
        //num.n3 = 5 * n + 1;//6, 11, 16, 21, 26
        //strcpy_s(num.name, "aaaaa");
        //fwrite(&num, sizeof(struct threeNum), 1, fptr);
        //fread(&num, sizeof(struct threeNum), 1, fptr);
        //printf("n1: %d\tn2: %d\tn3: %d\n", num.n1, num.n2, num.n3);
        printf("%s - %d\n", sArray[n].name, sArray[n].yearOfBirth);
    }
    fclose(fptr1);

    return 0;
}