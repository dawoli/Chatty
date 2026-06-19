#include <bits/stdc++.h>
using namespace std;
int t,n,ans;
int a[100005][3];
void dfs(int x,int n1,int n2,int n3,int sum){
	if(x==n+1){
		if(sum>ans){
			ans=sum;
		}
		return ;
	}
	if(n1+1<=n/2) dfs(x+1,n1+1,n2,n3,sum+a[x][0]);
	if(n2+1<=n/2) dfs(x+1,n1,n2+1,n3,sum+a[x][1]);
	if(n3+1<=n/2) dfs(x+1,n1,n2,n3+1,sum+a[x][2]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
//  (¡¨£¾Ä¿£¼) 
//  (¨s¨‰Ãó¨‰)¨s 
//  [¡ğ.£à§¥¡ä¡¤ ¡ğ] 
//  (¡¥¨Œ¡¥£»)...
//  ¨R ©n ¨Q 
//  o(¨i©n¨i)o 
//  /(¨Òo¨Ò)/~~
//  ©³©¿Ä¹©»©·...(((m-__-)m 
