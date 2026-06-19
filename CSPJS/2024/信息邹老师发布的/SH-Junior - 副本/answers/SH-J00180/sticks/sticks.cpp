#include<bits/stdc++.h>
using namespace std;
int stk(int x,int ans){
	if(x<0||x==1) return -1;
	if(x==0) return ans;
	else if(x==2) return ans*10+1;
	else if(x==3) return ans*10+7;
	else if(x==4) return ans*10+4;
	else if(x==5) return ans*10+2;
	else if(x==6) return ans*10+6;
	else if(x==7) return ans*10+8;
	if(ans){
		if(x==0) return ans;
		else if(x>0) ans=stk(x-6,ans*10);
	}
	else ans=min(stk(x-2,1),stk(x-5,2));
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T=0,n=0;
	cin>>T;
	vector<int> m(T);
	for(int i=0;i<T;i++){
		cin>>n;
		if(n<2) m.at(i)=-1;
		else m.at(i)=stk(n,0);
	}
	for(int i=0;i<T;i++)
		cout<<m.at(i)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
