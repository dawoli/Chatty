#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const ll N=1e5+10;
struct stu{
	ll A,B,C;
};
stu sta[N],stb[N],stc[N];
bool cmpa(stu x,stu y){
	return (x.A-max(x.B,x.C))>(y.A-max(y.B,y.C));
}
bool cmpb(stu x,stu y){
	return (x.B-max(x.A,x.C))>(y.B-max(y.A,y.C));
}
bool cmpc(stu x,stu y){
	return (x.C-max(x.B,x.A))>(y.C-max(y.B,y.A));
}
void slove(){
	ll n;
	cin>>n;
	ll s,acnt=0,bcnt=0,ccnt=0;
	for(s=1;s<=n;s++){
		ll a,b,c;
		cin>>a>>b>>c;
		ll mx=max(max(a,b),c);
		if(a==mx){
			sta[++acnt].A=a;
			sta[acnt].B=b;
			sta[acnt].C=c;
		}else if(b==mx){
			stb[++bcnt].A=a;
			stb[bcnt].B=b;
			stb[bcnt].C=c;
		}else if(c==mx){
			stc[++ccnt].A=a;
			stc[ccnt].B=b;
			stc[ccnt].C=c;
		}
	}
	sort(sta+1,sta+acnt+1,cmpa);
	sort(stb+1,stb+bcnt+1,cmpb);
	sort(stc+1,stc+ccnt+1,cmpc);
	while(acnt>n/2){
		if(sta[acnt].B>sta[acnt].C){
			bcnt++;
			stb[bcnt]=sta[acnt];
			acnt--;
		}else{
			ccnt++;
			stc[ccnt]=sta[acnt];
			acnt--;
		}
	}
	while(bcnt>n/2){
		if(stb[bcnt].A>stb[bcnt].C){
			acnt++;
			sta[acnt]=stb[bcnt];
			bcnt--;
		}else{
			ccnt++;
			stc[ccnt]=stb[bcnt];
			bcnt--;
		}
	}
	while(ccnt>n/2){
		if(stc[ccnt].B>stc[ccnt].A){
			bcnt++;
			stb[bcnt]=stc[ccnt];
			ccnt--;
		}else{
			acnt++;
			sta[acnt]=stc[ccnt];
			ccnt--;
		}
	}
	ll sum=0;
	for(s=1;s<=acnt;s++){
		sum+=sta[s].A;
	}
	for(s=1;s<=bcnt;s++){
		sum+=stb[s].B;
	}
	for(s=1;s<=ccnt;s++){
		sum+=stc[s].C;
	}
	cout<<sum<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	ll s;
	for(s=1;s<=t;s++){
		slove();
	} 
	return 0;
} 
/*如果你知道
这是你最后一次接触OI
你会如何做？如何想？

sang心bing狂地把你谷所有的黑题抄一遍？
在屏幕前痛哭流涕？
写一封道别的信？
打破惯例摸一场鱼？

我坐在CSP-S的考场上，哭不出，也不能哭。唯一可以做的就是切掉第一道题，然后，没了。
现在是北京时间16:43:02，距离AFO还有1小时46分钟58秒，而我却什么都做不了。
除非身临其境，没有人可以体会到我的无力感。

认证结束的铃声一响起，我的OI路也走到了尽头。
从此以后，OI明如白昼的夜空中又少了一颗星星。他离去的时候不像流星，而是悄无声息地消失了。

可又有谁在乎呢？

没人。

作文里的情景并没有出现在我身上。
除非奇迹出现，
当然，不会的。
现在是北京时间16:49:50，距离AFO还有1小时40分钟10秒。

我不知道该说什么好了。那就，再见吧，


OI。*/
