#include "tab_generator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>


Tab_Generator::Tab_Generator(int&& host_numbers, int&& host_num_for_one)
    : _host_numbers(host_numbers)
    , _host_num_for_one(host_num_for_one)
{
    if (host_numbers == 0 || host_numbers < 0 )
    {
        return;
    }
}

void Tab_Generator::Gen_file(const std::string &path)
{
    if (_host_numbers >0)
    {
        struct Tab
        {
            int data = 0;
            std::string host = "";
            int time = 1640984400;
            int count = 0;
        };

        Tab tab;

        std::vector <Tab> a (_host_num_for_one*_host_numbers);

        std::ofstream file_1;
        file_1.open(path);
        file_1 <<std::endl <<"  ______________________________________________________"<<std::endl;
        file_1 <<" | " << std::setw( 11 )<<"host_name "<<" | "<< std::setw( 11 )<<"time "<<" | "<< std::setw( 11 )<<"bites "<<" | "<<std::setw( 10 )<<"operation "<<" | ";
        file_1 <<std::endl <<" |"<<"_____________|_____________|_____________|____________"<<"|"<<std::endl;

        std::vector <std::vector <Tab>> my_tab (_host_num_for_one*_host_numbers);

        for (int i = 1; i <=_host_numbers; ++i)
        {
            for (int j = 1; j <= _host_num_for_one; ++j)
            {
                a.at(j).host = "host_" + std::to_string(i);
                file_1 <<" | " <<std::setw( 11 )<<a.at(j).host<<" | " ;

                a.at(j).time = a.at(j - 1).time + 100*j +(rand() % 11 - 5);
                file_1 <<std::setw( 11 )<<a.at(j).time<<" | " ;

                a.at(j).data = a.at(j - 1).data +12 +12*j+ (rand() % 11 - 5);
                file_1 <<std::setw( 11 )<<a.at(j).data<<" | " ;

                a.at(j).count = a.at(j - 1).count +(1+rand() % 5);
                file_1 <<std::setw( 10 )<<a.at(j).count <<" | ";

                file_1 <<std::endl <<" |"<<"_____________|_____________|_____________|____________"<<"|";

                my_tab[i] = a;
                file_1 << std::endl;
            }
        }
    std::cout<< "tab ready\n";
    }
    else std::cout<< "error";
};

std::string Tab_Generator::tab_cleaner(const std::string &path)
{
    if (_host_numbers >0)
    {
        std::vector<std::string> new_word;
        std::ifstream file(path);
        std::string word;

        while(!file.eof())
        {
            file >> word;
            if (word != " " && word != "|" && word != "_"&&
                word != "|_____________|_____________|_____________|____________|" &&
                word != "______________________________________________________" &&
                word != "operation" &&
                word != "host_name" &&
                word != "time" &&
                word != "bites")
            {
                new_word.push_back(word);
                new_word.push_back(" ");
            }
        }

            std::ofstream file_4;
            file_4.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/two.txt");
            std::copy(new_word.begin(), new_word.end(), std::ostream_iterator<std::string>(file_4));
            file_4.close();
            std::cout<<"table cleared "<< std::endl;
            std::string new_path = "D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/two.txt";
            return new_path;
    }
    else return 0;
}
