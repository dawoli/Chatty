#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const long long N=2e5+9;
long long n,q;
string a,b;
struct Str{
	string a,b;
}s[N];
bool cmp(const Str &u,const Str &v){
	return u.a.size()<v.a.size();
}
long long ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	std::sort(s+1,s+1+n,cmp);
	while(q--){
		ans=0;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<"0\n";
			continue;
		}
		for(long long i=1;i<=n;i++){
			if(s[i].a.size()>a.size()) break;
//			cout<<endl<<"s["<<i<<"].a="<<s[i].a<<"\n";
			for(long long j=0;j<=a.size()-s[i].a.size();j++){
//				cout<<"j="<<j<<"\n";
				bool flag=1;
				for(long long k=0;k<s[i].a.size();k++){
//					cout<<"a["<<j+k<<"]="<<a[j+k]<<",s["<<i<<"].a["<<k<<"]="<<s[i].a[k]<<endl;
					if(a[j+k]!=s[i].a[k]){
						flag=0;
						break;
					}
				}
				if(flag){
//					cout<<"OK\n";
					string t=a;
					for(long long k=0;k<s[i].a.size();k++){
						t[j+k]=s[i].b[k];
					}
//					cout<<"t="<<t<<endl;
					ans+=(t==b);
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
