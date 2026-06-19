#include<bits/stdc++.h>
using namespace std;
//si ren bang,dou shi huai dongxi!!
//pantu tewu yexinjia dajunfa 

//const int LUOGU=909552;

char s[1000010];int uu[1000010],cu=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//froepen("number.out","w",stdout);
	//froepen
	//rp++
	//slove()
	//mian
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	int us=strlen(s);
	sort(s,s+us);
	for(int i=us-1;i>=0;i--){
		if(s[i]>='0'&&s[i]<='9')cout<<s[i];
	}
	return 0;
} 
