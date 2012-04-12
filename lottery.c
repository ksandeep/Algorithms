// Bloomberg Interview Question - CareerCup
/*
I have a lottery ticket. Each of these lottery tickets has a 6 digit number on it. The winning lottery tickets are those whose sum of the first three digits is equal to the sum of the last three digits. How many possible winning tickets are there? 
Note: Leading ‘ZEROES’ are counted. So a number like 004103 is a valid winning ticket since 0+0+4 = 1+0+3.
*/


# include <stdio.h>
# define N 27          // 9*9*9

int main()
{
	int arr[N];
	int i, d1, d2, d3;
	long result = 0;
	for (i=0; i < N; i++)
		arr[i] = 0;
		
	for (d1 = 0; d1 < 10; d1++)
		for (d2 = 0; d2 < 10; d2++)	
			for (d3 = 0; d3 < 10; d3++)
				arr[(d1+d2+d3)]++;
		
	
	for (i=0; i < N; i++)
		result += arr[i]*arr[i];
	
	printf("\n Winning tickets countt = %ld\n", result);

	return 0;
}
