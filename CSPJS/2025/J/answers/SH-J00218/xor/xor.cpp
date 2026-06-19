#include<bits/stdc++.h> 
using namespace std;
int a[1005],b[1005];
struct two{
	int l;
	int r; 
};
two p[1000005];
bool cmp(two mm,two nn){
	if(mm.l<nn.l)return 1;
	if(mm.l>nn.l)return 0;
	else return mm.r<nn.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,cnt=0,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){	
			if((b[j]^b[i-1])==k){
				cnt++;
				p[cnt].l=i;
				p[cnt].r=j;
				
			}
		}
	}
	sort(p+1,p+1+cnt,cmp);
	int now=1,nnn=1;
	while(now<=n){
		for(int i=nnn;i<=cnt;i++){
			if(p[i].l>=now){
				now=p[i].r+1;
				sum++;
				nnn=i;
				break;
			}
		}
	}cout<<sum;
	return 0;
}
