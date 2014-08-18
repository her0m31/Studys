/* list.h */
struct cell{
  float value;
  struct cell *next;
};
int push(float data);
int pop(float *data);
int insert_cell(struct cell **pointer, float new_value);
void delete_cell(struct cell **poniter);
