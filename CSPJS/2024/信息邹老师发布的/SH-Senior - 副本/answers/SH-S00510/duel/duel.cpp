#include <bits/stdc++.h>
using namespace std;

int n, mos[100001],last,weak_count,now_count,cnt;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);

	cin>>n;
	cnt=n;
	for(int i=0;i<n;++i){
		cin>>mos[i];
	}
	sort(mos,mos+n);
	for(int i=0;i<n;++i){
		if(mos[i]!=last){
			last=mos[i];
			weak_count+=now_count;
			now_count=0;
		}
		if(weak_count){
			--weak_count;
			--cnt;
		}
		now_count++;
	}
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
