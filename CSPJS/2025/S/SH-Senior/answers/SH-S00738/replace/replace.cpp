#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
map<string,string> h;
map<string,bool> h2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for (int i = 1; i <= n; i++){
		string x,y;
		cin>>x>>y;
		h[x]=y;
		h2[x]=1;
	}
	for (int i = 1; i <= m; i++){
		string a,b,c="",x="";
		cin>>a>>b;
		string y=a;
		ans=0;
		for (int j = 1; j <= a.size(); j++){
			c=x="";
			y=a;
			for (int k = 0; k < a.size(); k++){
				if (k>=j) x+=a[k-j];
				c+=a[k];
				y=y.erase(0,1);
				if (k>=j-1){
					if (k>=j) c=c.erase(0,1);
//					cout<<x<<" "<<c<<" "<<y<<" "<<h2[c]<<"\n";
					if (h2[c]){
						ans+=(x+h[c]+y==b);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
