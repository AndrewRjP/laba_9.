//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <locale.h>
#include <string.h>
#define MAXLINE 255

int equalWords(char str[])
{
  char temp[MAXLINE];
  strcpy(temp, str);
  const char* limits = " \n.,;!?";
  for(int i = 0; 1; i++)
  {
    char t[MAXLINE];
    strcpy(t, temp);
    char* ptr = strtok(t, limits);
    char word[MAXLINE];
    for (int j = 0; j < i; j++)
      ptr = strtok(NULL, limits);
    if (!ptr) return 0;
    strcpy(word, ptr);
      ptr = strtok(NULL, limits);
    while (ptr)
    {
      if (strcmp(ptr, word) == 0) return 1;
      ptr = strtok(NULL, limits);
    }
  }
}

int vowelCounter(char *s)
{
  int count = 0;
  for (int i = 0; i < strlen(s); i++)
    if (s[i] == 'a' || s[i] == 'A' || s[i] == 'u' || s[i] == 'U' || s[i] == 'e' || s[i] == 'E' ||
      s[i] == 'o' || s[i] == 'O' || s[i] == 'y' || s[i] == 'Y' || s[i] == 'i' || s[i] == 'I')
      count++;
  return count;
}

int main(void)
{
  char str[MAXLINE];
  char lStr[MAXLINE];
  FILE *fp1 = fopen("F1.txt", "w");
  printf("Fill file \"F1.txt\" with data:\n");
  for (int i = 1; 1; i++)
  {
    printf("Row %d: ", i);
    fgets(str, MAXLINE, stdin);
    str[strlen(str)-1] = '\0';
    fputs(str, fp1);
    fputs("\n", fp1);
    printf("Continue? 'y' - yes other button - no:");
    char sym;
    scanf("%c", &sym);
    getchar();
    if (sym != 'y') break;
  }
  fclose(fp1);
  fp1 = fopen("F1.txt", "r");
  FILE *fp2 = fopen("F2.txt", "w");

  int size = 0;
  while (fgets(str, MAXLINE, fp1))
  {
    if (equalWords(str)) {
      fputs(str, fp2);
      strcpy(lStr, str);
      size++;
    }
  }
  fclose(fp1);
  fclose(fp2);
  if(size > 0) printf("\nAmount of vowel letters in last row of file \"F2.txt\" = %d\n\n", vowelCounter(lStr));
  else printf("\file \"F2.txt\" is empty\n\n");

  getchar();
  return 0;
}
