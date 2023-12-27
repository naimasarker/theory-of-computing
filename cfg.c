#include<stdio.h>
#include<string.h>

char str[100];

int ispalindrome(int length){
    for(int i=0,j=length-1; i<=length || j>=0; i++, j--){
        if(str[i]!=str[j]){
            return 1;
        }
    }
    return 0;
}

void cfg(char strp[],int length){
    char str1[100], str2[100], str3[100];
    int lenS = strlen(str);
    strcpy(str2, strp);
    int i, j;
    for( i=1,j=0; i<length-1 && j<length-1; i++,j++ ){
        str1[j] = str2[i];
    }
    str1[j] = '\0';
    //printf("Str1:%s\n", str1);
    int len1 = strlen(str1);
    if(length == 1 || length == 3){
        printf("%s\n", str);
        return;
    }   
    else{  
        int i, j, k=0;
        for(i=0; i<(lenS-len1)/2; i++){
            str3[i] = str[i];
            k = i+1;
        }
        str3[k] = str1[0];
        str3[k+1] = 'p';
        str3[k+2] = str1[len1-1];
        for(j=((lenS-len1)/2)+len1, k =k+3; j<lenS && (k<len1+(lenS-len1)); j++, k++){
           str3[k] = str[j];
        }
        str3[k] = '\0';
        printf("%s=>", str3);
        cfg(str1,len1);
        
    }

}


int main(void){
        
    printf("Input a string: ");
    scanf("%s", &str);
    int length = strlen(str);
    int result = ispalindrome(length);
    if(result == 1){
        printf("Not in this grammar.\n");
    }
    else{
        printf("p=> ");
        printf("%cp%c=> ",str[0], str[length-1]);
        cfg(str,length);
    }
    return 0;
}