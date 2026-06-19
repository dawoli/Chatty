#include<bits/stdc++.h>
#include<map>
using namespace std;
const int MAXN=1e5+5;
long long T;
void solve(){
	map<long long,long long> M1,M2;
	long long ans1=0,ans2=0;
	long long n,m,L,V;
	cin>>n>>m>>L>>V;
	long long d[MAXN],v[MAXN],a[MAXN]; 
	for(long long i=1;i<=n;i++)
		cin>>d[i]>>v[i]>>a[i];
	for(long long i=1;i<=m;i++){
		long long p;
		cin>>p;
		M1[p]=0;
		M2[p]=0;
	}
	for(long long i=1;i<=n;i++){
		double buff=(V*V-v[i]*v[i])/(2.0*a[i]);
		if(a[i]>0){
			long long d1=d[i]+(long long)buff;
			auto it1=M1.upper_bound(d1);
			if(it1!=M1.end()) it1->second++,ans1++; 
		}
		else if(a[i]==0){
			if(v[i]>V){
				auto it2=M1.lower_bound(d[i]);
				if(it2!=M1.end()) it2->second++,ans1++;
			}
		}
		else{
			if(v[i]>V){
				long long d2=d[i]+(long long)buff;
				auto it3=M1.lower_bound(d[i]);
				auto it4=M2.lower_bound(d2);
				if(it3!=it4){
					ans1++;
					it3->second++;
					it4->second--;					
				} 
			}
			
		}
	}
	bool flag=1;
	for(auto it1=M1.begin(),it2=M2.begin();it1!=M1.end();it1++,it2++){
		if(it2->second<0) flag=1;
		if(it1->second>0 && flag){
			ans2++;
			flag=0;
		}
		cout<<it1->second<<' '<<it2->second<<endl;
	}
	cout<<ans1<<' '<<n-ans2<<endl;
	return; 
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
