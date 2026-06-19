#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,len;
string t1,t2;
struct{
	string a,b;
}s[N];
int ans;

void check(){
	for(int i=1;i<=n;++i){
		string x=s[i].a,y=s[i].b;
		int lenx=x.size();
		int lent=t1.size();
		if(lenx>lent){
			continue;
		}
		for(int k=0;k<=lent-lenx;++k){
			bool flag=false;
			for(int j=0;j<lenx;++j){
				if(x[j]!=t1[j+k]){
					flag=true;
					break;
				}
			}	
			if(flag==false){
				string p=t1;
				for(int j=0;j<lenx;++j){
					p[j+k]=y[j];
				}
				if(p==t2){
					ans++;
				}
				
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i].a>>s[i].b;
	}
	
	while(q--){
		ans=0;
		cin>>t1>>t2;
		len=t1.size();
		if(len!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		check();
		cout<<ans<<endl;
	}
	return 0;
}
