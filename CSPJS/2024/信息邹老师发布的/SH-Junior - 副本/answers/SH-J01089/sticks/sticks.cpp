#include <bits/stdc++.h>
using namespace std;
long long answer[51]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,0,0,0,2888888,6888888,10888888};
string com(string y,string z){
	for(int i=0;i<y.size();i++){
		if(y[i]<z[i]) return y;
		if(z[i]<y[i]) return z;
	}
	return y;
}
string f(int x,int num){
	string ans1="",ans2="",ans3="",ans4="",ans5="",ans6="";
	if(x==0) return ans1;
	if(x==1) return "dddddddd";
	if(x>=7){
		ans1+="8";
		ans1+=f(x-7,num+1);
	}
	if(x>=6){
		if(num!=1) ans2+="0";
		else ans2+="6";
		ans2+=f(x-6,num+1);
	}
	if(x>=5){
		ans3+="2";
		ans3+=f(x-5,num+1);
	}
	if(x>=4){
		ans4+="4";
		ans4+=f(x-4,num+1);
	}
	if(x>=3){
		ans5+="7";
		ans5+=f(x-3,num+1);
	}
	ans6+="1";
	ans6+=f(x-2,num+1);
	string mins="999999999999";
	if(ans1.size()<mins.size()&&ans1.size()) mins=ans1;
	if(ans2.size()<mins.size()&&ans2.size()) mins=ans2;
	if(ans3.size()<mins.size()&&ans3.size()) mins=ans3;
	if(ans4.size()<mins.size()&&ans4.size()) mins=ans4;
	if(ans5.size()<mins.size()&&ans5.size()) mins=ans5;
	if(ans6.size()<mins.size()&&ans6.size()) mins=ans6;
	if(ans1.size()==mins.size()) mins=com(mins,ans1);
	if(ans2.size()==mins.size()) mins=com(mins,ans2);
	if(ans3.size()==mins.size()) mins=com(mins,ans3);
	if(ans4.size()==mins.size()) mins=com(mins,ans4);
	if(ans5.size()==mins.size()) mins=com(mins,ans5);
	if(ans6.size()==mins.size()) mins=com(mins,ans6);
	for(int i=0;i<mins.size();i++){
		if (mins[i]=='d') return "dddddddd";
	}
	return mins;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<=50){
			cout<<answer[n]<<endl;
			continue;
		}
		if(n%7==0){
			int k=n/7;
			for(int i=1;i<=k;i++) cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==1){
			int k=n/7;
			cout<<10;
			for(int i=1;i<k;i++) cout<<8;
			cout<<endl;
			continue;
		}
		
		string ans=f(n,1);
		for(int i=0;i<ans.size();i++){
			if(ans[i]=='d'){
				cout<<-1<<endl;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
