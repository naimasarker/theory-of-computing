#include <stdio.h>
#include <string.h>

char trans(char transition[][2][3], char str[], int n, int m, char state[], char alpha[], char end, int currentSIn, int pos, char currentState) {
    if (currentState == '1') {
        return 0;
    }

    if (pos == strlen(str)) {
        if (currentState == end) {
            printf("\nAccepted\n");
            return currentState;
        }
        return 0;
    }

    int symbolIn, neState;

    char symbol = str[pos];

    for (symbolIn = 0; symbolIn < m; symbolIn++) {
        if (symbol == alpha[symbolIn]) {
            for (neState = 0; neState < n; neState++) {
                char nextState = transition[currentSIn][symbolIn][neState];
                if (nextState != '1') {
                    char result = trans(transition, str, n, m, state, alpha, end, nextState - 'A', pos + 1, nextState);
                    if (result != 0) {
                        return result; 
                    }
                }
            }
            break; 
        }
    }

    return 0; 
}

int main(void) {
    int numState, numAlpha;
    int i,j,k;
    printf("enter the num of state and num of alphabet: ");
    scanf("%d %d", &numState, &numAlpha);

    char state[numState + 1];
    char alpha[numAlpha + 1];

    printf("Alphabets: ");
    for (i = 0; i < numAlpha; i++) {
        scanf(" %c", &alpha[i]);
    }


    printf("States: ");
    for ( i = 0; i < numState; i++) {
        scanf(" %c", &state[i]);
    }

    char transition[numState][numAlpha][numState];

    printf("Transition table:\n");
    for (i = 0; i < numState; i++) {
        for (j = 0; j < numAlpha; j++) {
            for (k = 0; k < numState; k++) {
                printf("state %c-> %c:", state[i], alpha[j]);
                scanf(" %c", &transition[i][j][k]);
            }
        }
    }

    getchar();
    char str[100];
    char start = state[0];
    char end = state[numState - 1];

    printf("Enter the String: ");
    gets(str);


    char result = trans(transition, str, numState, numAlpha, state, alpha, end, 0, 0, start);

    if (result == 0) {
        printf("\nRejected\n");
    }

    return 0;
}
