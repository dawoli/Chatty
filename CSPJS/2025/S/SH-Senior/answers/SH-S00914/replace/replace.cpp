#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

string a[200010] , b[200010] , s , t;
int n , q , posa[200010] , posb[200010];

unsigned hs1[200010] , hs2[200010];

int tryrep(int x)
{
    int cnt = 0;
    for (int i = 0; i + a[x].size() <= s.size(); i++)
    {
        //printf("try:%d;str_to_rep=%s<->%s;\n" , i , s.substr(i , b[x].size()).begin() , a[x].begin());
        if (s.substr(i , a[x].size()) == a[x])
        {
            string ss = s.substr(0 , i) + b[x] + s.substr(i + b[x].size());
            //printf(" str_rep=%s;\n" , ss.begin());
            cnt += (ss == t);
        }
    }
    return cnt;
}

void solve1()
{
    while (q--)
    {
        cin >> s >> t;
        if (s.size() != t.size())
        {
            cout << "0\n";
            continue;
        }
        long long rep = 0;
        for (int i = 1; i <= n; i++)
        {
            rep += tryrep(i);
        }
        printf("%lld\n" , rep);
    }
}

map<int , int> mp;

void solve2()
{
    for (int i = 1; i <= n; i++)
    {
        posa[i] = a[i].find('b');
        posb[i] = b[i].find('b');
    }
    while (q--)
    {
        cin >> s >> t;
        if (s.size() != t.size())
        {
            cout << "0\n";
            continue;
        }
        int rep = 0 , poss = s.find('b');
        for (int i = 1; i <= n; i++)
        {
            rep += (poss >= posa[i] && a[i].size() - posa[i] <= s.size() - poss && t[poss - posa[i] + posb[i]] == 'b');
        }
        printf("%d\n" , rep);
    }
}

void solve3()
{
    for (int i = 1; i <= n; i++)
    {
        posa[i] = a[i].find('b');
        posb[i] = b[i].find('b');
        mp[posa[i] - posb[i]]++;
    }
    while (q--)
    {
        cin >> s >> t;
        if (s.size() != t.size())
        {
            cout << "0\n";
            continue;
        }
        printf("%d\n" , mp[s.find('b') - t.find('b')]);

    }
}

int main()
{
    freopen("replace.in" , "r" , stdin);
    freopen("replace.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    if (q == 1 || (n <= 100 && q <= 100))
    {
        solve1();
        return 0;
    }
    solve2();
    return 0;
}
