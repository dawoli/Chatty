#include <bits/stdc++.h>
using namespace std;
int n,m=0;
int r[100005]={};
int f[100005]={};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	for(int i=1;i<=n;i++){
		f[r[i]]++;
	}
	for(int i=1;i<=100005;i++){
		if(f[i]>m){
			m=f[i];
		}
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
