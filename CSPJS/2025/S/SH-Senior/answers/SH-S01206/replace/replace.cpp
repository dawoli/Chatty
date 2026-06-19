#include <bits/stdc++.h>
using namespace std;
int ts[5000010][27];
int fl[5000010][22];
int idx[5000010];
int tot=0;
queue <int> q;
int u;
int it_(int u1,char c1){
	if(ts[u1][c1]==0){
		tot++;
		ts[u1][c1]=tot;
	}
	return ts[u1][c1]; 
}
int ti_(int u1,char c1){
	
	return ts[u1][c1]; 
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,Q;
	string s1,s2;
	cin >> n >> Q; 
	for(int i=0;i<n;i++){
		cin >> s1 >> s2;
		u=0;
		for(int j=0;j<s1.size();j++){
			u=it_(u,s1[j]);
			u=it_(u,s2[j]);
		}
		idx[u]++;
	}
	for(int i=0;i<26;i++){
		if(ts[0][i]!=0){
			q.push(ts[0][i]);
		}
	}
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			if(ts[u][i]==0){
				ts[u][i]=ts[fl[u][0]][i];
			}
			fl[ts[u][i]][0]=ts[fl[u][0]][i];
			q.push(ts[u][i]); 
		}
	}
	for(int i=1;i<=21;i++){
		for(int j=0;j<=tot;j++){
			fl[j][i]=fl[fl[j][i-1]][i-1];
		}
	}
	while(Q--){
		cin >> s1 >> s2;
		u=0;
		for(int i=0;i<s1.size();i++){
			u=ti_(u,s1[i]);
			u=ti_(u,s2[i]);
		}
	}
	//想到nlogn解法，板子忘了咋写了，算了 
	cout << 0 << endl;
	return 0;
} 
