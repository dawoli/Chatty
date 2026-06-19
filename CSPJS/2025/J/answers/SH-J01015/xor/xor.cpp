#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
int n,k;
int a[500005],b[500005];
struct hege{
	int start,end;
}h[600505];
bool cmp(hege x,hege y){
	return x.end<y.end;
}
int main(){
	//½â×¢ÊÍ£¡£¡£¡£¡£¡£¡£¡ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
		//cout<<b[i]<<" ";
	}
	int good=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[i-1]^b[j])==k){
				h[good].start=i;h[good].end=j;
				good++;
			}
		}
	}
	/*for(int i=0;i<good;i++){
    	printf("%d %d\n",h[i].start,h[i].end);
	}*/
	sort(h,h+good,cmp);
	int ans=0,nowend=-1;
	for(int i=0;i<good;i++){
		if(nowend<h[i].start){
		nowend=h[i].end;
		ans++;
	    }
	}
	cout<<ans;
	return 0;
}
/*
4 3
2 1 0 3
*/
