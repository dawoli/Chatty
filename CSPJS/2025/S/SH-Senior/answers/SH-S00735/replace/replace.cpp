#include <bits/stdc++.h>
using namespace std;
int n,q,at,bt,ans,t;
string qsa,qsb,keya,keyb,rep[200005][2];
bool dif[5000005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>rep[i][0]>>rep[i][1];
	}
	for (int x=1;x<=q;x++){
		ans=0;
		cin>>qsa>>qsb;
		if (qsa.length()!=qsb.length()){  //长度不同直接不行 
			cout<<"0"<<endl;
			continue;
		}
		//特殊性质B 
		t=0;
		while (1){  // 找到qsa中"b"的位置 
			if (qsa[t]=='b'||t==qsa.length()){
				at=t;
				break;
			}
			t++;
		}
		t=0;
		while (1){  // 找到qsb中"b"的位置 
			if (qsb[t]=='b'||t==qsb.length()){
				bt=t;
				break;
			}
			t++;
		}
		keya="b";
		for (int i=1;i<=abs(bt-at);i++){
			keya+='a';
			keyb+='a';
		}
		keyb+='b';
		if (at<bt){
			for (int i=1;i<=n;i++){
				if (-1<int(qsa.find(rep[i][0]))&&qsa.find(rep[i][0])<qsa.length()&&-1<int(qsb.find(rep[i][1]))&&qsb.find(rep[i][1])<qsb.length()&&-1<int(rep[i][0].find(keya))&&rep[i][0].find(keya)<rep[i][0].length()&&-1<int(rep[i][1].find(keyb))&&rep[i][1].find(keyb)<rep[i][1].length()){
					ans++;
				}
			}
		}
		else {
			for (int i=1;i<=n;i++){
				if (-1<int(qsa.find(rep[i][0]))&&qsa.find(rep[i][0])<qsa.length()&&-1<int(qsb.find(rep[i][1]))&&qsb.find(rep[i][1])<qsb.length()&&-1<int(rep[i][0].find(keyb))&&rep[i][0].find(keyb)<rep[i][0].length()&&-1<int(rep[i][1].find(keya))&&rep[i][1].find(keya)<rep[i][1].length()){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
