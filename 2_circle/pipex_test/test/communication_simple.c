/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:12:17 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/26 18:44:45 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd[2];
    int id;
    int x;
    int y;

    if (pipe(fd) == -1)
    {
        printf("erreur[pipe]\n");
        return (1);
    }
    id = fork();
    if (id == -1)
    {
        printf("erreur[fork]\n");
        return (1);
    }
    if (id == 0)
    {
        close(fd[0]);
        printf("enter a number : \n");
        scanf("%d", &x);
        if (write(fd[1], &x, sizeof(int)) == -1)
        {
            printf("erreur[write]\n");
            return (1);
        }
        close(fd[1]);
    }
    if (id != 0)
    {
        close(fd[1]);
        if (read(fd[0], &y, sizeof(int)) == -1)
        {
            printf("erreur[read]\n");
            return (1);
        }
        close(fd[0]);
        printf("we got : %d\n", y);
    }
    return (0);
}