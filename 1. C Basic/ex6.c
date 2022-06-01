#include <stdio.h>
#include <ctype.h>

void CharReadWrite(FILE *fin, FILE *fout)
{
	int c;
	while ((c=fgetc(fin)) != EOF){
        if(isupper(c)){
            c=tolower(c);
        }
        else if(islower(c)){
            c=toupper(c);
        }
        fputc(c, fout);  /* write to a file */
        putchar(c);
	}
}

int main(){
	FILE *fptr1, *fptr2;
	char filename1[]= "lab1w.txt";
	char filename2[]= "lab1.txt";

	if ((fptr1 = fopen(filename1, "w")) == NULL){
		printf("Cannot open %s.\n", filename1);
        return 0;
	}
    else if ((fptr2 = fopen(filename2, "r")) == NULL){
        printf("Cannot open %s.\n", filename2);
        return 0;
	}
    else {
        CharReadWrite(fptr2, fptr1);
        fclose(fptr1);
        fclose(fptr2);
        return 0;
	}
}