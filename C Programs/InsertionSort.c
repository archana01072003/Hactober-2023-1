// Program - Insertion Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int array[1000000];

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main()
{
    struct timeval t0;
    struct timeval t1;
    float elapsed;
    
	int i,key,ch,position;
	long size,limit;
	printf("Enter number of Elements: ");
	scanf("%ld",&size);
	int array[size];
	printf("Enter Upper limit in place values: ");
	scanf("%ld",&limit);
	
	int num=size;
	int j,x,y,temp;
	srand( (unsigned) time(NULL) * getpid());
	gettimeofday(&t0, NULL);
	if(array != NULL)
	{
		for(j = 0; j < num; j++)
		{
			array[j] = rand()%limit;
		}
	}
	gettimeofday(&t1, NULL);
	elapsed = timedifference_msec(t0, t1);
	printf("\n");
	printf("List of Numbers:\n");
	for(j = 0; j < num; j++)
	{
		printf("%d\n",array[j]);
	}				
	printf("Random Generation code executed in %f milliseconds.\n", elapsed);
    printf("\n");
    
    gettimeofday(&t0, NULL);
 	for (i=1;i<num;i++) 
    {
        position=array[i];
        j=i-1;

        while(j>=0 && array[j]>position) 
        {
            array[j+1] = array[j];
            j = j - 1;
        }
        array[j + 1] = position;
    }
    gettimeofday(&t1, NULL);
    elapsed = timedifference_msec(t0, t1);
    printf("Insertion Sorted List of Numbers:\n");
	for(j = 0; j < num; j++)
	{
		printf("%d\n",array[j]);
	}
   printf("Insertion Sort Code executed in %f milliseconds.\n", elapsed);
}
