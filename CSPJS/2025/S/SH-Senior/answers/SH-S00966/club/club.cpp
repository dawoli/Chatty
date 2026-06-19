#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][3],ch[100010],ans,b[100010];
void dfs(int dep){
	if(dep>=n+1){
		int l[3]={0,0,0},cnt=0;
		for(int i=1;i<=n;i++){
			l[ch[i]]++;
			cnt+=a[i][ch[i]];
		}
		if(l[0]>n/2||l[1]>n/2||l[2]>n/2) return;
		ans=max(ans,cnt);
		return;
	}
	ch[dep]=0;
	dfs(dep+1);
	ch[dep]=1;
	dfs(dep+1);
	ch[dep]=2;
	dfs(dep+1);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool flagb=1;
		ans=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=0;k<3;k++){
				cin>>a[j][k];
			}if(a[j][2]!=0)flagb=0;
		}
		if(flagb){
			for(int i=1;i<=n;i++){
				ans+=a[i][0];
				b[i]=a[i][1]-a[i][0];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
			cout<<ans<<endl;
		}
		else{
			dfs(1);
			cout<<ans<<endl;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
