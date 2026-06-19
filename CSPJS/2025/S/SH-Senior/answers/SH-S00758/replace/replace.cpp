#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;

int n, q, b1[N], b2[N], sz[N];
string s1[N], s2[N], t1, t2;
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	if(n<=100){
		for(int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
		}
		while(q--){
			cin>>t1>>t2;
			int cnt=0, len=t1.size();
			for(int i=1;i<=n;i++){
				for(int st=0;st+s1[i].size()<=len;st++){
					if(t1.substr(st, s1[i].size())==s1[i]){
						string tmp="";
						tmp+=t1.substr(0, st);
//						cout<<tmp<<endl;
						tmp+=s2[i];
//						cout<<tmp<<endl;
						tmp+=t1.substr(s1[i].size()+st, len-s1[i].size()-st);
//						cout<<tmp<<endl;
//						cout<<endl;
						if(tmp==t2)cnt++;
					}
				}
			}
			cout<<cnt<<endl;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
			sz[i]=s1[i].size();
			for(int j=0;j<s1[i].size();j++){
				if(s1[i][j]=='b')b1[i]=j+1;
				if(s2[i][j]=='b')b2[i]=j+1;
			}
			s1[i]=" "+s1[i];
			s2[i]=" "+s2[i];
		}
		while(q--){
			cin>>t1>>t2;
			int len=t1.size();
			if(len!=t2.size()){
				cout<<"0\n";continue;
			}
			t1=" "+t1;t2=" "+t2;
			int cnta=0, cntb=0, pos1=0, pos2=0;bool flag=0;
			for(int i=1;i<=len;i++){
				if(t1[i]=='a')cnta++;
				else if(t1[i]=='b')cntb++, pos1=i;
				if(t2[i]=='a')cnta++;
				else if(t2[i]=='b')cntb++, pos2=i;
			}
			if(cnta+cntb!=len*2||cntb!=2){
				cout<<"0\n";continue;
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				int lsz1=b1[i]-1, rsz1=sz[i]-b1[i];
				int lsz2=b2[i]-1, rsz2=sz[i]-b2[i];
//				cout<<n<<' '<<pos1<<' '<<pos2<<' '<<lsz1<<' '<<rsz1<<' '<<lsz2<<' '<<rsz2<<endl;
				if(pos1>=lsz1&&pos2>=lsz2&&len-pos1>=rsz1&&len-pos2>=rsz2){
					if(pos1-b1[i]+b2[i]==pos2&&pos1-b1[i]>=0&&pos2-b2[i]>=0)ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
