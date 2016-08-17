/* material.c */
 #include<stdio.h>

struct item {
  char  *part_name;
  int   n_spart;
  int   spart[10];
  float q_spart[10];
} buhin[20];
  
void init_buhin(void);
 
float get_q(int p, int q);
  
int main()
{
  float t_quant;
  int p0;
  int q0;
  
  init_buhin();

  p0 = 0;
  q0 = 11;

  t_quant = get_q(p0, q0);

  printf("Total quantity of %s is %f in %s. \n", 
         buhin[q0].part_name, t_quant, buhin[p0].part_name);

  return 0;
}

void init_buhin(void)
{
  buhin[0].part_name = "メニュー";
  buhin[0].n_spart = 4;
    buhin[0].spart[0] = 1;
    buhin[0].q_spart[0] = 20.0;
    buhin[0].spart[1] = 2; 
    buhin[0].q_spart[1] = 15.0;
    buhin[0].spart[2] = 3;  
    buhin[0].q_spart[2] = 30.0;
    buhin[0].spart[3] = 4; 
    buhin[0].q_spart[3] = 10.0;

  buhin[1].part_name = "カツ定";
  buhin[1].n_spart = 3;
    buhin[1].spart[0] = 5;
    buhin[1].q_spart[0] = 1.0;
    buhin[1].spart[1] = 6; 
    buhin[1].q_spart[1] = 1.0;
    buhin[1].spart[2] = 7;  
    buhin[1].q_spart[2] = 1.0;

  buhin[2].part_name = "カツ丼";
  buhin[2].n_spart = 2;
    buhin[2].spart[0] = 8;
    buhin[2].q_spart[0] = 1.0;
    buhin[2].spart[1] = 6; 
    buhin[2].q_spart[1] = 1.0;

  buhin[3].part_name = "ラーメン";
  buhin[3].n_spart = 2;
    buhin[3].spart[0] = 9;
    buhin[3].q_spart[0] = 1.0;
    buhin[3].spart[1] = 10; 
    buhin[3].q_spart[1] = 1.0;

  buhin[4].part_name = "カツ丼セット";
  buhin[4].n_spart = 2;
    buhin[4].spart[0] = 2;
    buhin[4].q_spart[0] = 1.0;
    buhin[4].spart[1] = 3; 
    buhin[4].q_spart[1] = 1.0;

  buhin[5].part_name = "おかず";
  buhin[5].n_spart = 2;
    buhin[5].spart[0] = 11;
    buhin[5].q_spart[0] = 1.0;
    buhin[5].spart[1] = 12; 
    buhin[5].q_spart[1] = 1.0;

  buhin[6].part_name = "ごはん";
  buhin[6].n_spart = 0;

  buhin[7].part_name = "味噌汁";
  buhin[7].n_spart = 0;

  buhin[8].part_name = "具";
  buhin[8].n_spart = 2;
    buhin[8].spart[0] = 11;
    buhin[8].q_spart[0] = 1.0;
    buhin[8].spart[1] = 13; 
    buhin[8].q_spart[1] = 1.0;

  buhin[9].part_name = "麺";
  buhin[9].n_spart = 0;

  buhin[10].part_name = "スープ";
  buhin[10].n_spart = 0;

  buhin[11].part_name = "トンカツ";
  buhin[11].n_spart = 0;


  buhin[12].part_name = "キャベツ";
  buhin[12].n_spart = 0;

  buhin[13].part_name = "玉子";
  buhin[13].n_spart = 0;
}

float get_q(int p, int q)
{
  int i;
  float r = 0.0;

  if (p == q)
    r = 1.0;
  else if (buhin[p].n_spart != 0)
    for (i = 0; i < buhin[p].n_spart; i++)
      r += get_q(buhin[p].spart[i], q) * buhin[p].q_spart[i];

  return r;
}
