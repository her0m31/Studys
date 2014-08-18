

/* coulomb-function.c */

extern PI;                                   /* PI  e0  q  es  r   */
extern e0;                                   /* ��   ��  ����       */
                                             /* ��   ��            */       
double coulomb(double q, double es, double r)/* ��   �� ��  ��  ��  */
{                                            /* ��   �� ��  ��  ��  */
  return q / (4.0 * PI * es * e0 * r * r);   /* ��   �� ��  ��  ��  */
}                                            /* ��   �� ��  ��  ��  */
