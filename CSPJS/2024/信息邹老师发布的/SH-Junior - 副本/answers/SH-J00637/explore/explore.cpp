#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,ans=0,ansx[1000009];
ll rob[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		ll n,m,k,X,Y,D;
		char a[1009][1009];
		cin>>n>>m>>k;
		cin>>X>>Y>>D;
		for(int j=1;j<=n;j++){
			for(int f=1;f<=m;f++){
				cin>>a[j][f];
			}
		}
		for(int j=0;j<=n+1;j++){
			for(int f=0;f<=m+1;f++){
				if(a[j][f]=='.'){
					;
				}
				else a[j][f]='x';
			}
		}
		ll j=X,f=Y,ans=1;
		a[1][1]='0';
		while(k>0){
			if(D==0){
				if(a[j][f+1]!='x'){
					if(a[j][f+1]=='.'){
						ans++;
						a[j][f+1]='0';
					}
					k--;
					f++;
				}
				else{
					k--;
					D=1;
				}
			}
			else if(D==1){
				if(a[j+1][f]!='x'){
					if(a[j+1][f]=='.'){
						ans++;
						a[j+1][f]='0';
					}
					k--;
					j++;
				}
				else{
					k--;
					D=2;
				}
			}
			else if(D==2){
				if(a[j][f-1]!='x'){
					if(a[j][f-1]=='.'){
						ans++;
						a[j][f-1]='0';
					}
					k--;
					f--;
				}
				else{
					k--;
					D=3;
				}
			}
			else{
				if(a[j-1][f]!='x'){
					if(a[j-1][f]=='.'){
						ans++;
						a[j-1][f]='0';
					}
					k--;
					j--;
				}
				else{
					k--;
					D=0;
				}
			}
		}
		ansx[i]=ans;
	}
	for(int i=1;i<=T;i++)
		cout<<ansx[i]<<endl;
	return 0;
}
