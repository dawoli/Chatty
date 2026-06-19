#include<bits/stdc++.h>
using namespace std;
int a[6][15];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);	
	int n,m,k,t,x,y,d,x2,y2,ans;
	string s[1009];
	cin>>t;
	for(int i=0;i<t;i++){
		ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		
		if(d==0){
			x2=0;
			y2=1;
		}
		else if(d==1){
			x2=1;
			y2=0;
		}
		else if(d==2){
			x2=0;
			y2=-1;
		}
		else if(d==3){
			y2=0;
			x2=-1;
		}
		for(int j=0;j<n;j++){
			cin>>s[j];
		}
		if(k==0){
			cout<<0<<endl;
			continue;
		}
		if(n==1&&n==m){
			cout<<1<<endl;
			continue;
		}
		else if(k==1&&(x+x2)>0&&(x+x2)<=m&&(y+y2)>0&&(y+y2)<=n&&s[x+x2][y+y2]=='.'){
			cout<<2<<endl;
			continue;
		}
		else if(k==1){
			cout<<1<<endl;
			continue;
		}
		for(int j=0;j<k;j++){
			if((x+x2)>0&&(x+x2)<=m&&(y+y2)>0&&(y+y2)<=n&&s[x+x2][y+y2]=='.'){
				ans++;
				x=x+x2;
				y=y+y2;
			}
			else{
				if(d=3){
					d=0;
				}
				else{
					d++;
				}
			}
			if(d==0){
				x2=0;
				y2=1;
			}
			else if(d==1){
				x2=1;
				y2=0;
			}
			else if(d==2){
				x2=0;
				y2=-1;
			}
			else if(d==3){
				y2=0;
				x2=-1;
			}
			
		}
		cout<<ans;
	}
	return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
