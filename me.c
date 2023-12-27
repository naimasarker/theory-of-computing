
/*#include<stdio.h>
int main(void){
    char alpha[3]="01";
    int k;
    printf("input k:");
    scanf("%d", &k);
    char str[8][k+1];
    int currentIn =0;
    for(int j=0; j<8; j++){
       for(int i=0; i<=2 ; i++){
            str[j][i]=alpha[currentIn];
            currentIn++;
            if(currentIn>1){
                currentIn =0;
            }
        }
        printf("%s\n", str[j]);
    }
    /*if(currentIn == k){
        printf("%s\n", str);
    }*/
    
   // return 0;
//}
//*********************************1*****************************
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char generateSymbol() {
    return rand() % 2 + '0';
}

int main() {
    srand(time(NULL));
    char alpha[] = {'0', '1'};

    int numStrings = 5;
    int stringLength = 10; 

    printf("Generated strings:\n");
    for (int i = 0; i < numStrings; i++) {
        char generatedString[stringLength + 1];
        generatedString[stringLength] = '\0'; 
        for (int j = 0; j < stringLength; j++) {
            generatedString[j] = generateSymbol();
        }
        printf("%s\n", generatedString);
    }

    return 0;
}*/
//*****************************************b-----
/*#include<stdio.h>
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
    //for(int i=0; str4[i]!='\0'; i++){
    //    printf("%c", str4[i]);
    //}
    printf("%s", str4);
    return 0;
}*/

////////////////////////////////////////////////////////////////////////2a
/*#include<stdio.h>
int main(void){
    char alpha[3]="01";
    int k;
    printf("Input the valu of K: ");
    scanf("%d",&k);
    int indicate[k];
    for(int i=0; i<k; i++){
        indicate[i]=0;
    }
    if(k>=0){
        while(1){
            for(int i=0; i<k; i++){
                printf("%c",alpha[indicate[i]]);
            }
            printf("\n");
            int i=k-1;
            while(i>=0 && indicate[i]==1){
                indicate[i]=0;
                i--;
            }
            if(i<0){
                break;
            }
            else{
                indicate[i]++;
            }
        }
    }
    else{
        printf("Change you input.\n");
    }
    return 0;
}*/

//**********************************2b*****************************
/*#include<stdio.h>
int main(void){
    int flag = 0, count=0;
    char w[12];
    printf("Input a string:\n");
    scanf("%s", &w);
    for(int i =0; w[i]!='\0'; i++){
        count++;
    }
    
    int l = count-1; 
    for(int i=0,j=l; i<=l || j>=0; i++, j--){
        if(w[i]!=w[j]){
            flag =1;
            break;
        }
    }
    if(flag == 1){
        printf("w is not a palindrome");
    }
    else{
        printf("w is a palindrome.");
    }
    return 0;
}*/
//*****************LAB-2 "DFA" **************************
#include<stdio.h>
char trans(char transition[][2], char str[], int n, int m, char state[], char alpha[]){
    char currentState = state[0];
    int currentSIn = 0;
    printf("%c",currentState);
    
    for(int i=0; str[i]!='\0'; i++){
        char symbol = str[i];
        int symbolIn = -1;
        for(int j=0; j<m; j++){
            if(symbol == alpha[j]){
                symbolIn = j;
                break;
            }
            
        }
        currentState = transition[currentSIn][symbolIn];
        printf("->%c",currentState);
        for(int k=0; k<n; k++){
            if(state[k]==currentState){
                currentSIn = k;
            }
        }
    }
    
    return currentState;
}
int main(void){
    int numState, numAlpha;
    printf("enter the num of state and num of alphabet: ");
    scanf("%d %d", &numState, &numAlpha);
    char state[numState+1];
    char alpha[numAlpha+1];
    printf("Alphabets: ");
    for(int i=0; i<numAlpha; i++){
        scanf(" %c", &alpha[i]);
    }
    printf("States: ");
    for(int i=0; i<numState; i++){
        scanf(" %c", &state[i]);
    }
    char transition[numState][numAlpha];
    printf("Transition table:\n");
    for(int i=0; i<numState; i++){
        for(int j=0; j<numAlpha; j++){
            printf("state %c-> %c:",state[i], alpha[j]);
            scanf(" %c",&transition[i][j]);
        }
    }
    getchar();
    char str[100];
    char start = state[0];
    char end = state[numState-1];
    printf("Enput the String: ");
    gets(str);
    char runningState = trans(transition, str, numState, numAlpha, state,alpha); 
    if(runningState == end){
        printf("\nAccepted.\n");
    }
    else{
        printf("\nRejected.\n");
    }
    return 0;
}