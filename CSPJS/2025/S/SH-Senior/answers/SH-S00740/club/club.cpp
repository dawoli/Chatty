#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
long long df;
long long n,m,t,k;
struct node{
	int v,l;
}a[N][3];
int b[N][3];
bool cmp(node a,node b){
	return a.v>b.v;
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	cin>>k;
	int z[3];
	int s=0,r=1;
	z[0]=0,z[1]=0,z[2]=0;
	for(int i=1;i<=k;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0].v>>a[i][1].v>>a[i][2].v;
			a[i][0].l=0,a[i][1].l=1,a[i][2].l=2;
			sort(a[i],a[i]+3,cmp);
			s+=a[i][0].v;
			b[a[i][0].l][++z[a[i][0].l]]=a[i][0].v-a[i][1].v;
		}
		for(int i=0;i<3;i++){
			if(z[i]*2>n)
			break;
		}
		if(!r){
			cout<<s<<endl;
			continue;
		}
		sort(b[r],b[r]+z[r]);
		for(int i=n/2+1;i<=z[r]-n/2;i++){
			s=s-b[r][i];
		}
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
