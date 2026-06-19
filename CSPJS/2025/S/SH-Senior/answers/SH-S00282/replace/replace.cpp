#include<bits/stdc++.h>
using namespace std;
string tf[10001];
string ts[10001];
int dff[10001];
int dfs[10001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	int cnnt=0;
	for(int i=0;i<n;i++){
		string x,y;
		cin>>x>>y;
		tf[cnnt]=x;
		ts[cnnt]=y;
		int l=0,r=x.length()-1;
		while(x[l]==y[l]) l++;
		while(x[r]==y[r]) r--;
		dff[cnnt]=l;dfs[cnnt]=r;
		cnnt++;
	}
	while(q!=0){
		q--;
		string sf,sc;
		cin>>sf>>sc;
		int l=0,r=sf.length()-1;
		while(sf[l]==sc[l]) l++;
		while(sf[r]==sc[r]) r--;
		int ls=l-r+1;
		int ans=0;int fl=0;
		while(fl<n){
			if(dfs[fl]-dff[fl]+1<ls||tf[fl].length()>sf.length()){
				fl++;continue;
			}
			for(int i=0;i<=sf.length()-tf[fl].length();i++){
				int j=0;int tpt=0;
				while(j<tf[fl].length()){
					if(tf[fl][j]!=sf[i+j]||ts[fl][j]!=sc[i+j]) break;
					tpt++;j++;
				}
				if(tpt==tf[fl].length()-1) ans++;
			}
			fl++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
