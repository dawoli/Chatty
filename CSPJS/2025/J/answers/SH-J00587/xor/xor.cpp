#include<bits/stdc++.h>
using namespace std;
int ans=0,n,k,cnt,a[500009],f[500009],id[500009];
bool cmp(const int a,const int b){
	return f[a]>f[b];
}
int yihuo(int x,int y){
	int cnt=0,x2[30],y2[30],z2[30];
	bool flagx=0,flagy=0;
	for(int i=21;i>=0;i--){
		int ii=pow(2,i);
		x2[i]=x/ii;
		y2[i]=y/ii;
		x%=ii,y%=ii;
	}
	for(int i=0;i<=21;i++)
		if(x2[i]==y2[i]) z2[i]=0;
		else z2[i]=1;
	for(int i=0;i<=21;i++){
		cnt+=(z2[i]*pow(2,i));
	}
	return cnt;
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cnt=n+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			f[i]=i;
			continue;
		}
		int x=a[i];
		for(int j=i-1;j>=1;j--){
			x=yihuo(x,a[j]);
			if(x==k) {f[i]=j; break;}
		}
	}
	for(int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(f[id[i]]==0) break;
		if(cnt>id[i]){
			cnt=f[id[i]];
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
