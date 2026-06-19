#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,q;
string s1[1010],s2[1010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++)  cin>>s1[i]>>s2[i];
	string a,b;
	while (q--){
		cin>>a>>b;
		ll ans=0;
		for (int i=1;i<=n;i++){
			for (int j=0;j<a.size()-s1[i].size()+1;j++){
				bool flag=1;
				for (int k=j;k<j+s1[i].size();k++){
					if (a[k]!=s1[i][k]){
						flag=0;
						break;
					}
				}
				if (flag){
					string t=a;
					for (int k=j;k<j+s1[i].size();k++)  t[k]=s2[i][k];
					if (t==b)  ans++;
				}
			} 
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
