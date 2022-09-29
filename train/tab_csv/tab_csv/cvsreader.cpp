#include "cvsreader.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>

void Cvsreader::read_tab(const std::string& path)  // принимает путь к файлу
{
    std::ifstream file(path);

    std::string symbol;                  // для подсчета букв в имени колонки
    std::string word;                    //целое имя колонки
    std::vector<std::string> new_word;  // здесь хранятся все имена колонок + vector of names - по количеству колонок определяется смещение
    std::vector<std::string> all_tab;   // здесь хранятся значения из таблицы и имена(номера) строк вместе

    file >> word; // сюда считывается только одна первая строка целиком (имена колонок: ,A,B,Cell)
    std::string::iterator iter = word.begin();
    for(; iter != word.end(); ++iter)
    {
        if(*iter != ',')
        {
            symbol += *iter;
        }
        if (*iter == ',')
        {
            new_word.emplace_back(symbol); // записываем в вектор по отдельному имени колонки
            symbol.clear();
        }
        if(iter == word.end() -1)
        {
            new_word.emplace_back(symbol); // записывает последнее имя в колонке
            symbol.clear();
        }
    }

    while(!file.eof())
    {
        file >> word; // теперь сюда считывается все подряд пока не дойдет до конца файла
        std::string::iterator itr = word.begin();
        for(; itr != word.end(); ++itr)
        {
            if(*itr != ',')
            {
                symbol += *itr;
            }
            if (*itr == ',')
            {
                all_tab.emplace_back(symbol); // записывает в вектор каждое полученное значение
                symbol.clear();
            }
            if(itr == word.end() -1)
            {
                all_tab.emplace_back(symbol); // записывает каждое последнее значение в строке
                symbol.clear();
            }
        }
    }
    file.close();

    // фиксим таблицу
    while(search(all_tab) == true) // search проверяет есть ли еще значения в таблице типа =A1+B1
    {
        fix_tab(new_word, all_tab);
    }

    // выводим верную таблицу
    for(int i = 1; i < new_word.size(); ++i)
    {
        std::cout<<","<<new_word[i];
        names_colomn.push_back(",");  // записала в объект names_colomn значения...зачем? возможно, чтобы дальше можно было пользоваться, хотя по сути это не нужно
        names_colomn.push_back(new_word[i]);
    }
    std::cout <<std::endl;

    for(int j = 1; j <= all_tab.size(); ++j)
    {
        std::cout << all_tab[j-1];
        names_colomn.push_back(all_tab[j-1]);
        if(j != all_tab.size() && (j % new_word.size()  != 0))
        {
            std::cout<<",";
            names_colomn.push_back(",");
        }
        if(j % new_word.size()  == 0)
        {
            std::cout<<std::endl;
        }
    }
}

void Cvsreader::fix_tab(std::vector<std::string> new_word,  std::vector<std::string>& all_tab)
{
    // graph_for_fix ищет колонку со значением "=" внутри, если такой нет возращаемое значение равно all_tab.end()
    auto graph_for_fix =  std::find_if(all_tab.begin(), all_tab.end(),
                                       [](const std::string& value)
                                       {
                                           return value[0] == '=';
                                       }
                                       );
//    std::cout<< *graph_for_fix << std::endl;

    if(graph_for_fix != all_tab.end())
    {
        std::string formating = *graph_for_fix;        // сюда записана строка типа =A1+B1

        std::string arg1; // сюда запишем название первой колонки указывающей откуда брать значение
        std::string num_arg1; // сюда запишем номер колонки указывающей откуда брать первое значение
        std::string arg2;// сюда запишем название второй колонки указывающей откуда брать значение
        std::string num_arg2;// сюда запишем номер колонки указывающей откуда брать второе значение
        char op = 0; // сюда запишем операцию, производимую над колонками

        std::string::iterator itr1 = formating.begin()+1;
        std::string::iterator itr2; // здесь пока пусто, но потом сиюда запишется указатель на второе значение из колонки

        // в первом цикле считываем первую колонку, номер первой колонки и операцию
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
                itr2 = itr1; // итератор2 теперь указывает на значение после операции
                break;
            }
        }
        // второй цикл запишет второе значение и номер колонки
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
        if(iter1 == new_word.end()) // если таблица битая, то find не найдет такого имени колонки и вернет указатель на end() и тогда все ляжет
        {
            std::cout << "no colomn1 in tab!!"<< std::endl;
            throw std::exception{};
        }
        auto iter2 = find(new_word.begin(), new_word.end(), arg2);
        if(iter2 == new_word.end()) // если таблица битая, то find не найдет такого имени колонки и вернет указатель на end() и тогда все ляжет
        {
            std::cout << "no colomn2 in tab!!"<< std::endl;
            throw std::exception{};
        }

        std::string first; // сюда считается первое значение из таблицы в виде строки
        std::string second; // сюда считается второе значение из таблицы в виде строки

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

        int first_int = std::stoi(first); // переделываем значения в int
        int sedcond_int = std::stoi(second);
        int result = 0; // сюда запишем результат операции

        switch(op) // здесь считается операция
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
            default: // если не было считано нужной операции все упадет
            {
                std::cout << "no operation for do!!"<< std::endl;
                throw std::exception{};
            }
        }

        // исправляем значение в таблице all_tab

        std::string result_for_vector = std::to_string(result);

        for(int i = 0; i < all_tab.size(); ++i)
        {
            if(all_tab[i] == formating)
            {
                all_tab[i] = result_for_vector;
            }
        }
    }
}

bool Cvsreader::search(std::vector<std::string>& all_tab) // ищем есть ли в таблице выражение с '='
{
    auto graph_for_fix =  std::find_if(all_tab.begin(), all_tab.end(),
                                       [](const std::string& value)
                                       {
                                           return value[0] == '=';
                                       }
                                       );
    if(graph_for_fix == all_tab.end())
        return false;
    else return true;
}
