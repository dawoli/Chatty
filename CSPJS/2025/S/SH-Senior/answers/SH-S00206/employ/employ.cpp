#include<iostream>
using namespace std;
long long n,m;
string s;
long long c[505];
const long long N=998244353;
bool A=1;
bool ch[505];
int a[505];
int ans=0;
bool judge(){
	int ca=0;
	int gv=0;
	for(int i=1;i<=n;i++){
		if(c[a[i]]<=gv){
			gv++;
		} 
		else if(s[i-1]=='1'){
			ca++;
		}
		else if(s[i-1]=='0'){
			gv++;
		}
	}
	return ca>=m;
}
void dfs(int d){
	if(d>n){
		if(judge()){
			ans++;
		} 
//		for(int i=1;i<=n;i++){
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!ch[i]){
			a[d]=i;
			ch[i]=1;
			dfs(d+1);
			a[d]=0;
			ch[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			A=0;
		}
	}
	if(A){
		
	}
	else{
		dfs(1);
		cout<<ans;
	}
	return 0;
} 
