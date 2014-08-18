

/* coulomb-function.c */

extern PI;                                   /* PI  e0  q  es  r   */
extern e0;                                   /* ¢¬   ¢¬  ¡¡¡¡       */
                                             /* ¡Ã   ¡Ã            */       
double coulomb(double q, double es, double r)/* ¡Ã   ¡Ã ¢¬  ¢¬  ¢¬  */
{                                            /* ¡Ã   ¡Ã ¡Ã  ¡Ã  ¡Ã  */
  return q / (4.0 * PI * es * e0 * r * r);   /* ¡Ã   ¡Ã ¡Ã  ¡Ã  ¡Ã  */
}                                            /* ¢­   ¢­ ¢­  ¢­  ¢­  */
