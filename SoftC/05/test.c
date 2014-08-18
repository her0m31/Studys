
char *animal[NUM_DATA] = {"Cat", "Dog", "Tiger", "Bug", "Bird",
                          "Fish", "Seep", "Cow", "Pig", "Rat"
};

void StrSort(char *str[ ], int n);
void main(void);

void StrSort(char *str[ ], int n)
{
  int i, j, k;
  char *temp;            /* ����ѥݥ��� */
  
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if ((strcmp(str[j], str[i])) < 0) {
        temp = str[i];                /* ����ѥݥ��󥿤�Ȥ� */
        str[i] = str[j];              /* i + 1���ܤ˾��������Ǥ� */
        str[j] = temp;                /* str[i] �����Ǥȸ� */
      }
    }
    for (k = 0; k < n; k++)            /* �����Ȥ�����в��ɽ�� */
      printf("%s  ", str[k]);
    printf("\n");
  }
}

int main()
{
  int i;
  
  printf("��������: ");

  for (i = 0;  i < NUM_DATA; i++)
    printf("%s  ", animal[i]);

  printf("\n\n");
  printf("�����ȳ���\n\n");

  StrSort(animal, NUM_DATA);/* animal���������Ƭ���ɥ쥹 */

  printf("\n�����ȸ�: ");/* �����ȷ�̤�ɽ�� */
  for (i = 0; i < NUM_DATA; i++)
    printf("%s  ", animal[i]);

  printf("\n");
}
