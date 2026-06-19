#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[200005],ans=0;
bool cer[2000005];
void bond(){
	
	int max=-1,tmp;
	bool l=false;
	for(int i=1;i<=n;++i){
		if(cer[i]==true){
			continue;
		}
		if(a[i]>max){
			max=a[i];
			tmp=i;
			l=true;
		}
		
	}
	if(l==false){
		return;
	}
	bool flag=false;
	for(int i=tmp+1;i<=n;++i){
		
		if(a[i]==max){
			flag=true;

			cer[i]=true;
			cer[tmp]=true;
			for(int j=tmp;j<=i;++j){
			}
			ans+=max;
		}
	}
	if(flag==false){
		cer[tmp]=true;
	}
	bond();
}
void doit(){
	ans=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		cer[i]=false;
	}
	bond();
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int w=1;w<=t;++w){
		doit();
	}
	return 0;
}
