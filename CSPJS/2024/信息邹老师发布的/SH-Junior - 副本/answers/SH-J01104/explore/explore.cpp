#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
long long maxn=-2147483648,minn=2147483647,ans=1;
char mapp[1005][1005];
struct z{
	int x;
	int y;
	int d;
}b;
z move(z c){
	if(c.d==0){
		c.y+=1;
	}
	if(c.d==1){
		c.x+=1;
	}
	if(c.d==2){
		c.y-=1;
	}
	if(c.d==3){
		c.x-=1;
	}
	return c;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		ans=1;
		long long n,m,k;
		cin>>n>>m>>k;
		cin>>b.x>>b.y>>b.d;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>mapp[i][j];
			}
		}
		for(int i=0;i<k;){
			if(mapp[move(b).x][move(b).y]=='x'||(move(b).x<0||move(b).x>n||move(b).y<0||move(b).y>n)){
				b.d=(b.d+1)%4;
				i++;
			}
			b.x=move(b).x;
			b.y=move(b).y;
			mapp[b.x][b.y]='&';
			i++;
			if(i==k){
				break; 
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(mapp[i][j]=='&'){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
