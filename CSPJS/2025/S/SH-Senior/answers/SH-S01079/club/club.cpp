#include<iostream>
#include<cstring> 
#include<algorithm>
#include <stdio.h>
#define int long long
using namespace std;
const int N=2e5+1;
int max(int x,int y){
	if(x>y) return x;
	return y;
}
struct A{
	int x,y,z,s;
	int m(){
		if(x>y&&x>z) {s=1;return x;}
		if(y>z) {s=2;return y;}
		s=3; return z;
	}
	int m(int p){
		if(p==1) return max(y,z);
		if(p==2) return max(x,z);
		return max(x,y);
	}
	int dxy(){
		return (x-y);
	}
	int dyz(){
		return (y-z);
	}
	int dzx(){
		return (z-x);
	}
}a[N];

int cnt[4];

int n,Ans;

bool cmp1(A b,A c){
	return min(b.dxy(),-b.dzx())<min(c.dxy(),-c.dzx());
}

bool cmp2(A b,A c){
	return min(-b.dxy(),b.dyz())<min(-c.dxy(),c.dyz());
}

bool cmp3(A b,A c){
	return min(-b.dyz(),b.dzx())<min(-c.dyz(),c.dzx());
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		Ans=0;
		memset(cnt,0,sizeof(cnt));

		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].m();
			cnt[a[i].s]++;
		}
//		cout<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<endl;
		if(cnt[1]>n/2){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				Ans+=a[i].m(1);
			}
			for(int i=n/2+1;i<=n;i++) Ans+=a[i].x;
		}
		else if(cnt[2]>n/2){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++){
				Ans+=a[i].m(2);
			}
			for(int i=n/2+1;i<=n;i++) Ans+=a[i].y;
		}
		else if(cnt[3]>n/2){
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n/2;i++){
//				cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<endl;
				Ans+=a[i].m(3);
			}
			for(int i=n/2+1;i<=n;i++) Ans+=a[i].z;
		}
		else for(int i=1;i<=n;i++) Ans+=a[i].m();
		
		cout<<Ans<<endl;
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
