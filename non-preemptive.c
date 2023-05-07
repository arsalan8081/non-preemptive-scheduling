#include<stdio.h>

int main() {
  int time, sum_bt = 0, smallest, n, i;
  int sumt = 0, sumw = 0;
  printf("Enter the no. of processes : ");
  scanf("%d", & n);
  int bt[n], at[n];
  for (i = 0; i < n; i++) {
    printf("Enter Arrival Time & Burst Time for process P%d : ", i + 1);
    scanf("%d%d", &at[i],&bt[i]);
    sum_bt += bt[i];
  }
  printf("\nProcess\t|\tAT\t|\tBT\t|\tCT\t|\tTAT\t|\tWT\t|\tRT\n");
  bt[9] = 9999;
  for (time = 0; time < sum_bt;) {
    smallest = 9;
    for (i = 0; i < n; i++) {
      if (at[i] <= time && bt[i] > 0 && bt[i] < bt[smallest])
        smallest = i;
    }
    printf("P%d\t\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", smallest+1,at[smallest],bt[smallest],time+bt[smallest],time+bt[smallest]- at[smallest],time-at[smallest],time-at[smallest]);
    sumt += time + bt[smallest] - at[smallest];
    sumw += time - at[smallest];
    time += bt[smallest];
    bt[smallest] = 0;
  }
  printf("\n\nAverage Waiting Time = %f", sumw * 1.0 / n);
  printf("\n\nAverage Turn Around Time = %f", sumt * 1.0 / n);
  return 0;
}
