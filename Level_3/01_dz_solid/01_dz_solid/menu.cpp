#include <iostream>
#include <conio.h>

#include "menu.h"


void Menu::print_menu()
{
    int x = 1;
    char one = '*';
    char two = ' ';
    char tree = ' ';
    char four = ' ';
    char five = ' ';

    while(true)
    {
        std::cout<<one<<" 1.Get order"<<std::endl;
        std::cout<<two<<" 2.Get check"<<std::endl;
        std::cout<<tree<<" 3.Take chips"<<std::endl;
        std::cout<<four<<" 4.Get out"<<std::endl;
        std::cout<<five<<" 5. ???"<<std::endl;

        int move;
        std::cin>>move;
        switch (move)
        {
        case 1:
            if(x == 5)
            {
                x = 4;
                four = '*';
                five = ' ';
            }
            else if(x == 4)
            {
                x = 3;
                four = ' ';
                tree = '*';
            }
            else if(x == 3)
            {
                x = 2;
                tree = ' ';
                two = '*';
            }
            else if(x == 2)
            {
                x = 1;
                two = ' ';
                one = '*';
            }
            else if(x == 1)
                break;
        break;
        case 2:
            if(x == 1)
            {
                x = 2;
                one = ' ';
                two = '*';
            }
            else if(x == 2)
            {
                x = 3;
                two = ' ';
                tree = '*';
            }
            else if(x == 3)
            {
                x = 4;
                tree = ' ';
                four = '*';
            }
            else if(x == 4)
            {
                x = 5;
                four = ' ';
                five = '*';
            }
            else if(x == 5)
                break;
        break;
        }
        system("cls");
    }
}
