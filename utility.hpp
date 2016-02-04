#ifndef UTILITY_HPP_INCLUDED
#define UTILITY_HPP_INCLUDED

#include <fstream>
#include <map>
#include <vector>
#include <iostream>
#include <boost\filesystem.hpp>

namespace dps
{
    std::map<uintmax_t,std::vector<boost::filesystem::path>>
        MapAllFiles(boost::filesystem::path);
}



#endif // UTILITY_HPP_INCLUDED
