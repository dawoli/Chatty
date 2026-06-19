#include <bits/stdc++.h>
using namespace std;

int t,n,cnta,cntb,cntc,sum;
bool visa[100005],visb[100005],visc[100005];

struct node{
	int a,b,c;
}a[100005];

node num[100005],num1[100005],num2[100005];

bool cmp(int a,int b){
	return a>b;
}

bool cmp1(node a,node b){
	return a.a>b.a;
}

//void solve(){
//	for(int i=1;i<=n;i++){
//		cin>>a[i].a>>a[i].b>>a[i].c;
//		if(a[i].a>=a[i].b){
//			cnta++;
//		}else{
//			cntb++;
//		}
//		else if(a[i].c>=a[i].a&&a[i].c>=a[i].b){
//			cntc++;
//		}
//	}
//	int k=n/2;
//	if(cnta>k){
//		for(int i=1;i<=cnta;i++){
//			num[i]=a[i];
//		}
//		sort(num+1,num+cnta+1,cmp1);
//		
//	}
//	cout<<sum<<endl;
//	sum=0;
//	for(int i=1;i<=n;i++){
//		visa[i]=visb[i]=visc[i]=0;
//	}
//}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			cin>>a[1].a>>a[1].b>>a[1].c>>a[2].a>>a[2].b>>a[2].c;
			sum=max(max(a[1].a+a[2].b,a[1].b+a[2].a),max(max(a[1].a+a[2].c,a[1].b+a[2].c),max(a[1].c+a[2].a,a[1].c+a[2].b)));
			cout<<sum<<endl;
			sum=0;
			continue;
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>a[i].a>>a[i].b>>a[i].c;
			}
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				sum+=a[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				sum+=a[i].b;
			}
			cout<<sum<<endl;
			sum=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
