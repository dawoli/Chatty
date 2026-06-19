#include <bits/stdc++.h>
using namespace std;

int n;
string s;
set<string> set1;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    scanf("%d",&n);
    for(int i = 1; i <= n;i++){
        cin >> s;
        set1.insert(s);
    }

    int ans = 52-set1.size();
    cout << ans << endl;

    //cout << "Hello world!" << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
