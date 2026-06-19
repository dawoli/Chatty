#include <bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++){
	    int b = s[i];
        if (b >= 48 && b <= 57){
            a[b - 48]++;
        }
	}
	for (int i = 9; i >= 0; i--){
		if (a[i] > 0){
			char c = i + 48;
			for (int j = 1; j <= a[i]; j++)
                cout << c;
		}
	}
	return 0;
}
