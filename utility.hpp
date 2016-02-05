#ifndef UTILITY_HPP_INCLUDED
#define UTILITY_HPP_INCLUDED

#include <fstream>
#include <map>
#include <vector>
#include <iostream>
#include <boost\filesystem.hpp>
#include <algorithm>
#include <iterator>

namespace dps
{
std::vector<char> ReadAllBytes(const char*);
std::map<uintmax_t,std::vector<boost::filesystem::path>>
    MapFilesBySize(std::vector<boost::filesystem::path>);
}
/*
map<uintmax_t,vector<path>>MapFilesBySize(vector<path> roots);
    */

#endif // UTILITY_HPP_INCLUDED
