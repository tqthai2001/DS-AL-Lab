#include <stdio.h>
#include <ctype.h>

void LineReadWrite(FILE *fin, FILE *fout)
{
	while (!feof(fin)){
        char str[100];
        fgets(str,99,fin);
        fputs(str,fout);
        puts(str);
	}
}

int main(){
	FILE *fptr1, *fptr2;
	char filename1[]= "lab2w.txt";
	char filename2[]= "lab2.txt";

	if ((fptr1 = fopen(filename1, "w")) == NULL){
		printf("Cannot open %s.\n", filename1);
        return 0;
	}
    else if ((fptr2 = fopen(filename2, "r")) == NULL){
        printf("Cannot open %s.\n", filename2);
        return 0;
	}
    else {
        LineReadWrite(fptr2, fptr1);
        fclose(fptr1);
        fclose(fptr2);
        return 0;
	}
}