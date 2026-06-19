#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int id,a,b,c,t;
}m[N];
bool cmp(node x,node y){
	int xx,yy;
	if(x.t==1)xx=max(x.b,x.c);
	else if(x.t==2)xx=max(x.a,x.c);
	else xx=max(x.a,x.b);
	if(y.t==1)yy=max(y.b,y.c);
	else if(y.t==2)yy=max(y.a,y.c);
	else yy=max(y.a,y.b);
	return xx>yy;
}
void solve(){
	int n=0,p=0,q=0,r=0,s=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i].a>>m[i].b>>m[i].c;
		m[i].id=i;
		int k=max(m[i].a,max(m[i].b,m[i].c));
		m[i].a-=k,m[i].b-=k,m[i].c-=k,s+=k;
		if(m[i].a==0){
			m[i].t=1,p++;
		}else if(m[i].b==0){
			m[i].t=2,q++;
		}else{
			m[i].t=3,r++;
		}
	}
	sort(m,m+n,cmp);
	if(p<=n/2&&q<=n/2&&r<=n/2){
		cout<<s<<endl;
		return;
	}else if(p>n/2){
		int cnt=p-n/2,j=0;
		while(cnt){
			if(m[j].t!=1){
				j++;
			}else{
				s+=max(m[j].b,m[j].c);
				j++;
				cnt--;
			}
		}
	}else if(q>n/2){
		int cnt=q-n/2,j=0;
		while(cnt){
			if(m[j].t!=2){
				j++;
			}else{
				s+=max(m[j].a,m[j].c);
				j++;
				cnt--;
			}
		}
	}else{
		int cnt=r-n/2,j=0;
		while(cnt){
			if(m[j].t!=3){
				j++;
			}else{
				s+=max(m[j].b,m[j].a);
				j++;
				cnt--;
			}
		}
	}
	cout<<s<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	while(t--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
