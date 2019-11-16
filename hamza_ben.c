// benbachir hamza M2 IIPE  
// gcc -Wall -fopenmp pt1.c -o pp -lm

#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <time.h> 
#include<math.h>
#include<omp.h>

#define M 4
#define N 4


int A [M][M];
int B [M][M];
int C [M][M]; 
int k,j = 0; 

int main(int argc, char *argv[])
 {

  double debut,fin;
  double fin1,debut1;
  //srand(time(NULL));


 for (int i = 0; i < M; i++) { 
        for (int j = 0; j < M; j++) { 
            A[i][j] = rand() % 10; 
            B[i][j] = rand() % 10; 
        } 
    } 

    // affichage matrice A 
printf("matrice A \n") ;
	 for (int i = 0; i < M; i++)
        { 
        for (int j = 0; j < M; j++)
 		printf("%d \t",A[i][j]) ;
         printf("\n");
		}

        //affichage matrice B 
			printf("\n matrice B \n") ;
	 for (int i = 0; i < M; i++) 
        { 
        for (int j = 0; j < M; j++)
 		printf("%d \t",B[i][j]);
         printf("\n");
        }

        //calcule parallel du matrice C 
        debut=clock();
         #pragma omp parallel for
         
         
        for ( int i = 0;i < M; i++)
               {
        for (int j = 0; j < M; j++) 
            {
		 for (int k = 0; k < M; k++)
                C[i][j] += A[i][k] * B[k][j]; 
            }

               }
         
          
        fin=clock();
        printf("\n"); 
          // afficahge matrice C 
          printf("Matrice C : \n ");
       afficher(M,M,C);
    printf("temps parallele=%f\n", (double)(fin-debut)/CLOCKS_PER_SEC);
        
        //calcule sequenciel du matrice C 
        debut1=clock();
        for ( int i = 0;i < M; i++)
        {
        for (int j = 0; j < M; j++) 
            {
		 for (int k = 0; k < M; k++)
                C[i][j] += A[i][k] * B[k][j]; 
            }

        }
        
        fin1=clock();

    
        // afficahge matrice C en sequenciel  
         printf("Matrice C en sequenciel : \n ");
        afficher(M,M,C);
        printf("\n"); 
        printf("temps sequenciel=%f\n", (double)(fin1-debut1)/CLOCKS_PER_SEC);
	  
    return 0;

    }
  

void afficher(int ligne,int col,int x[ligne][col])
{
   for (int i = 0; i < ligne; ++i)
   {
       for (int j = 0; j < col; ++j)
       {
           printf("%d ", x[i][j]); 
       }
       printf("\n"); 
   }
}
    

