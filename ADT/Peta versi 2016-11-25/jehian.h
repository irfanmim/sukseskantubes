#ifndef STRING_H
#define STRING_H

long strlen(char CC[])
{
	int i = 0;
	while (CC[i] != '\0')
	{
		++i;
	}
	return i;
}

int strcmp(char A[], char B[])
{
	int found = 1;
	if (strlen(A) == strlen(B))
	{
		int i = 0;
		while (i < strlen(A) && found)
		{
			if (A[i] != B[i])
			{
				found = 0;
			}
			else
			{
				++i;
			}
		}
		return found;
	}
	else
	{
		return 0;
	}
}

#endif
