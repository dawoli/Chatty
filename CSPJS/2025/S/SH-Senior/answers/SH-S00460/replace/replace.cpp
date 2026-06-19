#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[200009],s2[200009];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string c1,c2;
		cin>>c1>>c2;
		s1[i]=c1,s2[i]=c2;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		string c1,c2,c;
		int l=0,r=0;
		bool flag=0;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				if(flag==0)l=i;
				while(i<t1.size()&&t1[i]!=t2[i]){
					c1+=t1[i];
					c2+=t2[i];
					i++;
				}
				r=i-1;
				if(flag){
					c1=c+c1;c2=c+c1;
					c.clear();
				}
				flag=1;
			}else c+=t1[i];
		}
		ans=0;
		while(l>=0||r<t1.size()){
			for(int i=1;i<=n;i++){
				if(s1[i]==c1&&s2[i]==c2)ans++;
			}
			if(l==0&&r<t1.size()-1)c1+=t1[++r],c2+=t2[r];
			else if(l>0&&r==t1.size()-1)c1=t1[--l]+c1,c2=t2[l]+c2;
			else c1=t1[--l]+c1+t1[++r],c2=t2[l]+c2+t2[r];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
