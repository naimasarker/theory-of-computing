#include<stdio.h>
#include<string.h>

int found =0;
char path1[100],path2[100], str[20], output1[20]="S", output[20];
char base[3][10] = {"aS", "aSbS",""};

void replacement(char output[], char *replace, int p){
    int length = strlen(output);
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
            modified[j++] = output[i];
        }
    }

    modified[j] = '\0'; 

    strcpy(output, modified); 
    printf("%s=>", output);
}


void cfg(){
    int length = strlen(str);
    strcpy(output, output1);
    for(int i=0; i<length; i++){
        if(str[i] == 'a' && output[i] == 'S'){
            replacement(output, base[0], i);
            if(str[i+1] == 'a' && strchr(output, 'S'))
            i++;
            replacement(output, base[1], i);
            
        }
        else if(str[i] == 'b' && strchr(output, 'S')){
            replacement(output, base[2], i);
        }

    }
    if(strcmp(output, str)){
        found++;
    }
    printf("%s ", str);
    
}

void cfg1(){
    int length = strlen(str);
    strcpy(output, output1);
    for(int i=0; i<length; i++){
        if(str[i] == 'a' && output[i] == 'S'){
            replacement(output, base[1], i);
            if(str[i+1] == 'a' && strchr(output, 'S'))
            i++;
            replacement(output, base[0], i);
            
        }
        else if(str[i] == 'b' && strchr(output, 'S')){
            replacement(output, base[2], i);
        }

    }
    printf("%s ", str);
    if(strcmp(output, str)){
        found++;
    }
}

int main(void){
    printf("Enter the string: ");
    gets(str);
    if(str[0] == 'a'){
        printf("path-1:S->");
        cfg();
        printf("\n");
        printf("path-2:S->");
        cfg1();
        printf("\n");
        if(found == 2){
        printf("The grammar is ambiguous.\n");
        }
    }
    else{
        printf("The grammar is not ambiguous.");
    }
    return 0;
}