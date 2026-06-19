#include <bits/stdc++.h>
using namespace std;
int num[16],n;
bool color[16];
int sum=0;
int fc(int st,int end,bool d,bool o){
	if(st>=end) return 0;
	int cnt=0;
	for(int i=st;i<=end;i++){
		if(d){
			for(int j=i+1;j<=end;j++){
			if(num[i]==num[j]){
				sum=max(sum,fc(st,i,1,0)+fc(i+1,j-1,0,0)+fc(j+1,end,1,0)+num[i]);
			}
		}
	}
		else{
			if(num[i]==num[i+1]){
				cnt+=num[i];
			}
		}
	}
	
	if(!d&&num[st]==num[st+1]) cnt+=num[st];
	if(o) return sum;
	if(!d) return cnt;
	return 0;
}
int main(){
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++) cin>>num[i];
		cout<<fc(1,n,1,1)<<endl;
	}
	return 0; 
} 
