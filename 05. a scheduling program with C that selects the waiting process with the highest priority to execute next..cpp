#include<stdio.h>

struct priority_scheduling {
  char process_name;
  int burst_time, waiting_time, turn_around_time, priority;
} temp_process;

int main() {
  int num, total = 0, ASCII = 65, pos;
  float avg_wt, avg_tat;

  printf("Enter total number of Processes: ");
  scanf("%d", &num);
  struct priority_scheduling process[num];

  for (int i = 0; i < num; i++, ASCII++) {
    process[i].process_name = ASCII;
    printf("\nEnter burst time and priority of process %c: ", process[i].process_name);
    scanf("%d %d", &process[i].burst_time, &process[i].priority);
  }

  for (int i = 0; i < num; i++) {
    pos = i;
    for (int j = i + 1; j < num; j++)
      if (process[j].priority > process[pos].priority) pos = j;
    temp_process = process[i]; process[i] = process[pos]; process[pos] = temp_process;
  }

  process[0].waiting_time = 0;
  for (int i = 1; i < num; i++) {
    process[i].waiting_time = 0;
    for (int j = 0; j < i; j++) process[i].waiting_time += process[j].burst_time;
    total += process[i].waiting_time;
  }

  avg_wt = (float) total / num;
  total = 0;
  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < num; i++) {
    process[i].turn_around_time = process[i].burst_time + process[i].waiting_time;
    total += process[i].turn_around_time;
    printf("  %c\t\t%d\t\t%d\t\t%d\n", process[i].process_name, process[i].burst_time, process[i].waiting_time, process[i].turn_around_time);
  }

  avg_tat = (float) total / num;
  printf("\nAverage Waiting Time: %f", avg_wt);
  printf("\nAverage Turnaround Time: %f\n", avg_tat);

  return 0;
}
