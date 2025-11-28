#include "Replacer.hpp"

Replacer::Replacer(const std::string& filename, const std::string& s1, const std::string &s2)
    : filename(filename), s1(s1), s2(s2) {}

Replacer::~Replacer() {}

void Replacer::replace()
{
    if (s1.empty())
    {
        std::cerr << "s1 is empty" << std::endl;
        return;
    }

    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "cant open " << filename << std::endl;
        return ;
    }

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cerr << "cant create " << filename << ".replace" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        std::size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outfile << line << std::endl;
    }

    infile.close();
    outfile.close();
}