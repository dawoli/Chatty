#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int> play[maxn];int query[maxn][2];
int t,n,k,q,r,c,l,s;bool bj1=true;
void solver1(){
	for(int i=0;i<q;i++){
		bool bj=false;
		if(query[i][1]==1){
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<n;j++){
			for(int k1=0;k1<play[j].size();k1++){
				if(play[j][k1]!=1) continue;
				for(int l=1;l<k;l++){
					if(k1+l>=play[j].size()) break;
					if(play[j][k1+l]==query[i][1]){
						bj=true;break;
					}
				}
				if(bj) break;
			}
			if(bj) break;
		}
		if(bj) cout<<1<<endl;
		else cout<<0<<endl;
	}
}
map<int,int> change;int back[maxn];
void bfs(){
	for(int i=0;i<q;i++) cout<<0<<endl;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d %d %d",&n,&k,&q);
		for(int j=0;j<n;j++){
			cin>>l;
			for(int k=0;k<l;k++){
				cin>>s;
				play[j].push_back(s);
			}
		}
		for(int j=0;j<q;j++){
			cin>>query[j][0]>>query[j][1];
			bj1=bj1&&(query[j][0]==1);
		}
		if(bj1) solver1();
		else bfs();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
