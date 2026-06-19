#include<bits/stdc++.h>
using namespace std;
int n,t,ans;
string s1[200005],s2[200005],a,b,p,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>t;
	for(int i = 1;i <= n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(t--){
		ans = 0;
		cin>>a>>b;
		if(a.length() != b.length()){
			cout<<0<<endl;
			continue;
		}
		for(int i = 1;i <= n;i++){
			if(a.length() < s1[i].length()){
				continue;
			}
			for(int j = 0;j < a.length()-s1[i].length()+1;j++){
				p = a;
				q = b;
				for(int k = j;k <= j+s1[i].length()-1;k++){
					if(p[k] == s1[i][k-j]){
						p[k] = s2[i][k-j];
					}
					else{
						p[k] = '0';
					}
				}
				if(p == q){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
