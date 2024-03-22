#include <stdio.h>
#include <stdlib.h>

int main() {
  int cpu_numbers[6];
  int user_numbers[6];

  for (int i = 0; i < 6; i++) {
    cpu_numbers[i] = rand() % 60 + 1;
    for (int j = 0; j < i; j++) {
      if (cpu_numbers[i] == cpu_numbers[j]) {
        i--;
        break;
      }
    }
  }

  for (int i = 0; i < 6; i++) {
    printf("Enter number %d: ", i + 1);
    scanf("%d", &user_numbers[i]);

    if (user_numbers[i] < 1 || user_numbers[i] > 60) {
      printf("Invalid number. Please enter a number between 1 and 60.\n");
      i--;
    }

    for (int j = 0; j < i; j++) {
      if (user_numbers[i] == user_numbers[j]) {
        printf("Number already entered. Please enter a different number.\n");
        i--;
        break;
      }
    }
  } 

  printf("The lottery numbers are: ");
  for (int i = 0; i < 6; i++) {
    printf("%d ", cpu_numbers[i]);
  }
  printf("\n");

  int count = 0;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (user_numbers[i] == cpu_numbers[j]) {
        count++;
      }
    }
  }

  printf("You guessed %d numbers correctly.\n", count);

  if (count == 6) {
    printf("Congratulations! You won the lottery! 🎉\n");
  } else {
    printf("You unfortunately did not win the lottery 🐿\n");
  }

  return 0;
}
