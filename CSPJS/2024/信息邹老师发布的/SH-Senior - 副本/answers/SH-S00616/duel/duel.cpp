#include<bits/stdc++.h>
using namespace std;
int f[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>f[i];
	}
	sort(f+1,f+m+1);
	int n=f[1];
	int k=1;
	for(int j=2;j<=m;j++){
		
		if(f[j]>n){

			n=f[k+1];
			k++;
			
		}
	}
	
	cout<<m-k+1;
	return 0;
}
