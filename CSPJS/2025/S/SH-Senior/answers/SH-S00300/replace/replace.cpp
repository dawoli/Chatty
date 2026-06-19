#include<bits/stdc++.h>
using namespace std;
int n,q,ss[200005][3],tt[200005][3],b_1,b_2;
string s_1[200005],s_2[200005],t_1[200005],t_2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s_1[i]>>s_2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t_1[i]>>t_2[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<s_1[i].size();j++){
			if(s_1[i][j]=='b'){
				b_1=j;
				ss[i][1]=j;
				ss[i][2]=s_1[i].size()-j-1;
			}
			if(s_2[i][j]=='b'){
				b_2=j;
			}
		}
		ss[i][0]=b_2-b_1;
	}
	for(int i=1;i<=q;i++){
		for(int j=0;j<t_1[i].size();j++){
			if(t_1[i][j]=='b'){
				b_1=j;
				tt[i][1]=j;
				tt[i][2]=t_1[i].size()-j-1;
			}
			if(t_2[i][j]=='b'){
				b_2=j;
			}
		}
		tt[i][0]=b_2-b_1;
		int ans=0;
		for(int j=1;j<=n;j++){
			if(tt[i][1]>=ss[j][1]&&tt[i][2]>=ss[j][2]&&tt[i][0]==ss[j][0]){
				ans++;
			}
		}
		cout<<ans<<"/n";
	}
	return 0;
}
