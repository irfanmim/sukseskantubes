#include "boolean.h"
#include "custring.h"

long strlen(char CC[])
{
	long i = 0;
	while (CC[i] != '\0')
	{
		++i;
	}
	return i;
}

boolean Strcmp(char A[], char B[])
{
	boolean same = true;
	int i;
	if (strlen(A) == strlen(B))
	{
		int panjang = strlen(A);
		while (i < panjang && same)
		{
			if (A[i] != B[i])
			{
				same = false;
			}
			else
			{
				++i;
			}
		}
		return same;
	}

	else
	{
		return (!same);
	}
}
