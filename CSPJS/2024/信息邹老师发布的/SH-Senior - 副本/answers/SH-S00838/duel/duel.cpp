#include<bits/stdc++.h>
#define ll long long
#define N 100009
#define R 100009
#define CON 2000009
#define INF 1000009
using namespace std;
int n,r[N];
int cnt1,cnt2,mx_val;
bool flag1=true,flag30=true;
int f[CON],ct[R];
bool ok[CON];

void solve12(){
	cout<<n-min(cnt1,cnt2)<<endl;
}

inline bool query(ll con,int x){
	if((con>>x)&1) return true;
	return false;
}
inline ll click(ll con,int x){
	con|=(1<<x);
	return con;
}

//void print(ll con){
//	for(int i=1;i<=n;i++){
//		cout<<query(con,i)<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<query(con,n+i)<<" ";
//	}
//	cout<<endl<<endl;;
//}

//con att-di
int solveBF(ll con){
	if(ok[con]) return f[con];
	ok[con]=true;
	
	bool flag=true;
	int cnt=0;
	int res=INF;
	
	for(int i=1;i<=n;i++){
		if(!query(con,n+i)) cnt++;
		if(query(con,n+i) || query(con,i)) continue;
		
		flag=false;
		for(int j=1;j<=n;j++){
			if(query(con,n+j) || j==i) continue;
			
			if(r[i]<=r[j]){
				ll tar_con=click(con,i);
				res=min(res,solveBF(tar_con));
			}
			else{
				ll tar_con=click(con,i);
				tar_con=click(tar_con,n+j);
				res=min(res,solveBF(tar_con));
			}
		}
	}
	
	if(flag){
		f[con]=cnt;
		return cnt;
	}
	f[con]=res;
	return res;
}

void solve(){
	int cnt=0;
	for(int i=1;i<=mx_val;i++){
		if(ct[i]==0) continue;
		if(ct[i]>=cnt){
			cnt=ct[i];
		}
	}
	cout<<cnt<<endl;
}

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		
		ct[r[i]]++;
		if(ct[r[i]]!=1) flag30=false;
		mx_val=max(mx_val,r[i]);
		
		if(r[i]>2) flag1=false;
		if(flag1){
			if(r[i]==1) cnt1++;
			else if(r[i]==2) cnt2++;
		}
	}
	
	if(flag1){
		solve12();
		return 0;
	}
	if(n<=10){
		cout<<solveBF(0)<<endl;
		return 0;
	}
	if(n<=30&&flag30){
		cout<<1<<endl;
		return 0;
	}
	solve();
	return 0;
} 
