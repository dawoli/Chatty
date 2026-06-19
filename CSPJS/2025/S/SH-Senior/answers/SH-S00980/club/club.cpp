#include<bits/stdc++.h>
using namespace std;
long long s[4]={0,0,0,0};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t){
	t--;
	long long n;
	cin>>n;
	long long t[114514][5],tp[114514];
	for(long long i=1;i<=n;i++){
		long long a=0,b=0,c=0;
		cin>>a>>b>>c;
		a=a*10+1;
		b=b*10+2;
		c=c*10+3;
		if(c<b)swap(b,c);
		if(c<a)swap(a,c);
		if(b<a)swap(a,b);
		t[i][0]=c-b;
		t[i][1]=a;
		t[i][2]=b;
		t[i][3]=c;
		tp[i]=t[i][0]*100001+i;
	}
	sort(tp+1,tp+n);
	long long c[4]={0,0,0,0},ans=0;
	for(long long i=n;i>=1;i--){
		long long k=tp[i]%100001;
		if(c[t[k][3]%10]<(n/2)){
			c[t[k][3]%10]++;
			ans+=t[k][3]/10;
		}else{
			c[t[k][2]%10]++;
			ans+=t[k][2]/10;
		}
	}
	cout<<ans<<endl;
}
	return 0;
}
