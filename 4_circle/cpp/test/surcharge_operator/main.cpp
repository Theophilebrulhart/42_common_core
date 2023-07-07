/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:29:24 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/09 12:50:34 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IntegerClass.hpp"

int main(void)
{
  Integer x(30);
  Integer y(10);
  Integer z(0);

  std::cout << "value of x : " << x << std::endl;
  std::cout << "value of y : " << y << std::endl;
  std::cout << "value of z : " << z << std::endl;
  y = Integer(12);
  std::cout << "value of y : " << y << std::endl;
  z = x + y;
  std::cout << "value of z : " << z << std::endl;
  return (0);
}


// 1 + 1 -> infixe
// + 1 1 -> prefixe ou fonctionnelle -> +(1, 1) -> 1.+(1) -> en fonction membre
// 1 1 + -> postfixe