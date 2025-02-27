#ifndef CUTTING_OPTIONS_H
#define CUTTING_OPTIONS_H

#define MAX_CUTTING_OPTIONS 20

typedef struct {
    int length;
    int value;
} cutting_option;

extern cutting_option cutting_options[MAX_CUTTING_OPTIONS];
extern int num_cutting_options;

void readcutting_options();

#endif
