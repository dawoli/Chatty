#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[1000005];
bool cmp(ll x,ll y){
	return x > y;
}
int main(){
	//freopen("number","in",stdin);
	//freopen("number","out",stdout);
	cin >> s; 
	ll j = 0;
	for(int i = 0;i < s.size();i++){
		if(isdigit(s[i])){
  		    a[j] = s[i] - '0';
			j++;
		}
	}
	sort(a,a + j,cmp);
	for(int i = 0;i < j;i++){
		cout << a[i];
	}
	
	return 0;
}
