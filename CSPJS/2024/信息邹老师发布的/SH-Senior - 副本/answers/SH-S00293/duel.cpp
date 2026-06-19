#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans;
multiset<int> st;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	ans=n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(st.empty()){
			st.insert(a[i]);
			continue;
		}
		else{
			multiset<int>::iterator it=st.lower_bound(a[i]);
			if(it==st.begin()){
				st.insert(a[i]);
				continue;
			}
			it--;
//			cout<<a[i]<<' '<<*it<<endl;
			if(!st.empty()) st.erase(it),ans--;
			st.insert(a[i]);
		}
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
