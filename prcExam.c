//*****************************DFA
/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char alpha[20], state[20];
char transition[20][20];

char trans(int n, int m, char str[]){
    char currentState = state[0];
    int currentSIn = 0;
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
        printf("->%c", currentState);
        for(int k=0; k<n; k++){
            if(state[k] == currentState){
                currentSIn = k;
            }
        }
    }
    return currentState;
}

int main(void){
    int numState, numAlpha;
    printf("Enter the num of state and alphabet:");
    scanf("%d %d", &numState, &numAlpha);
    printf("Alphabets:");
    for(int i=0; i<numAlpha; i++){
        scanf(" %c", &alpha[i]);
    }
    printf("states:");
    for(int i=0; i<numState; i++){
        scanf(" %c", &state[i]);
    }
    for(int i=0; i<numState; i++){
        for(int j=0; j<numAlpha; j++){
            printf("state %c-> %c:", state[i], alpha[j]);
            scanf(" %c", &transition[i][j]);
        }
    }
    getchar();
    char str[100];
    char start = state[0];
    char end = state[numState-1];
    printf("Enter the input string:");
    gets(str);
    char runningState = trans(numState, numAlpha, str);
    if(runningState == end){
        printf("\nAccepted\n");
    }
    else{
        printf("\nRejected\n");
    }
    return 0;
}*/

//******************NFA **************
/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char alpha[20], state[20], transition[20][20][20], str[20];

char trans(int n, int m, int currentSIn, int pos, char currentState, char end){
    if(currentState == '1'){
        return 0;
    }
    if(pos == strlen(str)){
        if(currentState == end){
            printf("\nAccepted\n");
            return currentState;
        }
        return 0;
    }
    int symbolIn, neState;
    char symbo = str[pos];
    for(symbolIn =0; symbolIn<m; symbolIn++){
        if(symbo == alpha[symbolIn]){
            for(neState=0; neState<n; neState++){
                char nextState = transition[currentSIn][symbolIn][neState];
                if(neState !='1'){
                    char result = trans(n, m, nextState-'A', pos+1, nextState, end);
                    if(result != 0){
                        return result;
                    }
                }
            }
            break;
        }
    }
    return 0;
}

int main(void){
    int numState, numAlpha;
    printf("Enter the number of state and alphabet:");
    scanf("%d %d", &numState, &numAlpha);
    printf("Alphabets:");
    for(int i=0; i<numAlpha; i++){
        scanf(" %c", &alpha[i]);
    }
    printf("State:");
    for(int i=0; i<numState; i++){
        scanf(" %c", &state[i]);
    }
    printf("Transition table:\n");\
    for(int i=0; i<numState; i++){
        for(int j=0; j<numAlpha; j++){
            for(int k=0; k<numState; k++){
                printf("state %c-> %c:", state[i], alpha[j]);
                scanf(" %c", &transition[i][j][k]);
            }
        }
    }
    getchar();
    printf("Enter the string:");
    gets(str);
    char end = state[numState-1];
    char start = state[0];
    char result = trans(numAlpha, numState, 0, 0, start, end);
    if(result == 0){
        printf("\nRejected\n");
    }
    return 0;
}*/

//****************************pumping lemma
/*#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

char w[100], x[10], y[10], z[80], yp[80], w1[100];
int i, j, lenW, lenW1, count0=0, count1;
void generateString(int n, int pattern){
    int index = 0;
    if(pattern == 1){
        for(i=0; i<n; i++){
            w[index++] = '0';
        }
        for(i=0; i<n; i++){
            w[index++] = '1';
        }
    }
    else if(pattern == 2){
        for(int i=0; i<n; i++){
            w[index++] = '0';
        }
        for(int i=0; i<2*n; i++){
            w[index++] = '1';
        }
    }
    printf("w = %s\n", w);
    lenW = strlen(w);
}

void divideString(int n){
    for(i=0; i<1; i++){
        x[i] = w[i];
    }
    x[i] = '\0';
    for(j=0,i=1; i<n; i++, j++){
        y[j] = w[i];
    }
    y[j] = '\0';
    for(j=0,i=n; w[i]!='\0'; j++, i++){
        z[j] = w[i];
    }
    z[j] = '\0';
    printf("x:%s\n", x);
    printf("y:%s\n", y);
    printf("z:%s\n", z);
}

int concatinate(int pattern){
    strcpy(w1, "");
    strcat(w1, x);
    strcat(w1, yp);
    strcat(w1, z);
    printf("W1:%s\n", w1);
    lenW1 = strlen(w1);
    int current0 = 0, current1 = 0;
    for(i=0; i<lenW1; i++){
        if(w1[i] == '0'){
            current0++;
            current1 = 0;
        }
        else if(w1[i] == '1'){
            current1++;
            current0 = 0;
        }
        if(current0>count0){
            count0 = current0;
        }
        if(current1>count0){
            count1 = current1;
        }
    }
    if(pattern == 1){
        if(count0 != count1){
            printf("This is not a ragular language\n");
            return 1;
        }
        else{
            printf("This is a ragular language\n");
        }
    }
    if(pattern == 2){
        if((2*count0) != count1){
           printf("This is not a ragular language\n");
           return 1;
        }
        else{
            printf("This is  a ragular language\n");
        }
    }
    return 0;
}

void pumping(int pattern){
    int k;
    for(k =0; ; k++){
        if(k == 0){
            strcpy(yp, "");
            int r = concatinate(pattern);
            if(r == 1){
                break;
            }
        }
        strcat(yp, y);
        int r = concatinate(pattern);
        if(r == 1){
            break;
        }
    }
}

int main(void){
    int n, pattern;
    srand(time(NULL));
    n = rand()% 10+2;
    //printf("n = %d\n", n);
    printf("Enter the pattern(1 for 0^n1^n, 2 for 0^n1^2n): ");
    scanf("%d", &pattern);
    printf("n =%d pattern = %d\n", n, pattern);
    generateString(n,pattern);
    divideString(n);
    pumping(pattern);
    return 0;
}*/

