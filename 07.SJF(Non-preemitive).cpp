#include <stdio.h>
typedef struct {
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;
void calculateTimes(Process processes[], int n) {
    int current_time = 0, completed = 0;
    while (completed < n) {
        int shortest_index = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].completion_time == 0) {
                if (shortest_index == -1 || processes[i].burst_time < processes[shortest_index].burst_time) {
                    shortest_index = i;
                }
            }
        }
        if (shortest_index != -1) {
            current_time += processes[shortest_index].burst_time;
            processes[shortest_index].completion_time = current_time;
            processes[shortest_index].turnaround_time = processes[shortest_index].completion_time - processes[shortest_index].arrival_time;
            processes[shortest_index].waiting_time = processes[shortest_index].turnaround_time - processes[shortest_index].burst_time;
            completed++;
        } else {
            current_time++;
        }
    }
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for process %d: ", processes[i].pid);
        scanf("%d", &processes[i].burst_time);
        printf("Enter arrival time for process %d: ", processes[i].pid);
        scanf("%d", &processes[i].arrival_time);
        processes[i].completion_time = 0;
    }
    calculateTimes(processes, n);
    printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].pid, processes[i].burst_time, processes[i].arrival_time,
               processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    return 0;
}
