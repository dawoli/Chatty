#include<bits/stdc++.h>
using namespace std;
struct N{
	int a,b,c,sum;
};
N ar[100010];
bool cmp(N a,N b){
	return a.sum>b.sum;
}
void sort111(int& a,int& b,int& c){
	if(a<b) swap(a,b);
	if(a<c) swap(a,c);
	if(b<c) swap(b,c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,a,b,c;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			ar[i].a=a,ar[i].b=b,ar[i].c=c;
			sort111(a,b,c);
			ar[i].sum=a-b;
		}
		sort(ar+1,ar+n+1,cmp);
		int ans=0,cnta=0,cntb=0,cntc=0;
		for(int i=1;i<=n;i++){
			a=ar[i].a,b=ar[i].b,c=ar[i].c;
			int maxa=0;
			if(a>=b&&a>=c)
				maxa=1;
			else if(b>=a&&b>=c)
				maxa=2;
			else 
				maxa=3;
			if(maxa==1){
				if(cnta>=n/2)
					ans+=max(b,c);
				else{
					ans+=a,cnta++;
				}
			}
			else if(maxa==2){
				if(cntb>=n/2)
					ans+=max(a,c);
				else{
					ans+=b,cntb++;
				}				
			}
			else{
				if(cntc>=n/2)
					ans+=max(b,a);
				else{
					ans+=c,cntc++;
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
