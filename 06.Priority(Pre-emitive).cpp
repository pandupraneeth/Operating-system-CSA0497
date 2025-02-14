#include <stdio.h>
#include <stdbool.h>
typedef struct {
    int pid;
    int burst_time;
    int remaining_time;
    int priority;
    int arrival_time;
} Process;
int findNextProcess(Process processes[], int n, int current_time) {
    int highest_priority = -1;
    int next_process = -1;
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
            if (highest_priority == -1 || processes[i].priority < highest_priority) {
                highest_priority = processes[i].priority;
                next_process = i;
            }
        }
    }
    return next_process;
}
void preemptivePriorityScheduling(Process processes[], int n) {
    int current_time = 0;
    int completed_processes = 0;
    while (completed_processes < n) {
        int next_process = findNextProcess(processes, n, current_time);
        if (next_process == -1) {
            current_time++;
            continue;
        }
        processes[next_process].remaining_time--;
        current_time++;

        if (processes[next_process].remaining_time == 0) {
            completed_processes++;
            printf("Process %d finished at time %d\n", processes[next_process].pid, current_time);
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
        printf("Enter priority for process %d: ", processes[i].pid);
        scanf("%d", &processes[i].priority);
        printf("Enter arrival time for process %d: ", processes[i].pid);
        scanf("%d", &processes[i].arrival_time);
        processes[i].remaining_time = processes[i].burst_time;
    }
    preemptivePriorityScheduling(processes, n);
    return 0;
}
