#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int d[15],c[15],ss[15],h[15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","r",stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if (s[0] == 'D'){
            if (s[1] != 'A' && s[1]!= 'T' && s[1] != 'J' && s[1] != 'Q'  && s[i] != 'K'){
                int c = s[1] - '0';
                d[c]++;
            }
            else if (s[1] == 'A') d[1]++;
            else if (s[1] == 'T') d[10]++;
            else if (s[1] == 'J') d[11]++;
            else if (s[1] == 'Q') d[12]++;
            else if (s[1] == 'K') d[13]++;
        }
        else if (s[0] == 'C'){
            if (s[1] != 'A' && s[1]!= 'T' && s[1] != 'J' && s[1] != 'Q'  && s[i] != 'K'){
                int x = s[1] - '0';
                c[x]++;
            }
            else if (s[1] == 'A') c[1]++;
            else if (s[1] == 'T') c[10]++;
            else if (s[1] == 'J') c[11]++;
            else if (s[1] == 'Q') c[12]++;
            else if (s[1] == 'K') c[13]++;
        }
        else if (s[0] == 'S'){
            if (s[1] != 'A' && s[1]!= 'T' && s[1] != 'J' && s[1] != 'Q'  && s[i] != 'K'){
                int c = s[1] - '0';
                ss[c]++;
            }
            else if (s[1] == 'A') ss[1]++;
            else if (s[1] == 'T') ss[10]++;
            else if (s[1] == 'J') ss[11]++;
            else if (s[1] == 'Q') ss[12]++;
            else if (s[1] == 'K') ss[13]++;
        }
        else {
            if (s[1] != 'A' && s[1]!= 'T' && s[1] != 'J' && s[1] != 'Q'  && s[i] != 'K'){
                int c = s[1] - '0';
                h[c]++;
            }
            else if (s[1] == 'A') h[1]++;
            else if (s[1] == 'T') h[10]++;
            else if (s[1] == 'J') h[11]++;
            else if (s[1] == 'Q') h[12]++;
            else if (s[1] == 'K') h[13]++;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 13; i++)
    {
        if (h[i] == 0) cnt++;
        if (ss[i] == 0) cnt++;
        if (c[i] == 0) cnt++;
        if (d[i] == 0) cnt++;
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
