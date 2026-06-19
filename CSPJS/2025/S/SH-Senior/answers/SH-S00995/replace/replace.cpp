#include<bits/stdc++.h>
using namespace std;
int n,q;
pair<string,string> a[210000];
string q1,q2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string t1,t2,s1="",s2="";
		cin>>t1>>t2;
		for(int j=0;j<t1.length();j++){
			if(t1[j]!=t2[j]){
				s1+=t1[j];
				s2+=t2[j];
			}
		}
		//cout<<s1<<" "<<s2<<"\n";
		a[i]=make_pair(s1,s2);
	}
	while(q--){
		cin>>q1>>q2;
		if(q1.length()!=q2.length()){
			cout<<0<<"\n";
			continue;
		}
		string t1="",t2="";
		for(int i=0;i<q1.length();i++){
			if(q1[i]!=q2[i]){
				t1+=q1[i];
				t2+=q2[i];
			}
		}
		//cout<<t1<<" "<<t2<<endl;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].first==t1&&a[i].second==t2)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
