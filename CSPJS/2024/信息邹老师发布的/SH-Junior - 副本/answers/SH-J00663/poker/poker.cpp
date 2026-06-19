#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[55][3];
int n,f[55],cnt;
signed main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		int k=0;
		if(a[i][2]=='A'){
			k+=1;
		}else if(a[i][2]=='T'){
			k+=10;
		}else if(a[i][2]=='J'){
			k+=11; 
		}else if(a[i][2]=='Q'){
			k+=12;
		}else if(a[i][2]=='K'){
			k+=13;
		}else{
			k+=(a[i][2]-'0');
		}
		if(a[i][1]=='C'){
			k+=13;
		}if(a[i][1]=='H'){
			k+=26;
		}if(a[i][1]=='S'){
			k+=39;
		}
		f[k]++;
	}for(int i=1;i<=52;i++){
		if(f[i]==0){
			cnt++;
		}
	}cout<<cnt;
	return 0;
}
