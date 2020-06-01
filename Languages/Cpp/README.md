## Right Value Reference
[Tutorial](https://www.jianshu.com/p/d19fc8447eaa)

# Basics
## Array
1. init an array first
```
bool dp[1000][1000] = {false}; //! fuck
```
2. 

# String, Vectors, Containers
```
s.substr(i,n);//return sub_string with n characters from i
```
## grammar
```
m==n==1 // will always return True if m==n
```
- check array border

# Advance
- [lambda expression](https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=vs-2019)
# Sort
```
bool comp_vector(const std::vector<int> a, const std::vector<int> b)
{
    return a[1] < b[1];
}
// use lambda expression 

std::sort(myvector.begin(), myvector.end(), [](int l, int r) {
    return l < r;
});
```

## left reference (c++11)  
### TODO