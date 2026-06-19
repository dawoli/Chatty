#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n,q,a[200010],b[200010],c[200010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>s;
    	a[i]=s.length();
    	for(int j=0;j<a[i];j++)if(s[j]=='b')b[i]=j;
    	cin>>s;
    	for(int j=0;j<a[i];j++)if(s[j]=='b')c[i]=j;
    }
    for(int i=1;i<=q;i++){
    	int ans=0;
        int x,y,z;
        cin>>s;
        z=s.length();
		for(int j=0;j<z;j++)if(s[j]=='b')x=j;
        cin>>s;
		for(int j=0;j<z;j++)if(s[j]=='b')y=j;
		for(int j=1;j<=n;j++){
			if(x-y==b[j]-c[j]&&x>=b[j]&&z-x>=a[j]-b[j])ans++;
		}
		cout<<ans<<endl;
    }
	return 0;
}
