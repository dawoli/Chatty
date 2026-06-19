#include<bits/stdc++.h>
using namespace std;
int n,q;
string sa[200005],sb[200005],qsa,qsb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sa[i]>>sb[i];
	}
	int ans=0;
	while(q--){
		ans=0;
		cin>>qsa>>qsb;
		if(qsa.size()!=qsb.size()){
			cout<<0<<endl;
			continue;
		}
		int l=-1,r=-1;
		for(int i=0;i<qsa.size();i++)
			if(l==-1&&qsa[i]!=qsb[i])l=i;
		for(int i=qsa.size()-1;i>0;i--)
			if(r==-1&&qsa[i]!=qsb[i])r=i;
		for(int i=0;i<l+1;i++){
			for(int j=r;j<qsa.size();j++){
				if(i<=l && j>=r){
					string t1,t2;
					for(int k=0;k<=j-i;k++){
						t1+=qsa[k+i];
						t2+=qsb[k+i];
					}
					for(int z=1;z<=n;z++){
						if(t1==sa[z]&&t2==sb[z])ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

