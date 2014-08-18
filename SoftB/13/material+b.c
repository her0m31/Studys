
int main()
{
  float t_quant;
  int p0;
  int q0;
  int i;
  
  init_buhin();

  p0 = 0;
  for (i = 0; i < 14; i++){
    
    if (buhin[i].n_spart == 0){
      
      t_quant = get_q(p0, i);
      
      printf("Total quantity of %s is %f in %s. \n", 
             buhin[i].part_name, t_quant, buhin[p0].part_name);
    }
  }
  
  return 0;
}
