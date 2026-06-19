#include<bits/stdc++.h>
using namespace std;
int n,q,b1[200001],b2[200001];
string t1,t2,s1[200001],s2[200001];
void solveBF(){
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int ali=0;
			bool uok=0;
			for(int j=0;j<t1.size();j++){
				if(uok) break;
				if(t1[j]==s1[i][ali]){
					ali++;
					if(ali==s1[i].size()){
						uok=1;
						string tmp=t1;
						for(int k=0;k<ali;k++){
							tmp[j-ali+k+1]=s2[i][k];
						}
						if(tmp==t2) ans++;
					}
				}
				else ali=0;
			}
		}
		cout<<ans<<endl;
	}
	return;
}
void solveSP(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b') b1[i]=j;
			if(s2[i][j]=='b') b2[i]=j;
		}
	}
	while(q--){
		cin>>t1>>t2;
		int tb1,tb2,ans=0;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<t1.size();i++){
			if(t1[i]=='b') tb1=i;
			if(t2[i]=='b') tb2=i;
		}
		for(int i=1;i<=n;i++){
			if(tb2-tb1==b2[i]-b1[i]&&tb1>=b1[i]&&t1.size()-tb1>=s1[i].size()-b1[i]) ans++;
		}
		cout<<ans<<endl;
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	if(q==1||n<1001) solveBF();
	else solveSP();
	return 0;
}
