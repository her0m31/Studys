/* engine.c */
#include<stdio.h>

struct item {
  char  *part_name;
  int   n_spart;
  int   spart[10];
  float q_spart[10];
} buhin[30];
  
void init_buhin(void);
 
float get_q(int p, int q);
  
int main()
{
  float t_quant;
  int p0;
  int q0;
  int i;

  init_buhin();

  p0 = 0;
  for (i = 0; i < 22; i++){
  
    if (buhin[i].n_spart == 0){
      t_quant = get_q(p0, i);
      
      printf("Total quantity of %s is %f in %s. \n", 
             buhin[i].part_name, t_quant, buhin[p0].part_name);
    }
  }
  return 0;
}

void init_buhin(void)
{
  buhin[0].part_name = "部品";
  buhin[0].n_spart = 4;
    buhin[0].spart[0] = 1;
    buhin[0].q_spart[0] = 10.0;
    buhin[0].spart[1] = 2; 
    buhin[0].q_spart[1] = 6.0;
    buhin[0].spart[2] = 3;  
    buhin[0].q_spart[2] = 4.0;
    buhin[0].spart[3] = 4;  
    buhin[0].q_spart[3] = 0.0;

  buhin[1].part_name = "直４エンジン";
  buhin[1].n_spart = 4;
    buhin[1].spart[0] = 4;
    buhin[1].q_spart[0] = 1.0;
    buhin[1].spart[1] = 15; 
    buhin[1].q_spart[1] = 1.0;
    buhin[1].spart[2] = 6;  
    buhin[1].q_spart[2] = 1.0;
    buhin[1].spart[3] = 3;  
    buhin[1].q_spart[3] = 4.0;

  buhin[2].part_name = "V8エンジン";
  buhin[2].n_spart = 4;
    buhin[2].spart[0] = 4;
    buhin[2].q_spart[0] = 2.0;
    buhin[2].spart[1] = 16; 
    buhin[2].q_spart[1] = 2.0;
    buhin[2].spart[2] = 5; 
    buhin[2].q_spart[2] = 1.0;
    buhin[2].spart[3] = 3; 
    buhin[2].q_spart[3] = 8.0;

  buhin[3].part_name = "PSAssy";
  buhin[3].n_spart = 4;
    buhin[3].spart[0] = 11;
    buhin[3].q_spart[0] = 1.0;
    buhin[3].spart[1] = 12; 
    buhin[3].q_spart[1] = 1.0;
    buhin[3].spart[2] = 13; 
    buhin[3].q_spart[2] = 1.0;
    buhin[3].spart[3] = 14; 
    buhin[3].q_spart[3] = 2.0;
  
  buhin[4].part_name = "SHAssy";
  buhin[4].n_spart = 4;
    buhin[4].spart[0] = 19;
    buhin[4].q_spart[0] = 1.0;
    buhin[4].spart[1] = 20; 
    buhin[4].q_spart[1] = 1.0;
    buhin[4].spart[2] = 21; 
    buhin[4].q_spart[2] = 2.0;
    buhin[4].spart[3] = 9; 
    buhin[4].q_spart[3] = 10.0;

  buhin[5].part_name = "CCA(直8用)";
  buhin[5].n_spart = 4;
    buhin[5].spart[0] = 16;
    buhin[5].q_spart[0] = 1.0;
    buhin[5].spart[1] = 17; 
    buhin[5].q_spart[1] = 1.0;
    buhin[5].spart[2] = 18; 
    buhin[5].q_spart[2] = 1.0;
    buhin[5].spart[3] = 10; 
    buhin[5].q_spart[3] = 10.0;

  buhin[6].part_name = "CCA(直４用)";
  buhin[6].n_spart = 4;
    buhin[6].spart[0] = 7;
    buhin[6].q_spart[0] = 1.0;
    buhin[6].spart[1] = 8; 
    buhin[6].q_spart[1] = 1.0;
    buhin[6].spart[2] = 9; 
    buhin[6].q_spart[2] = 1.0;
    buhin[6].spart[3] = 10; 
    buhin[6].q_spart[3] = 10.0;

    buhin[7].part_name = "クランクケース(直4用)";
    buhin[7].n_spart = 0;

    buhin[8].part_name = "クランクシャフト(直4用)";
    buhin[8].n_spart = 0;

    buhin[9].part_name = "クランクケースカバー(直4用)";
    buhin[9].n_spart = 0;

    buhin[10].part_name = "ボルト";
    buhin[10].n_spart = 0;

    buhin[11].part_name = "ピストン";
    buhin[11].n_spart = 0;

    buhin[12].part_name = "ガスケット";
    buhin[12].n_spart = 0;

    buhin[13].part_name = "コンロッド";
    buhin[13].n_spart = 0;

    buhin[14].part_name = "ピストングリップ";
    buhin[14].n_spart = 0;
 
    buhin[15].part_name = "シリンダ(直4用)";
    buhin[15].n_spart = 0;

    buhin[16].part_name = "シリンダ(V8用)";
    buhin[16].n_spart = 0;
  
    buhin[17].part_name = "クランクケース(V8用)";
    buhin[17].n_spart = 0;

    buhin[18].part_name = "クランクシャフト(V8用)";
    buhin[18].n_spart = 0;

    buhin[19].part_name = "シリンダヘッド";
    buhin[19].n_spart = 0;

    buhin[20].part_name = "シリンダヘッドカバー";
    buhin[20].n_spart = 0;

    buhin[21].part_name = "カムシャフト";
    buhin[21].n_spart = 0;
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
