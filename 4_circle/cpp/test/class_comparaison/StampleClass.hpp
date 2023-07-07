/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampleClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:32:32 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/19 16:30:18 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef STAMPLECLASS_H
# define STAMPLECLASS_H

class Sample
{
    public :

        Sample(int v);
        ~Sample(void);

        int getfoo(void) const;
        int comparefoo(Sample *other) const;
    
    private :

        int _private_foo;
};

# endif