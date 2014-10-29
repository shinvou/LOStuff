//
//  LOStuff.c
//  LOStuff
//
//  Created by Timm Kandziora on 13.01.14.
//  Copyright (c) 2014 shinvou Dev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

const int n4_1[] = {0,1,1,1,1,0,1,0,1,1,0,0,1,0,0,0};
const int n4_2[] = {1,1,0,1,0,0,0,1,1,1,1,0,0,1,0,0};
const int n4_3[] = {1,0,1,1,1,0,0,0,0,1,1,1,0,0,1,0};
const int n4_4[] = {1,1,1,0,0,1,0,1,0,0,1,1,0,0,0,1};

const int n5_1[] = {1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,0,1,0,1};
const int n5_2[] = {1,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1};

const int hint_matrix4[16][16] = {
    {1,1,0,0,1,0,1,0,0,1,1,1,0,0,0,0},
    {1,1,1,0,0,0,0,1,1,1,0,1,0,0,0,0},
    {0,1,1,1,1,0,0,0,1,0,1,1,0,0,0,0},
    {0,0,1,1,0,1,0,1,1,1,1,0,0,0,0,0},
    {1,0,1,0,1,0,1,1,1,0,1,0,0,0,0,0},
    {0,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0},
    {1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0},
    {0,1,0,1,1,1,0,1,0,1,0,1,0,0,0,0},
    {0,1,1,1,1,0,1,0,1,1,0,0,0,0,0,0},
    {1,1,0,1,0,0,0,1,1,1,1,0,0,0,0,0},
    {1,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0},
    {1,1,1,0,0,1,0,1,0,0,1,1,0,0,0,0},
    {0,1,1,1,1,0,1,0,1,1,0,0,1,0,0,0},
    {1,1,0,1,0,0,0,1,1,1,1,0,0,1,0,0},
    {1,0,1,1,1,0,0,0,0,1,1,1,0,0,1,0},
    {1,1,1,0,0,1,0,1,0,0,1,1,0,0,0,1}
};

const int hint_matrix5[23][23] = {
    {0,1,1,1,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0},
    {1,1,0,1,1,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,0},
    {1,0,1,1,1,1,0,1,1,0,0,0,1,1,0,1,1,1,1,1,0,1,0},
    {1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1},
    {0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,1,1,0},
    {0,0,1,0,1,0,1,1,0,1,0,0,1,0,0,0,0,0,1,1,0,0,0},
    {0,1,0,1,0,1,1,0,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0},
    {1,0,1,0,0,1,0,1,1,0,0,0,0,0,1,1,0,1,0,1,1,0,1},
    {0,0,1,0,0,0,1,1,1,0,1,0,0,1,1,1,0,0,1,0,0,1,1},
    {1,0,0,0,0,1,1,0,0,0,1,0,1,0,1,0,1,1,0,1,0,0,1},
    {0,0,0,0,1,0,0,0,1,1,0,0,1,0,1,1,1,1,1,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1},
    {0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,0,0,1,1,0},
    {1,1,1,0,0,0,1,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0},
    {1,1,0,0,1,0,0,1,1,1,1,0,0,1,1,1,1,0,1,0,1,0,0},
    {0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,1,0,1,0,1,1,0,1},
    {0,0,1,1,0,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,0,0,1},
    {0,0,1,0,1,0,1,1,0,1,1,0,1,0,0,1,1,0,1,1,1,0,0},
    {0,1,1,0,0,1,0,0,1,0,1,0,0,1,1,0,1,1,1,0,0,0,1},
    {1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,0,1},
    {0,0,0,1,1,0,0,1,0,0,0,1,1,0,1,1,0,1,0,1,1,1,0},
    {0,0,1,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1},
    {0,0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,1,0,1,1,0,1,0}
};

