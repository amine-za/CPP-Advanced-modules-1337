/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:39:06 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/27 23:57:30 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// #include <iostream>

// int main() {
//     // Representing a null-like value for a double
//     double myValue = std::numeric_limits<double>::quiet_NaN();

//     // Check if the value is NaN
//     if (std::isnan(myValue))
//         std::cout << "The value is NaN." << std::endl;
//     else
//         std::cout << "The value is not NaN." << std::endl;
//     return 0;
// }

        // if (file_content[x][4] != '-' || file_content[x][7] != '-' 
        // || file_content[x][10] != ' ' || file_content[x][11] != '|' || file_content[x][12] != ' ')
        //     return (1);
        
            // if (!std::isdigit(file_content[x][y]) && file_content[x][y] != '-' && file_content[x][y] != '+'
            //         && file_content[x][y] != ' ' && file_content[x][y] != '|' && file_content[x][y] != '\n')
            //     return (1);

std::string    *add_arg_to_array(std::string *array, std::string arg)
{
    static int i;
    std::string *new_array = new std::string[i+2];

    for(int x = 0; x < i; x++)
        new_array[x] = array[x];
    new_array[i] = arg;
    new_array[i] += '\n';
    delete[] array;
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

bool FirstFourAreDigits(std::string str)
{
    for (int i = 0; i < 4; i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

int form_check(std::string line)
{
    if (line.size() > 12 && (line[10] != ' ' || line[11] != '|' || line[12] != ' ')) // Description: Check if the date part is separated from the value part well
        return (std::cerr << "Error: unvalide line form\n", 1);
    if (line.size() == 11 || line.size() == 12)
        return (std::cerr << "Error: no value\n", 1);
    if (line[4] != '-' || line[7] != '-')              // Description: The '-' characters that should be between the date parts
        return (std::cerr << "Error: unvalide date\n", 1);
    for(int y = 0; line[y] && y < 11; y++)
    {
        if (y < 4 && !std::isdigit(line[y]))           // Description: The year part : if the index is lower than 4 there should be just digits
            return (std::cerr << "Error: unvalide date\n", 1);
        if (y > 4 && y < 7 && !std::isdigit(line[y]))  // Description: The year part : if the index is lower than 7 there should be just digits
            return (std::cerr << "Error: unvalide date\n", 1);
        if (y > 7 && y < 10 && !std::isdigit(line[y])) // Description: The year part : if the index is lower than 10 there should be just digits
            return (std::cerr << "Error: unvalide date\n", 1);
    }
    if (line[13])
    {
        double var;
        std::stringstream   ss(&line[13]);
        if (!(ss >> var))
            return (std::cerr << "Error: unvalide value\n", 1);
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
        std::cerr << "Error: unvalide date\n";
    return (date);
}

std::string return_date(std::string line)
{
//  Description : get the date from a line of data.csv file
    std::string date = line;
    for(int x = 10; date[x]; x++)
        date[x] = '\0';
    return (date);
}

double return_value(std::string line, int flag)
{/*
    •Description : Get the value (price) from a line of data.csv file.
    •About the flag variable : If flag == 0 that mean that i want to get the value from the input file,
     and if flag == 1 that mean that i want to get the value from the data file,                      */
    double  value;
    int     divide_index; // The index of the char that divide the date from the value

    if (flag == 0)
        divide_index = 13;
    if (flag == 1)
        divide_index = 11;
    if ((int)line.size() > divide_index + 1)
        line = &line[divide_index];
    else
        return (std::numeric_limits<double>::quiet_NaN()); // To check it : std::isnan(myValue)
    std::stringstream   ss(line);
    if (!(ss >> value)) // converting the string that contain the number to a double
    {
        std::cerr << "An error appearse while triying to get the value\n";
        exit(1);
    }
    return (value);
}

void    fill_the_container(std::map<std::string, double> *Map)
{
    std::string     line;
    std::ifstream   file("data.csv");
    
    if (!file.is_open())
    {
        std::cerr << "Error: An error appears while trying to read the data.csv file\n";
        exit(1);
    }
    std::getline(file, line);
    while (1)
    {
        std::getline(file, line);
        if (file.eof())
            break;
        Map->insert(std::make_pair(return_date(line), return_value(line, 1)));
    }
}

void    print_result(std::string line, std::map<std::string, double> Map)
{
    double  result;                                      // The result of (quantity * value)
    double  bitcoin_quantity = return_value(line, 0);   // How many bitcoin the user have.
    std::map<std::string, double>::iterator it = (Map.lower_bound(return_date(line)));

    if (it != Map.begin() && it->first != return_date(line))
        it--;
    result = bitcoin_quantity * it->second;
    if (return_value(line, 0) > 1000)
        std::cerr << "Error: too large a number." << std::endl;
    else if (bitcoin_quantity >= 0)
        std::cout << return_date(line) << " => " << return_value(line, 0) << " = " << result << std::endl;
    else
        std::cerr << "Error: not a positive number.\n";
}

void    DoTheRealWork(std::string *file_content, std::map<std::string, double> Map)
{
    int *date;
    int lines_num = count_lines(file_content);

    std::time_t currentTime = std::time(NULL);                          //
    std::tm* localTime = std::localtime(&currentTime);                  //
    if (localTime == NULL)                                              //           That part of the
    {                                                                   //
        std::cerr << "Error: Failed to get local time." << std::endl;   //
        exit(1);                                                        //          function is just for
    }                                                                   // 
    bool leap_year;                                                     //
    int year = localTime->tm_year + 1900;                               //          getting today's date
    // int month = localTime->tm_mon + 1;                               //          
    // int day = localTime->tm_mday;                                    //
    
    if (file_content[0] != "date | value\n")
        std::cerr << "Error: first line form error\n";
    for(int x = 1; x < lines_num; x++)
    {
        std::string str = file_content[x];
        str[str.length()-1] = '\0';
        std::cout << str << " : ";
        // std::cout << "                                                             " << file_content[x] << std::endl;
        if (form_check(file_content[x]))
            continue;
        leap_year = false;
        double var = (double)year / 4.0;
        std::cout << "double : " << var << std::endl;
        if ((double)(int)var != var) // HHHHH there is a double type cast here, that is just for removing the period from the double number
            leap_year = true;
        std::cout << leap_year << std::endl;
        date = date_to_int_array(file_content[x]);
        if (date[1] < 1 || date[1] > 12 || date[2] < 1 || date[2] > 31)
            std::cerr << "Error: bad input => " << file_content[x];
        else if (date[1] == 2 && ((leap_year == true && date[2] > 29) || (leap_year == false && date[2] > 28)))
            std::cerr << "Error: Leap year problem\n";
        else
            print_result(file_content[x], Map);
    }
}

std::map<std::string, double> completeTask(char *input)
{
    std::string     line;
    std::string     *file_content = new std::string[0]; // Where i will store the content of the input file
    std::string     file_name = input;
    std::ifstream   file(file_name);
    std::map<std::string, double> Map;

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
    fill_the_container(&Map); // Fill a map container with the bitcoin data that comes with the project
    DoTheRealWork(file_content, Map);
    return (Map);
}

int main(int ac, char **av)
{
    if (ac == 2)
        std::map<std::string, double> Map = completeTask(av[1]);
    else
        std::cerr << "Error: could not open file.\n";
}
