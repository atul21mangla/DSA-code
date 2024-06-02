#include <stdio.h>
#include <string.h>

void computeLPSArray(char *pattern, int patternLength, int *lpsArray);

void KMPSearch(char *pattern, char *text)
{
    int found = 0;
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int lpsArray[patternLength];
    computeLPSArray(pattern, patternLength, lpsArray);

    int i = 0;
    int j = 0;
    while ((textLength - i) >= (patternLength - j))
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        if (j == patternLength)
        {
            printf("Found pattern at shift %d\n", i - j);
            found = 1;
            j = lpsArray[j - 1];
        }
        else if (i < textLength && pattern[j] != text[i])
        {
            if (j != 0)
                j = lpsArray[j - 1];
            else
                i = i + 1;
        }
    }
    if (found == 0)
        printf("Match Not Found At Any Index!!");
}

void computeLPSArray(char *pattern, int patternLength, int *lpsArray)
{
    int len = 0;
    lpsArray[0] = 0;
    int i = 1;
    while (i < patternLength)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lpsArray[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lpsArray[len - 1];
            }
            else
            {
                lpsArray[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    char text[1000];
    char pattern[1000];
    printf("Enter the main String:\n");
    scanf("%s", text);
    printf("Enter the pattern String:\n");
    scanf(" %s", pattern);
    KMPSearch(pattern, text);
    return 0;
}