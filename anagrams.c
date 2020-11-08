#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define STRLN 250000

void test(void);

enum bool{true, false};
typedef enum bool bool;

bool is_anagram(char a[], char b[]);

/*anagram: nsik
  possible words: inks, kins, sink, skin*/

int main(void)
{
  char anagram[STRLN];
  char words[STRLN];

  test();

  scanf("%s", anagram);
  printf("\n");

  FILE * fpointer;
  if((fpointer = fopen("eng_370k_shuffle.txt", "r")) == NULL){
    printf("Error: cannot read file\n");
    exit(EXIT_FAILURE);
  }

  while(fscanf(fpointer, "%s", words) == 1){
    if(is_anagram(anagram, words) == true){
      printf("%s\n", words);
    }
  }
  fclose(fpointer);
  return 0;
}

bool is_anagram(char a[], char b[])
{
  int first[26] = {0}, second[26] = {0}, i = 0;

/*rule 1: each str cannot be identical*/
  if(strcmp(a, b) == 0){
    return false;
  }
/*rule 2: each str should be of equal length*/
  if(strlen(a) != strlen(b)){
    return false;
  }
/*rule 3: count of each character within each str should be equal*/
  while (a[i] != '\0') {
    first[a[i] - 'a']++;
    i++;
  }
  i = 0;
  while (b[i] != '\0') {
    second[b[i] - 'a']++;
    i++;
  }
  for (i = 0; i < 26; i++){
    if (first[i] != second[i]){
      return false;
    }
  }
  return true;
}

void test(void)
{
  char a[] = "nsik";
  char b[] = "skin";
  char c[] = "sink";
  char d[] = "sinks";
  char e[] = "poop";

  assert(is_anagram(a, b) == true);
  assert(is_anagram(a, c) == true);
  assert(is_anagram(a, d) == false);
  assert(is_anagram(a, e) == false);
  assert(is_anagram(a, b) == true);
}
