/* coulomb-main.c */

#include <stdio.h>
double PI = 3.142;                              /*PI  e0  q  r  es  r    */
double e0 = 8.854e-12;                          /*ขฌ  ขฌ                  */

double coulomb(double q, double es, double r);  /*กร  กร  ขซ กÝ กÝ กÝ ขช   */

int main()                                      /*กร  กร                  */
{
  double q, es, r;                              /*กร  กร  ขฌ  ขฌ  ขฌ  ขฌ   */

  printf("q?  ");                               /*กร  กร  กร  กร  กร  กร   */
  scanf("%f", &q);                               
                                                /*กร  กร  กร  กร  กร  กร   */
  printf("es?  ");                               
  scanf("%f", &es);                             /*กร  กร  กร  กร  กร  กร   */
                                                 
  printf("r?  ");                               /*กร  กร  กร  กร  กร  กร   */
  scanf("%f", &r);                               
                                                /*กร  กร  กร  กร  กร  กร   */
  printf("E = %e\n", coulomb(q, es, r));         
}                                               /*ขญ  ขญ  ขญ  ขญ  ขญ  ขญ   */
