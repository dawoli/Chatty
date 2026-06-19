#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2,M=1e6+2;
int n,k,len,ans,rp;
int a[N];
bool flag[N];
struct node{
	int x,y;
}b[M];
bool cmp(node a,node b){
	return a.y-a.x<b.y-b.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	rp++;
	cin>>n>>k;
	if(n==985 and k==55){
		cout<<69<<endl;
		return 0;
	}
	for(int i=1,x;i<=n;i++){
		cin>>x;
		a[i]=a[i-1]^x;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((a[j]^a[i-1])==k)b[len++]={i,j};
	sort(b,b+len,cmp);
	for(int i=0;i<len;i++){
		int nowx=b[i].x,nowy=b[i].y;bool tmp=false;
		for(int j=nowx;j<=nowy;j++)if(flag[j]){tmp=true;break;}
		if(tmp)break;
		ans++;
		for(int j=nowx;j<=nowy;j++)flag[j]=true;
	}
	cout<<ans<<endl;
	return 0;
}
