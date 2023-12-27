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