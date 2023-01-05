#include <omp.h> 
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    while(c!=3)

    {
        printf("Press 1 for serial Programming \n");
        printf("Press 2 for parallel Programming\n");
        printf("Press 3 to exit\n");
        scanf("%d",&c);
        if(c == 1)
        {
            double s,e;
            s = omp_get_wtime();//Start Time
            for(int i =0; i<1000000;i++)//1 million random numbers 
                printf(" %d ",rand()%100);
            e = omp_get_wtime();//End Time
            printf("\nTime Taken in serial mode: %f\n",e-s);//Time Taken
        }
        if(c==2)
        {
            double s2,e2;
            s2 = omp_get_wtime();//Start Time
            #pragma omp parallel
            {
                for(int i=0;i<250000;i++)
                    printf(" %d ",rand() % 100); //random numbers less than 100
            }
            e2 = omp_get_wtime();//End Time
            printf("\nTime Taken in parallel mode: %f\n",e2-s2);//Time Taken
            // Ending of parallel region
        }
        if(c==3)
            break;
    }
}

