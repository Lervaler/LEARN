#ifndef SUMM_PROIZ_H
#define SUMM_PROIZ_H

#include <iostream>
#include <string>
#include <vector>
#include "func_1_info.h"
#include "func_2_pro_host.h"

struct Tab
{
    int data = 0;
    std::string host {};
    int time = 0;
    int count = 0;
};

class Summ_Proizvodn
{
public:
    Summ_Proizvodn (int&& all_host_number, int&& host_num_for_one);
    void gen_all_proizvodn(const std::string &path,
                                const Summ_Proizvodn& other,
                                const int time_start, const int time_end);
//    void gen_tab_summ_proizvodn(std::vector<double> pro_host_other, const Summ_Proizvodn& other);

private:
    int _all_host_number;
    int _host_num_for_one;
    std::vector<Tab> sum_tab_clean(const std::string &path, const Summ_Proizvodn& other);
};

#endif // SUMM_PROIZ_H
