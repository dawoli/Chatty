#include<bits/stdc++.h>
using namespace std;

int t,n;
long long cnt,ans;
int a[1000006][3],c[1000006];
void dfs(int x,int y){
	for(int ww=x;ww>y;ww--){
		if(a[ww][2]>=y){
			if(ww-a[ww][2]==1){
				ans+=a[ww][1];
				return;
			}else if(ww-a[ww][2]==2){
				ans+=a[ww][1];
				return;
			}else{
				dfs(ww,a[ww][2]);
				return;
			}			
		}
	}
	return;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	for(int www=1;www<=t;www++){
		n=0;
		cnt=0;ans=0;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1];
		}
		a[1][2]=-2;
		for(int i=n;i>=1;i--){
			int yy=0;
			for(int j=i-1;(yy==0 && j>=1);j--){
				a[1][2]=-2;
				a[i][2]=-1;
				if(a[i][1]==a[j][1]){
					a[i][2]=j;
					yy=1;
				}
			}
		}
		int flag=1;int pos=n;
		while(flag){
			
			if(pos==-2 || pos==1){
				flag=0;
			}
			if(flag){
				if(a[pos][2]==-1){
					pos--;
				}else if(pos-a[pos][2]==1){
					ans+=a[pos][1];
//					pos=a[pos][2];
					pos--;
				}else if(pos-a[pos][2]==2){
					ans+=a[pos][1];
//					pos=a[pos][2];
					pos--;
				}else{
					ans+=a[pos][1];
					pos--;
				}
				if(pos==-2 || pos==1 || pos==0){
					flag=0;
				}
			}
			
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
