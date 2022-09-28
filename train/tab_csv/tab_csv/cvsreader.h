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
    void fix_tab(std::vector<std::string>& new_word,  std::vector<std::string>& all_tab);

};


#endif // CVSREADER_H
