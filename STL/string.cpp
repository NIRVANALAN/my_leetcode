#include <string>
#include <iostream>
using std::string;
int main(int argc, char const *argv[])
{
    // * string
    std::string s1 = "hiyahiya";
    std::string s2 = s1;
    std::string s3(10, 'c');
    printf("size of string is %d\n", s3.size());
    std::cout << "min(1,2)==" << std::min(1, 2) << '\n';
    std::cout << "min(2,1)==" << std::min(2, 1) << '\n';
    std::cout << "min('a','z')==" << std::min('a', 'z') << '\n';
    std::cout << "min(3.14,2.72)==" << std::min(3.14, 2.72) << '\n';
    return 0;
}
