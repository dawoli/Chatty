#include<iostream>
using namespace std;
const int MAXN=1e5+5;
int n; 
int a[10]={6,2,5,5,4,5,6,3,7,6};
string dp[MAXN];
void solve(){
	cin>>n;
	if(n==1){
		cout<<-1<<endl;
	}else{
		cout<<dp[n]<<endl;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	dp[0]="";
	string temp;
	for(int i=2;i<MAXN;i++){
		for(int j=0;j<9;j++){
			if(i<a[j]||i-a[j]==1){
				continue;
			}
			temp=dp[i-a[j]];
			temp.push_back(j+'0');
			if(temp[0]=='0'){
				continue;
			}
			if(dp[i]==""){
				dp[i]=temp;
			}else{
				if(dp[i].length()>temp.length()){
						dp[i]=temp;
				}else if(dp[i].length()==temp.length()){
					if(dp[i]>temp){
						dp[i]=temp;
					}
				}
			}
		}
//		cout<<i<<" "<<dp[i]<<endl;
	}
	cin>>T;
//	cout<<"%%%"<<T<<endl;
	while(T--){
		solve();
	}
	return 0;
}
