/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:50:51 by theophilebr       #+#    #+#             */
/*   Updated: 2023/01/22 15:55:54 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
    int a = 42;                             //valeur de référence

    int const   *b = &a;                    //Implicite type qualifier cast -> promotion
    int const   *c = (int const *)&a;    //Explicite type qualifier cast -> promotion

    int const   *d = &a;
    int         *e = d;                     // HOulaaa faut pas faire de demotion là
    int         *f = (int *)d;              // ok ca va compilé mais t'as du faire de la merde pour en arriver là
}