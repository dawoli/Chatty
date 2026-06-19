#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long t,n,ans;
long long ggg[N],hidx;
struct node{
	long long a[4];
	long long maxa,id,cha=INT_MAX;
}man[N];
struct fuck{
	long long type;
	long long delta[N];
	long long idx;
}wtf[4];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	//取消注释!!!!!!!!
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//取消注释!!!!!!!!
	cin>>t;
	for(int kkk=1;kkk<=t;kkk++){
		n=0;
		ans=0;
		for(int i=1;i<=3;i++){
			memset(man[i].a,0,sizeof(man[i].a));
			man[i].cha=0;
			man[i].id=0;
			man[i].maxa=0;
		}
		for(int i=1;i<=3;i++){
			memset(wtf[i].delta,0,sizeof(wtf[i].delta));
			wtf[i].idx=0;
			wtf[i].type=0;
		}
		memset(ggg,0,sizeof(ggg));
		cin>>n;
		for(int i=1;i<=n;i++){
//			cout<<"man";
			cin>>man[i].a[1]>>man[i].a[2]>>man[i].a[3];
			man[i].maxa=max(man[i].a[1],max(man[i].a[2],man[i].a[3]));
			
			if(man[i].maxa==man[i].a[1]){
				wtf[1].idx++;
				wtf[1].delta[wtf[1].idx]=i;
				man[i].id=1;
				man[i].cha=man[i].maxa-max(man[i].a[2],man[i].a[3]);
			}else if(man[i].maxa==man[i].a[2]){
				wtf[2].idx++;
				wtf[2].delta[wtf[2].idx]=i;
				man[i].id=2;
				man[i].cha=man[i].maxa-max(man[i].a[1],man[i].a[3]);
			}else{//man[i].maxa==man[i].a[3]
				wtf[3].idx++;
				wtf[3].delta[wtf[3].idx]=i;
				man[i].id=3;
				man[i].cha=man[i].maxa-max(man[i].a[1],man[i].a[2]);
			}
			ans+=man[i].maxa;
		}
//		cout<<"kao";
		wtf[1].type=1;
		wtf[2].type=2;
		wtf[3].type=3;
		
		if(wtf[1].idx<wtf[3].idx){
			swap(wtf[1],wtf[3]);
		}
		if(wtf[1].idx<wtf[2].idx){
			swap(wtf[1],wtf[2]);
		}
		if(wtf[2].idx<wtf[3].idx){
			swap(wtf[2],wtf[3]);
		}
//		cout<<"fa";
		if(wtf[1].idx<=n/2){
//			cout<<"manbooooo";
			cout<<ans<<"\n";
			continue;
		}
		for(int i=n;i>=1;i--){
			if(man[i].id==wtf[1].type){
				hidx++;
				ggg[hidx]=man[i].cha;
			}
		}
//		if(kkk==2){
//			cout<<"\nvvvvvvvvvvv\n";
//			for(int jj=1;jj<=hidx;jj++){
//				cout<<ggg[jj]<<" ";
//			}
//			cout<<"\nvvvvvvvvvvv\n";
//		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(ggg[i]>ggg[j]){
					swap(ggg[i],ggg[j]);
				}
			}
		}
//		if(kkk==2){
//			cout<<"\nvvvvvvvvvvv\n";
//			for(int jj=1;jj<=hidx;jj++){
//				cout<<ggg[jj]<<" ";
//			}
//			cout<<"\nvvvvvvvvvvv\n";
//		}
		for(int i=wtf[1].idx;i>n/2;i--){
			ans-=ggg[wtf[1].idx-i+1];
		}
		cout<<ans<<"\n";
//		if(kkk==2){
//			cout<<"//////////\n";
//			for(int k=1;k<=n;k++){
//				for(int i=1;i<=3;i++){
//					cout<<man[k].a[i]<<" ";
//				}
//				cout<<"\n"<<man[k].cha<<"\n"<<man[k].id<<"\n"<<man[k].maxa<<"\n//////////\n";
//			}
//			for(int k=1;k<=3;k++){
//				for(int i=1;i<=wtf[k].idx;i++){
//					cout<<wtf[k].delta[i]<<" ";
//				}
//				cout<<"\n";
//				cout<<wtf[k].idx<<" "<<wtf[k].type<<"\n////////manbaout!!!!\n";
//			}
//			for(int jj=1;jj<=hidx;jj++){
//				cout<<ggg[jj]<<" ";
//			}
//			cout<<"\nvvvvvvvvvvv\n";
//		}
//		cout<<"cao";
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
