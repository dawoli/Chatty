#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=2e5+10;
int bucket[N];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,n,k,q,m,a,b;
	cin>>t;
	while(t--){
		memset(bucket,0,sizeof(bucket));
		cin>>n>>k>>q;
		vector< vector<int> >v(n);
		for(int i=0;i<n;i++){
			cin>>m;
			vector<int>s(m);
			for(int j=0;j<m;j++){
				cin>>s[j];
				bucket[s[j]]+=1;
			}
			v.push_back(s);
		}
		while(q--){
			cin>>a>>b;
			if(!bucket[b])puts("0");
			else if(!bucket[1])puts("0");
			else{
				int idb,id1=2147483647;
				for(int i=0;i<n;i++){
					for(int j=0;j<v[i].size();j++){
						if(v[i][j]==b){
							for(int x=j-1;x>=0&&j-x<=k;x--){
								if(v[i][x]==1){
									idb=j,id1=x;
									break;
								}
							}
						}
						if(id1!=2147483647)break;
					}
					if(id1!=2147483647)break;
				}
				puts(id1==2147483647?"0":"1");
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
