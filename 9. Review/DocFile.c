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
    FILE *f = fopen("programx.bin", "rb");
    fread(&dulieu, sizeof(Contact), 1, f);
    printf("%s %s %s\n", dulieu.name, dulieu.tel, dulieu.email);
    fclose(f);
    return 0;
}