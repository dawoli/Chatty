#include <bits/stdc++.h>
using namespace std;
int a[100100];
vector<int> v;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int cnt=1;
	int xb=0;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			cnt++;
			if(!v.empty()){
				while(xb!=-1&&v[xb]==0)xb--;
				if(xb!=-1)v[xb]--;
				
			}
		}
		else{
			v.push_back(cnt);
			cnt=1;
			xb=v.size()-1;
			while(v[xb]==0)xb--;
			if(xb!=-1)v[xb]--;
		}
//		printf("debugstart\n");
//		for(int i=0;i<v.size();i++){
//			printf(" %d",v[i]); 
//		}
//		printf("\ndebugend\n");
	} 
	
	v.push_back(cnt);
	long long ans=0;
	for(int i=0;i<v.size();i++){
		ans+=v[i];
	}
	printf("%lld\n",ans);
	return 0;
}
