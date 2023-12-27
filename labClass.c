#include<stdio.h>
int main(void){
    char str[5][12];
    int count[5], f=0, count2=0, count3=0, count1;
    for(int i=0; i<5; i++){
        scanf("%s", str[i]);
    }
    printf("length:\n");
    for(int i=0; i<5; i++){
        for(int j=0; str[i][j]!='\0'; j++){
            count[i]=j+1;
        }
        printf("%d\n", count[i]);
    }
    char str1[12]="01100";
    for(int i=0; str1[i]!='\0'; i++){
        if(str1[i] != '0' && str1[i]!='1'){
            f = 1;
            break;
        }
    }
    if(f == 0){
        printf("W is from the alphabet.\n");
    }
    else{
        printf("W is not from the alphabet.\n");
    }
    char str2[12]="010101010";
    char str3[12]="01010100010";
    char str4[24];
    for(int i =0; str2[i]!='\0'; i++){
        count2++;
    }
    for(int i =0; str3[i]!='\0'; i++){
        count3++;
    }
    count1 = count2+count3;
    for(int i=0; str2[i]!='\0'; i++){
        str4[i]=str2[i];
    }
    for(int i=count2, j=0; i<=count1 && str3[j]!='\0'; i++, j++){
        str4[i]=str3[j];
    }
    /*for(int i=0; str4[i]!='\0'; i++){
        printf("%c", str4[i]);
    }*/
    printf("%s", str4);
    return 0;
}