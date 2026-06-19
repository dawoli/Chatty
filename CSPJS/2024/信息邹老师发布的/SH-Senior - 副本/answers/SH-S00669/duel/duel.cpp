#include <bits/stdc++.h>
using namespace std;

int n;
multiset<int> r, attack;
int cnt = 0;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;
    int r1;
    for (int i = 1; i <= n; i++)
    {
        cin >> r1;
    	r.emplace(r1);
    	attack.emplace(r1);
	}
    while (!r.empty())
    {
        auto it = attack.lower_bound(*(r.begin()) + 1);
        if (*it == *(r.begin()) && ++it != attack.end())
        {
            cnt++;
        	attack.erase(++it);
        	attack.erase(*(r.begin()));
        	r.erase(r.begin());
		}
        else if (it == attack.end())
            break;
        else
        {
            cnt++;
        	attack.erase(it);
        	attack.erase(*(r.begin()));
        	r.erase(r.begin());
		}
    }
    
    cout << n - cnt;

    return 0;
}
