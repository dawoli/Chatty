#include<bits/stdc++.h>
using namespace std;
int n,m,id,pos,x,y;
int a[110];
vector<int> ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	id=a[1];
	for(int i=1;i<=n*m;i++){
		ans.push_back(a[i]);
	}
	sort(ans.begin(),ans.end());
	for(int i=n*m;i>=1;i--){
		if(ans[i]==id){
			pos=i;
		}
	}
	int k=ans.size();
	pos=k-pos;
	if(int(pos*1.0/m)%2){
		if(int(pos*1.0/m)*m==pos){
			x=n;
			y=pos/m;
		}else{
			x=n-(pos-(int(pos*1.0/m)*m))+1;
			y=pos/m+1;
		}
	}else{
		if(int(pos*1.0/m)*m==pos){
			x=1;
			y=pos/m;
		}else{
			x=(pos-(int(pos*1.0/m)*m));
			y=pos/m+1;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}

