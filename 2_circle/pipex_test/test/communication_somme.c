#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

	int main(void)
	{
	int fd[2];
	int id;
	int	array[] = {1, 2, 3, 4, 5 ,6, 10};
	int start;
	int arr_size;
	int end;
	int sum;
	int sum_final;
	int i;

	arr_size = sizeof(array) / sizeof(int);
	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (1);
	if (id == 0)
	{
		start = 0;
		end = arr_size / 2;
	}
	else
	{
		start = arr_size / 2;
		end = arr_size;
	}
	i = start;
	sum = 0;
	while (i < end)
	{
		sum += array[i];
		i++;
	}
	printf("somme interm : %d\n", sum);
	if (id == 0)
	{
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(sum)) == -1)
			return (1);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		if (read(fd[0], &sum_final, sizeof(sum_final)) == -1)
			return (1);
		close(fd[0]);
		sum_final += sum;
		printf("somme final : %d\n", sum_final);
		wait(NULL);
	}
}