#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
string s[N],p[N];
string pre[N],lst[N];
ll n,q,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	//cout<<n<<q;
	for(int i=1;i<=n;i++) cin>>s[i]>>p[i];
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		string cnt="";
		for(int j=0;j<a.size();j++){
			if(j==0) pre[j]=a[j];
			else pre[j]=pre[j-1]+a[j];
		}
		lst[a.size()]="";
		for(int j=a.size()-1;j>=0;j--){
			lst[j]=a[j]+lst[j+1];
		}
		for(int j=0;j<a.size();j++){
			cnt="";
			for(int k=j;k<a.size();k++){
				cnt+=a[k];
				for(int t=1;t<=n;t++){
					//cout<<cnt<<endl;
					if(cnt==s[t]){
						string check="";
						if(j-1>=0) check+=pre[j-1];
						check+=p[t];  
						check+=lst[k+1];
						//cout<<check<<" "<<b<<endl; 
						if(check==b) ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
