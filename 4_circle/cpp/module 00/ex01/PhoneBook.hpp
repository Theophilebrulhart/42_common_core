/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:48:39 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/20 19:00:26 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "Contact.hpp"
# include <iostream>
# include <iomanip> 

class PhoneBook
{

    public :

        PhoneBook();
        ~PhoneBook(void);
        
        void    addContact();
        void    searchContact(int i) const;
        void    printContacts() const;

    private :
    
        Contact contacts[8];
        int _nbrContact;
		int	_nbrContactMax;
        
};

#endif