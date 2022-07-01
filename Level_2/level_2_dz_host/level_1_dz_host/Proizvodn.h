#ifndef PROIZVODN_H
#define PROIZVODN_H
#include <iostream>
#include <string>

class Proizvodn
{
public:
    Proizvodn (int&& host_number);
    std::string tab_clean(const std::string &path);
    void gen_tab_proizvodn(const std::string &path, const Proizvodn& other);
private:
    int _host_number;
};


#endif // PROIZVODN_H
