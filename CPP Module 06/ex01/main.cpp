/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:18:48 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/31 14:52:52 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Serializer S;
    
    Data D;
    Data *after_cast;
    uintptr_t buffer = 0;
    D.value = 4869;

    buffer = S.serialize(&D);
    std::cout << "before: " << buffer << std::endl;
    after_cast = S.deserialize(buffer);
    std::cout << "after: " << after_cast->value << std::endl;
}