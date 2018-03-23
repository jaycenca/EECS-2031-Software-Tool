#include <stdio.h>

#define N 10

void walking(char str[N][N], int i, int j);
void displayMatrix(char str[N][N] );
void initializeArray(char str[N][N], int n);
int checkGenerated(int generate[4], int n);
void resetGenerated(int generate[4], int n);


int main()
{
	char str[N][N];
	int i, j;
	
	//initializing the 2D array
	initializeArray(str ,N);

	//performing algorithm
	walking(str, i , j );
	//char start = 'A';
	//printf("%c\n", start+1);
	
	//displaying the result
	displayMatrix(str);
	
}

//displaying the array
void displayMatrix(char str[N][N])
{
	int i, j;

	for ( i = 0; i < N; i++ )
	{
		for ( j = 0; j < N; j++)
		{
			char current = str[i][j];
			printf("%c ", current);
		}
		printf("\n");
	}
}

//initializing the array 
void initializeArray(char arr[N][N], int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			arr[i][j] = '.';
		}
	}
}

//assuring all corners are checked
int checkGenerated(int generate[4], int n)
{
	//flag indicating true
	int flag = 1;

	/**
	 * loop through all elements in the array
	 *
	 * if one element in the array is zero, the array is not full.
	**/
	int i;
	for(i = 0; i < n; i++)
	{
		if(generate[i] == 0)
			flag = 0;
	}

	return flag;
}

//reset all corners when one of the corners is free to move 
void resetGenerated(int generate[4], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		generate[i] = 0;
	}

}

/**
 * performing algorithm
 *
 * 
 *
 **/
void walking(char arr[N][N], int i, int j)
{   	
	//reinitialize i and j for waling purpose
	i = 0;
	j = 0;

	char start = 'A';

	//generating random number between 0 and 3
	srand(time(NULL));
	int random = rand()%4;

	//keep track the value of if all four values are hit
	int violation = 0;
	int full = 0;

	//array to keep track of the generated number that have been seem
	int generated[4] = {0};

	//count if the generated number seem
	int count = 0;

	//initialize A at i = 0, j = 0
	arr[i][j] = start;

	/*
	 * Random = 0 --- means going up 
	 * Random = 1 --- means going down
	 * Random = 2 --- means going left
	 * Random = 3 --- means going right
	 *
	 *
	 * 1) check if the random number have appeared before
	 * 2) update the array that storing the random number 
	 * 3) update the i and j indices
	 * 4) check all directions for the existen character 
	 */

	start += 1;

	while ( start != 'Z' + 1 && violation == 0)
	{
		random = rand()%4;
		
		//move up
		if(random == 0 && generated[random] != 1 )
		{
			//printf("The random number is %d\n", random);
			generated[random] = 1;

			if(i >= 1 && arr[i-1][j] == '.')
			{
				arr[i-1][j] = start;
				start += 1;
				i--;
				resetGenerated(generated, 4);
			}
		}

		//move down
		else if(random == 1 && generated[random] != 1)
		{
			//printf("The random number is %d\n", random);
			generated[random] = 1;
			
			if(i < 9 && arr[i+1][j] == '.')
			{
				arr[i+1][j] = start;
				start += 1;
				i++;
				resetGenerated(generated, 4);
			}

		}

		//move left
		else if(random == 2 && generated[random] != 1)
		{
			//printf("The random number is %d\n", random);
			generated[random] = 1;

			if(j >= 1 && arr[i][j-1] == '.')
			{
				arr[i][j-1] = start;
				start += 1;
				j--;
				resetGenerated(generated, 4);
			}

		}

		//move right
		else if(random == 3 && generated[random] != 1)
		{
			//printf("The random number is %d\n", random);
			generated[random] = 1;
			
			if(j < 9 && arr[i][j+1] == '.')
			{
				arr[i][j+1] = start;
				start += 1;
				j++;
				resetGenerated(generated, 4);
			}

		}
		//all directions blocked
		else 
		{
			int flag = checkGenerated(generated,4);
			if(flag == 1)
				full = 1;
		}

		if(full == 1)
			violation = 1;
	}
}
