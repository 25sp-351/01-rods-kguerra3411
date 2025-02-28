#include "rod_cut.h"
#include "cutting_options.h"

int rodCut(int remainingLength, int *cutCounts) {
    if (remainingLength == 0) return 0;

    int maxValue = 0;
    int subCutCounts[MAX_CUTTING_OPTIONS] = {0};

    for (int i = 0; i < num_cutting_options; i++) {
        if (cutting_options[i].length <= remainingLength) {
            int tempCutCounts[MAX_CUTTING_OPTIONS] = {0};
            int currentValue = cutting_options[i].value + rodCut(remainingLength - cutting_options[i].length, tempCutCounts);

            if (currentValue > maxValue) {
                maxValue = currentValue;
                for (int j = 0; j < MAX_CUTTING_OPTIONS; j++) {
                    subCutCounts[j] = tempCutCounts[j];
                }
                subCutCounts[i]++;
            }
        }
    }

    for (int j = 0; j < MAX_CUTTING_OPTIONS; j++) {
        cutCounts[j] = subCutCounts[j];
    }

    return maxValue;
}
