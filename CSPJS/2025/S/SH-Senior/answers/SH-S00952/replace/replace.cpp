#include<bits/stdc++.h>
using namespace std;

int n,q,d[200009];
string sx[200009],sy[200009];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sx[i]>>sy[i];
		for(int j=0;j<sx[i].size();j++){
			if(sx[i][j]!=sy[i][j]){
				d[i]=j;
				break;
			}
		}
	} 
	while(q--){
		string S,C;
		cin>>S>>C;
		if(S.size()!=C.size()){
			cout<<0<<"\n";
			continue;
		}
		int st=0,ed=0;
		for(int i=0;i<S.size();i++){
			if(S[i]!=C[i]){
				st=i;
				break;
			}
		}
		for(int i=S.size()-1;i>=0;i--){
			if(S[i]!=C[i]){
				ed=i;
				break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(sx[i].size()-d[i]<ed-st+1){
				continue;
			}
			bool flag=0;
			if(st<d[i])continue;
			for(int j=st-d[i],k=0;k<sx[i].size();j++,k++){
				if(sx[i][k]!=S[j]||sy[i][k]!=C[j]){
					flag=1;
					break;
				}
			}
			if(flag==0){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
