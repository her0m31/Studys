/* complex.h */

struct complex {
  double real;
  double imaginary;
};
struct complex add(struct complex x, struct complex y);
struct complex min(struct complex x, struct complex y);
struct complex mul(struct complex x, struct complex y);
struct complex div(struct complex x, struct complex y);
void put_complex(struct complex z);
