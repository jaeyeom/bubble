
#ifndef _LINE_NO_HPP_
#define _LINE_NO_HPP_

#include <vector>
#include <fstream>

namespace Bubble
{
    std::vector<int> line_no;

    inline void read_line_no(const char* filename)
    {
        std::ifstream f;
        f.open(filename);
        if (!f) {
            std::cerr << "Error. Couldn't find *.line file." << std::endl;
            std::cerr << "There should be \"" << filename << "\"." << std::endl;
            exit(1);
        }
        line_no.clear();
        while(true) {
            int x;
            f >> x;
            if (f.fail()) break;
            line_no.push_back(x);
        }
        f.close();
    }

    inline int get_original_line_number(int l)
    {
        return line_no[l-1]+1;
    }
}

#endif
