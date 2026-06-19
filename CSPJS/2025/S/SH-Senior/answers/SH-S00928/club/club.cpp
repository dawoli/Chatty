#include<bits/stdc++.h>
using namespace std;

int t,sum[4];

struct fay{
	int fir,sec,thi;
	int maxx,mid,minn;
	int ch1,ch2;
}a[200004];

bool cmp(fay x,fay y){
	if(x.ch1!=y.ch1) return x.ch1>y.ch1;
	else if(x.maxx!=y.maxx) return x.maxx>y.maxx;
	return x.ch2>y.ch2;
}

void solve(){
	
	int n,ans=0;
	cin>>n;
	int m=n/2;
	for(int i=1;i<=n;i++){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		a[i].maxx=max(aa,max(bb,cc));
		a[i].minn=min(aa,min(bb,cc));
		if(aa!=a[i].maxx&&aa!=a[i].minn) a[i].mid=aa;
		if(bb!=a[i].maxx&&bb!=a[i].minn) a[i].mid=bb;
		if(cc!=a[i].maxx&&cc!=a[i].minn) a[i].mid=cc;
		if(aa==a[i].maxx) a[i].fir=1;if(aa==a[i].mid) a[i].sec=1;if(aa==a[i].minn) a[i].thi=1;
		if(bb==a[i].maxx) a[i].fir=2;if(bb==a[i].mid) a[i].sec=2;if(bb==a[i].minn) a[i].thi=2;
		if(cc==a[i].maxx) a[i].fir=3;if(cc==a[i].mid) a[i].sec=3;if(cc==a[i].minn) a[i].thi=3;
		a[i].ch1=a[i].maxx-a[i].mid;
		a[i].ch2=a[i].mid-a[i].minn;
	}
	sort(a+1,a+n+1,cmp);
	sum[1]=0;
	sum[2]=0;
	sum[3]=0;
	for(int i=1;i<=n;i++){
		int num1=a[i].fir,num2=a[i].sec,num3=a[i].thi;
		if(sum[num1]+1<=m){
			sum[num1]++;
			ans+=a[i].maxx;
		}else if(sum[num2]+1<=m){
			sum[num2]++;
			ans+=a[i].mid;
		}else{
			sum[num3]++;
			ans+=a[i].minn;
		}
	}
	cout<<ans<<endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
}
