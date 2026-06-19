#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int n,d[N];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int q;cin>>q;
		d[q]++;
	}
	int res=0;
	for(int i=1;i<N;i++){
		res=max(0,res-d[i]);
		res+=d[i];
	} 
	cout<<res<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

