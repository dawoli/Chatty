#include<bits/stdc++.h>
using namespace std;
struct stu{
	int o,tw,th,id;
	int cha;
}a[100005];
int pa[100005],pb[100005],pc[100005];
int main(){
	 freopen("club.in","r",stdin);
	 freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int ans=0;
		int n;
		cin>>n;
		
		int cnta=0,cntb=0,cntc=0,summax=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].o>>a[i].tw>>a[i].th;
			a[i].id=n;
			if(a[i].o>=a[i].tw&&a[i].o>=a[i].th){
				cnta++;
				summax+=a[i].o;
				if(a[i].tw>=a[i].th){a[i].cha=a[i].o-a[i].tw;pa[cnta]=a[i].cha;}
				if(a[i].th>=a[i].tw){a[i].cha=a[i].o-a[i].th;pa[cnta]=a[i].cha;}
			}
			if(a[i].tw>=a[i].o&&a[i].tw>=a[i].th){
				cntb++;
				summax+=a[i].tw;
				if(a[i].o>=a[i].th){a[i].cha=a[i].tw-a[i].o;pb[cntb]=a[i].cha;}
				if(a[i].th>=a[i].o){a[i].cha=a[i].tw-a[i].th;pb[cntb]=a[i].cha;}
			}
			if(a[i].th>=a[i].o&&a[i].th>=a[i].tw){
				cntc++;
				summax+=a[i].th;
				if(a[i].o>=a[i].tw){a[i].cha=a[i].th-a[i].o;pc[cntc]=a[i].cha;}
				if(a[i].tw>=a[i].o){a[i].cha=a[i].th-a[i].tw;pc[cntc]=a[i].cha;}
			}
		}
//		cout<<"sum"<<summax<<endl;
//		cout<<"cha"<<a[1].cha<<" "<<a[2].cha<<endl;
//		if(n==2){cout<<max(a[1].o+a[2].tw,max(a[1].o+a[2].th,max(a[1].tw+a[2].o,max(a[1].tw+a[2].th,max(a[1].th+a[2].o,a[1].th+a[2].tw)))))<<endl;continue;}
//		cout<<cnta<<" "<<cntb<<" "<<cntc<<endl;
//		for(int i=1;i<=cntc;i++){
//			cout<<pc[i]<<" ";
//		}
//		cout<<endl;
		if(cnta>n/2){
			int cra=0;
			int p=cnta-n/2;
//			cout<<"p="<<p<<endl;
			sort(pa+1,pa+cnta+1);
//			cout<<"pa1="<<pa[1];

		
			for(int i=1;i<=p;i++){
				cra+=pa[i];
			}
//			cout<<"cra="<<cra<<endl;
			ans=summax-cra;
//			cout<<"ans="<<ans<<endl;
		}
		if(cntb>n/2){
			int crb=0;
			int p=cntb-n/2;
			sort(pb+1,pb+cntb+1);
			for(int i=1;i<=p;i++){
				crb+=pb[i];
			}
			ans=summax-crb;
		}
		if(cntc>n/2){
			int crc=0;
			int p=cntc-n/2;
			sort(pc+1,pc+cntc+1);
			for(int i=1;i<=p;i++){
				crc+=pc[i];
			}
			ans=summax-crc;
		}
		if(cnta<=n/2&&cntb<=n/2&&cntc<=n/2){
			ans=summax;
		}
		cout<<ans<<endl;
	} 
	return 0;
}
