/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:31:24 by vegret            #+#    #+#             */
/*   Updated: 2023/09/04 16:02:52 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include <string>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &source);
		~Dog();
		Dog &operator=(const Dog &source);
		void makeSound() const;
};

#endif
