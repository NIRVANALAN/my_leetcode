#include <iostream>
#include <vector>
#include <algorithm>

/*
comp
Binary function that accepts two elements in the range as arguments, and returns a value convertible to bool. The value returned indicates whether the element passed as first argument is considered to go before the second in the specific strict weak ordering it defines.
The function shall not modify any of its arguments.
This can either be a function pointer or a function object.
*/

bool comp(int i, int j)
{
    return i < j;
}
struct comp_object
{
    bool operator()(int i, int j) { return i < j; }
} my_comp_object;

bool comp_vector(const std::vector<int> a, const std::vector<int> b)
{
    return a[1] < b[1];
}

void sort_test()
{

    int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
    std::vector<int> a = {1, 5};
    std::vector<int> b = {2, 4};
    std::vector<std::vector<int>> myvector = {a, b};

    // std::sort(myvector.begin(), myvector.end(), comp);
    std::sort(myvector.begin(), myvector.end(), comp_vector);
    for (size_t i = 0; i < myvector.size(); i++)
    {
        std::cout << myvector[i][0] << " ";
    }
    std::cout << std::endl;
}

void comp_array()
{

    int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
    std::vector<int> myvector(myints, myints + sizeof(myints) / sizeof(int));

    // std::sort(myvector.begin(), myvector.end(), comp);
    // std::sort(myvector.begin(), myvector.end(), my_comp_object);
    std::sort(myvector.begin(), myvector.end(), [](int l, int r) {
        return l < r;
    });
    for (size_t i = 0; i < myvector.size(); i++)
    {
        std::cout << myvector[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    comp_array();
    return 0;
}
