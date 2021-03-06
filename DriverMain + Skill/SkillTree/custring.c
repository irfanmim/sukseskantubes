#include "boolean.h"
#include "custring.h"

boolean Strcmp(char A[], char B[])
{
	boolean same = true;
	int i = 0;
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

long strlen(char CC[])
{
	long i = 0;
	while (CC[i] != '\0')
	{
		++i;
	}
	return i;
}

void Strcpy(char A[], char B[])
{
	int i, len = strlen(B);
	for (i = 0; i < len; ++i)
	{
		A[i] = B[i];
	}
	for (i = strlen(A); i > strlen(B); --i)
	{
		A[i] = '\0';	
	}
}

void Strcat(char* A, char B[])
{
	int i, lenA = strlen(A), lenB = strlen(B);
	for (i = lenA; i < lenA+lenB; ++i)
	{
		A[i] = B[i-lenA];
	}
	for (i = strlen(A); A[i] != B[lenB-1]; --i)
	{
		A[i] = '\0';
	}
}

void KataToStr(Kata A, char B[])
{
	int i, len = A.Length;
	for (i = 0; i < len; i++)
	{
		A.TabKata[i+1] = B[i];
	}
	B[i] = '\0';
}
