#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
inline int read(){
	int x=0,op=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			op=-1;
		}
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*op;
}
const int N=1e5+9;
int t,n;
struct Pt{
	int st;
	int top,cl1;
	int mid,cl2;
	int low,cl3;
} a[3*N],k1[N],k2[N],k3[N];
bool cmp(Pt a,Pt b){
	if(a.top-a.mid<b.top-b.mid){
		return 1;
	}
	else if(a.top-a.mid>b.top-b.mid){
		return 0;
	}
	else {
		return a.mid>b.mid;
	}
} 
bool vst[N];
int num1,num2,num3;
/*
struct QP{
	int c1,c2,c3;
} f[N][3];
*/
int f[N][3],ans,cnt[4];
void solve(){
	if(cnt[1]>n/2){
		sort(k1+1,k1+1+num1,cmp);
		int t=0;
		while(cnt[1]>n/2){
			ans=ans-k1[++t].top+k1[t].mid;
			cnt[1]--;
		}
	}
	if(cnt[2]>n/2){
		
		sort(k2+1,k2+1+num2,cmp);
		int t=0;
		while(cnt[2]>n/2){
			ans=ans-k2[++t].top+k2[t].mid;
			cnt[2]--;
		}
	}
	if(cnt[3]>n/2){
		
		sort(k3+1,k3+1+num3,cmp);
		int t=0;
		while(cnt[3]>n/2){
			ans=ans-k3[++t].top+k3[t].mid;
			cnt[3]--;
		}
	}
	cout<<ans<<endl;
	
	
	
	
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int o=0;
	while(t--){
		n=read();
		for(int i=1;i<=n;i++){
			int p,q,r;
			p=read();
			q=read();
			r=read();
			a[i].st=i;
			if(p<=q&&q<=r){
				a[i].low=p;
				a[i].mid=q;
				a[i].top=r;
				a[i].cl1=3;
				a[i].cl2=2;
				a[i].cl3=1;
				k3[++num3]=a[i];
			}
			else if(p<=r&&r<=q){
				a[i].low=p;
				a[i].mid=r;
				a[i].top=q;
				a[i].cl1=2;
				a[i].cl2=3;
				a[i].cl3=1;
				k2[++num2]=a[i];
			}
			else if(q<=r&&r<=p){//p1 q2 r3
				a[i].low=q;
				a[i].mid=r;
				a[i].top=p;
				a[i].cl1=1;
				a[i].cl2=3;
				a[i].cl3=2;
				k1[++num1]=a[i];
			}
			else if(q<=p&&p<=r){
				a[i].low=q;
				a[i].mid=p;
				a[i].top=r;
				a[i].cl1=3;
				a[i].cl2=1;
				a[i].cl3=2;
				k3[++num3]=a[i];
			}
			else if(r<=p&&p<=q){
				a[i].low=r;
				a[i].mid=p;
				a[i].top=q;
				a[i].cl1=2;
				a[i].cl2=1;
				a[i].cl3=3;
				k2[++num2]=a[i];
			}
			else{
				a[i].low=r;
				a[i].mid=q;
				a[i].top=p;
				a[i].cl1=1;
				a[i].cl2=2;
				a[i].cl3=3;
				k1[++num1]=a[i];
			}
			ans+=a[i].top;
			cnt[a[i].cl1]++;
			
		}
		solve();
		cnt[3]=0;
		cnt[2]=cnt[3];
		cnt[1]=cnt[2];
		num1=num2=0;
		num3=0;
		ans=0;
	}
	return 0;
}

