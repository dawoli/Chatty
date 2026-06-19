#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
int t;
cin>>t;
for(int i=1;i<=t;i++){
	int j[1010],g[1010];
	string s[1010];
	int n,m,k,ans=1;
	cin>>n>>m>>k;
	int x,y,d,r,l;
	cin>>x>>y>>d;
	for(int p=1;p<=n;p++){
		for(int q=1;q<=m;q++){
			cin>>s[p][q];
		}
	}
	j[0]=x;
	g[0]=y;
	for(int q=1;q<=k;q++){
		if(d==0){
			r=x;
			l=y+1;
		}else if(d==1){
			r=x+1;
			l=y;
		}else if(d==2){
			r=x;
			l=y-1;
		}else if(d==3){
			r=x-1;
			l=y;
		}
		if(r<=n&&r>=0&&l<=m&&l>=1&&s[r][l]!='x'){
			x=r;
			y=l;
			int f=1;
			for(int u=1;u<=ans;u++){
				if(j[u]==x&&g[u]==y){
					f--;
					break;
				}
			}
			ans+=f;
			j[ans]=x;
			g[ans]=y;
		
		}else{
			x=x;
			y=y;
			d=(d+1)%4;
			
		}
	}
	
	
	
	
	
	cout<<ans<<endl;
	
	
	
}
return 0;
}

