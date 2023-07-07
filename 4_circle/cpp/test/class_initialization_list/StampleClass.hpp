/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampleClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:25:14 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/16 16:17:02 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAMPLECLASS_H
# define STAMPLECLASS_H

class Sample
{
    public :

        int         a1;
        char        c1;
        float       f1;
        float const pi;

        Sample(int p1, char p2, float p3, float const pi);
        ~Sample(void);

        void    bar(void) const;
};

# endif