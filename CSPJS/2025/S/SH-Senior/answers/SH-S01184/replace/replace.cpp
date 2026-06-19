#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,q,ans;
string ta,tb;
struct abc{
	string a,b;
}s[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i].a>>s[i].b;
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>ta>>tb;
		for(int j=1;j<=n;j++){
			int c=s[j].a.size(),v=ta.size();
			for(int k=0;k<=v-c;k++){
				if(ta.substr(k,c)==s[j].a && tb.substr(k,c)==s[j].b && 
				ta.substr(0,k)==tb.substr(0,k) && ta.substr(k+c,v-k-c)==tb.substr(k+c,v-k-c))
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
