#include <stdio.h>

void ReadWrite(FILE *fin, FILE *fout){
    int i = 1;
	while (!feof(fin)){
        char str[100];
        fgets(str,100,fin);
        printf("%d %s", i, str);
        i++;
	}
}

int main(){
	FILE *fptr1, *fptr2;
	char filename1[]= "labw.txt";
	char filename2[]= "lab.txt";

	if ((fptr1 = fopen(filename1, "w")) == NULL){
		printf("Cannot open %s.\n", filename1);
        return 0;
	}
    else if ((fptr2 = fopen(filename2, "r")) == NULL){
        printf("Cannot open %s.\n", filename2);
        return 0;
	}
    else {
        ReadWrite(fptr2, fptr1);
        fclose(fptr1);
        fclose(fptr2);
        return 0;
	}
}