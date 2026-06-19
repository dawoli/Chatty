#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int n,q;
const int d = 197;
int ha1[200086],ha2[200086];
int l[200086],bit[3000086];
int h1[3000086];

int calc(string s){
	int ans = 0;
	for(int i = 0; i <s.size(); ++i){
		ans*=d;
		ans+=s[i];
	}
	return ans;
}

signed main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0),cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i = 1; i <=n; ++i){
		string s1,s2;
		cin>>s1>>s2;
		ha1[i] = calc(s1),ha2[i] = calc(s2);
		l[i] = s1.size(); 
		//cout<<ha1[i]<<" "<<ha2[i]<<endl;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int h2 = calc(t2);
		h1[0] = t1[0];
		bit[0] = 1;
		int cnt = 0;
		for(int i = 1; i <t1.size(); ++i){
			h1[i] = h1[i-1]*d +t1[i];
			bit[i] = bit[i-1]*d;
		}
		for(int i = 1; i <=n; ++i){
			for(int j = 0; j +l[i]-1 < t1.size(); ++j){
				if(ha1[i] == h1[j+l[i]-1]-(h1[j]*bit[l[i]-1]) + t1[j]*bit[l[i]-1]){
					//cout<<1<<endl;
					if(h1[t1.size()-1]-(ha1[i]-ha2[i])*bit[t1.size()-j-l[i]]==h2)cnt++;
				}
			}
		}
		printf("%ulld\n",cnt);
	}
	return 0;
}

