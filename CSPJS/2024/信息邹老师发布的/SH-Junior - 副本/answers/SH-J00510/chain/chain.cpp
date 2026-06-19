#include<bits/stdc++.h>
using namespace std;
#define N 200007
int first[N],l[N];
vector<int> s[N];
int n,m,k;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(first,0x3f,sizeof(first));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=l[i];++j){
				s[i].pop_back();
			}
		}
		cin>>n>>k>>m;
		for(int i=1;i<=n;++i){
			cin>>l[i];
			int tmp=-2e9;//上一个1 
			for(int j=1;j<=l[i];++j){
				int u;
				cin>>u;
				if(u==1) tmp=j;
				s[i].push_back(u);
				first[u]=min(first[u],j-tmp+1);
			}
		}
		for(int i=1;i<=m;++i){
			int u,v;
			cin>>u>>v;
			cout<<(first[v]<=k)<<'\n';
		}
	}
	return 0;
}

/*
csp2024游记

Day -2
周四 

Day -1
周五。今天是校运会，但是啥都干不了，干脆直接别去了。

在家里复习

发现打线段树要30min破防了 

考纲有一半只是理解了，但不能写

但是我妈建议我睡觉 

晚上很晚睡着 

Day 1 上午

起来的时候精神还算好。简单吃了点

外面下大雨 考场外没见到太多熟人 之后见到了几个同学 和我练游泳的某人居然也来了（没想到）

然后开始了。花了5min打开了文件 花了1.5h打完T1-3全部代码。 感觉这个键盘和家里的还是有点区别，不过很快还是适应了 

后来检查到了一堆错误。比如文件名。希望T3别抱灵 

T1T2感觉是切了，但是T3大样例没有 感觉特判还算正确

T4如图，只有5pts了。还有20min，即使想到也来不及调试了

往好处想，我都这个年龄了，参加J组更多是熟悉环境的作用

T4大概是一个巧妙的做法 我看出了几个性质但是好像都没啥用

预估总共305pts 可能更低 无所谓了 

下午s加油   

*/
