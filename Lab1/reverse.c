#include<stdio.h>
#include<mpi.h>
int reverse(int n)
{
	int rev=0;
	while(n)
	{
		int k=n%10;
		rev=rev*10+k;
		n/=10;
	}
	return rev;
}
int main(int argc, char* argv[])
{
	int rank, size;	
	int arr[9]={18,523,301,1234,2,14,108,150,1928};
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	int k=reverse(arr[rank]);
	printf("%d ",k);
	MPI_Finalize();
}