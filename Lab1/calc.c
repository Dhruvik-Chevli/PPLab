#include <mpi.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
	int rank, size;
	int a=10,b=25;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    printf("the operation is performed on %d and %d\n",a,b);
    switch(rank)
    {
    	case 1: 
              printf("addition is %d\n",a+b);
            	break;
     	case 2: printf("subtraction is %d\n",a-b);
               	break;
      	case 3: printf("multiplication is %d\n",a*b);
               	break;
      	default: printf("division is %d\n",a/b);
                break;
   }

   	MPI_Finalize();
	return 0;
}