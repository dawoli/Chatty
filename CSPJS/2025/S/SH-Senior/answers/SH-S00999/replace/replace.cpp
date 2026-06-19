#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,q;
map<int,string> a,b;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		a[i]=s1;
		b[i]=s2;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int m1=t1.size();
		int m2=t2.size();
		if(m1!=m2){
			cout<<0<<endl;
			continue;
		}
		ll ans=0;
		for(int j=1;j<=n;j++){
			int d=t1.find(a[j]);
			int m=a[j].size();
			if(d>=0&&d<t1.size()){
				string t=t1;
				t.replace(d,m,b[j]);
				//cout<<a[j]<<endl;
				if(t==t2)ans++;
			}
			//cout<<t1<<" "<<t2<<endl;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