const int hint_matrix6[36][36] = {
    {1,0,1,0,1,1,0,0,1,0,0,0,1,1,0,1,1,1,0,0,1,0,1,0,1,0,1,1,0,0,1,0,1,0,0,0},
    {0,0,0,0,1,1,0,1,0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,1,0,0,1,1,1,0,0,0,0,1,0,0},
    {1,0,1,1,0,0,1,0,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,1,1,1,1,0,0,0,1,0},
    {0,0,1,1,0,1,0,1,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,1,0,0,0,1},
    {1,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,0,0,1,0,0,1,1,1,0,0,0,0,1,0,0,0},
    {1,1,0,1,0,1,0,0,0,1,0,0,1,1,1,0,1,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0,0,1,0,1},
    {0,0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,1,0,1,1,1,0,0,0,1,0,1,0,1,1,0,0},
    {0,1,0,1,0,0,1,1,0,1,1,0,0,0,0,1,0,1,1,1,1,0,1,1,0,1,0,1,0,1,0,0,1,1,1,0},
    {1,0,1,0,1,0,1,0,1,0,1,1,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1},
    {0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1,1,0,1,1},
    {0,0,1,0,1,0,0,1,1,0,1,1,1,0,1,0,0,0,1,1,0,1,1,1,1,0,1,0,1,0,0,1,1,1,0,0},
    {0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1,0,0,1,1,0,1},
    {1,1,0,1,1,1,0,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,1,1,0,1,1,0,0,1,0,1,0},
    {1,1,0,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,1,0,0,0,1},
    {0,0,0,1,1,1,0,0,1,0,1,0,0,1,1,1,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0},
    {1,1,1,0,0,0,0,1,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,1,1,1,1,0,0,0,1,0},
    {1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,1,1,0,0,1,0,1,0,0},
    {0,0,1,0,1,0,0,1,1,0,1,1,1,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1},
    {0,1,0,0,0,1,1,1,1,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,1,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0,0,0,0,1,1,1},
    {0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,1,0,0,1,1,1,0,0,1,0,1,0,0,1,1,1,0,0,0},
    {1,0,0,0,1,0,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,1,0,1,0,1,1},
    {0,1,0,1,0,0,1,1,0,1,1,0,0,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,1,0,1,1},
    {1,0,1,1,0,0,1,0,0,0,1,0,0,1,1,0,1,1,0,0,0,0,1,0,0,1,1,1,0,0,0,0,1,0,0,0},
    {0,0,1,1,1,0,0,1,0,1,0,1,1,1,1,0,1,1,0,0,0,1,0,1,1,1,0,1,1,0,0,1,0,1,0,0},
    {1,1,0,1,1,1,0,0,0,0,1,0,1,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0},
    {1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1},
    {0,1,1,1,0,0,1,0,1,0,1,0,1,1,0,1,1,1,1,0,1,0,0,0,0,1,1,0,1,1,0,0,1,0,1,0},
    {0,0,1,1,0,1,0,1,0,0,0,1,1,1,0,1,1,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,0},
    {1,0,1,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,1,1,0,1,1,1,0,0,1,0,0,0,1,0,1,0,1,1},
    {0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,1},
    {1,0,0,0,1,0,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,1,0,1,1,0,0},
    {0,1,0,0,0,1,1,1,1,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,1,1,0,1},
    {0,0,1,0,0,0,0,1,1,1,0,0,1,0,0,0,1,0,1,0,1,0,1,1,0,0,1,0,1,0,1,1,0,0,0,0},
    {0,0,0,1,0,1,0,0,1,1,0,1,0,1,0,1,0,0,1,1,1,0,1,1,0,0,0,1,0,0,1,1,0,1,0,1}
};

