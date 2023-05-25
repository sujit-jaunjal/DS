# MPI Addition of array

Steps to run MPI program:

- Open new terminal

```bash
cd 3_mpi
```

- Run

```bash
mpicc add.c
```

- Start registry

```bash
mpirun -np <any_no_of_cores> ./a.out
mpirun -np 4 ./a.out
```

```bash
⚠️ Make sure mpi version is 4.1.x using mpirun --version
```
