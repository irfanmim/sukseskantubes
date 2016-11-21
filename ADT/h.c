#include <stdio.h>
#include <stdlib.h>
void maketable(int A, int B)
{
	FILE *f;
	f = fopen("map.txt", "w");
	int i, j;
	for (i = 0; i < 1 && i < A; ++i)
	{
		fprintf(f, "%c", (char) 201);
		for (j = 1; j < B-1; ++j)
		{
			fprintf(f, "%c", (char) 205);
		}
		fprintf(f, "%c\n", (char) 187);
	}
	for (; i < 2 && i < A; ++i)
	{
		fprintf(f, "%c", (char) 186);
		for (j = 1; j < B-1; ++j)
		{
			fprintf(f, " ");
		}
		fprintf(f, "%c\n", (char) 186);
	}
	for (; i < 3 && i < A; ++i)
	{
		fprintf(f, "%c", (char) 204);
		for (j = 1; j < B-1; ++j)
		{
			fprintf(f, "%c", (char) 205);
		}
		fprintf(f, "%c\n", (char) 185);
	}
	for (; i < A-1; ++i)
	{
		fprintf(f, "%c", (char) 186);
		for (j = 1; j < B-1; ++j)
		{
			fprintf(f, " ");
		}
		fprintf(f, "%c\n", (char) 186);
	}
	for (i = A-1; i < A; ++i)
	{
		fprintf(f, "%c", (char) 200);
		for (j = 1; j < B-1; ++j)
		{
			fprintf(f, "%c", (char) 205);
		}
		fprintf(f, "%c\n", (char) 188);
	}
	fclose(f);
}
int main()
{
	maketable(20, 50);
	FILE *f;
	f = fopen("map.txt", "r");
	do
	{
		char temp[100];
		fgets(temp, 100, f);
		if (!feof(f)) printf("%s",temp);
	} while (!feof(f));
	fclose(f);
	return 0;
}
