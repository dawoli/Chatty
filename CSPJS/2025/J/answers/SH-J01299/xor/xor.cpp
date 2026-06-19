#include <bits/stdc++.h>
#define N 500009
using namespace std;
struct qj{int l,r;} q[N];
int a[N];
bool c[N];
int n,k,p;
bool cmp(qj a,qj b){
	if(a.r-a.l+1>b.r-b.l+1)
		return false;
	else if(a.r-a.l+1<b.r-b.l+1)
	    return true;
	else{
		if(a.r>b.r) return false;
		else return true;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int tmp;
	for(int i=1;i<=n;i++){
		tmp=a[i];
		if(a[i]==k){
			q[++p].l=i;
			q[p].r=i;
		}
		for(int j=i+1;j<=n;j++){
			tmp=(tmp^a[j]);
			if(tmp==k){ 
				q[++p].l=i;
				q[p].r=j;
			}
		}
	}
	int cnt=0;
	sort(q+1,q+p+1,cmp);
	bool flg=0;
	for(int i=1;i<=p;i++){
		if(q[i].l==q[i].r){
			cnt++;
			c[q[i].l]=1;
		}
		else{
			flg=0;
			for(int j=q[i].l;j<=q[i].r;j++)
				if(c[j]) flg=1;
			if(!flg){
		  	    cnt++;
		  	    for(int j=q[i].l;j<=q[i].r;j++)
					c[j]=1;
			}
		}
	}
	cout<<cnt;
	return 0;
}