bool isSolvable(const char levelString[], int lights)
{
    int current_state[lights], n1[lights], n2[lights], n3[lights], n4[lights];
    int i, dotprod;
    
    if (lights == 16) {
        memcpy(&n1, &n4_1, sizeof n1);
        memcpy(&n2, &n4_2, sizeof n2);
        memcpy(&n3, &n4_3, sizeof n3);
        memcpy(&n4, &n4_4, sizeof n4);
    } else if (lights == 25) {
        memcpy(&n1, &n5_1, sizeof n1);
        memcpy(&n2, &n5_2, sizeof n2);
    } else {
        return true;
    }
    
    for (i = 0; i < lights; i++) {
        char currentChar = levelString[i];
        current_state[i] = atoi(&currentChar);
    }
    
    dotprod = 0;
    
    for (i = 0; i < lights; i++) {
        dotprod = (dotprod + current_state[i] * n1[i]) % 2;
    }
    
    if (dotprod != 0) {
        return false;
    }
    
    dotprod = 0;
    
    for (i = 0; i < lights; i++) {
        dotprod = (dotprod + current_state[i] * n2[i]) % 2;
    }
    
    if (lights == 16) {
        if (dotprod != 0) {
            return false;
        }
        
        dotprod = 0;
        
        for (i = 0; i < lights; i++) {
            dotprod = (dotprod + current_state[i] * n3[i]) % 2;
        }
        
        if (dotprod != 0) {
            return false;
        }
        
        dotprod = 0;
        
        for (i = 0; i < lights; i++) {
            dotprod = (dotprod + current_state[i] * n4[i]) % 2;
        }
    }
    
    if (dotprod != 0) {
        return false;
    } else {
        return true;
    }
}

