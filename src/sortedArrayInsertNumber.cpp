/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int j;
	
	
		 if( (Arr == NULL)||(len<=0))  return NULL;
	
	else
	{
		Arr = (int *)realloc(Arr, (len + 1) * sizeof(int));

		if (Arr[0] >= num)
		{
			for (int i = len; i >= 1; i--)
				Arr[i] = Arr[i - 1];
			Arr[0] = num;
			
		}
		else if (Arr[len - 1] <= num)
		{
			Arr[len] = num;
			
		}
		else
		{
			for (int i = 0; i < len-1; i++)
			{
				if ((Arr[i] <= num)&&(num <= Arr[i + 1]))
				{
					for (j = len - 1; j > i; j--)
						Arr[j + 1] = Arr[j];
					Arr[j+1] = num;
					break;
				}
			}
		}

	}
	return Arr; 

}