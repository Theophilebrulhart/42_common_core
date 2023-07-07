/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:26:32 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/29 14:28:54 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int ft_strlen(char *str)
{
    int i = 0;

    if (!str)
        return (0);
    while (str[i])
        i++;
    return (1);
}

int cd(char **argv)
{
    int i;

    i = 0;
    while (argv[i])
        i++;
    if (i != 2)
    {
        write(2, "error: cd: bad arguments ", ft_strlen("error: cd: bad arguments "));
        write(2, argv[1], ft_strlen(argv[0]));
        write(2, "\n", 1);
        return (-1);
    }
        
    if (chdir(argv[1]) < 0)
    {
         write(2, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
        write(2, argv[1], ft_strlen(argv[0]));
        write(2, "\n", 1);
        return (-1);
    }
    return (0);
}

int is_pipe(char **argv)
{
    int i;
    int ret;

    i = 0;
    ret = 0;
    while (argv[i])
    {
        if (strncmp(argv[i], "|", 2) == 0)
        {
            ret = 1;
            argv[i] = 0;
            break ;
        }
        if (strncmp(argv[i], ";", 2) == 0)
        {
            ret = 1;
            argv[i] = 0;
            break ;
        }
        i++;
    }
    return (ret);
}

void    command(int argc, char **argv, char **envp, int prev, int *fd_prev)
{
    int i;
    int next;
    int fd_next[2];
    int exit_status;
    pid_t pid;

    if (argc <= 1)
        return ;
    next = is_pipe(argv);
    if (argv[0])
    {
        if (next && pipe(fd_next) < 0)
        {
            write (2, "fatal:error", 11);
            exit (1);
        }
        if (strncmp(argv[0], "cd", 3) == 0)
            cd(argv);
        if ((pid = fork()) < 0)
        {
            write (2, "error fatal\n", 12);
            exit (1);
        }
        if (pid == 0)
        {
            if (prev && dup2(fd_prev[0], 0) < 0)
                exit (-1);
            if (next && dup2(fd_next[1], 1) < 0)
                exit (-1);
            if (execve(argv[0], argv, envp) < 0)
            {
                write (2, "error: cannot execute ", 22);
                write (2, argv[0], ft_strlen(argv[0]));
                write (2,"\n", 1);
                exit (-1);
            }
        }
        else
            if (waitpid(pid, &exit_status, 0) < 0)
            {
                write (2, "fatal error\n", 12);
                exit (1);
            }
            if (prev)
                close(fd_prev[0]);
            if (next)
                close(fd_next[1]);
    }
    i = 0;
    while (argv[i])
        i++;
    command(argc -1 -i, argv +1 +i, envp, next, fd_next);
}

int main(int argc, char **argv, char **envp)
{
    int prev;
    int fd_prev[2];

    prev = 0;
    fd_prev[0] = 0;
    fd_prev[1] = 1;
    command(argc, argv + 1, envp, prev, fd_prev);
}