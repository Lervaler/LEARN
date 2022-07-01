#ifndef SUMM_PROIZ_H
#define SUMM_PROIZ_H

#include <iostream>
#include <string>

class Summ_Proizvodn
{
public:
    Summ_Proizvodn (int&& all_host_number, int&& host_num_for_one);
    std::string sum_tab_clean(const std::string &path);
    void gen_tab_summ_proizvodn(const std::string &path, const Summ_Proizvodn& other);
private:
    int _all_host_number;
    int _host_num_for_one;
};

#endif // SUMM_PROIZ_H
