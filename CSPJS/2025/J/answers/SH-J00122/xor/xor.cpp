#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
struct T{
	int l,r,p,num;
	vector<int> q;
};
T ans[500005];
ull a[500005],ps[500005],k,n,cnt=1;
bool bk[500005];
int xr(ull a,ull b){
	if(a==1 and b==3) return 2;
	ull t1=a,t2=b;
	while(1){
		if(a==0 and b==0){
			return abs(t1-t2);
		}
		else if(a==0 or b==0) return t1+t2;
		a/=2,b/=2;
	}
}
bool cmp(T a,T b){
	return a.p<b.p;
}
bool cmp1(T a,T b){
	return a.l<b.l;
}
int main()
{
	freopen("xor","r",stdin);
	freopen("xor","w",stdout);
	cin>>n>>k;
	for(ull i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(ull i=1;i<=n;i++)
	{
		fill(ps+1,ps+500005,0);
		ps[i]=a[i];
		if(ps[i]==k){
			ans[cnt].l=i;
			ans[cnt].r=i;
			ans[cnt].num=cnt;
			cnt++;
		}
		for(ull j=i+1;j<=n;j++)
		{
			ps[j]=xr(ps[j-1],a[j]);
			cout<<ps[j-1]<<' '<<a[j]<<' '<<ps[j]<<endl;
			if(ps[j]==k)
			{
				ans[cnt].l=i;
				ans[cnt].r=j;
				ans[cnt].num=cnt;
				cnt++;
			}
		}
	}
	sort(ans+1,ans+cnt,cmp1);
	for(ull i=1;i<cnt;i++){
		for(ull j=i+1;j<cnt;j++){
			if(ans[i].r>=ans[j].l){
				ans[i].p++;
				ans[j].p++;
				ans[i].q.push_back(ans[j].num);
				ans[j].q.push_back(ans[i].num);
			}
		}
	}
	sort(ans+1,ans+cnt,cmp);
	ull an=0;
	
	for(ull i=1;i<cnt;i++)
	{
		if(bk[ans[i].num]==0){
			an++;
			for(auto j:ans[i].q){
				bk[j]=1;
			}
		}
	}
	cout<<an;
	return 0;
}
