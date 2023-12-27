#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void identifyComments(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    bool inMultiLineComment = false;
    int lineNum = 1;

    while (fgets(line, sizeof(line), file)) {
        
            char *single_line_comment = strstr(line, "//");
            char *start_multi_line_comment = strstr(line, "/*");
            char *end_multi_line_comment = strstr(line, "*/");

            if (single_line_comment) {
                printf("Line NUmber:%d\n",lineNum);
                printf("Single-line comment: %s\n", single_line_comment);
            }

            if (start_multi_line_comment) {
                if (end_multi_line_comment) {
                    printf("Line NUmber:%d\n",lineNum);
                    printf("Multi-line comment: %.*s\n", (int)(end_multi_line_comment - start_multi_line_comment +2),start_multi_line_comment);

                }
                else if(!end_multi_line_comment){
                    printf("Line number:%d\n", lineNum);
                    printf("Comment was not write properly.\n");
                }
                
            }
            
            lineNum++;
        
    }

    fclose(file);
}

int main() {
    const char *filename = "test_code.c";
    identifyComments(filename);
    return 0;
}
