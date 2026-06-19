#include<bits/stdc++.h>
using namespace std;
int N,K,Q,L[1010],S[1010][2020];
set< pair<int,int> > E[200010];
set< pair<int,int> >::iterator Rnr;
bool solve(int r,int c,int n,int l){
	if(r<=0){
		if(c==n){
			return true;
		}else{
			return false;
		}
	}
	//cout<<r<<" "<<l<<" "<<n<<endl;
	int iii=E[n].size();
	if(iii==1) return false;
	for(Rnr=E[n].begin();iii>=0;Rnr++){
		int k=(*Rnr).first,I=(*Rnr).second; 
		if(k==l){
			iii--;
			continue;
		}
		for(int i=I+1;i<=L[k]&&i<I+K;i++){
			if(solve(r-1,c,S[k][i],k)){
				//cout<<l<<"  "<<k<<"  "<<n<<"  "<<S[k][i]<<endl;
				return true;
			}
		}
		iii--;
	}
	return false;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>N>>K>>Q;
		if(N>1000) continue;
		memset(L,0,sizeof L);
		memset(S,0,sizeof S);
		for(int k=1;k<=N;k++){
			cin>>L[k];
			for(int i=1;i<=L[k];i++){
				cin>>S[k][i];
				E[S[k][i]].insert(make_pair(k,i));
			}
		}
		while(Q--){
			int r,c;
			cin>>r>>c;
			//cout<<Q<<"---"<<endl;
			if(solve(r,c,1,0)) cout<<1<<endl;
			else cout<<0<<endl;
		}
		for(int i=1;i<=200000;i++)
			if(E[i].size()>0) E[i].clear();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
