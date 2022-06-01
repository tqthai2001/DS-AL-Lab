#include <stdio.h>

int main(){
	char in_name[25], out_name[25];
	FILE *fin, *fout;
	char c;

	printf("File to be copied: ");
	scanf("%s", in_name);
	printf("Output filename: ");
	scanf("%s", out_name);

	fin = fopen (in_name, "r");

	if(fin == NULL ) printf("Cannot open %s for reading.\n", in_name);
	else{
	    fout = fopen (out_name, "w");
		if( fout == NULL ) printf("Can't open %s for writing.\n", out_name);
		else{
			while((c=fgetc(fin)) != EOF){
				fputc(c, fout);
			}
            printf("File has been copied.\n");
			fclose (fout);
			fclose (fin);
		}
	}
}