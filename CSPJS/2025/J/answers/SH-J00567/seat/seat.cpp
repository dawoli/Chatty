#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class SeatFinder
{
public:
    SeatFinder(int rows);
    pair<int, int> operator() (int rate);
private:
    int rows; 
};

SeatFinder::SeatFinder(int rows) : rows(rows) {}

pair<int, int> SeatFinder::operator() (int rate)
{
    int x = (rate - 1) % rows + 1,
        y = (rate - 1) / rows + 1;
    return make_pair(y, y & 1 ? x : rows + 1 - x);
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;

    cin >> n >> m;

    vector<int> a(n * m + 1);
    SeatFinder f(n);

    for (int i = 1; i <= n * m; ++i)
    {
        cin >> a[i];
    }

    int rScore = a[1];

    sort(a.begin() + 1, a.end(), greater<int>());

    auto result = f(find(a.begin() + 1, a.end(), rScore) - a.begin());

    cout << result.first << ' ' << result.second << endl;

    return 0;
}
