#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <iostream>
#include <string>
#include <fstream>

class Replacer
{
private:
    std::string filename;
    std::string s1;
    std::string s2;
public:
    Replacer(const std::string& filename, const std::string& s1, const std::string &s2);
    ~Replacer();

    void replace();
};

#endif