#include<bits/stdc++.h>
using namespace std;
int T,a,b[100],co[100],fans=0;
int color(int c){
	if (c==a+1){
		int ans1=0;
		for (int i=1;i<=a;i++){
			int w=-1;
			for (int k=1;k<i;k++){
				if (co[i]==co[k])w=k;
			}
			if (co[i]==co[w] && b[i]==b[w])ans1+=b[i];
		}
		fans=max(fans,ans1);
		return 0;
	}
	co[c]=1;
	color(c+1);
	co[c]=2;
	color(c+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for (int i=1;i<=T;i++){
		fans=0;
		cin>>a;
		for (int j=1;j<=a;j++){
			cin>>b[j];
		}
		color(1);
		cout<<fans<<endl;
	}
	return 0;
}
