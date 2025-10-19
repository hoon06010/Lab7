#include <stdio.h>
#include <stdlib.h>

int* findMaxGrp(int* maxcnt, int maxgrp[]);
int* allocateMemory();

int main()
{
    int i, count = 100;
	int maxage = -1, minage = 1000;
	int maxscore = -1, minscore = 1000;
	int maxagecnt = 0, minagecnt = 0, maxscorecnt = 0, minscorecnt = 0;
	int age[100] = {11, 24, 19, 20, 25, 24, 34, 25, 22, 27, 24, 40, 23, 22, 31, 40, 39, 25, 36, 33, 34, 39, 18, 21, 20, 15, 28, 18, 22, 21, 26, 23, 40, 40, 27, 32, 18, 19, 26, 23, 34, 40, 15, 14, 35, 17, 16, 21, 20, 28, 21, 17, 36, 31, 30, 25, 28, 14, 18, 37, 32, 38, 23, 25, 34, 30, 39, 14, 26, 35, 30, 23, 28, 39, 31, 21, 29, 40, 17, 39, 22, 33, 24, 23, 21, 26, 24, 19, 25, 33, 29, 11, 40, 22, 24, 30, 33, 16, 40, 10};
	int score[100] = {83, 41, 56, 100, 65, 33, 98, 68, 98, 30, 86, 19, 16, 10, 42, 10, 20, 23, 96, 47, 92, 10, 81, 99, 71, 27, 91, 32, 60, 77, 36, 10, 28, 92, 18, 83, 65, 85, 40, 24, 29, 31, 88, 39, 60, 38, 37, 23, 47, 90, 100, 85, 16, 77, 27, 84, 77, 75, 10, 80, 87, 14, 63, 28, 99, 62, 86, 42, 12, 43, 68, 75, 90, 79, 44, 17, 80, 97, 32, 79, 21, 25, 91, 74, 82, 52, 20, 28, 85, 73, 63, 66, 22, 73, 90, 52, 14, 53, 46, 56};
	
	int maxagegrp[100], minagegrp[100];
	int maxscoregrp[100], minscoregrp[100];

    findMaxGrp(&maxagecnt, age);

    for (int i = 0; i < maxagecnt; i++)
		printf("Oldest Age(%d) score as %d\n", maxage, score[maxagegrp[i]]);
		


    return 0;
}

int* allocateMemory()
{
    int* ptr = (int*)malloc(100 * sizeof(int));
    if (ptr == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }

    return ptr;
}
int* findMaxGrp(int* maxcnt, int origingrp[])
{
    int maxnum = -1;
    int* ptr = allocateMemory();

    for (int i = 0; i < 100; i++)
    {
        if (origingrp[i] > maxnum)
        {
            maxnum = origingrp[i];
            *maxcnt = 1;

            free(ptr);
            ptr = allocateMemory();

            ptr[0] = i;
        }
        
        else if (origingrp[i] == maxnum)
            ptr[*maxcnt++] = i;
    }

    return ptr;
}