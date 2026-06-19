#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
string s;
long long a[MAXN];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	memset(a,10,sizeof(a));
	long long n = s.size();
	for(int i = 0;i <= n-1;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[i] = s[i]-'0';
		}
	}
	sort(a,a+n,cmp);
	for(int i = 0;i <= n-1;i++){
		if(a[i] <= 9) cout << a[i];
	}
	return 0;
}
