#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll mx1,p1,mx2,p2,dif;
}a[100010];
struct unit{
	ll num,id;
}b[4][50010];
ll t,n,ans,len[4];
bool cmp(unit x,unit y){
	if(a[x.id].dif!=a[y.id].dif){
		return a[x.id].dif<a[y.id].dif;
	}
	return a[x.id].mx1<a[y.id].mx2;
}
bool cmp2(unit x,unit y){
	if(a[x.id].mx1!=a[y.id].mx1){
		return a[x.id].mx1>a[y.id].mx1;
	}
	return a[x.id].mx2<a[y.id].mx2;
}
void fun(ll u){
	ll hd=1;
	for(int i=n/2+1;i<=len[u];i++){
		if(b[u][i].num>a[b[u][hd].id].dif){
			ll tmp=a[b[u][hd].id].p2;
			b[tmp][++len[tmp]].num=a[b[u][hd].id].mx2;
			b[u][hd].num=0;
			hd++;
		}
		else{
			for(int j=i;j<=len[u];j++){
				ll tmp=a[b[u][j].id].p2;
				b[tmp][++len[tmp]].num=a[b[u][j].id].mx2;
				b[u][j].num=0;
			}
			break;
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		len[1]=len[2]=len[3]=0;
		for(int i=1;i<=n;i++){
			ll a11,a22,a33;
			cin>>a11>>a22>>a33;
			if(a11>a22){
				if(a11>a33){
					a[i].mx1=a11;
					a[i].p1=1;
					if(a22>a33){
						a[i].mx2=a22;
						a[i].p2=2;
					}
					else{
						a[i].mx2=a33;
						a[i].p2=3;
					}
				}
				else{
					a[i].mx1=a33;
					a[i].p1=3;
					a[i].mx2=a11;
					a[i].p2=1;
				}
			}
			else{
				if(a22>a33){
					a[i].mx1=a22;
					a[i].p1=2;
					if(a11>a33){
						a[i].mx2=a11;
						a[i].p2=1;
					}
					else{
						a[i].mx2=a33;
						a[i].p2=3;
					}
				}
				else{
					a[i].mx1=a33;
					a[i].p1=3;
					a[i].mx2=a22;
					a[i].p2=2;
				}
			}
			a[i].dif=a[i].mx1-a[i].mx2;
			b[a[i].p1][++len[a[i].p1]].num=a[i].mx1;
			b[a[i].p1][len[a[i].p1]].id=i;
		}
		for(int i=1;i<=3;i++){
			sort(b[i]+1,b[i]+len[i]+1,cmp);
		}
		if(len[1]>n/2){
			sort(b[1]+n/2+1,b[1]+len[1]+1,cmp2);
			fun(1);
		}
		else if(len[2]>n/2){
			sort(b[2]+n/2+1,b[2]+len[2]+1,cmp2);
			fun(2);
		}
		else if(len[3]>n/2){
			sort(b[3]+n/2+1,b[3]+len[3]+1,cmp2);
			fun(3);
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=len[i];j++){
//				cout<<i<<','<<j<<':'<<b[i][j].num<<' ';
				ans+=b[i][j].num;
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
