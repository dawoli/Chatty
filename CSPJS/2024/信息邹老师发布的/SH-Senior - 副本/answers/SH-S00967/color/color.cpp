#include<bits/stdc++.h>
#define long long ll
#define unsigned long long ull
using namespace std;
int a[200005];
int maxx=0;
int n;
void dfs(string c,int i){
	if(i==n+1){
//		cout<<c<<endl;
		int cnt=0;
		for(int j=0;j<c.size();j++){
			for(int k=j-1;k>=0;k--){
//				if(c=="101"){
//					cout<<c[k]-'0'<<" "<<c[j]-'0'<<endl;
//				}
				if(c[k]-'0'==c[j]-'0'){
					if(a[k+1]==a[j+1]){
						cnt+=a[j+1];
					}
					break;
				}
			}
		}
		maxx=max(maxx,cnt);
		return ;
	}
	dfs(c+'0',i+1);
	dfs(c+'1',i+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		string c;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(c,1);
		cout<<maxx<<endl;
		maxx=0;
		memset(a,0,sizeof(a));
	}
	return 0;
}
