#include<bits/stdc++.h>
using namespace std;

int n,ans;
int s[100005],t[100005];
stack<int>a;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		s[k]++;
		t[k]++;
	}
	
	for(int i=100000;i>=1;i--){
		if(s[i]!=0){
			a.push(i);
		}
	}
	int x=0,y=0;
	ans=n;
	while(!a.empty()){
		bool flag=true;
		x=a.top();
		y=0;
		a.pop();
		if(a.empty()){
		    break;
		}
		else{
			while(!s[a.top()]){
				a.pop();
			}
			if(!a.empty()){
				y=a.top();
				
				s[x]--;
			    t[x]--;
			    s[y]--;			
			    ans--;
			
			    if(t[x]==0)flag=false;
			}
		}
		if(flag==true)a.push(x);
	}
	cout<<ans;
	return 0;
} 
