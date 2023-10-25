#include <stdio.h>

void fcfs(int pages[], int n, int frames) {
  int faulttables[frames];
  int faults = 0;
  for (int i = 0; i < frames; i++) {
    faulttables[i] = -1;
  }

  for (int i = 0; i < n; i++) {
    int found = 0;
    int page = pages[i];
    for (int j = 0; j < frames; j++) {
      if (faulttables[j] == page) {
        found = 1;
        break;
      }
    }
    if (!found) {
      faulttables[faults % frames] = page;
      faults++;
    }
  }
  printf("Number of faults: %d\n", faults);
}

int main() {
  int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
  int n = sizeof(pages) / sizeof(pages[0]);
  int frames = 4;
  fcfs(pages, n, frames);
}