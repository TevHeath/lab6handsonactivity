#include <stdio.h>
#include <string.h>

#define MAX_BUF 256

int main()
{
    char buf[MAX_BUF];
    int letterCount[26] = {0}; // Array to store the count of each letter initialized to zeros

    printf("Enter text strings (press Enter on an empty line to exit):\n");

    while (1)
    {
        if (!fgets(buf, sizeof(buf), stdin)) // Error handling for fgets
            break;

        // Check for an empty line to exit the loop
        if (strlen(buf) == 1 && buf[0] == '\n')
        {
            break;
        }

        // If buffer is full and the last character isn't a newline, read and discard the remaining characters.
        if (buf[strlen(buf) - 1] != '\n')
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }

        // Iterate through the characters in the buf
        for(int i = 0; i < strlen(buf); i++)
        {
            if (buf[i] >= 65 && buf[i] <= 90) // ASCII value for 'A' is 65 and for 'Z' is 90
            {
                letterCount[buf[i] - 65]++;
            }
            else if (buf[i] >= 97 && buf[i] <= 122) // ASCII value for 'a' is 97 and for 'z' is 122
            {
                letterCount[buf[i] - 97]++;
            }
        }
    }

    // Display the letter counts
    printf("Distribution of letters in the input:\n");
    for(int i = 0; i < 26; i++)
    {
        printf("%c: %d ", 'A' + i, letterCount[i]);
        if((i+1) % 10 == 0) // Newline for every 10 letters for better formatting
        {
            printf("\n");
        }
    }

    return 0;
}
