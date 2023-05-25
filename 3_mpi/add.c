#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    printf("\n");
    // print rank and size
    printf("Rank: %d, Size: %d\n", rank, size);
    int ar_size = size * 5; // p=6
    int num[ar_size];       // N=6*5=30

    for (int i = 0; i < ar_size; i++)
        num[i] = i + 1;
    // print array
    if (rank == 0)
    {
        printf("Array: ");
        for (int i = 0; i < ar_size; i++)
            printf("%d ", num[i]);
        printf("\n");
    }
    int local_n = ar_size / size; // Elements per process = 5

    if (rank == 0)
    {
        int s[size]; // size =6
        printf("Distribution at rank %d \n", rank);

        for (int i = 1; i < size; i++)
            MPI_Send(&num[i * local_n], local_n, MPI_INT, i, 1, MPI_COMM_WORLD);

        int sum = 0, local_sum = 0;
        for (int i = 0; i < local_n; i++)
        {
            local_sum += num[i];
        }

        for (int i = 1; i < size; i++)
        {
            MPI_Recv(&s[i], 1, MPI_INT, i, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        printf("local sum at rank %d is %d\n", rank, local_sum);
        sum = local_sum;

        for (int i = 1; i < size; i++)
            sum += s[i];

        printf("final sum = %d\n\n", sum);
    }
    else
    {
        int k[local_n];
        MPI_Recv(k, local_n, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        int local_sum = 0;
        for (int i = 0; i < local_n; i++)
        {
            local_sum += k[i];
        }

        printf("local sum at rank %d is %d\n", rank, local_sum);
        MPI_Send(&local_sum, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}
