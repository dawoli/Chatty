#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[1000010],ai = 1;
bool cmp(ll x,ll y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if('0' <= s[i] && s[i] <= '9')
			a[ai++] = s[i] - '0';
	}
	sort(a + 1,a + ai,cmp);
	for(int i = 1;i < ai;i++){
		cout << a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
