#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,cnt[5];
struct stu{
	int rk[5];
	double a[5],d[5],sum,avr;
}s[100005];
bool cmp23(const stu &a,const stu &b){
	return a.a[1]>b.a[1];
}
bool cmp3(const stu &a,const stu &b){
	long long diffa=a.a[1]-a.a[2],diffb=b.a[1]-b.a[2];
	if(diffa!=diffb)
		return diffa>diffb;
	return a.a[1]>b.a[1];
} 
bool cmp(const stu &a,const stu &b){
	return a.a[a.rk[1]]-a.a[a.rk[2]]>b.a[b.rk[1]]-b.a[b.rk[2]];
}
bool all0(int x){
	for(int i=1;i<=n;i++)
		if(s[i].a[x]!=0)
			return false;
	return true;
}
void solve23(){
	sort(s+1,s+n+1,cmp23);
	for(int i=1;i<=n/2;i++)
		ans+=s[i].a[1];
}
void solve3(){
	sort(s+1,s+n+1,cmp3);
	for(int i=1;i<=n/2;i++)
		ans+=s[i].a[1];
	for(int i=n/2+1;i<=n;i++)
		ans+=s[i].a[2];
}
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)
			s[i].sum+=s[i].a[j];
		s[i].avr=s[i].sum/3.0;
		for(int j=1;j<=3;j++)
			s[i].d[j]=s[i].a[j]-s[i].avr;
		if(s[i].d[1]>=s[i].d[2]){
			if(s[i].d[1]>=s[i].d[3]){
				s[i].rk[1]=1;
				if(s[i].d[2]>=s[i].d[3])
					s[i].rk[2]=2,s[i].rk[3]=3;
				else
					s[i].rk[2]=3,s[i].rk[3]=2;
			}
			else{
				s[i].rk[1]=3;
				s[i].rk[2]=1;
				s[i].rk[3]=2;
			}
		}
		else{
			if(s[i].d[2]>=s[i].d[3]){
				s[i].rk[1]=2;
				if(s[i].d[1]>=s[i].d[3])
					s[i].rk[2]=1,s[i].rk[3]=3;
				else
					s[i].rk[3]=1,s[i].rk[2]=3;
			}
			else{
				s[i].rk[1]=3;
				s[i].rk[2]=2;
				s[i].rk[3]=1;
			}
		}
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++){
		int x=s[i].rk[1],y=s[i].rk[2];
		if(cnt[x]<n/2)
			cnt[x]++,ans+=s[i].a[x];
		else
			cnt[y]++,ans+=s[i].a[y];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		for(int i=1;i<=3;i++)
			cnt[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			s[i].sum=0;
			for(int j=1;j<=3;j++){
				cin>>s[i].a[j];
			}
		}
		if(all0(3)){
			if(all0(2))
				solve23();
			else
				solve3();
		}
		else
			solve();
		cout<<ans<<endl; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
