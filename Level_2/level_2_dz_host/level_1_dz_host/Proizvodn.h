#ifndef PROIZVODN_H
#define PROIZVODN_H
#include <iostream>
#include <string>

class Proizvodn
{
public:
    Proizvodn (int&& host_number);
    void gen_tab_proizvodn(const std::string &path);
private:
    int _host_number;
};


#endif // PROIZVODN_H
