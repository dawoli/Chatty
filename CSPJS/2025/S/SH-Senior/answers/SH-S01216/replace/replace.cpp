#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll M = 2e5+9;
ll n, q;
string str1[M], str2[M];
string que1[M], que2[M];
ll nxt1[M], nxt2[M];
//ll Nxt1[M], Nxt2[M];
ll ans[M];
ll diff_str[M], diff_que[M];
pll a[M];
ll cpy[M];
//char lst_diff_str[M], lst_diff_que[M]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	memset(ans, 0, sizeof(ans));
//	string s;
//	cin >> s;
//	s = " "+s;
//	for(ll i = 2, j = 0;i<s.size();i++){
//		while(j>0 && s[i]!=s[j+1]) j = nxt1[j];
//		if(s[i]==s[j+1]) j++;
//		nxt1[i] = j;
//	}
//	for(ll i = 1;i<s.size();i++){
//		cout << nxt1[i] << " ";
//	}
//	cout<<"\n";
	for(ll i = 1;i<=n;i++){
		cin >> str1[i] >> str2[i];
		str1[i] = " " + str1[i];
		str2[i] = " " + str2[i];
		for(ll j = 1;j<str1[i].size();j++){
			if(str1[i][j]!=str2[i][j]){
				diff_str[i]	++;
			}
		}
	} 
	for(ll i = 1;i<=q;i++){
		cin >> que1[i] >> que2[i];
		que1[i] = " " + que1[i];
		que2[i] = " " + que2[i];
		if(que1[i].size()!=que2[i].size()) continue;
		for(ll j = 1;j<que1[i].size();j++){
			if(que1[i][j]!=que2[i][j]){
				diff_que[i]	++;
			}
		}
		a[i] = {diff_que[i], i};
	}
//	cout<<"diff_que:\n";
//	for(ll i = 1;i<=q;i++){
//		cout<<diff_que[i]<<" ";
//	}
//	cout<<"\n";
	sort(a+1, a+1+q);
	for(ll i = 1;i<=q;i++){
		cpy[i] = a[i].first;
	}
	for(ll I = 1;I<=n;I++){
		//cout<<"I = "<<I<<"\n";
		for(ll i = 2, j = 0;i<str1[I].size();i++){
			while(j>0 && str1[I][i]!=str1[I][j+1]) j = nxt1[j];
			if(str1[I][i]==str1[I][j+1]) j++;
			nxt1[i] = j;
		}
		for(ll i = 2, j = 0;i<str2[I].size();i++){
			while(j>0 && str2[I][i]!=str2[I][j+1]) j = nxt2[j];
			if(str2[I][i]==str2[I][j+1]) j++;
			nxt2[i] = j;
		}
		ll l = lower_bound(cpy+1, cpy+1+q, diff_str[I]) - cpy;
		ll r = upper_bound(cpy+1, cpy+1+q, diff_str[I]) - cpy;
		for(ll K = l;K<r;K++){
			ll k = a[K].second;
			//cout<<"  k = "<<k<<"\n";
			if(que1[k].size()!=que2[k].size()){
				//cout<<"continue, A\n";
				continue;
			}
			if(que1[k].size()<str1[I].size()){
				//cout<<"continue, B\n";
				continue;
			} 
			if(diff_que[k] != diff_str[I]){
				continue;
			}
			for(ll i = 1, j1 = 0, j2 = 0;i<que1[k].size();i++){
				while(j1>0 && que1[k][i]!=str1[I][j1+1]) j1 = nxt1[j1];
				if(que1[k][i]==str1[I][j1+1]) j1++;
				while(j2>0 && que2[k][i]!=str2[I][j2+1]) j2 = nxt2[j2];
				if(que2[k][i]==str2[I][j2+1]) j2++;
				//cout<<"    i = "<<i<<", j1 = "<<j1<<", j2 = "<<j2<<"\n";
				if(j1 == j2 && j1 == str1[I].size() - 1 && diff_str[I] == diff_que[k]){
					//cout<<"    i = "<<i<<", ans[k]++\n";
					ans[k]++;
					break;
				} 
			}
		}
		//cout<<"\n";
	}
	for(ll i = 1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
} 

/*
6 3
ab cd
bab ccd
al ti
ab bc
cab ccd
dcab dccd

edcab edccd
abcab bcccd
efcab efccd

*/ 
