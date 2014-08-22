#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int media_data (int tmp[])
{
	int m;
	int i,j;
	
	printf("\n\n arreglo tmp de i:  ");
		for(i = 0; i < 5; ++i)
			printf("%d",tmp[i] );

	for(i=0; i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(tmp[i] > tmp[j])
			{
				m = tmp[i];
				tmp[i]=tmp[j];
				tmp[j]=m;
			}	
		}
	}
	m=tmp[2];

	printf("\n\n arreglo ordenado tmp:  ");
		for(i = 0; i < 5; ++i)
			printf("%d",tmp[i] );
	printf("\t->%d\n", m );
	return m;
};

void getMedian (int lista_1[], int lista_2[], int ARRAY_SIZE)
{
	int wSize = 5;
	int i = 0;
	int j = 0;
	int tmp[ wSize ];
	for ( i=0; i<ARRAY_SIZE;  i++)
	{
		switch ( i )
		{
			case 0:
					tmp[0]=lista_1[0];
					tmp[1]=lista_1[0];
					
					for (j=0;j<3;j++)
					{
						tmp[j+2]=lista_1[i+j];
					}
			break;

			case 1:
					tmp[0]=lista_1[0];
					
					for (j=0;j<4;j++)
					{
						tmp[j+1]=lista_1[j];
					}
			break;

			case 10:
					tmp[4]=lista_1[10];
					tmp[3]=lista_1[10];
					
					for (j=0;j<3;j++)
					{
						tmp[2-j]=lista_1[i-j];
					}
			break;


			case 9:
					tmp[4]=lista_1[10];
					tmp[3]=lista_1[10];
					
					for (j=0;j<3;j++)
					{
						tmp[j]=lista_1[(i-2)+j];
					} 
			break;

			default :
					for (j=0;j<5;j++)
					{
						tmp[j]=lista_1[(i-2)+j];
					}
			break;
		}
		printf("Ciclo i =%d\n",i );
		lista_2[i]=media_data(tmp);
	}



};

void fillArray (int lista[], int ARRAY_SIZE)
{
	int i;
	for (i=0;i<ARRAY_SIZE+1;i++)
	{
		lista[i]=rand()% 23459;	
	}
 

};

int main (int argc, const char * argv [])
{
//	Define the size of the b array.	
	int i,c;
	int ARRAY_SIZE = 11 ;
	int b[ ARRAY_SIZE ];
	int bp[ARRAY_SIZE];
	fillArray( b, ARRAY_SIZE );

	//a is the test array
	int a[] = { 7, 12, 1, -2, 0, 15, 4, 11, 9, 22, 8};
	int ap[11];

	printf("\n\nNo media array is:  ");
		for(i = 0; i < ARRAY_SIZE; ++i)
			printf(" %d ", a[i]);
		
	//testing
	fillArray(b,ARRAY_SIZE);
	getMedian( a, ap, ARRAY_SIZE);

	//c= media_data(tmp);
	printf("\n\nMadian array is:  ");
		for(i = 0; i < ARRAY_SIZE; ++i)
			printf(" %d ", ap[i]);
		printf("\n");

return 0;
}