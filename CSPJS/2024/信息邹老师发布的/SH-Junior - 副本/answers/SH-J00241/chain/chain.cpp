#include <bits/stdc++.h>
using namespace std;
int T,n,k,q,l[100005],tmp,r,c;
vector<int> a[100005];
bool dfs(int r1,int c1,int lst)
{
	if(r1==1)
	{
		for(int i=0;i<n;i++){
			for(int j=0;j<l[i];j++){
				if(a[i][j]==c1)
				{
					for(int le=1;le<k&&j-le>=0;le++)
					{
						if(a[i][j-le]==1) return 1;
					}
				}
			}
		}
		return 0;
	}
	for(int i=0;i<n;i++){
		if(i!=lst)
		for(int j=0;j<l[i];j++){
			if(a[i][j]==c1)
			{
				for(int le=1;le<k&&j-le>=0;le++)
				{
					if(dfs(r1-1,a[i][j-le],i)){
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("chain.in","r",stdin);freopen("chain.out","w",stdout);
	cin >> T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		cin >>n>>k>>q;
		for(int i=0;i<n;i++){
			cin >>l[i];
			for(int j=0;j<l[i];j++){
				cin >>tmp;
				a[i].push_back(tmp);
				
			}
		}
		for(int i=0;i<q;i++){
			cin >>r>>c;
			cout << dfs(r,c,-1)<<endl;
		}
		
	}
	return 0;
}
