#include <stdio.h>
#include <string.h>

// void replace(char s[], char c1, char c2){
//     int i;
//     for(i=0;i<strlen(s);i++){
//         if(c1 == s[i]){
//             s[i] = c2;
//         }
//     }
// }

void replace(char *s, char c1, char c2){
    int i;
    while(*s != '\0'){
        if(c1 == *s){
            *s = c2;
        }
        *s++;
    }
}

int main(){
    char str[100];
    char ch1, ch2;
    printf("Enter string: ");
    fseek(stdin, 0, SEEK_END);
    scanf("%s", str);
    printf("Enter 2 characters: ");
    fseek(stdin, 0, SEEK_END);
    scanf("%c %c", &ch1, &ch2);
    replace(str, ch1, ch2);
    printf("Result: %s", str);
}