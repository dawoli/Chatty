#include <bits/stdc++.h>
using namespace std;

int n;
string x;
bool ishave[256][256];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        ishave[x[0]][x[1]] = 1;
    }

    int ans = 0;
    char flower[] = {'D', 'C', 'H', 'S'};
    char point[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    for (char f : flower)
    {
        for (char p : point)
        {
            if (!ishave[f][p]) ans++;
        }
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
