/* timetable.c */
#include<stdio.h>

#define N 40

struct time{
  int hour;
  int min;
};

void search (struct time *now, struct time *timetable);

int main()
{
  struct time current;
  struct time igr[N] = {{ 6,21}, { 6,34}, { 6,49}, { 7,13}, { 7,28},
                        { 7,35}, { 7,43}, { 7,50}, { 8, 0}, { 8,34},
                        { 8,45}, { 9, 2}, { 9,17}, { 9,40}, {10,16},
                        {10,42}, {11, 9}, {11,43}, {12,10}, {12,30},
                        {13,12}, {13,41}, {14,12}, {14,38}, {15, 5},
                        {15,39}, {16,25}, {16,38}, {17, 0}, {17,41},
                        {18,21}, {18,37}, {18,51}, {19,18}, {20,16},
                        {20,29}, {21,02}, {21,33}, {22, 8}, {22,27}};

  printf("Enter current time [hh:mm] : "); 
  scanf("%2d : %2d", &current.hour, &current.min);

  search (&current, igr);

  return 0;
}

void search (struct time *now, struct time *timetable)
{
  int i, j;
  
  printf("\t Departure \t Waiting time\n");
  
  j = 0;
  for(i = 0; i < 40 && j < 3; i++){
    if (now->hour == (timetable + i)->hour && now->min < (timetable + i)->min 
                                                      || now->hour < (timetable + i)->hour){
      printf("%d)\t %d:%02d \t\t %d[min.]\n", ++j, (timetable + i)->hour, (timetable + i)->min,
         (((timetable + i)->hour * 60) + (timetable + i)->min) - ((now->hour * 60) + now->min));
    }
  }
}
