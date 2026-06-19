#include<bits/stdc++.h>
using namespace std;
std::ifstream fin("detect.in");
std::ofstream fout("detect.out");
const int e=1e5+5;
int T,n,m,L,V;
int d[e],v[e],a[e],p[e];
int find(int x){
	int l=1,r=m;
	while(l<r){
		int mid=(l+r)/2;
		if(x<=p[mid])r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	fin>>T;
	while(T--){
		int cnt=0;
		int first[e]={},last[e]={},D[e]={};
		fin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)fin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)fin>>p[i];
		for(int i=1;i<=n;i++){
			int pt1=find(d[i]);
			if(d[i]>p[pt1])first[i]=0;
			else if(a[i]>0){
				if(v[i]>V){
					first[i]=pt1,last[i]=m;
					D[pt1]++;
					cnt++;
				}
				else{
					double pos=d[i]+(pow(V,2)-pow(v[i],2))*0.5/a[i];
					int pt2=find(ceil(pos));
					if(pow(V,2)-pow(v[i],2)==2*a[i]*(p[pt2]-d[i]))pt2++;
					if(pos>=p[m])first[i]=0;
					else{
						first[i]=pt2,last[i]=m;
						D[pt2]++;
						cnt++;
					}
				}
			}
			else if(a[i]==0){
				if(v[i]>V){
					first[i]=pt1,last[i]=m;
					D[pt1]++;
					cnt++;
				}
				else first[i]=0;
			}
			else{
				if(v[i]>V){
					double pos=d[i]+(pow(V,2)-pow(v[i],2))*0.5/a[i];
					int pt2=find(ceil(pos))-1;
					if(pos>p[m])pt2++;
					if(pt1>pt2)first[i]=0;
					else{
						first[i]=pt1,last[i]=pt2;
						D[pt1]++,D[pt2+1]--;
						cnt++;
					}
				}
				else first[i]=0;
			}
		}
		fout<<cnt<<" ";
		int ans=m,dele[e]={};
		while(1){
			int M=0,j,now=0;
			for(int i=1;i<=m;i++){
				now+=D[i];
				if(M<now&&!dele[i]){
					M=now;
					j=i;
				}
			}
			if(!M)break;
			dele[j]=1;
			ans--;
			for(int i=1;i<=n;i++){
				if(first[i]){
				for(int j=first[i];j<=last[i];j++){
					if(dele[j]){
						D[first[i]]--,D[last[i+1]]++;
						first[i]=0;
						break;
					}
				}
			}
			}
		}
		fout<<ans<<endl;
	}
	return 0;
}
