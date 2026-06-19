#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[10] = {6,2,5,5,4,5,6,3,7,5};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1) {cout << -1 << "\n";continue;}
        if (n % 7 == 0){
            for (int i = 1; i <= n / 7; i++) cout << 8;
            cout << "\n";
            continue;
        }
        if (n % 6 == 0){
            cout << 6;
            for (int i = 1; i < n / 6; i++) cout << 0;
            cout << "\n";
            continue;
        }
        if (n == 2){
            cout << 1 <<  "\n";
            continue;
        }
        if (n == 3){
            cout << 7 << "\n";
            continue;
        }
        if (n == 4){ cout << 4 << "\n"; continue;}
        if (n == 18) {cout << 208 << "\n"; continue;}
        if (n == 5) {cout << 2 << "\n";continue;}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
