#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int a[N],b[N],c[N];
vector<int> va,vb,vc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
			    sum+=a[i];
				va.push_back(a[i]-max(b[i],c[i]));
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
			    sum+=b[i];
				vb.push_back(b[i]-max(a[i],c[i]));
			}else{
				sum+=c[i];
			    vc.push_back(c[i]-max(a[i],b[i]));
			}
		}
		if(va.size()>n/2){
			sort(va.begin(),va.end());
			for(int i=0;i+n/2<va.size();i++)sum-=va[i];
		}else if(vb.size()>n/2){
			sort(vb.begin(),vb.end());
			for(int i=0;i+n/2<vb.size();i++)sum-=vb[i];
		}else if(vc.size()>n/2){
			sort(vc.begin(),vc.end());
			for(int i=0;i+n/2<vc.size();i++)sum-=vc[i];
		}
		cout<<sum<<"\n";
		va.clear();
		vb.clear();
		vc.clear();
	}
	return 0;
}
/*
浔阳江头夜送客，枫叶荻花秋瑟瑟
主人下马客在船，举杯欲饮无管弦
醉不成欢惨将别，别时茫茫江浸月
忽闻水上琵琶声，主人忘归客不发
寻声暗问弹者谁，琵琶声停欲语迟
移船相近遥相见，添酒回灯重开宴
千呼万唤始出来，犹抱琵琶半遮面
转轴拨弦三两声，未成曲调先有情
弦弦掩抑声声思，似诉平生不得志 
低眉信手续续弹，说尽心中无限事
轻拢慢捻抹复挑，初为霓裳后六夭 
*/
