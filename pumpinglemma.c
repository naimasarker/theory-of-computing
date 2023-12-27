/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char w[100], x[10], y[10], z[80], y1[80], w1[100];
int i,j, lenW,lenW1,count0=0,count1=0;

void generateString(int n) {
    int  index=0;
    for (i = 0; i < n; i++) {
        w[index++] = '0';
    }
    for (i = 0; i < n; i++) {
        w[index++] = '1';
    }
    printf("%s\n", w);

    int length = strlen(w);
}

void divideString(int n){
    for(i=0; i<1; i++){
        x[i] = w[i];
    }
    x[i] = '\0';
    for(j=0,i=1; i<n; i++,j++){
        y[j] = w[i];
    }
    y[j] = '\0';
    
    for(j=0,i=n; w[i]!='\0'; i++,j++){
        z[j] = w[i];
    }
    z[j] = '\0';
    printf("%s\n", x);
    printf("%s\n",y);
    printf("%s\n",z);
}

int concatinate(){
    strcpy(w1,"");
    strcat(w1,x);
    strcat(w1,y1);
    strcat(w1,z);
    printf("W1:%s\n",w1);
    lenW1 = strlen(w1);
    int current0=0, current1=0;
    for(i=0; w1[i] != '\0' ; i++){
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
        if(current1>count1){
            count1 = current1;
        }
    }
    if(count0 != count1){
        printf("This  is not a ragular language\n");
        return 1;
    }
    else{
        printf("This is a ragular language.\n");
    }
    return 0;
}

void pumping(){
    int k;
    for(k=0; ; k++){
        if(k == 0){
            strcpy(y1, "");
            int r = concatinate();
            if(r==1){
                break;
            }
        }
        strcat(y1, y);
        int r = concatinate();
        if(r==1){
            break;
        }
    }
}

int main() {
    int n;
    srand(time(NULL));
    n = rand() % 10 + 2;
    printf("n = %d\n", n);
    generateString(n);
    divideString(n);
    pumping();
    return 0;
}*/
//****************************************************
//0^n1^n and 0^n1^2n together
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char w[100], x[10], y[10], z[80], yp[80], w1[100];
int i,j, lenW,lenW1,count0=0,count1=0;

void generateString(int n, int pattern) {
    int index=0;
    if (pattern == 1) {
        for (i = 0; i < n; i++) {
            w[index++] = '0';
        }
        for (i = 0; i <n; i++) {
            w[index++] = '1';
        }
    } else if (pattern == 2) {
        for (i = 0; i < n; i++) {
            w[index++] = '0';
        }
        for (i = 0; i <2*n; i++) {
            w[index++] = '1';
        }
    }
    printf("W:%s\n", w);
    int lenW = strlen(w);
}

void divideString(int n){
    for(i=0; i<1; i++){
        x[i] = w[i];
    }
    x[i] = '\0';
    for(j=0,i=1; i<n; i++,j++){
        y[j] = w[i];
    }
    y[j] = '\0';
    
    for(j=0,i=n; w[i]!='\0'; i++,j++){
        z[j] = w[i];
    }
    z[j] = '\0';
    printf("x:%s\n", x);
    printf("y:%s\n",y);
    printf("z:%s\n",z);
}

int concatinate(int pattern){
    strcpy(w1,"");
    strcat(w1,x);
    strcat(w1,yp);
    strcat(w1,z);
    printf("W1:%s\n",w1);
    lenW1 = strlen(w1);
    int current0=0, current1=0;
    for(i=0; w1[i] != '\0' ; i++){
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
        if(current1>count1){
            count1 = current1;
        }
    }
    if(pattern == 1){
        if(count0 != count1){
        printf("This  is not a ragular language\n");
        return 1;
        }
        else{
            printf("This is a ragular language.\n");
        }
    }

    if(pattern == 2){
        if((2*count0) != count1){
        printf("This  is not a ragular language\n");
        return 1;
        }
        else{
            printf("This is a ragular language.\n");
        }
    }
    
    return 0;
}

void pumping(int pattern){
    int k;
    for(k=0; ; k++){
        if(k == 0){
            strcpy(yp, "");
            int r = concatinate(pattern);
            if(r==1){
                break;
            }
        }
        strcat(yp, y);
        int r = concatinate(pattern);
        if(r==1){
            break;
        }
    }
}

int main() {
    int n, pattern;
    srand(time(NULL));
    n = rand() % 10 + 2;
    printf("n = %d\n", n);
    printf("Enter the pattern (1 for 0^n1^n, 2 for 0^n1^2n): ");
    scanf("%d", &pattern);
    printf("n = %d, Pattern = %d\n", n, pattern);
    generateString(n, pattern);
    divideString(n);
    pumping(pattern);
    return 0;
}
