#include <stdio.h>
#include <string.h>

int nfind(char *str, char *pat)
{
    int i, j, start = 0;
    int lasts = strlen(str) - 1;
    int lastp = strlen(pat) - 1;
    int endmatch = lastp;

    for (i = 0; endmatch <= lasts; endmatch++, start++) {
        if (str[endmatch] == pat[lastp]) {
            j = 0;
            for (i = start; j < lastp && str[i] == pat[j]; i++)
                j++;
            if (j == lastp)
                return start;
        }
    }
    return -1;
}

void StrReplace(char *string, char *pat, char *Rep)
{
    int i, j;
    char Res[50];
    int pos = 0;

    while (pos != -1) {
        pos = nfind(string, pat);
        Res[0] = '\0';
        if (pos == -1) {
            printf("\n%s is not found in %s\n", pat, string);
        } else {
            printf("\n%s is found at pos %d in %s",
                   pat, pos, string);
            for (i = 0; i < pos; i++)
                Res[i] = string[i];
            for (j = 0; j < strlen(Rep); j++)
                Res[i++] = Rep[j];
            for (j = pos + strlen(pat); string[j] != '\0'; j++)
                Res[i++] = string[j];
            Res[i] = '\0';
            printf("\nAfter Replace %s\n", Res);
            for (i = 0; i < strlen(Res); i++)
                string[i] = Res[i];
            string[i] = '\0';
        }
    }
}

int main()
{
    char string[] = {"AADAACAADAABAADAA"};
    char pat[] = {"ADAA"};
    char Rep[] = {"XXX"};
    StrReplace(string, pat, Rep);
    return 0;
}
