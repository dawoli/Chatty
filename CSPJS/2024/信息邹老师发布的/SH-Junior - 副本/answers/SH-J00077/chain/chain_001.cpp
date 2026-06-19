#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int T,n,k,q,flag;
int s[N][N],l[2*N],r,c;
bool getanswer(int r,int c,int m,int now){
	r--;
	if(r==0&&now==c) return 1;
	if(r==0&&now!=c) return 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=l[i];j++){
			if(s[i][j]==now&&i!=m){
				for(int f=1;f<k;f++){
					if(j+f<=l[i])
					flag+=getanswer(r,c,i,s[i][j+f]);
				}
			}
		}
	}
	if(flag>0) return 1;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>s[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			cout<<getanswer(r+1,c,0,1)<<endl;
			flag=0;
		}
	}
	return 0;
}
