#include<stdio.h>
#include<string.h>

char str [100];
char A[2][10] = {"0A", ""};
char B[3][10] = {"0B","1B",""};
char S[10] = "A1B";
char str1[100];

void replacement(char str1[], char *replace, int p){
    int length = strlen(str1);
    int replacementLength = strlen(replace);
    char modified[100]; 
    int j = 0;

    for (int i = 0; i < length; i++) {
        if (i == p) {
            for (int k = 0; k < replacementLength; k++) {
                modified[j++] = replace[k];
            }
        }
         else {
            modified[j++] = str1[i];
        }
    }

    modified[j] = '\0'; 

    strcpy(str1, modified); 
    printf("%s=>", str1);
}


void leftmost(){
    strcpy(str1, S);
    int length = strlen(str);

    for (int i = 0; i <length; i++) {
        if (str[i] == '0' && str1[i]=='A') {
            replacement(str1, A[0], i);
        }
        else if(str[i] == '1' && str1[i] == 'A'){
            replacement(str1, A[1], i);
        }
        else if(str[i] == '0' && str1[i] == 'B'){
            replacement(str1, B[0], i);
        }
        else if(str[i] == '1' && str1[i] == 'B'){
            replacement(str1, B[1], i);
        }
        /*else if(str[i] == '\0' && str1[i] == 'B'){
            replacement(str1, B[2], i);
        }*/
    }
    printf("%s ", str);
    
}

void rightmost(){    
    strcpy(str1, S);
    int length = strlen(str);
    int length1 = strlen(S)-1;
    while(length1>=0){
        if(str1[length1] == 'B'){
            replacement(str1, B[0], length1);
            replacement(str1, B[1], length1+1);
            replacement(str1, B[2], length1+2);
        }
        else if(str1[length1] == 'A'){
            replacement(str1, A[0], length1);
            replacement(str1, A[0], length1+1);
        }
        length1--;
    }
    
    printf("%s ", str);
}

int main(void){
    printf("Enter the string:");
    gets(str);
    printf("Leftmost:");
    printf("S=>A1B=>");
    leftmost();
    printf("\n");
    printf("Rightmost: ");
    printf("S=>A1B=>");
    rightmost();
    return 0;
}
