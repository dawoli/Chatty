#include <bits/stdc++.h>
using namespace std;
int T;
#define N 100001
int n,m,L,V;
int d[N],v[N],a[N];
int t[N],l[N];
int p[N],c[N];
void rmcar(int x){
	for(int i=x;i<n;i++){
		d[i]=d[i+1];
		v[i]=v[i+1];
		a[i]=a[i+1];
		t[i]=t[i+1];
		l[i]=l[i+1];
	}
	d[n]=v[n]=a[n]=t[n]=l[n]=0;
	n--;
}
void rmdet(int x){
	for(int i=x;i<m;i++){
		p[i]=p[i+1];
		c[i]=c[i+1];
	}
	p[m]=c[m]=0;
	m--;
}
void solve(){
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			t[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i]);
			l[i]=L+1;
		}
		else if(a[i]<0)
			if(v[i]>V){
				t[i]=d[i];
				l[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i]);
			}
			else{
				rmcar(i--);
				continue;
			}
		else if(v[i]>V){
			t[i]=d[i];
			l[i]=L+1;
		}
		else{
			rmcar(i--);
			continue;
		}
		if(t[i]>L)
			rmcar(i--);
	}
	
	int res1=0;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			if(p[j]>=t[i]&&p[j]<=l[i]){
				res1++;
				c[j]++;
				break;
			}
	cout<<res1<<' ';
	
	int res2=0;
	for(int i=1;i<=m;i++)
		if(c[i]==0){
			rmdet(i--);
			res2++;
		}
	for(int i=m;i>=1;i--){
		int tst=0;
		for(int j=1;j<=n;j++)
			for(int k=m;k>=1;k--)
				if(p[k]>=t[j]&&p[k]<=l[j]&&k!=i){
					tst++;
					break;
				}
		if(tst==res1){
			rmdet(i--);
			res2++;
		}
	}
	cout<<res2<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
			cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)
			cin>>p[i];
		solve();
	}
	return 0;
} 
