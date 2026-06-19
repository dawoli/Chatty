#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
long long tong[2000005],a[2000005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(tong,0,sizeof(tong));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			tong[a[i]]++;
		}
		stack<int>s1;
		stack<int>s2;
		for(int i=1;i<=n;i++){
			if(tong[a[i]]>1){
				if(!s1.empty() && s1.top()==a[i]){
					ans+=a[i];
					s1.pop();
					tong[a[i]]--;
					if(tong[a[i]]>1 && s1.empty() ){
						s1.push(a[i]);
					}
				}else if(!s2.empty() && s2.top()==a[i]){
					ans+=a[i];
					s2.pop();
					tong[a[i]]--;
					if(tong[a[i]]>1 && s2.empty()){
						s2.push(a[i]);
					}	
				}else if(!s1.empty() && !s2.empty() && a[i]>=s1.top() ){
					tong[s1.top()]--;
					s1.pop();
					s1.push(a[i]);
				}else if(!s1.empty() && !s2.empty() && a[i]>=s2.top() ){
					tong[s2.top()]--;
				
					s2.pop();
					s2.push(a[i]);
				}else{
					if(s1.empty()){
						s1.push(a[i]);
					}else if(s2.empty()){
						s2.push(a[i]);
					}	
				}
			}else if(!s1.empty() && !s2.empty()){
				if(s1.top()<=s2.top()){
					tong[s1.top()]--;
					s1.pop();
				}else{
					tong[s2.top()]--;
					s2.pop();
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
