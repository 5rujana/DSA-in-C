#include <stdio.h>

int main() {
    int lineCount = 0;
    int wordCount = 0;
    int ch;
    int isNewLine = 1; // Indicates if the current character starts a new line

    printf("Enter text (type '#' and press Enter to end):\n");

    while ((ch = getchar()) != '#') {
        // Increment line count if a newline character is encountered
        if (ch == '\n') {
            lineCount++;
            isNewLine = 1;
        }
        // Increment word count if a non-space character is encountered and isNewLine is set
        else if (ch != ' ' && ch != '\t' && ch != '\r') {
            if (isNewLine) {
                wordCount++;
                isNewLine = 0;
            }
        }
        // Reset isNewLine when encountering a space, tab, or carriage return character
        else {
            isNewLine = 1;
        }
    }

    // Increment line count and word count if the last character was not '#'
    if (ch != '#') {
        lineCount++;
        wordCount++;
    }

    // Print the counts
    printf("Line count: %d\n", lineCount);
    printf("Word count: %d\n", wordCount);

    return 0;
}
