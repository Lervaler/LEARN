#include "cvsreader.h"

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

void Cvsreader::read_tab(const std::string& path)
{
    std::ifstream file(path);

    std::string symbol;                    // для подсчета имени в строке
    std::string word;                      //построчные слова
    std::vector<std::string> new_word;    // vector of names - по длине первой строки определяется смещение
    std::vector<std::string> all_tab;

//    std::getline(file, word);

//while(!file.eof())

    file >> word;
    std::string::iterator iter = word.begin();
    for(; iter != word.end(); ++iter)
    {
        if(*iter != ',')
        {
            symbol += *iter;
        }
        if (*iter == ',')
        {
            new_word.emplace_back(symbol);
            symbol.clear();
        }
        if(iter == word.end() -1)
        {
            new_word.emplace_back(symbol);
            symbol.clear();
        }
    }

    while(!file.eof())
    {
        file >> word;
        std::string::iterator itr = word.begin();
        for(; itr != word.end(); ++itr)
        {
            if(*itr != ',')
            {
                symbol += *itr;
            }
            if (*itr == ',')
            {
                all_tab.emplace_back(symbol);
                symbol.clear();
            }
            if(itr == word.end() -1)
            {
                all_tab.emplace_back(symbol);
                symbol.clear();
            }
        }
    }

    file.close();

    std::cout<< new_word.size()<< std::endl;

    std::cout<<std::stoi(all_tab[8]) << std::endl;

    auto r =  std::find_if(all_tab.begin(), all_tab.end(),
                              [](const std::string& value)
                              {
                                  return value[0] == '=';
                              }
                          );
    std::cout<< *r << std::endl;
    std::string formating = *r;        // сюда записана строка типа =A1+B1

    // ищем первый и второй элементы подлежащие операции по имени

    std::string arg1;
    std::string num_arg1;
    std::string arg2;
    std::string num_arg2;
    char op = 0;

    std::string::iterator itr1 = formating.begin()+1;
    std::string::iterator itr2;

    for(; itr1 != formating.end(); ++itr1)
    {
        if((*itr1 >='A' && *itr1 <='Z') || (*itr1 >='a' && *itr1 <='z'))
        {
            arg1 += *itr1;
        }
        if(*itr1 >='0' && *itr1 <='9')
        {
            num_arg1 += *itr1;
        }
        if (*itr1 == '+' || *itr1 == '-' || *itr1 == '/' || *itr1 == '*')
        {
            op = *itr1;
            itr2 = itr1;
            break;
        }
    }
        for(; itr2 != formating.end(); ++itr2)
       {
                if((*itr2 >='A' && *itr2 <='Z') || (*itr2 >='a' && *itr2 <='z'))
                {
                    arg2 += *itr2;
                }
                if(*itr2 >='0' && *itr2 <='9')
                {
                    num_arg2 += *itr2;
                }
        }

//  ищем по итераторам аргументов значения, на которые указывают элементы

    auto iter1 = find(new_word.begin(), new_word.end(), arg1);
    auto iter2 = find(new_word.begin(), new_word.end(), arg2);

    std::string first;
    std::string second;

    for(int i = 0; i < all_tab.size(); ++i * new_word.size())
    {
        if(all_tab[i] == num_arg1)
        {
           first = all_tab[i+std::distance(new_word.begin(), iter1)];
           break;
        }
    }

    for(int i = 0; i < all_tab.size(); ++i * new_word.size())
    {
        if(all_tab[i] == num_arg2)
        {
           second = all_tab[i+std::distance(new_word.begin(), iter2)];
           break;
        }
    }

    // подсчет операции двух индексов

    int first_int = std::stoi(first);
    int sedcond_int = std::stoi(second);
    int result = 0;

    switch(op)
    {
        case '+':
        {
            result = first_int + sedcond_int;
            break;
        }
        case '-':
        {
            result = first_int - sedcond_int;
            break;
        }
            case '*':
        {
            result = first_int * sedcond_int;
            break;
        }
            case '/':
        {
            result = first_int / sedcond_int;
            break;
        }
    }


    int dsf = 0;
}
