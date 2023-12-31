/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:18:48 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/04 18:37:17 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data D;
    Data *after_cast;
    uintptr_t buffer = 0;
    D.value = 4869;

    std::cout << "before serialize: " << D.value << std::endl;
    buffer = Serializer::serialize(&D);
    std::cout << "after serialize: " << buffer << std::endl;
    after_cast = Serializer::deserialize(buffer);
    std::cout << "after deserialize: " << after_cast->value << std::endl;
}