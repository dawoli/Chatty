#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","W",stdout);
	string s;
	cin >> s;
	int pos = 1;
	for (int i = 0;i<s.size();i++){
		    if (s[i] == '0'){
			   a[pos] = 0;
		    }
		    if (s[i] == '1'){
			   a[pos] = 1;
		    }
		    if (s[i] == '2'){
			a[pos] = 2;
		    }
		    if (s[i] == '3'){
			a[pos] = 3;
		    }
		    if (s[i] == '4'){
			a[pos] = 4;
		    }
		    if (s[i] == '5'){
			a[pos] = 5;
		    }
		    if (s[i] == '6'){
			a[pos] =6;
		    }
		    if (s[i] == '7'){
			a[pos] = 7;
		    }
		    if (s[i] == '8'){
			a[pos] = 8;
		    }
		    if (s[i] == '9'){
			a[pos] = 9;
		    }
		    if (s[i] > 47 && s[i] < 58) pos++;
	}
	int n = pos;
	sort(a+1,a+n+1);
	for (int i = n;i>=2;i--){
	    cout << a[i];
	}
	return 0;
}
