#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],pre[500005],ans,cnt,now;
struct node{
	int start,end;
}p[500005];
bool cmp(node a1,node a2){
	return a1.start<a2.start ||  a1.start==a2.start && a1.end<a2.end; 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		pre[i]=a[i];
	}
	for(int i=1;i<=n;i++) {
		pre[i]^=pre[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int t=pre[i-1];
			t^=pre[j];
			if(t==k)
			{
				cnt++;
				p[cnt].start=i;
				p[cnt].end=j;
				//cout<<i<<' '<<j<<endl;
				//ans++;
				//i=j;
				break;	
			}
		}
	}
	sort(p+1,p+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(p[i].start<now&&p[i].end<now){
			now=p[i].end;
		} 
		if(p[i].start>now) 
		{
			now=p[i].end;
			ans++;
		}
	}
	/*for(int i=1;i<=cnt;i++){
		cout<<p[i].start<<" "<<p[i].end<<endl;
	}*/
	cout<<ans<<endl;
	return 0;
} 
/*
4 0 
2 1 0 3
*/ 
