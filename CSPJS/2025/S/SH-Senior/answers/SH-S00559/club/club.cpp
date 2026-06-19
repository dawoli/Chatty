#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    int id, a, b, c;
};

class Solution
{
public:
    Solution();
    void solve(istream &in, ostream &out);
private:
    vector<Student> a, b, c;
    int n;
};

Solution::Solution()
{
    a.push_back({0, 0, 0});
}

bool compareUsingA(Student x, Student y)
{
    return x.a > y.a;
}

bool compareUsingB(Student x, Student y)
{
    return x.b > y.b;
}

bool compareUsingC(Student x, Student y)
{
    return x.c > y.c;
}

void Solution::solve(istream &in, ostream &out)
{
    in >> n;

    for (int i = 1; i <= n; ++i)
    {
        Student s;
        s.id = i;
        in >> s.a >> s.b >> s.c;
        a.push_back(s);
    }

    b = c = a;

    sort(a.begin() + 1, a.end(), compareUsingA);
    sort(b.begin() + 1, b.end(), compareUsingB);
    sort(c.begin() + 1, c.end(), compareUsingC);

    int sum = 0;

    // 1

    vector<bool> used1(n + 1);
    int sum1 = 0;

    for (int i = 1; i <= (n >> 1); ++i)
    {
        sum1 += a[i].a;
        used1[a[i].id] = true;
    }

    for (int i = 1, selected = 0; i <= n && selected <= (n >> 1); ++i)
    {
        if (!used1[b[i].id])
        {
            sum1 += b[i].b;
            used1[b[i].id] = true;
            ++selected;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!used1[c[i].id])
        {
            sum1 += c[i].c;
        }
    }

    sum = sum1;

    // 2

    vector<bool> used2(n + 1);
    int sum2 = 0;

    for (int i = 1; i <= (n >> 1); ++i)
    {
        sum2 += a[i].a;
        used2[a[i].id] = true;
    }

    for (int i = 1, selected = 0; i <= n && selected <= (n >> 1); ++i)
    {
        if (!used2[c[i].id])
        {
            sum2 += c[i].c;
            used2[c[i].id] = true;
            ++selected;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!used2[b[i].id])
        {
            sum2 += b[i].b;
        }
    }

    sum = max(sum, sum2);

    // 3

    vector<bool> used3(n + 1);
    int sum3 = 0;

    for (int i = 1; i <= (n >> 1); ++i)
    {
        sum3 += b[i].b;
        used3[b[i].id] = true;
    }

    for (int i = 1, selected = 0; i <= n && selected <= (n >> 1); ++i)
    {
        if (!used3[a[i].id])
        {
            sum3 += a[i].a;
            used3[a[i].id] = true;
            ++selected;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!used3[c[i].id])
        {
            sum3 += c[i].c;
        }
    }

    sum = max(sum, sum3);

    // 4

    vector<bool> used4(n + 1);
    int sum4 = 0;

    for (int i = 1; i <= (n >> 1); ++i)
    {
        sum4 += b[i].b;
        used4[b[i].id] = true;
    }

    for (int i = 1, selected = 0; i <= n && selected <= (n >> 1); ++i)
    {
        if (!used4[c[i].id])
        {
            sum4 += c[i].c;
            used4[c[i].id] = true;
            ++selected;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!used4[a[i].id])
        {
            sum4 += a[i].a;
        }
    }

    sum = max(sum, sum4);

    // 5

    vector<bool> used5(n + 1);
    int sum5 = 0;

    for (int i = 1; i <= (n >> 1); ++i)
    {
        sum5 += c[i].c;
        used5[c[i].id] = true;
    }

    for (int i = 1, selected = 0; i <= n && selected <= (n >> 1); ++i)
    {
        if (!used5[a[i].id])
        {
            sum5 += a[i].a;
            used5[a[i].id] = true;
            ++selected;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!used5[b[i].id])
        {
            sum5 += b[i].b;
        }
    }

    sum = max(sum, sum5);

    // 6

    vector<bool> used6(n + 1);
    int sum6 = 0;

    for (int i = 1; i <= (n >> 1); ++i)
    {
        sum6 += c[i].c;
        used6[c[i].id] = true;
    }

    for (int i = 1, selected = 0; i <= n && selected <= (n >> 1); ++i)
    {
        if (!used6[b[i].id])
        {
            sum6 += b[i].b;
            used6[b[i].id] = true;
            ++selected;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!used6[a[i].id])
        {
            sum6 += a[i].a;
        }
    }

    sum = max(sum, sum6);

    out << sum << endl;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        Solution s;
        s.solve(cin, cout);
    }

    return 0;
}
