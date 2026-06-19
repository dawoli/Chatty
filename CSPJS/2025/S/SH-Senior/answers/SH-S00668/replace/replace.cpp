#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	string s,t[q][2];
	int difs[n];
	int sb[n][4];
	for(int i = 0;i < n;i++){
		cin>>s;
		int cnt = 0,nn = s.size();
		while(cnt < nn and s[cnt] == 'a') cnt++;
		sb[i][0] = cnt;
		sb[i][1] = nn - cnt - 1;
		cin>>s;
		cnt = 0;
		while(cnt < nn and s[cnt] == 'a') cnt++;
		sb[i][2] = cnt;
		sb[i][3] = nn - cnt - 1;
		difs[i] = sb[i][0] - sb[i][2];
	}
	while(q--){
		int t1l,t1r,t2l,t2r;
		string st1,st2;
		cin>>st1>>st2;
		int n1 = st1.size(),n2 = st2.size();
		if(n1 != n2){
			cout<<0<<endl;
			continue;
		}
		for(int i = 0;i < n1;i++){
			if(st1[i] == 'b'){
				t1l = i;
				t1r = n1 - t1l - 1;
			}
		}
		for(int i = 0;i < n2;i++){
			if(st2[i] == 'b'){
				t2l = i;
				t2r = n2 - t2l - 1;
			}
		}
		int ans = 0;
		int dift = t1l - t2l;
		for(int i = 0;i < n;i++){
			if(t1l >= sb[i][0] and t1r >= sb[i][1] and difs[i] == dift){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
