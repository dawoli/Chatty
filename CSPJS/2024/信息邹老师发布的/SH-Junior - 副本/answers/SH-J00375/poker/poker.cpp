#include<bits/stdc++.h>
using namespace std;
int f[100][100];
int ans;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		char a,b;
		cin>>a>>b;
		int x=(int)a;
		int y=(int)b;
		if(f[x][y]==0){
			f[x][y]=1;
			ans++;
		}
	}
	cout<<52-ans<<endl;
	return 0;
} 
