#include<bits/stdc++.h>
#define a first
#define b second
#define num second
using namespace std;
namespace Soaring_Wings
{
    int n;
    double x, w[5], ans[5] = {0}, cnt = 0.000000;
    set<pair<pair<double, int>, int>> s;
    void Soar()
    {
        cin >> n;
        for (int i = 1; i <= 4; i++)
        {
            cin >> x;
            w[i] = x;
            s.insert(make_pair(make_pair(x, 0), i));
        }
        if (w[1] == w[2] && w[2] == w[3] && w[3] == w[4])
        {
            cout << fixed << setprecision(6) << 2 * n;
            return;
        }
        while (s.size() != 1)
        {
            auto i = s.begin(), j = next(s.begin());
            cout<<i->a.a<<' '<<i->a.b<<' '<<j->a.a<<' '<<j->a.b<<' '<<endl;
            ans[i->num] = i->a.b + j->a.b;
            ans[j->num] = j->a.b + i->a.b;
            double o = i->a.a + j->a.a;
            int p = i->a.b + j->a.b;
            s.erase(i);
            s.erase(s.begin());
            s.insert(make_pair(make_pair(o, p + 1.0), 0));
        }
        if (count(ans + 1, ans + 5, 0) == 2)
        {
            for (int i = 1; i <= 4; i++)
            {
                if (ans[i] == 0) cnt += 3 * w[i];
                else if (ans[i] == 2) cnt += 2 * w[i];
                else cnt += 1 * w[i];
                cout<<cnt<<' ';
            }
            cnt *= n;
        }
        else
        {
            cnt = 2 * n;
        }
        cout << fixed << setprecision(6) << cnt;
        return;
    }
}
int main()
{
    Soaring_Wings::Soar();
    return EXIT_SUCCESS;
}