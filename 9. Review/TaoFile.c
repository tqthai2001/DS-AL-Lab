#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact{
    char name[30];
    char tel[10];
    char email[35];
}Contact;

int main(){
    Contact dulieu;
    FILE *f = fopen("program.bin", "wb");
    strcpy(dulieu.name, "Thai");
    strcpy(dulieu.tel, "123");
    strcpy(dulieu.email, "t@gmail.com");
    fwrite(&dulieu, sizeof(Contact), 1, f);
    fclose(f);
    return 0;
}