void integerToBinaryShow(long long lights, long long number)
{
    long long n, c, k;
    
    n = number;
    
    for (c = lights - 1; c >= 0; c--) {
        k = n >> c;
        
        if (k & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    
    printf("\n");
}

void integerToBinaryShowSolvable(long long lights, long long number)
{
    int i;
    char level[37];
    long long n, c, k;
    
    n = number;
    
    for (c = lights - 1; c >= 0; c--) {
        k = n >> c;
        
        if (k & 1) {
            level[lights-1-c] = '1';
        } else {
            level[lights-1-c] = '0';
        }
    }
    
    if (isSolvable(level, lights)) {
        for (i = 0; i < lights; i++) {
            printf("%c", level[i]);
        }
        
        printf("\n");
    }
}

void integerToBinaryPrintToFile(long long lights, long long number, const char *filename)
{
    long long n, c, k;
    
    n = number;
    
    FILE *file = fopen(filename, "a");
    
    for (c = lights - 1; c >= 0; c--) {
        k = n >> c;
        
        if (k & 1) {
            fprintf(file, "1");
        } else {
            fprintf(file, "0");
        }
    }
    
    fprintf(file, "\n");
    
    fclose(file);
}

void integerToBinaryPrintToFileSolvable(long long lights, long long number, const char *filename)
{
    int i;
    char level[37];
    long long n, c, k;
    
    n = number;
    
    FILE *file = fopen(filename, "a");
    
    for (c = lights - 1; c >= 0; c--) {
        k = n >> c;
        
        if (k & 1) {
            level[lights-1-c] = '1';
        } else {
            level[lights-1-c] = '0';
        }
    }
    
    if (isSolvable(level, lights)) {
        for (i = 0; i < lights; i++) {
            fprintf(file, "%c", level[i]);
        }
        
        fprintf(file, "\n");
    }
    
    fclose(file);
}

void acpy(int src[], int dest[], int lights)
{
    int i;
    for (i = 0; i < lights; i++) {
        dest[i] = src[i];
    }
}

void addto(int src[], int v[], int lights)
{
    int i;
    for (i = 0; i < lights; i++) {
        src[i] = (src[i] + v[i]) % 2;
    }
}

int wt(int v[], int lights)
{
    int i, t = 0;
    for (i = 0; i < lights; i++) {
        t = t + v[i];
    }
    
    return t;
}

void solveLevel(const char levelString[], int lights, int anomaly)
{
    int hint_matrix[anomaly][anomaly];
    int hint_vector[lights], best[lights], next[lights], current_state[anomaly], n1[lights], n2[lights], n3[lights], n4[lights];
    int i, j;
    
    if (lights == 16) {
        memcpy(&n1, &n4_1, sizeof n1);
        memcpy(&n2, &n4_2, sizeof n2);
        memcpy(&n3, &n4_3, sizeof n3);
        memcpy(&n4, &n4_4, sizeof n4);
        memcpy(&hint_matrix, &hint_matrix4, sizeof hint_matrix);
    } else if (lights == 25) {
        memcpy(&n1, &n5_1, sizeof n1);
        memcpy(&n2, &n5_2, sizeof n2);
        memcpy(&hint_matrix, &hint_matrix5, sizeof hint_matrix);
    } else {
        memcpy(&hint_matrix, &hint_matrix6, sizeof hint_matrix);
    }
    
    for (i = 0; i < lights; i++) {
        hint_vector[i] = 0;
        best[i] = 0;
        next[i] = 0;
    }
    
    for (i = 0; i < anomaly; i++) {
        char currentChar = levelString[i];
        current_state[i] = atoi(&currentChar);
    }
    
    for (i = 0; i < anomaly; i++) {
        for (j = 0; j < anomaly; j++) {
            hint_vector[i] = (hint_vector[i] + current_state[j] * hint_matrix[i][j]) % 2;
        }
    }
    
    if (lights == 36) {
        printf("\n");
        
        for (i = 0; i < lights; i++) {
            if (i == 6 | i == 12 | i == 18 | i == 24 | i == 30) {
                printf("\n");
            }
            
            printf("%d", hint_vector[i]);
        }
        
        printf("\n\n");
        
        return;
    }
    
    acpy(hint_vector, best, lights);
    
    acpy(hint_vector, next, lights);
    addto(next, n1, lights);
    
    if (wt(next, lights) < wt(best, lights)) {
        acpy(next, best, lights);
    }
    
    acpy(hint_vector, next, lights);
    addto(next, n2, lights);
    
    if (wt(next, lights) < wt(best, lights)) {
        acpy(next, best, lights);
    }
    
    if (lights == 16) {
        acpy(hint_vector, next, lights);
        addto(next, n3, lights);
        
        if (wt(next, lights) < wt(best, lights)) {
            acpy(next, best, lights);
        }
        
        acpy(hint_vector, next, lights);
        addto(next, n4, lights);
        
        if (wt(next, lights) < wt(best, lights)) {
            acpy(next, best, lights);
        }
    }
    
    acpy(hint_vector, next, lights);
    addto(next, n1, lights);
    addto(next, n2, lights);
    
    if (lights == 16) {
        if (wt(next, lights) < wt(best, lights)) {
            acpy(next, best, lights);
        }
        
        acpy(hint_vector, next, lights);
        addto(next, n1, lights);
        addto(next, n3, lights);
        
        if (wt(next, lights) < wt(best, lights)) {
            acpy(next, best, lights);
        }
        
        acpy(hint_vector, next, lights);
        addto(next, n1, lights);
        addto(next, n4, lights);
        
        if (wt(next, lights) < wt(best, lights)) {
            acpy(next, best, lights);
        }
        
        acpy(hint_vector, next, lights);
        addto(next, n2, lights);
        addto(next, n3, lights);
        
        if (wt(next, lights) < wt(best, lights)) {
            acpy(next, best, lights);
        }
        
        acpy(hint_vector, next, lights);
        addto(next, n2, lights);
        addto(next, n4, lights);
        
        if (wt(next, lights) < wt(best, lights)) {
            acpy(next, best, lights);
        }
        
        acpy(hint_vector, next, lights);
        addto(next, n3, lights);
        addto(next, n4, lights);
    }
    
    if (wt(next, lights) < wt(best, lights)) {
        acpy(next, best, lights);
    }
    
    printf("\n");
    
    for (i = 0; i < lights; i++) {
        if (lights == 16) {
            if (i == 4 | i == 8 | i == 12) {
                printf("\n");
            }
        } else {
            if (i == 5 | i == 10 | i == 15 | i == 20) {
                printf("\n");
            }
        }
        
        printf("%d", best[i]);
    }
    
    printf("\n\n");
}

void firstChoice()
{
    int choice, secondChoice;
    
    printf("\nSelect the grid size of the lights out puzzle:\n");
    printf("1) 4x4, 16 lights (65536 possible levels)\n");
    printf("2) 5x5, 25 lights (33554432 possible levels)\n");
    printf("3) 6x6, 36 lights (68719476736 possible levels)\n\n");
    
    printf("Enter: ");
    scanf("%d", &choice);
    
    printf("\nSelect whether to write to file or show in here:\n");
    printf("1) Write to file\n");
    printf("2) Show in here\n\n");
    
    printf("NOTE: This will take some time.\n\n");
    
    printf("Enter: ");
    scanf("%d", &secondChoice);
    
    if (secondChoice == 2) {
        printf("\n");
    }
    
    if (choice == 1) {
        int i;
        for (i = 0; i < pow(2, 16); i++) {
            if (secondChoice == 1) {
                integerToBinaryPrintToFile(16, i, "4x4_all.txt");
            } else {
                integerToBinaryShow(16, i);
            }
        }
    } else if (choice == 2) {
        int i;
        for (i = 0; i < pow(2, 25); i++) {
            if (secondChoice == 1) {
                integerToBinaryPrintToFile(25, i, "5x5_all.txt");
            } else {
                integerToBinaryShow(25, i);
            }
        }
    } else {
        int i;
        for (i = 0; i < pow(2, 36); i++) {
            if (secondChoice == 1) {
                integerToBinaryPrintToFile(36, i, "6x6_all.txt");
            } else {
                integerToBinaryShow(36, i);
            }
        }
    }
    
    printf("\n");
    printf("Finished.\n\n");
}

void secondChoice()
{
    
    int choice, secondChoice;
    
    printf("\nSelect the grid size of the lights out puzzle:\n");
    printf("1) 4x4, 16 lights (65536 possible levels, 4096 solvable levels)\n");
    printf("2) 5x5, 25 lights (33554432 possible levels, 8388608 solvable levels)\n");
    printf("3) 6x6, 36 lights (68719476736 possible levels, 68719476736 solvable levels)\n\n");
    
    printf("Enter: ");
    scanf("%d", &choice);
    
    printf("\nSelect whether to write to file or show in here:\n");
    printf("1) Write to file\n");
    printf("2) Show in here\n\n");
    
    printf("NOTE: This will take some time.\n\n");
    
    printf("Enter: ");
    scanf("%d", &secondChoice);
    
    if (secondChoice == 2) {
        printf("\n");
    }
    
    if (choice == 1) {
        int i;
        for (i = 0; i < pow(2, 16); i++) {
            if (secondChoice == 1) {
                integerToBinaryPrintToFileSolvable(16, i, "4x4_solvable.txt");
            } else {
                integerToBinaryShowSolvable(16, i);
            }
        }
    } else if (choice == 2) {
        int i;
        for (i = 0; i < pow(2, 25); i++) {
            if (secondChoice == 1) {
                integerToBinaryPrintToFileSolvable(25, i, "5x5_solvable.txt");
            } else {
                integerToBinaryShow(25, i);
            }
        }
    } else {
        int i;
        for (i = 0; i < pow(2, 36); i++) {
            if (secondChoice == 1) {
                integerToBinaryPrintToFile(36, i, "6x6_all.txt");
            } else {
                integerToBinaryShow(36, i);
            }
        }
    }
    
    printf("\n");
    printf("Finished.\n\n");
}

void thirdChoice()
{
    int choice;
    char level[37];
    
    printf("\nSelect the grid size of the lights out puzzle:\n");
    printf("1) 4x4, 16 lights\n");
    printf("2) 5x5, 25 lights\n");
    printf("3) 6x6, 36 lights\n\n");
    
    printf("Enter: ");
    scanf("%d", &choice);
    
    printf("\nPlease enter the level you want to solve:\n\n");
    
    printf("Enter: ");
    scanf("%36s", level);
    
    if (choice == 1) {
        if (isSolvable(level, 16)) {
            solveLevel(level, 16, 16);
        } else {
            printf("\nThis level is not solvable.\n\n");
        }
    } else if (choice == 2) {
        if (isSolvable(level, 25)) {
            solveLevel(level, 25, 23);
        } else {
            printf("\nThis level is not solvable.\n\n");
        }
    } else {
        solveLevel(level, 36, 36);
    }
}

int main()
{
    int choice;
    
    printf("\nHello. What do you want to do?\n");
    printf("1) Display or save all possible levels, whether they are solvable or not\n");
    printf("2) Display or save all solvable levels\n");
    printf("3) Solve a specific level\n\n");
    
    printf("Enter: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        firstChoice();
    } else if (choice == 2) {
        secondChoice();
    } else {
        thirdChoice();
    }
    
    return 0;
}
