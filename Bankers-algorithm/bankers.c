#include<stdio.h>
#include<stdlib.h>

void main() {
  int n, m, i, avail[10], j, max[10][10], alloc[10][10], need[10][10], finish[10];
  int flag, y = 0, fin[70], l, k;
  printf("Enter the number of process :\n");
  scanf("%d", & n);
  printf("Enter the number of resources :\n");
  scanf("%d", & m);
  printf("Enter the AVAILABLE number of instance for each resource :\n");
  for (i = 0; i < m; i++) {
    printf("Resource %d\t", i + 1);
    scanf("%d", & avail[i]);
  }
  printf("Enter the MAXIMUM resource count for each process\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("process %d-resource %d\t", i + 1, j + 1);
      scanf("%d", & max[i][j]);
    }
  }
  printf("Enter the allocated resource count for each process\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("process %d-resource %d\t", i + 1, j + 1);
      scanf("%d", & alloc[i][j]);
    }
  }
  printf("Need matrix \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      need[i][j] = max[i][j] - alloc[i][j];
      printf("%d\t", need[i][j]);
    }
    printf("\n");
  }
  for (i = 0; i < n; i++) {
    finish[i] = 0;
  }
  for (i = 0; i < 5; i++) {
    for (j = 0; j < n; j++) {
      if (finish[j] == 0) {
        flag = 0;
        for (k = 0; k < m; k++) {
          if (need[j][k] > avail[k]) {
            flag = 1;
            break;
          }
        }
        if (flag == 0) {
          fin[y++] = j;
          for (l = 0; l < m; l++) {
            avail[l] = avail[l] + alloc[j][l];
          }
          finish[j] = 1;
        }
      }
    }
  }
  
  for (i = 0; i < n; i++) {
    if (finish[i] == 0) {
      
      printf("not in safe state\n");
      exit(1);
    }
  }
  
    printf("the system is in safe state\n");
    for (i = 0; i < n - 1; i++) {
      printf("P%d->", fin[i]);
    }
    printf("P%d", fin[n - 1]);
  
}

