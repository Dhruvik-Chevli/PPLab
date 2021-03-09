#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
int main(int argc, char* argv[])
{
	int rank,size;
	int k;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    
    if(size!=5)
    {
    	printf("\nUse 5 processes\n");
        MPI_Abort(MPI_COMM_WORLD,EXIT_FAILURE);
    }
    if(rank==0)
    {
    	printf("Please enter the integer you want to send.\n");
    	scanf("%d",&k);
    	MPI_Send(&k,1,MPI_INT,1,0,MPI_COMM_WORLD);
    }
    else if(rank!=4)
    {

    	MPI_Recv(&k,1,MPI_INT,rank-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    	printf("Process[%d] recieved: %d From %d\n", rank, k, rank-1);
    	k+=1;
    	MPI_Send(&k,1,MPI_INT,rank+1,0,MPI_COMM_WORLD);
    }
    else
    {
    	MPI_Recv(&k,1,MPI_INT,rank-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    	printf("Process[%d] recieved: %d From %d\n", rank, k, rank-1);
    	k+=1;
    	MPI_Send(&k,1,MPI_INT,0,0,MPI_COMM_WORLD);
    }
    MPI_Finalize();
}