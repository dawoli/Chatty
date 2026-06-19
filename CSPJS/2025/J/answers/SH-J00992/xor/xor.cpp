#include<bits/stdc++.h>
using namespace std;//erfen
int n,k,a[500005],xa[500005];
struct qujian{
	int l,r;
};
struct inp{
	int x,id;
}a100[500005];
qujian v[500005];
long long cnt=0,ans;
bool cmp(qujian x,qujian y){ 
	return x.r==y.r?x.l>y.l:x.r<y.r;
}
bool cmp100(inp x,inp y){ 
	return x.x==y.x?x.id<y.id:x.x<y.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a100[i].id=i;
		a[i]=a[i] xor a[i-1];
		a100[i].x=a[i]; 
	}
	for(int i=1;i<=n;i++){
		xa[i]=a[i] xor k;
	}
	if(n<=1000){//60pts 
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=0;j--){//xa[0]==0 
				if(xa[i]==a[j]) {
					v[++cnt]=(qujian){j+1,i};//必须严格不重叠区间 
					break;
				}
			}		
		}
		//区间覆盖
		sort(v+1,v+1+cnt,cmp);
		int r=0;
		for(int x=1;x<=cnt;x++){
			if(v[x].l<=r) continue;
			ans++;
			r=v[x].r;
		}cout<<ans;
		
	}else{//100pts
		sort(a100+1,a100+1+n,cmp100);//存id 
		sort(a+1,a+1+n);
		a100[n+1].x=INT_MAX;//极大值 
		n++;//---------------
		for(int i=1;i<=n-1;i++){
			int loc=lower_bound(a,a+1+n,xa[i])-a;		//a[0]有值 
			if(loc==n||a[loc]>xa[i]){//无匹配
				continue; 
			}int l=0;
			bool flag=0;
			while(loc<n-1&&a[loc]==xa[i]&&a100[loc].id<i){
				flag=1;
				l=max(l,a100[loc].id);
				loc++;
			}
			if(flag) v[++cnt]=(qujian){l+1,i};
		}
		//区间覆盖
		sort(v+1,v+1+cnt,cmp);		
		int r=0;
		for(int x=1;x<=cnt;x++){
			if(v[x].l<=r) continue;
			ans++;
			r=v[x].r;
		}cout<<ans;		
	}
	return 0;
}
