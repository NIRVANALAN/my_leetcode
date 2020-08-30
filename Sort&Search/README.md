## Lambda function
- 56 Merge Intervals

Using Lambda function in ```sort``` is faster compared to static user-defined function.
```
sort(intervals.begin(), intervals.end(), [](const vector<int> &o1, const vector<int> &o2) { return (o1[0] < o2[0]); });
```
Static function by default 
```
    static bool compIntervals(vector<int> a, vector<int> b)
    {
        return a[0] < b[0]; //slow, default comparator
    }
```