#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > s;
int cd[100100];
int n,k,q;
int r,c;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	int alp;
	
	while(T--){
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&cd[i]);
			for(int j=1;j<=n;j++){
				scanf("%d",&alp);
				s[i].push_back(alp);
			}
			
		}
		bool flag=false,flag2=false;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=s[i].size();j++){
				if(s[i][j]==1&&(!flag))flag=true;
				else{
					cout<<1<<'\n';
					flag2=1;
					break;
				}
			}
			
		}
		if(!flag2)cout<<0<<'\n';
		
	}
	return 0;
}
