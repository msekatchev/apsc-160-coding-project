#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

void processTextFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    int totalWords = 0;

    printf("Basic text analysis for file: %s\n", filename);
    printf("----------------------------------------\n");

    // Simple word counter
    while (fscanf(file, "%99s", word) == 1) {
        // Remove punctuation from the end of the word
        int len = strlen(word);
        while (len > 0 && ispunct(word[len - 1])) {
            word[len - 1] = '\0';
            len--;
        }
        
        if (strlen(word) > 0) {
            totalWords++;
            // Convert to lowercase for case-insensitive counting
            for (int i = 0; word[i]; i++) {
                word[i] = tolower(word[i]);
            }
            
            // Here you could add more analysis functions
            // For now, just count words
        }
    }

    printf("Total words in text: %d\n", totalWords);
    fclose(file);
}

int main() {
    const char* filename = "sample_text.txt"; // Replace with your text file
    processTextFile(filename);
    return 0;
}