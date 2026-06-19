#include <bits/stdc++.h>
using namespace std;

int n,r[100005],ans;
bool vis[100005];
vector<int> v;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		v.push_back(r[i]);
	}
	sort(r+1,r+n+1);
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++){
		int l=0,ri=n-1,mid;
		bool flag=false;
		while(l<=ri){
			mid=(l+ri)/2;
			if(v[mid]>r[i]){
				flag=true;
				break;
			}else{
				l=mid+1;
			}
		}
		if(!flag){
			ans++;
			continue;
		}
		v[mid]=0;
		vis[mid]=true;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
