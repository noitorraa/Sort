#include <stdio.h>
#define NMAX 10
int input(int *a, int *n, int *check);
void output(int *a, int n);
int sort(int *a, int n);

int main() {
  int data[NMAX];
  int num, check = 0;
  input(data, &num, &check);
  if (check == 0) {
    sort(data, num);
    output(data, num);
  }
  return 0;
}

int input(int *a, int *n, int *check) {
  printf("Напиши сколько элементов будешь вводить: ");
  if (scanf("%d", n) == 1 && getchar() == '\n' && *n >= 1 && *n <= 10) {
    for (int i = 0; i < *n; i++) {
      printf("Введи число %d: ", i + 1);
      if (scanf("%d", &a[i]) != 1 || getchar() != '\n') {
        printf("n/a\n");
        *check = 1;
        break;
      }
    }
  } else {
    printf("n/a\n");
    *check = 1;
  }
  return 0;
}

int sort(int *a, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = (n - 1); j > i; j--) {
      if (a[j - 1] > a[j]) {
        int _switch = a[j - 1];
        a[j - 1] = a[j];
        a[j] = _switch;
      }
    }
  }
  return 0;
}

void output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
