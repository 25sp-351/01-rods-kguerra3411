#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double calculate_ratio(int value, int length) { return (double)value / length; }

int compare_segments(const void *a, const void *b) {
  int *segmentA = (int *)a;
  int *segmentB = (int *)b;

  double ratioA = calculate_ratio(segmentA[1], segmentA[0]);
  double ratioB = calculate_ratio(segmentB[1], segmentB[0]);

  return (ratioA < ratioB) - (ratioA > ratioB);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("rod length invalid\n");
    return 1;
  }

  int totalRodLength = atoi(argv[1]);
  if (totalRodLength <= 0) {
    printf("Invalid rod length. Please provide an integer greater than 0.\n");
    return 1;
  }

  int segmentData[20][2];
  int numberOfSegments = 0;
  char userInput[100];

  printf("Enter segment data as <length>, <value>\n");

  while (fgets(userInput, sizeof(userInput), stdin)) {
    int segmentLength, segmentValue;
    if (sscanf_s(userInput, "%d, %d", &segmentLength, &segmentValue) == 2) {
      if (segmentLength > 0 && segmentValue >= 0) {
        segmentData[numberOfSegments][0] = segmentLength;
        segmentData[numberOfSegments][1] = segmentValue;
        numberOfSegments++;
      } else {
        printf("Invalid segment data. Ensure length > 0 and value >= 0.\n");
      }
    } else {
      printf("Invalid format. Please use <length>, <value>.\n");
    }
  }

  qsort(segmentData, numberOfSegments, sizeof(segmentData[0]),
        compare_segments);

  int totalValue = 0;
  int remainingRodLength = totalRodLength;

  for (int i = 0; i < numberOfSegments; i++) {
    if (remainingRodLength <= 0) {
      break;
    }

    int segmentLength = segmentData[i][0];
    int segmentValue = segmentData[i][1];
    int maxSegmentsToUse = remainingRodLength / segmentLength;

    if (maxSegmentsToUse > 0) {
      int valueToAdd = maxSegmentsToUse * segmentValue;
      printf("\n%d @ %d = %d\n", maxSegmentsToUse, segmentLength, valueToAdd);

      totalValue += valueToAdd;
      remainingRodLength -= maxSegmentsToUse * segmentLength;
    }
  }

  printf("\nRemaining rod: %d\n", remainingRodLength);
  printf("Total value: %d\n", totalValue);

  return 0;
}
