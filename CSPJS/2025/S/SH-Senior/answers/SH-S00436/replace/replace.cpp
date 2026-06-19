#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N = 1e5+9;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i = 1;i <= n;i++) cin>>s1[i]>>s2[i];
	while (q--){
		string t1,t2;
		cin>>t1>>t2;
		if (t1.size() != t2.size()){
			cout<<0<<endl;
			continue;
		}
		int ans = 0;
		int lt = t1.size();
		for (int i = 0;i < lt;i++){
			if (i > 0 && t1[i-1] != t2[i-1]) break;
			for (int j = 1;j <= n;j++){
				int ls = s1[j].size();
				if (i+ls-1 > lt) continue;
				bool flag = 1;
				for (int k = 0;k < ls;k++){
					if (t1[i+k] != s1[j][k] || t2[i+k] != s2[j][k]){
						flag = 0;
						break;
					}
				}
				if (flag){
					for (int k = i+ls;k < lt;k++){
						if (t1[k] != t2[k]){
							flag = 0;
							break;
						}
					}
				}
				if (flag) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
