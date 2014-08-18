
char *animal[NUM_DATA] = {"Cat", "Dog", "Tiger", "Bug", "Bird",
                          "Fish", "Seep", "Cow", "Pig", "Rat"
};

void StrSort(char *str[ ], int n);
void main(void);

void StrSort(char *str[ ], int n)
{
  int i, j, k;
  char *temp;            /* 作業用ポインタ */
  
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if ((strcmp(str[j], str[i])) < 0) {
        temp = str[i];                /* 作業用ポインタを使い */
        str[i] = str[j];              /* i + 1番目に小さい要素と */
        str[j] = temp;                /* str[i] の要素と交換 */
      }
    }
    for (k = 0; k < n; k++)            /* ソートの途中経過を表示 */
      printf("%s  ", str[k]);
    printf("\n");
  }
}

int main()
{
  int i;
  
  printf("ソート前: ");

  for (i = 0;  i < NUM_DATA; i++)
    printf("%s  ", animal[i]);

  printf("\n\n");
  printf("ソート開始\n\n");

  StrSort(animal, NUM_DATA);/* animalは配列の先頭アドレス */

  printf("\nソート後: ");/* ソート結果を表示 */
  for (i = 0; i < NUM_DATA; i++)
    printf("%s  ", animal[i]);

  printf("\n");
}
