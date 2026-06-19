#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int T,n,m,L,v;
struct car{
	int d,v,a;
	double t,s;
}c[N];
int p[N];

int open_moni[N];
bool check[N];

bool judge(int tot,int cnt){
	
	int num=0;
	memset(check,0,sizeof(check));
	for(int moni=1;moni<=tot;moni++){
		int loc=p[open_moni[moni]];
		
		for(int i=1;i<=n;i++){
			if(check[i])continue;
			if(loc<c[i].d)continue;
			
			int s=loc-c[i].d;
			double speed=(double)sqrt(c[i].v*c[i].v+2*c[i].a*s)*1.0;
			double limit=v*1.0;
			if(speed>limit)check[i]=1;
		}
	}
	for(int i=1;i<=n;i++)if(check[i]){
		num++;
		//cout<<i<<" ";
	}
	//cout<<"\n";
	if(num==cnt)return 1;
	else return 0;
}

void slove_1(){
	memset(check,0,sizeof(check));
	
	for(int moni=1;moni<=m;moni++){
		int loc=p[moni];
		
		for(int i=1;i<=n;i++){
			if(check[i])continue;
			if(loc<c[i].d)continue;
			
			int s=loc-c[i].d;
			double speed=(double)sqrt(c[i].v*c[i].v+2*c[i].a*s)*1.0;
			double limit=v*1.0;
			if(speed>limit)check[i]=1;
		}
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++)if(check[i]){
		//cout<<i<<" ";
		cnt++;
	}
	//cout<<"\n";
	cout<<cnt<<" ";
	
	int minn=m;
	for(int i=0;i<(1<<m);i++){
		int tot=0;
		for(int j=0;j<m;j++)
			if(i&(1<<j))open_moni[++tot]=j+1;
		if(judge(tot,cnt))minn=min(minn,tot);
	}
	cout<<m-minn<<"\n";
}

void slove_a(){
	memset(check,0,sizeof(check));
	
	int loc=p[m];
	for(int i=1;i<=n;i++){
		if(check[i])continue;
		if(loc<c[i].d)continue;
	
		if(c[i].v>v)check[i]=1;
	}
	
	int tot=0;
	for(int i=1;i<=n;i++)if(check[i])tot++;
	
	cout<<tot<<" ";
	if(tot)cout<<m-1<<"\n";
	else cout<<m<<"\n"; 
}

void slove_b(){
	memset(check,0,sizeof(check));
	
	int loc=p[m];
	for(int i=1;i<=n;i++){
		if(check[i])continue;
		if(loc<c[i].d)continue;
		
		int s=loc-c[i].d;
		double speed=(double)sqrt(c[i].v*c[i].v+2*c[i].a*s)*1.0;
		double limit=v*1.0;
		if(speed>limit)check[i]=1;
	}
	
	int tot=0;
	for(int i=1;i<=n;i++)if(check[i])tot++;
	
	cout<<tot<<" ";
	if(tot)cout<<m-1<<"\n";
	else cout<<m<<"\n"; 
}

int bin(double x){
	int l=1,r=m;
	while(l<=r){
		int md=(l+r)>>1;
		if((double)p[md]>x)r=md-1;
		else if((double)p[md]==x)return md;
		else {
			l=md+1;
		}
	}
	return l-1;
}

void slove_c(){
	int num=0;
	for(int i=1;i<=n;i++){
		double s=(v*v-c[i].v*c[i].v)/(2*c[i].a)*1.0;
		if(s<0.0)continue;
		
		double dis=s+c[i].d;
		for(int j=1;j<=m;j++)
			if((double)p[j]>=c[i].d&&(double)p[j]<=dis){
				num++;
				break;
			}
	}
	cout<<num<<" ";
	
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>v;
		
		bool check_a=1,check_b=1,check_c=1;
		
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
			if(c[i].a)check_a=0;
			if(c[i].a<=0)check_b=0;
			if(c[i].a>=0)check_c=0;
		}
			
		for(int i=1;i<=m;i++)cin>>p[i];
		
		
		if(check_a)slove_a();
		else if(check_b)slove_b();
		else slove_1();
	}
	
	return 0;
}

