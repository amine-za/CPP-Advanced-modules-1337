/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:31:49 by azaghlou          #+#    #+#             */
/*   Updated: 2024/01/09 21:54:04 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string RmSpaceInEnd(std::string line)
{
//  Description : A function that remove the spaces in the end of a string
    std::string str;
    int x = line.size() - 1;

    while(line[x] == ' ')
    {
        line[x] = '\0';
        x--;
    }
    for(int x = 0; line[x]; x++)
        str += line[x];
    return (str);
}

bool    hasNonDigitCharacters(std::string line)
{
//  Function description : just a function that check if the string contains just numbers or not.
//  Return value : The true return represent that it have something else.
    for(int x = 0; line[x]; x++)
    {
        if (!std::isdigit(line[x]) && line[x] != '.')
            return (true);
    }
    return (false);
}

bool    valide_date( int *date, bool *leap_year)
{
//  Function description : A function that check if the date is valide in the month days condition and handle the future date condition 
    
    std::time_t currentTime = std::time(NULL);                          //
    std::tm* localTime = std::localtime(&currentTime);                  //
    if (localTime == NULL)                                              //           That part of the
    {                                                                   //
        std::cerr << "Error: Failed to get local time." << std::endl;   //          function is just for
        exit(1);                                                        //
    }                                                                   //          getting today's date 
    int year = localTime->tm_year + 1900;                               //
    int month = localTime->tm_mon + 1;                                  //          
    int day = localTime->tm_mday;                                       //
    int month_days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};    // The number of days on each month
    
    if (date[1] <= 12 && date[2] > month_days[date[1] - 1])
        return (std::cerr << "Error: That month day is wrong\n", true);
    if (date[0] > year || (date[0] == year && date[1] > month ) || (date[0] == year && date[1] == month && date[2] > day))
    {
        std::cerr << "Error: I can't see the future\n";
        return (true);
    }
    if (date[0] < 2009 || (date[0] == 2009 && date[1] < 1 ) || (date[0] == 2009 && date[1] == 1 && date[2] < 2))
    {
        std::cerr << "Error: bad input => " << date[0] << "-" << date[1] << "-" << date[2] << std::endl;
        return (true);
    }
    *leap_year = leapTrueFalse(date[0]);
    return (false);
}

bool    leapTrueFalse(int year)
{
//  Description : A function that takes a year and return a bool that determine if its a leap year of not
    float  d = (float)year / 4.0;

    if (d == (static_cast<int>(d)))
        return(true); 
    return(false);
}

int form_check(std::string line)
{
    if (line.size() > 12 && (line[10] != ' ' || line[11] != '|' || line[12] != ' ')) // Description: Check if the date part is separated from the value part well
        return (std::cerr << "Error: unvalide line form\n", 1);
    if (line.size() == 11 || line.size() == 12)
        return (std::cerr << "Error: no value\n", 1);
    if (line[4] != '-' || line[7] != '-')                       // Description: The '-' characters that should be between the date parts
        return (std::cerr << "Error: unvalide date\n", 1);
    for(int y = 0; line[y] && y < 11; y++)
    {
        if (y < 4 && !std::isdigit(line[y]))                    // Description: The year part : if the index is lower than 4 there should be just digits
            return (std::cerr << "Error: unvalide date\n", 1);
        if (y > 4 && y < 7 && !std::isdigit(line[y]))           // Description: The year part : if the index is lower than 7 there should be just digits
            return (std::cerr << "Error: unvalide date\n", 1);
        if (y > 7 && y < 10 && !std::isdigit(line[y]))          // Description: The year part : if the index is lower than 10 there should be just digits
            return (std::cerr << "Error: unvalide date\n", 1);
    }
    if (line.size() > 14)
    {
        float var;
        std::stringstream   ss(&line[13]);
        if (line[13] == '-')
            return (std::cerr << "Error: not a positive number.\n", 1);
        if (!(ss >> var) || hasNonDigitCharacters(&line[13]))
            return (std::cerr << "Error: unvalide value\n" << var << "\n", 1);
    }
    return (0);
}
// 2011-01-03 => 1.2 = 0.36

int    date_to_int_array(std::string line, int *date)
{
//  Description: First i will arrange the date in a string array then convert it and put it in an int array
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
    if (!(ss1 >> date[0]) || !(ss2 >> date[1]) || !(ss3 >> date[2]) || date[1] == 0)
        return (std::cerr << "Error: unvalide date\n", 1);    // here is the problem
    return (0);
}

std::string get_date(std::string line)
{
//  Description : get the date from a line of data.csv file
    std::string date = line;
    for(int x = 10; date[x]; x++)
        date[x] = '\0';
    return (date);
}

float   get_data_value(std::string line)
{
    float   value;

    line = &line[11];
    std::stringstream   ss(line);
    if (!(ss >> value)) // converting the string that contain the number to a float
        std::cerr << "An error appearse while triying to get the value\n";
    return (value);
}

void    fill_the_container(std::map<std::string, float> *Map)
{
//  Function description : A function that fill the map container given in parameters with the data from data.csv file
    std::string     line;
    std::ifstream   file("data.csv");
    
    if (!file.is_open())
        std::cerr << "Error: An error appears while trying to read the data.csv file\n";
    std::getline(file, line);
    while (1)
    {
        std::getline(file, line);
        Map->insert(std::make_pair(get_date(line), get_data_value(line)));
        if (file.eof())
            break;
    }
}

void    print_result(std::string line, std::map<std::string, float> Map)
{
//  Function description : A function that check if the input value is too high and calcule and print the result

    float  result;                 // The result of (quantity * value)
    std::string str = &line[13];   // How many bitcoin the user have.
    std::stringstream ss(str);
    float bitcoin_quantity;

    if (!(ss >> bitcoin_quantity)) // converting the string that contain the number to a float
        return (std::cerr << "No value entered\n", void());
    int date[3];
    date_to_int_array(line, &date[0]);
    std::map<std::string, float>::iterator it = (Map.lower_bound(get_date(line)));
    if (date[0] >= 2022 || (date[0] >= 2022 && date[1] >= 3) || (date[0] >= 2022 && date[1] >= 3 && date[2] >= 29))
        it--;
    else if (it != Map.begin() && it->first != get_date(line))
        it--;
    result = (float)bitcoin_quantity * (float)(it->second);
    if (bitcoin_quantity > 1000)
        std::cerr << "Error: too large a number." << std::endl;
    else if (bitcoin_quantity >= 0)
        std::cout << get_date(line) << " => " << bitcoin_quantity << " = " << result << std::endl;
    else
        std::cerr << "Error: not a positive number.\n";
}

void    DoTheRealWork(std::map<std::string, float> Map, std::string input_file)
{
    int             date[3];
    bool            leap_year;
    std::string     line;
    std::ifstream   file(input_file);

    if (!file.is_open())
        std::cerr << "Error: it appears that there is something wrong with the parameter you entered\n";
    std::getline(file, line);
    line = RmSpaceInEnd(line);
    if (line != "date | value\n" && line != "date | value" && line != "")
        std::cerr << "Error: first line form error\n";
    if (file.eof())
        return;
    while(!(line.empty()))
    {
        if (file.eof())
            break;
        std::getline(file, line);
        line = RmSpaceInEnd(line);
        if (line.empty())
            continue;
        if (form_check(line)){}
        else if (date_to_int_array(line, &date[0])){}
        else if (valide_date(date, &leap_year)){}
        else if (date[1] < 1 || date[1] > 12 || date[2] < 1 || date[2] > 31)
            std::cerr << "Error: bad input => " << line << std::endl;
        else if (date[1] == 2 && ((leap_year == true && date[2] > 29) || (leap_year == false && date[2] > 28)))
            std::cerr << "Error: Leap year problem\n";
        else
            print_result(line, Map);
    }
}
// 2011-01-03 => 1.2 = 0.36