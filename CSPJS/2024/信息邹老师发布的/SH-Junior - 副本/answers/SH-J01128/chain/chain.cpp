#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,s[2010][1010];//人，数
int num[200010];
int x=-1,y=-1;
int abab;
int r,c,flag=0,jup;
bool check() {
	int tmp=r%n;
	if(tmp==0) tmp=n;
//	cout<<tmp<<endl;
	y=-1;
//	//第一个人有没有r
//	flag=0;
//	for(int i=1; i<=s[1][0]; i++) {
//		if(s[1][i]==r) {
//			flag=1;
//			y=i;
//			break;
//		}
//	}
//	if(!flag) {
//		cout<<"------------a-----------------"<<endl;
//		return 0;
//	}
	//第一个人有1，到r的距离够不够
	flag=0;
	if(x-y+1<=k) {
		flag=1;
	}
	if(!flag) {
//		cout<<"-----------dui---------------"<<endl;
		return 0;
	}
	//两人之间是否有相同的数
	flag=0;
//	cout<<"-------------------dddd-----------------"<<endl;
	for(int i=2; i<=min(tmp,n); i++) {
		for(int j=1; j<=s[i-1][0]; j++)
			num[s[i-1][j]]=1;
		for(int j=1; j<=s[i][0]; j++) {
			if(num[s[i][j]]==1) {
				flag=1;
				break;
			}
		}
		if(!flag) {
			return 0;
		}
	}
	//结尾是否有c
//	cout<<"----------------------wwww--------------------"<<endl;
//	cout<<c<<endl;
	flag=0;
	for(int j=1; j<=s[tmp][0]; j++) {
		if(s[tmp][j]==c) {
			flag=1;
			break;
		}
	}
	if(!flag) {
		return 0;
	}
	return 1;
}
void init() {
	memset(s,0,sizeof(s));
	memset(num,0,sizeof(num));
	n=k=q=r=c=jup=flag=0;
	x=-1,y=-1;
	abab=0;
}
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int f=1; f<=t; f++) {
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++){
			cin>>s[j][0];
			for(int i=1; i<=s[j][0]; i++) {
				cin>>s[j][i];
			}
		}
//		cout<<"----------x--------------"<<endl; 
		//第一个人是否有1
		flag=0;
		for(int i=1; i<=s[1][0]; i++) {
			if(s[1][i]==1) {
				flag=1;
				x=i;
				break;
			}
		}
		if(!flag) {
			jup=1;
		}
		for(int i=1; i<=q; i++) {
			cin>>r>>c;
			if(jup) {
				cout<<0<<endl;
				continue;
			}
			if(r==1){
				abab=0;
				for(int i=1;i<=s[1][0];i++){
					if(s[1][i]==c&&i>x&&i-x+1<=k){
						cout<<1<<endl;
						abab=1;
						break;
					}
				}
//				cout<<"32547025780923570985427309"<<endl;
				if(abab==1) continue;
				else cout<<0<<endl;
				continue;
			}
			
			if(check()==0){
				cout<<0<<endl;
				continue;
			}
			cout<<1<<endl;
		}
	}
	return 0;
}
