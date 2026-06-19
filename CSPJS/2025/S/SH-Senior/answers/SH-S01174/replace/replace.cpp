#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200009;
int s_b_front[N][3];
int s_left[N][3]; 
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string s1,s2;
		cin>>s1>>s2;
		s_b_front[i][1]=s1.find('b');
		s_left[i][1]=s1.size()-s_b_front[i][1]-1;
		s_b_front[i][2]=s2.find('b');
		s_left[i][2]=s2.size()-s_b_front[i][2]-1;
	}
	for(int i=1;i<=q;++i){
		string q1,q2;
		cin>>q1>>q2;
		int frnt1,frnt2,bck1,bck2;
		frnt1=q1.find('b');
		bck1=q1.size()-frnt1-1;
		frnt2=q2.find('b');
		bck2=q2.size()-frnt2-1;
		if(q1.size()!=q2.size()) cout<<0<<endl;
		else{
			int ans=0;
			for(int j=1;j<=n;++j){
				if(s_b_front[j][1]-s_b_front[j][2]==frnt1-frnt2){
					if(s_b_front[j][1]<=frnt1&&s_b_front[j][2]<=frnt2&&s_left[j][1]<=bck1&&s_left[j][2]<=bck2) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

