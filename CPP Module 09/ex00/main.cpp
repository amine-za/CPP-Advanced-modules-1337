/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:39:06 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/25 20:59:16 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//      filename = av[1];
//      std::ifstream input(filename);
//      std::getline(input, line);
//      file_content += line;
//      if (!input.eof())
//      file_content += '\n';

std::string    *add_arg_to_array(std::string *array, std::string arg)
{
    static int i;
    std::string *new_array = new std::string[i+1];

    for(int x = 0; x < i; x++)
        new_array[x] = array[x];
    new_array[i] = arg;
    new_array[i] += '\n';
    delete[] array;
    array = &new_array[0];
    i++;
    return (new_array);
}

int count_lines(std::string *file_content)
{
    int num = 0;
    while(!file_content[num].empty())
        num++;
    return (num);
}

int form_check(std::string *file_content)
{
    std::string first_line = "date | value\n";
    if (file_content[0] != first_line)
        return (1);
    int lines_num = count_lines(file_content);
    for(int x = 1; x < lines_num; x++)
    {
        // if (file_content[x][4] != '-' || file_content[x][7] != '-' 
        // || file_content[x][10] != ' ' || file_content[x][11] != '|' || file_content[x][12] != ' ')
        //     return (1);
        for(int y = 0; file_content[x][y] && y < 11; y++)
        {
            // if (!std::isdigit(file_content[x][y]) && file_content[x][y] != '-' && file_content[x][y] != '+'
            //         && file_content[x][y] != ' ' && file_content[x][y] != '|' && file_content[x][y] != '\n')
            //     return (1);
            if ((y == 4 || y == 7) && file_content[x][y] != '-') // Description: The '-' characters that should be between the date parts
                return (1);
            else if (y < 4 && !std::isdigit(file_content[x][y])) // Description: The year part : if the index is lower than 4 there should be just digits
                return (1);
            else if (y < 7 && !std::isdigit(file_content[x][y])) // Description: The year part : if the index is lower than 7 there should be just digits
                return (1);
            else if (y < 10 && !std::isdigit(file_content[x][y])) // Description: The year part : if the index is lower than 10 there should be just digits
                return (1);
            else if (file_content[x][10] != ' ' || file_content[x][11] != '|' || file_content[x][12] != ' ') // Description: Check if the date part is separated from the value part well
                return (1);
            if (file_content[x][13])
            {
                std::stringstream   ss(&file_content[x][13]);
                double var;
                if (!(ss >> var))
                    return (1);    
                std::cout << var << std::endl;
            }
        }
    }
    return (0);
}

int  *date_to_int_array(std::string line)
{
//  Description: First i will arrange the date in a string array then convert it and put it in an int array

    int         *date = new int[3];
    std::string array[3]; 

    for(int x = 0; x < 4; x++)
        array[0] += line[x];
    for(int x = 5; x < 7; x++)
        array[1] += line[x];
    for(int x = 8; x < 10; x++)
        array[2] += line[x];
    
    std::stringstream ss1(array[0]);
    std::stringstream ss2(array[1]);
    std::stringstream ss3(array[2]);
    if (!(ss1 >> date[0]) || !(ss2 >> date[1]) || !(ss3 >> date[2]))
        std::cerr << "An error appearse while triying to get the date\n";
    return (date);
}

int return_value(std::string line)
{
    int value;
    std::stringstream ss(line);

    if (!(ss >> value))
        std::cerr << "An error appearse while triying to get the value\n";
    return (value);
}

void    fill_the_map(std::map<int[3], double> Map, std::string *file_content)
{
    int lines_num = count_lines(file_content);
    
    // std::map<int[3], double>::iterator it = Map.begin();
    for(int x = 1; x < lines_num; x++)
    {
        int array[3] = {11, 22,33};
        Map.insert(std::make_pair(array, 22.0));
        // it.insert(std::make_pair(date_to_int_array(file_content[x], return_value(file_content[x]))));
    }
}

std::map<int[3], double> parsing(char *input)
{
    std::string     line;
    std::string     *file_content = new std::string[0];
    std::string     file_name = input;
    std::ifstream   file(file_name);
    std::map<int[3], double> Map;

    if (!file.is_open())
    {
        std::cerr << "Error: it appears that there is something wrong with the parameter you entered\n";
        exit(1);
    }
    while (1)
    {
        std::getline(file, line);
        file_content = add_arg_to_array(file_content, line);
        if (file.eof())
            break;
    }
    if (form_check(file_content))
    {
        std::cerr << "Error: it appears that there is something wrong with the parameter you entered\n";
        exit(1);
    }
    fill_the_map(Map, file_content);
    return (Map);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::map<int[3], double> Map = parsing(av[1]);
    }
    else
        std::cerr << "Error: no input file\n";
}
