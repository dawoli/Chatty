#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[100010];
bool s[100005];
vector<int> num;


void duel(){
	int m=num.size();
	for(int i=1;i<m;++i){
		if(num[i]>=num[i-1]){
			ans-=num[i-1];
		}else{
			ans-=num[i];
			int gap=num[i-1]-num[i];
			num[i]+=gap;
		}
		
	}
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout); 
	cin>>n;
	
	
	
	ans=n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=true;
	}
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	int k=a[1],cnt=1;
	for(int i=2;i<=n;++i){
		if(k==a[i]){
			cnt++;
		}else{
			num.push_back(cnt);
			
			k=a[i];
			cnt=1;
		}
	}
	num.push_back(cnt);
	int m=num.size();


	duel();
	
	cout<<ans<<endl;
	return 0;
}
