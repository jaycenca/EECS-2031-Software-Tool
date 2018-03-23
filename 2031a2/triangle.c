#include <stdio.h>

void displayTriangle(int n);
int messageErrorHandling();

int main(void)
{
	int n;

	//returns a value in the range between 1 and 20
	n = messageErrorHandling();
	
	displayTriangle(n);
	return 0;
}

//handle out-of-bound exception error
/*this method restricts the user
 *to enter only input in the range between 1 and 20
 *
 *Keep asking for input otherwise
*/ 
int messageErrorHandling()
{
	
	int n;
	printf("\nEnter the number of rows in the triangle: ");
	scanf("%d", &n);

	//Error Handling for invalid input
	if(n < 1 || n > 20)
	{
		printf("Please Enter A Valid Value!\nPlease Re-Run the program!!!\n");
		n = 0;
	}
	return n;

}

//function that only print the triangle
void displayTriangle(int n)
{
	int i, j;
	int mid = n - 1;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n * 2; j++)
		{
			if( i == n - 1 && j != n * 2 - 1)
				printf("*");
			else if( j == mid + i || j == mid - i )
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}
