#include <stdio.h>
#include <string.h>
#include <ctype.h>

// dem so lan xuat hien cua chu cai trong chuoi

int main(){
    char str[100];
    printf("Enter string: ");
    gets(str);
    int count[26]={0};
    int i;
    for(i=0;i<=strlen(str);i++){
        if(isalpha(str[i])){
            count[str[i]-'a']++;
        }
    }
    for(i=0;i<26;i++){
        if(count[i]!=0){
            printf("%c: %d\n", i+'a', count[i]);
        }
    }
}