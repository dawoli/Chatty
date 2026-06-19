#include<bits/stdc++.h>
#define M 214514
using namespace std;
string aa,bb,tta,ttb,ttaa,ttbb;
int ans,aal,bbl,dda,ddb;
unordered_map<string,int> mmp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>aa>>bb;
		aa=aa+bb;
		mmp[aa]=mmp[aa]+1;
	}
//	cout<<"setupdone\n";
	while(q--){
//		cout<<"QP "<<q<<"\n";
		ans=0;
		cin>>aa>>bb;
		aal=aa.length();
		if(aal!=bb.length()){
			cout<<"0\n";
			continue;
		}
		dda=ddb=-1;
		for(int i=0;i<aal;++i){
			if(aa[i]!=bb[i]){
				dda=i;
				break;
			}
		}
		for(int i=aal-1;i>=0;--i){
			if(aa[i]!=bb[i]){
				ddb=i;
				break;
			}
		}
		tta.clear();
		ttb.clear();
		ttaa.clear();
		ttbb.clear();
		if(dda!=-1){
			for(int i=dda;i<=ddb;++i){
				tta+=aa[i];
				ttb+=bb[i];
			}
			for(int i=dda;i>=0;--i){
				if(i!=dda){
					tta=aa[i]+tta;
					ttb=bb[i]+ttb;
				}
				ttaa=tta;
				ttbb=ttb;
				for(int j=ddb;j<aal;++j){
					if(j!=ddb){
						ttaa+=aa[j];
						ttbb+=bb[j];
					}
//					if(1){
//						cout<<sizeof(mmp)<<"\n";
//					}
					ans+=mmp[ttaa+ttbb];
				}
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}
