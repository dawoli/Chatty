#include<bits/stdc++.h>
using namespace std;
const int N=1009,M=1009; 
char ex[N][M],s[N][M];
void importmap(int a,int b){
	for(int i=0;i<=a+1;i++){
		ex[i][0]='x';
		ex[i][b+1]='x';
	}
	for(int i=0;i<=b+1;i++){
		ex[0][i]='x';
		ex[a+1][i]='x';
	}
	for(int i=1;i<=a;i++)
	  for(int j=1;j<=b;j++)
	    cin>>ex[i][j];
	for(int i=0;i<=a+1;i++)
	  for(int j=0;j<=b+1;j++)
	    s[i][j]='n';
}
void explore(int a,int b,int c,int num){
	for(int i=0;i<=num;i++){
		s[a][b]='y';
		if(c==0){
			if(ex[a][b-1]=='.')
			  b--;
			else
			  c=1;
		}
		else if(c==1){
			if(ex[a+1][b]=='.')
			  a++;
			else
			  c=2;
		}
		else if(c==2){
			if(ex[a][b+1]=='.')
			  b++;
			else
			  c=3;
		}
		else{
			if(ex[a-1][b]=='.')
			  a--;
			else
			  c=0;
		}	
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	int n,m,k,x,y,d;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		int ans=0;
		importmap(n,m);
		explore(x,y,d,k);
		for(int j=0;j<=n+1;j++)
		  for(int r=0;r<=m+1;r++)
		    if(s[j][r]=='y')
		      ans++;
	    cout<<ans<<endl;
	}
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++)
		  cout<<s[i][j]<<" ";
		cout<<endl;
	}
	  
	return 0;
}
