#include <bits/stdc++.h>
using namespace std;
struct st{
	int a,b,c;
};

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int ans=0;
		st a[n];
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c; 
		}
		vector<st> aa,bb,cc;
		int siz[4];siz[1]=0;siz[2]=0;siz[3]=0;
		for(int i=0;i<n;i++){
			int f,s,t;
			if(max(max(a[i].a,a[i].b),a[i].c)==a[i].a){
				f=1;
				if(max(a[i].b,a[i].c)==a[i].b){
					s=2;t=3;
				}else{
					s=3;t=2;
				}
			}else if(max(max(a[i].a,a[i].b),a[i].c)==a[i].b){
				f=2;
				if(max(a[i].a,a[i].c)==a[i].a){
					s=1;t=3;
				}else{
					s=3;t=1;
				}
			}else{
				f=3;
				if(max(a[i].b,a[i].a)==a[i].b){
					s=2;t=1;
				}else{
					s=1;t=2;
				} 
			}
		//	cout<<f<<" "<<s<<" "<<t<<endl;
			if(siz[f]+1<=n/2){
				siz[f]++;
				if(f==1) aa.push_back(a[i]),ans+=a[i].a;
				else if(f==2) bb.push_back(a[i]),ans+=a[i].b;
				else cc.push_back(a[i]),ans+=a[i].c;
		//		cout<<"log:input"<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<endl;
			}else{
				if(f==1){
					int maxn=0;
					int d=-1;
					for(int j=0;j<aa.size();j++){
						int o=maxn;
						maxn=max(maxn,a[i].a-aa[j].a+max(aa[j].b,aa[j].c));
						if(maxn!=o){
							d=j;
						}
					}
					if(d==-1||maxn<max(a[i].b,a[i].c)){
						if(s==2) bb.push_back(a[i]),ans+=a[i].b,siz[2]++;
						if(s==3) cc.push_back(a[i]),ans+=a[i].c,siz[3]++;
		//				cout<<"log:sec"<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<" "<<ans<<endl;
					}else{
	//					cout<<"log:rep"<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<endl;
						if(aa[d].b>=aa[d].c){
							ans+=a[i].a;
							ans-=aa[d].a;
							ans+=aa[d].b;
							bb.push_back(aa[d]);
							aa[d].a=a[i].a;
							aa[d].b=a[i].b;
							aa[d].c=a[i].c;
							siz[2]++;
						}else{
							ans+=a[i].a;
							ans-=aa[d].a;
							ans+=aa[d].c;
							cc.push_back(aa[d]);
							aa[d].a=a[i].a;
							aa[d].b=a[i].b;
							aa[d].c=a[i].c;
							siz[3]++;
						}
					}
				}else if(f==2){
					int maxn=0;
					int d=-1;
					for(int j=0;j<bb.size();j++){
		//				cout<<"comp:"<< a[i].b-bb[j].b+max(bb[j].a,bb[j].c)-max(a[i].a,a[i].c)<<endl;
						int o=maxn;
						maxn=max(maxn,a[i].b-bb[j].b+max(bb[j].a,bb[j].c));
						if(maxn!=o){
							d=j;
						}
					}
					if(d==-1||maxn<max(a[i].c,a[i].a)){
						if(s==1) aa.push_back(a[i]),ans+=a[i].a,siz[1]++;
						if(s==3) cc.push_back(a[i]),ans+=a[i].c,siz[3]++;
		//				cout<<"log:sec"<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<" "<<ans<<endl;
					}else{
		//				cout<<"log:rep"<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<endl;
						if(bb[d].a>=bb[d].c){
							ans+=a[i].b;
							ans-=bb[d].b;
							ans+=bb[d].a;
							aa.push_back(bb[d]);
							bb[d].a=a[i].a;
							bb[d].b=a[i].b;
							bb[d].c=a[i].c;
							siz[1]++;
						}else{
							ans+=a[i].b;
							ans-=bb[d].b;
							ans+=bb[d].c;
							cc.push_back(bb[d]);
							bb[d].a=a[i].a;
							bb[d].b=a[i].b;
							bb[d].c=a[i].c;
							siz[3]++;
						}
					} 
				}else{
					int maxn=0;
					int d=-1;
					for(int j=0;j<cc.size();j++){
						int o=maxn;
						maxn=max(maxn,a[i].c-cc[j].c+max(cc[j].b,cc[j].a));
						if(maxn!=o){
							d=j;
						}
					}
					if(d==-1||maxn<max(a[i].b,a[i].a)){
						if(s==1) aa.push_back(a[i]),ans+=a[i].a,siz[1]++;
						if(s==2) bb.push_back(a[i]),ans+=a[i].b,siz[2]++;
		//				cout<<"log:sec"<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<endl; 
					}else{
		//				cout<<"log:rep"<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<"to"<<cc[d].a<<" "<<cc[d].b<<" "<<cc[d].c<<endl;
						if(cc[d].a>=cc[d].b){
							ans+=a[i].c;
							ans-=cc[d].c;
							ans+=cc[d].a;
							aa.push_back(cc[d]);
							cc[d].a=a[i].a;
							cc[d].b=a[i].b;
							cc[d].c=a[i].c;
							siz[1]++;
						}else{
							ans+=a[i].c;
							ans-=cc[d].c;
							ans+=cc[d].b;
							bb.push_back(cc[d]);
							cc[d].a=a[i].a;
							cc[d].b=a[i].b;
							cc[d].c=a[i].c;
							siz[2]++;
						}
					}
				}	
			}	
		//	cout<<"nowans:"<<ans<<endl;
		}
		cout<<ans<<endl;
	}
}
