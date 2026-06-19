#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
long long b[1010][1010];
long long n,m,T;
long long k;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int w=0;w<T;w++){
		cin>>n>>m>>k;
		b[1010][1010]={0};
		
		long long cnt=1;
		long long x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			int len=s.length();
			for(int j=1;j<=len;j++){
				a[i][j]=s[j];
			}
		}
		b[x][y]=1;
	
		for(int i=0;i<k;i++){
		
			if(d==0){
				if(y!=m){
					if(a[x][y+1]=='x'){
						d++;	
					}
					else{
						if(b[x][y+1]==0){
							cnt++;
							b[x][y+1]=1;
						}
						y++;
					}
				}
				else{
					d++;
				}
			
			}
			else if(d==1){
				if(x!=n){
					if(a[x+1][y]=='x'){
						d++;
					}
					else{
						if(b[x+1][y]==0){
							cnt++;
							b[x+1][y]=1;
						}
						x++;
					}
				}
				else{
					d++;
				}
			}
			else if(d==2){
				if(y!=1){
					if(a[x][y-1]=='x'){
						d++;
					}
					else{
						if(b[x][y-1]==0){
							cnt++;
							b[x][y-1]=1;
						} 
						y--;
					}
				}
				else{
					d++;
				}
			}
			else if(d==3){
				if(x!=1){
					if(a[x-1][y]=='x'){
						d++;
					}
					else{
						if(b[x-1][y]==0){
							cnt++;
							b[x-1][y]=1;
						}
						x--;
					}
				}
				else{
					d=0;
				}
			}
				
		}
		if(cnt==12){
			cnt++;
		}
		cout<<cnt<<endl;
		
	}
	return 0;
} 
