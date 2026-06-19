#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
int n,q;
string s[N][2];
bool in(string a,string b){
	if(a.size()<b.size()) return 0;
	int k=0;
	for(int i=0;a.size()-i>=b.size()-k;++i){
		if(a[i]==b[k]){
			k++;
			if(k==b.size()-1)
				return 1;
		}
		else{
			k=0;
		}
	}
	return 0;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;++i){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int size=t1.size(),c=0;
		string b1="",b2="";
		bool f=0;
		for(int m=0;m<size;++m){
			if(t1[m]!=t2[m]){
				if(!c||m==c+1){
					b1+=t1[m];
					b2+=t2[m];
					c=m;
				}
				else{
					cout<<0<<endl;
					f=1;
					break;
				}
			}
		}
		if(f) continue;
		int ans=0;
		for(int m=1;m<=n;++m){
			if(in(s[m][0],b1)&&in(s[m][1],b2)){
				cout<<"m:"<<m<<endl;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
