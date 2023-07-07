/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:56:55 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/20 17:36:47 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>

class Contact
{
    public :

        Contact(void);
        ~Contact(void);
		
		std::string	getFirstName() const;
		void		setFirstName(std::string value);
		std::string	getLastName() const;
		void		setLastName(std::string value);
		std::string	getNickName() const;
		void		setNickName(std::string value);
		std::string getPhoneNumber() const;
		void		setPhoneNumber(std::string value);
		std::string	getSecret() const;
		void		setSecret(std::string value);

    private :

        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string	_phoneNumber;
        std::string _secret;
};

#endif