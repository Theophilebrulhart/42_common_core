/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:29:24 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/11 10:58:08 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

int main (void)
{
    Warrior *WarriorA = new Warrior();
    Character *WarriorB = new Warrior();
    Character *CharacterA = new Character();

    WarriorA->sayHello("Jean");
    WarriorB->sayHello("Claude");
    CharacterA->sayHello("Hubert");

    delete(WarriorA);
    delete(WarriorB);
    delete(CharacterA);
    return (0);
}