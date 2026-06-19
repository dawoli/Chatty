#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int T,n;
int a[N],c[N],f[N][2];

void slove_1(){
	int maxn=0;
	
	for(int state=0;state<(1<<n);state++){
		for(int i=0;i<n;i++)
			if(state&(1<<i))c[i+1]=1;
			else c[i+1]=0;
		
		int l=1,r=1;
		while(c[l]!=0)l++;
		while(c[r]!=1)r++;
		
		int tmp=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				if(l==i)continue;
				if(a[l]==a[i])tmp+=a[i];
				l=i;
			}
			else{
				if(r==i)continue;
				if(a[r]==a[i])tmp+=a[i];
				r=i;
			}
		}
		
		maxn=max(maxn,tmp); 
	}
	cout<<maxn<<"\n";
}

int loc[2005][2005],cnt;
struct node{int x,y;}tot[N];
bool cmp(node x,node y){
	return x.x*(x.y-1)>y.x*(y.y-1);
}
void slove_2(){
	cnt=0;
	memset(loc,0,sizeof(loc));
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++)
		tot[i].x=tot[i].y=0;
	for(int i=1;i<=n;i++){
		loc[a[i]][++tot[a[i]].x]=i;
		if(!tot[a[i]].y)cnt++;
		tot[a[i]].y=a[i];
	}
	
	sort(tot+1,tot+1+cnt,cmp);
	
	int ans=0;
	
	for(int i=1;i<=cnt;i++){
		int x=tot[i].x,y=tot[i].y;
	
		int tmp1=0;
		for(int j=2;j<=x;j++){
			bool check=0;
			for(int k=loc[y][j-1];k<=loc[y][j];k++)
				if(c[k]==1)check=1;
			if(!check)tmp1+=y;
		}
		
		int tmp2=0;
		for(int j=2;j<=x;j++){
			bool check=0;
			for(int k=loc[y][j-1];k<=loc[y][j];k++)
				if(c[k]==2)check=1;
			if(!check)tmp2+=y;
		}
		
		if(tmp1>tmp2){
			ans+=tmp1;
			for(int j=1;j<=x;j++)c[j]=1;
		}
		else{
			ans+=tmp2;
			for(int j=1;j<=x;j++)c[j]=2;
		}
	}
	
	cout<<ans<<'\n';
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>T;
	while(T--){
		cin>>n;
		
		bool check_10=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>10)check_10=0;
		}
		
		if(n<=15)slove_1();
		else slove_2();
	}
	
	return 0;
}

