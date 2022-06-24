#include <iostream>
//#include "my_string.h"
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <iterator>
#include <stdio.h>

using namespace std;

int main()
{
 struct Tab
{
 int data = 0;
 std::string host = "";
 int time = 1655901262;
 int count = 0;
 };
 Tab tab;

 std::vector <Tab> a (10);

ofstream file_1;
file_1.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/one.txt");
file_1 <<endl <<"  ______________________________________________________"<<endl;
file_1 <<" | " << std::setw( 11 )<<"host_name "<<" | "<< std::setw( 11 )<<"time "<<" | "<< std::setw( 11 )<<"bites "<<" | "<<std::setw( 10 )<<"operation "<<" | ";
file_1 <<endl <<" |"<<"_____________|_____________|_____________|____________"<<"|"<<endl;
std::vector <vector <Tab>> my_tab (10);

for (int i = 1; i <10; ++i)
{
    for (int j = 1; j < 10; ++j)
   {
        a.at(j).host = "host_" + to_string(i);
        file_1 <<" | " <<std::setw( 11 )<<a.at(j).host<<" | " ;

        a.at(j).time += 300*j +(rand() % 11 - 5);
        file_1 <<std::setw( 11 )<<a.at(j).time<<" | " ;

        a.at(j).data = a.at(j -1).data + 12 + (rand() % 100);
        file_1 <<std::setw( 11 )<<a.at(j).data<<" | " ;

        a.at(j).count = a.at(j - 1).count +(1+rand() % 5);
        file_1 <<std::setw( 10 )<<a.at(j).count <<" | ";

        file_1 <<endl <<" |"<<"_____________|_____________|_____________|____________"<<"|";

        my_tab[i] = a;
        file_1 << endl;
    }
}

file_1.close();


std::string str;
std::string path;
path = "D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/one.txt";

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
         str += word +" ";
     }
 }
//cout << str;

    ofstream file_4;
    file_4.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/two.txt");
     file_4 << str;
     file_4.close();

struct Tab_1
{
int data = 0;
string host {};
int time = 0;
int count = 0;
};

ifstream myfile("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/two.txt");
  if (!myfile)
  {
      cout << "error - no file\n";
  }

  Tab_1 info[1000];
  int size = 0;
  int i;
   for (i = 0; myfile; ++i)
   {
       (myfile >> info[i].host).get();
       (myfile >> info[i].time).get();
       (myfile >> info[i].data).get();
       (myfile >> info[i].count).get();
   }
   myfile.close();
   size = i;
//  for (int i = 0; i < size; i++)
//      cout << info[i].host << "\t" << info[i].data  << "\t" << info[i].time << "\t" << info[i].count << endl;

long double q = 0;
long double w = 0;
long double e = 0;
int k = 0;

ofstream file_5;
file_5.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/proizvod.txt");

cout << "choose host number: " << endl;
int host_num = 0;
cin >>host_num;

for (int j = 0; j <10; ++j)
{
if (info[j].host ==( "host_" + to_string(host_num)))
{
    cout <<info[j].data <<endl;
    cout <<info[j].time <<endl;
    q = (info[j+1].data)  -  (info[j].data);
    w= info[j+1].time - info[j].time;
    e = q /w;
    ++k;
    cout << e<< endl;
     file_5 << k << " " << e << endl;
}
}
 file_5.close();

    return 0;
}
