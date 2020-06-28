
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
// #include <unordered_map>
using namespace std;
int main(int argc, char const *argv[])
{
    map<int, string> chains;

    //1. insert
    chains.insert(pair<int, string>(0, "lanyushi"));
    chains.insert(map<int, string>::value_type(1, "yushi lan"));
    //unavailable when key exists
    chains[2] = "nirvanalan";
    chains[10] = "lawulawu";

    auto rst = chains.insert(pair<int, string>(3, "another one"));
    cout << rst.second << "\n"; // true if insert successfully

    //2. find
    auto find_iterator = chains.find(3);
    if (find_iterator != chains.end())
        cout << find_iterator->second << "\n";
    //3. delete
    // cout << chains.erase(1);
    auto erase_rst = chains.erase(chains.find(2)); //iterator pointed to the next key
    cout << erase_rst->second << "\n";
    // cout << chains.erase(chains.find(0)) << "\n";
    // bound
    auto lb = chains.lower_bound(5); // >= 5
    auto ub = chains.upper_bound(3); // > 3
    cout << ub->second;
    return 0;
}
