#include "cvsreader.h"

#include <iostream>

int main(int argc, char* argv[])
{
    constexpr int parametrs = 2;

    if(argc != parametrs)
    {
        return -1;
    }

    std::string cvs_filename = argv[1];

    Cvsreader reader;
    reader.read_tab(cvs_filename);

    return 0;
}
//"D:/01_Projects/HomeWork/LEARN/LEARN/train/tab_csv/tab_csv/tab2.csv"
