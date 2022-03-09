#ifdef __cplusplus
    #include <cstdio>

    using namespace std;
#else
    #include <stdio.h>
#endif

#include "task4Matrixes.h"


bool multiplyMatrixes(int *m1[], int m1Rows, int m1Columns,
                      int *m2[], int m2Rows, int m2Columns,
                      int* result[], int* resultRows, int* resultColumns)
{
    if (m2Rows != m1Columns) return false;
    *resultRows = m1Rows;
    *resultColumns = m2Columns;
    for (int w = 0; w < *resultRows; w++)
    {
        for (int k = 0; k < *resultColumns; k++)
        {
            for (int i = 0; i < m1Columns; i++)
            {
                result[w][k] += m1[w][i] * m2[i][k];
            }
        }
    }
    return true;
}
