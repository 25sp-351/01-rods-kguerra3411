/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include "cutting_options.h"
#include "rod_cut.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Error: No rod length provided.\n");
        fprintf(stderr, "Usage: %s <rod_length>\n", argv[0]);
        return 1;
    } 
    else if (argc > 2) {
        fprintf(stderr, "Error: Too many arguments provided.\n");
        fprintf(stderr, "Usage: %s <rod_length>\n", argv[0]);
        return 1;
    }

    char *endptr;
    long temp = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || temp <= 0) {
        fprintf(stderr, "Error: Invalid rod length. Must be a positive integer.\n");
        return 1;
    }
    int totalRodLength = (int)temp;

    printf("Enter segment data as <length>, <value>. Press Ctrl+D (or Ctrl+Z on Windows) when done.\n");
    readcutting_options();

    if (num_cutting_options == 0) {
        fprintf(stderr, "Warning: No valid segment data provided. The remaining rod is unchanged.\n");
        printf("Remaining rod: %d\n", totalRodLength);
        printf("Total value: 0\n");
        return 0;
    }

    int cutCounts[MAX_CUTTING_OPTIONS] = {0};
    int maxValue = rodCut(totalRodLength, cutCounts);

    printf("Optimal cutting strategy:\n");
    int remainingRod = totalRodLength;
    for (int i = 0; i < num_cutting_options; i++) {
        if (cutCounts[i] > 0) {
            int totalValue = cutCounts[i] * cutting_options[i].value;
            printf("%d @ %d = %d\n", cutCounts[i], cutting_options[i].length, totalValue);
            remainingRod -= cutCounts[i] * cutting_options[i].length;
        }
    }
    
    printf("Remaining rod: %d\n", remainingRod);
    printf("Total value: %d\n", maxValue);
    
    return 0;
}
