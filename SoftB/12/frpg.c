/* frpg.c */
#include<stdio.h>

struct condition{
  int life;
  int magic;
  int str;
  unsigned int sleep: 1;  
  unsigned int chaos: 1;
  unsigned int palsy: 1;  
  unsigned int poison: 1;
};

void change_condition(struct condition *pc, int en_str, int en_poison);

void mc_condition(struct condition *pc);

int main()
{
  int i;
  struct condition mc = {200, 100, 10, 1, 0, 0, 0};

  mc_condition(&mc);
  for (i = 0; i < 3; i++){
    change_condition(&mc, 10, 1);
    printf("\n");   
    mc_condition(&mc); 
  }  
  
  return 0;
}

void mc_condition(struct condition *pc)
{
  printf("À¸Ì¿ÎÏ\t %d\n", pc->life);
  printf("ËâË¡ÎÏ\t %d\n", pc->magic);
  printf("ÎÏ\t %d\n",pc->str);
  if(pc->sleep == 1 || pc->chaos == 1 || pc->palsy == 1 || pc->poison == 1)
    printf("¾õÂÖ");
  if (pc->sleep == 1)
    printf("\t¿çÌ²\n");
  if (pc->chaos == 1)
    printf("\tº®Íð\n");
  if (pc->palsy == 1)
    printf("\tËãáã\n");
  if (pc->poison == 1)
    printf("\tÆÇ\n");
}

void change_condition(struct condition *pc, int en_str, int en_poison)
{
  if (pc->sleep == 1){
    (pc->life) = (pc->life) - (en_str);
    (pc->sleep)= 0;
  }
  else
    (pc->life) = (pc->life) - ((en_str) / 2);
  
  if (pc->poison == 1)
    --(pc->str);
  
  if (en_poison == 1)
    (pc->poison) = 1;
}