//CNF********************************************
/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[100];

int ispalindrome(int length){
    for(int i=0, j=length-1; i<=length || j>=0; i++, j--){
        if(str[i] != str[j]){
            return 1;
        }
    }
    return 0;
}

void cfg(char strp[],int length){
    char str1[100], str2[100], str3[100];
    strcpy(str2, strp);
    int i, j, lenS;
    lenS = strlen(str);
    for(i=1, j=0; i<length-1 && j<length-1; i++, j++){
        str1[j] = str2[i];
    }
    str1[j] = '\0';
    //printf("str1:%s\n", str1);
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
        for(j=((lenS-len1)/2)+len1, k=k+3; j<lenS && (k<len1+(lenS-len1)); j++, k++){
            str3[k] = str[j];
        }
        str3[k] = '\0';
        printf("%s=> ",str3);
        cfg(str1, len1);
    }
}

int main(void){
    printf("Enter the string:");
    gets(str);
    int length = strlen(str);
    int result= ispalindrome(length);
    if(result == 1){
        printf("Not in this grammar.\n");
    }
    else{
        printf("p=> ");
        printf("%cp%c=> ", str[0], str[length-1]);
        cfg(str,length);
    }
    return 0;
}*/

//leftRight most**********************
/*#include<stdio.h>
#include<string.h>

char str[100];
char A[2][10] = {"0A", ""};
char B[3][10] = {"0B", "1B", ""};
char S[10] = "A1B";
char str1[100];

void replacement(char str1[], char *replace, int p){
    int length = strlen(str1);
    int replacementLength = strlen(replace);
    char modified[100];
    int j=0;
    for(int i=0; i<length; i++){
        if(i == p){
            for(int k =0; k<replacementLength; k++){
                modified[j++] = replace[k];
            }
        }
        else{
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
    for(int i=0; i<length; i++){
        if(str[i] == '0' && str1[i] == 'A'){
            replacement(str1, A[0], i);
        }
        else if(str[i] == '1' && str1[i]=='A'){
            replacement(str1, A[1], i);
        }
        else if(str[i] == '0' && str1[i] == 'B'){
            replacement(str1, B[0], i);
        }
        else if(str[i] == '1' && str1[i] == 'B'){
            replacement(str1, B[1], i);
        }
    }
    printf("%s ", str);
    
}

int main(void){
    printf("Enter the String:");
    gets(str);
    printf("leftmost:");
    printf("S=>A1B=>");
    leftmost();
    printf("\n");
    return 0;
}*/

//Regular expression 
/*#include<stdio.h>
#include<string.h>
int main(void){
    char r[3][3][10];
    char r1[3][3][100] = {"\0"};
    int i, j,k;
    for(i=0; i<3; i++){
       for(j=0; j<3; j++){
            scanf("%s",r[i][j]);
       }
    }
    printf("Rij(1):\n");
    k = 1;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
           printf("r%d%d = %s+%s(%s)*%s\n",i,j,r[i][j],r[i][k],r[k][k],r[k][j]);
           strcat(r1[i][j],r[i][j]);
           strcat(r1[i][j],"+");
           strcat(r1[i][j],r[i][k]);
           strcat(r1[i][j],"(");
           strcat(r1[i][j],r[k][k]);
           strcat(r1[i][j],")");
           strcat(r1[i][j],"*");
           strcat(r1[i][j],r[k][j]);
        }
    }

    k=2;
    printf("Rij(2):\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
           printf("r%d%d = %s + %s(%s)*%s\n",i,j,r1[i][j],r1[i][k],r1[k][k],r1[k][j]);
        }
    }

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dfa[3][2];
char RE[3][3][3][100];
int main()
{
    freopen("table.txt", "r", stdin);
    printf("Enter the transition table: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &dfa[i][j]);
        }
    }

    printf("Transition table-\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", dfa[i][j]);
        }
        printf("\n");
    }

    printf("Enter the value of R[0][i][j]\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%s", RE[0][i][j]);
        }
    }

    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            printf("RE(0)%d%d %s\n", j, k, RE[j][k]);
        }
    }
    for (int m = 1; m < 3; m++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int k = 1;
                strcpy(RE[m][i][j], RE[m - 1][i][j]);
                strcat(RE[m][i][j], "+");
                strcat(RE[m][i][j], RE[m - 1][i][k]);
                // if(RE[m-1][k][k]!=""){
                strcat(RE[m][i][j], "(");
                strcat(RE[m][i][j], RE[m - 1][k][k]);
                strcat(RE[m][i][j], ")*");
                //}
                strcat(RE[m][i][j], RE[m - 1][k][j]);
            }
        }
    }
    for (int m = 0; m < 3; m++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                printf("RE(%d)%d%d %s\n", m, j, k, RE[m][j][k]);
            }
        }
    }
}