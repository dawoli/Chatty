#include <bits/stdc++.h>
using namespace std;

long long val[100010][5];
long long f[210][210][210];
long long n;
long long num;
long long t;

void dfs(long long a,long long b,long long c,long long id,long long now){
	if(id>n)
		return ;
	if(now<=f[a][b][c])
		return ;
	f[a][b][c]=now;
	num=max(num,f[a][b][c]);
	if(a+1<=n/2&&now+val[id][0]>f[a+1][b][c])
		dfs(a+1,b,c,id+1,now+val[id][0]);
	if(b+1<=n/2&&now+val[id][1]>f[a][b+1][c])
		dfs(a,b+1,c,id+1,now+val[id][1]);
	if(c+1<=n/2&&now+val[id][2]>f[a][b][c+1])
		dfs(a,b,c+1,id+1,now+val[id][2]);
}

bool cmp(long long a,long long b){
	return a>b;
}

void slove1( ){
	for(long long i=0;i<=n;i++)
		for(long long j=0;j<=n;j++)
			for(long long k=0;k<=n;k++)
				f[i][j][k]=0;
	for(long long i=1;i<=n;i++)
		for(long long j=0;j<=n/2;j++)
			for(long long k=0;k<=n/2;k++){
				if(j+k>i)
					continue;
				long long l=i-j-k;
				if(l>n/2)
					continue;
				if(j>0)
					f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+val[i][0]);
				if(k>0)
					f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+val[i][1]);
				if(l>0)
					f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+val[i][2]);
				num=max(num,f[i][j][k]);
			}
	cout<<num;
}

void slove2( ){
	long long b[100010]={ };
	for(long long i=0;i<n;i++)
		b[i]=val[i][0];
	sort(b,b+n,cmp);
	for(long long i=0;i<n/2;i++)
		num+=b[i];
	cout<<num;
}

void slove( ){
	bool f1=true,f2=true;
	num=0;
	
	cin>>n;
	
	for(long long i=1;i<=n;i++){
		cin>>val[i][0]>>val[i][1]>>val[i][2];
		if(val[i][1]!=0)
			f1=false;
		if(val[i][2]!=0)
			f2=false;
	}
	
	if(n<=200)
		slove1( );
	else if(f1==true&&f2==true)
		slove2( );
	else
		cout<<"0";
	cout<<endl;
}

int main( ){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	while(t--){
		slove( );
	}
	return 0;
}
