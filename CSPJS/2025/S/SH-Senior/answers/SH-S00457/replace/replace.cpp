#include<bits/stdc++.h>
using namespace std;
string s1[200009],s2[200009],t1[200009],t2[200009];
int n,q,l,r;
bool tmp3=0;
bool flag=1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int ans=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
		ans=0;
		if(t1[i].length()!=t2[i].length()){
			continue;
		}
		for(int j=1;j<=n;j++){
			int tmp=t1[i].length();
			int tmp2=s1[j].length();
			for(int k=0;k+tmp2<=tmp;k++){
				flag=1;
				for(int l=0;l<k;l++){
					if(t1[i][l]!=t2[i][l]){
						flag=0;
						break;
					}
				}
				if(!flag) continue;
				for(int l=k;l<k+tmp2;l++){
					tmp3=1;
					if(t1[i][l]!=s1[j][l-k] or t2[i][l]!=s2[j][l-k]){
						tmp3=0;
						break;
					}
				}
				for(int l=k+tmp2;l<tmp;l++){
					if(t1[i][l]!=t2[i][l]){
						tmp3=0;
						break;
					}
				}
				if(tmp3){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
