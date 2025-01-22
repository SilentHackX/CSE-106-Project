
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int i, j, n, Random, NumberOfEdge = 0, SumOfDegree = 0;
    double total_time;
    clock_t start, end;
    time_t t;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int **Graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        Graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            Graph[i][j] = 0;
        }
    }

    srand((unsigned) time(&t));
    for (Random = 0; Random < n; Random++)
    {
        i = rand() % n;
        j = rand() % n;
        Graph[i][j] = 1;
    }

    start = clock();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (Graph[i][j] == 1)
            {
                SumOfDegree++;
            }
        }
    }
    NumberOfEdge = SumOfDegree / 2;
    end = clock();

    printf("No. of Edges = %d\n", NumberOfEdge);
    printf("Sum of Degree = %d\n", SumOfDegree);
    if (SumOfDegree == (NumberOfEdge * 2))
    {
        printf("The Handshaking logic holds.\n");
    }
    else
    {
        printf("The Handshaking logic does not hold.\n");
    }

    total_time = (double)(end - start);
    printf("Runtime = %f ms\n", total_time);

    return 0;
}
