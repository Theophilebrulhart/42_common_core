/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:32:47 by theophilebr       #+#    #+#             */
/*   Updated: 2023/01/22 15:44:10 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
    float   a = 42.042;         // valeur de référence

    void    *b = &a;            // cast implicite réinterpretation -> promotion
    void    *c = (void *)&a;    // cast explicite réinterprétation -> promotion

    void    *d = &a;            // Implicite promotion -> ok
    int     *e = d;             // Implicite demotion -> not ok at all
    int     *f = (int *)d;      // Explicite demotion -> ok but you're aware of the consequence

    printf("a : adresse %p, valeur %f\n", &a, a);
    printf("b : adresse %p\n", b);
    printf("c : adresse %p\n",c);
    printf("d : adresse %p\n", d);
    printf("e : adresse %p, valeur %d\n", e, *e);
    printf("f : adresse %p, valeur %d\n", f, *f);
}
