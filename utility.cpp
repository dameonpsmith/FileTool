#include "utility.hpp"

using namespace std;
using namespace boost::filesystem;

std::vector<char> ReadAllBytes(const char* root)
{
    std::ifstream s(root);
    vector<char> result;
    copy(istream_iterator<char>(s),istream_iterator<char>(),result.begin());
    return result;
}
map<uintmax_t,vector<path>>dps::MapFilesBySize(vector<path> roots)
{
    map<uintmax_t,vector<path>> results;
    stack<directory_iterator> estack;
    error_code ec;
    for(auto const root:roots)
    {
        try
        {
            estack.push(directory_iterator(root));
        }
        catch(...)
        {
            continue;
        }
        while(!estack.empty())
        {
            while(estack.top()!=directory_iterator())
            {
                auto info=estack.top()->status();
                try
                {
                    if(info.type()==file_type::directory_file)
                    {
                        estack.push(directory_iterator(estack.top()->path()));
                    }
                    else
                    {
                        results[file_size(estack.top()->path())].push_back(estack.top()->path());
                        estack.top()++;
                    }
                }
                catch(exception e)
                {
                    if (!estack.empty())estack.top()++;
                    continue;
                }
            }
            estack.pop();
            if(!estack.empty())estack.top()++;
        }
    }
    return results;
}
