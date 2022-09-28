#ifndef CVSREADER_H
#define CVSREADER_H

#include <vector>
#include <string>

class Cvsreader
{
private:
    std::vector<std::string> names_colomn;

public:
    void read_tab(const std::string& path);
    void fix_tab(std::vector<std::string> new_word, std::vector<std::string>& all_tab);
    bool search(std::vector<std::string>& all_tab);
};

#endif // CVSREADER_H
