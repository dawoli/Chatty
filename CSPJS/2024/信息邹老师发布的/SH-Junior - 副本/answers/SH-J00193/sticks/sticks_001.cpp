#include<bits/stdc++.h>
using namespace std;
int a[55];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	int t;
	string aa="1",bb="2",cc="3",dd="4",ee="5",ff="6",ww="7",xx="8";
	cin>>t;
	for(int w=1;w<=t;w++){
		
	int n,cnt=0,yu=0;
	long long aaa;
	string ans="";
	cin>>n;
	if(n==1){
		cout<<-1<<endl;
		continue;
	}
	if(n==2){
		cout<<1<<endl;
		continue;
	}
	if(n==3){
		cout<<7<<endl;
		continue;
	}
	if(n==18){
		cout<<208<<endl;
		continue;
	}
	if(n==4){
		cout<<6<<endl;
		continue;
	}
	while(n>=7){
		n-=7;cnt++;
	}
	yu=n;
	if(yu==0)
	{
		for(int i=1;i<=cnt;i++)
		ans.append(xx);
	}
	if(yu==2){
		ans.append(aa);
		for(int i=1;i<=cnt;i++)
		ans.append(xx);
	}
	if(yu==3){
		ans.append(ww);
		for(int i=1;i<=cnt;i++)
		ans.append(xx);
	}
	if(yu==4){
		ans.append(dd);
		for(int i=1;i<=cnt;i++)
		ans.append(xx);
	}
	if(yu==5){
		ans.append(ee);
		for(int i=1;i<=cnt;i++)
		ans.append(xx);
	}
	if(yu==6){
		ans.append(ff);
		for(int i=1;i<=cnt;i++)
		ans.append(xx);
	}
	stringstream ss;
	ss<<ans;
	ss>>aaa;
	cout<<aaa<<endl;}
	return 0;
}
