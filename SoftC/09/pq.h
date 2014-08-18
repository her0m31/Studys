/* pq.h */
#define QueueCapacity 6
int insert(int *queue, int new_value);
int maximum(int *queue);
int extractmax(int *queue);
void downheap(int *queue, int v, int n);
void to_heapsort(int *data, int n);
