#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> m;
pair<string,string> a[200005];
string t1,t2;
int ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>t1>>t2;
		a[i]=make_pair(t1,t2);
	}
	for(int i=0;i<q;i++){
		cin>>t1>>t2;
		ans=0;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			//cout<<a[i].first<<' '<<a[i].first.size()<<' '<<t1.size()<<endl;
			if(t1.size()>=a[i].first.size())
				for(int j=0;j<=t1.size()-a[i].first.size();j++){
					if(j>0&&t1[j-1]!=t2[j-1]) break;
					//cout<<j<<' '<<t1[j-1]<<' '<<t2[j-1]<<endl;
					bool f=1;
					for(int k=j;k<j+a[i].first.size();k++){
						if(t1[k]!=a[i].first[k-j]){
							f=0;
							break;
						}
					}
					
					if(f==1){
						//cout<<"!"<<j<<endl;
					    int k=j;
						for(;k<j+a[i].second.size();k++)
							if(a[i].second[k-j]!=t2[k]){
								f=0;
								break;
							}
		                if(f==0) continue;
		                for(k;k<t2.size();k++)
		                	if(t1[k]!=t2[k]){
		                		f=0;
		                		break;
							}
		                if(f==1) ans++;
					}
				}
		}
			
		cout<<ans<<endl; 
	} 
	return 0;
}
