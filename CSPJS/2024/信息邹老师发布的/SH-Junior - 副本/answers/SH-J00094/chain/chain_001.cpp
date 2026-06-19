#include<bits/stdc++.h>
using namespace std;
int f[110][2010],t,n,k,q,l[100010],mp[200010],minu[200010];
vector<int> s[100010];
int main(){
	freopen("chain2.in","r",stdin);
//	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		memset(mp,0,sizeof(mp));
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			scanf("%d",&l[i]);
			s[i].resize(l[i]);
			for(int j=0;j<l[i];j++){
				scanf("%d",&s[i][j]);
				mp[s[i][j]]=1;
			}
		}
		for(int i=1;i<=200000;i++)
			if(mp[i]==0)
				minu[i+1]=minu[i]+1;
			else
				minu[i+1]=minu[i];
		for(int i=1;i<=n;i++){
			for(int j=0;j<l[i];j++){
				s[i][j]-=minu[s[i][j]];
			}
		}
		f[0][1]=-1;
		for(int i=0;i<=100;i++){
			for(int j=1;j<=3000;j++){
				if(f[i][j]){
					for(int m=1;m<=n;m++){
						if(m==f[i][j])
							continue;
						for(int o=0,b=-0x3f3f3f3f;o<l[m];o++){
							if(o-b<k){
								if(f[i+1][s[m][o]]&&f[i+1][s[m][o]]!=m)
									f[i+1][s[m][o]]=-1;
								else
									f[i+1][s[m][o]]=m;
							}
							if(s[m][o]==j)
								b=o;
						}
					}
				}
			}
		}
		for(int i=0;i<q;i++){
			int r,c;
			scanf("%d%d",&r,&c);
			printf("%d\n",!!f[r][c]);
		}
	}
	return 0;
}
