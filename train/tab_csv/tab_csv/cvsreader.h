#ifndef CVSREADER_H
#define CVSREADER_H

#include <vector>
#include <string>


class Cvsreader
{
private:
    std::vector <std::vector<std::string>> names_colomn;
    std::vector<int> number_str;
public:

    void read_tab(const std::string& path);

};


#endif // CVSREADER_H
