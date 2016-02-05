#include <iostream>
#include "utility.hpp"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    vector<boost::filesystem::path> roots;
    roots.push_back("C:\amd");
    auto r=dps::MapFilesBySize(roots);
    return 0;
}
