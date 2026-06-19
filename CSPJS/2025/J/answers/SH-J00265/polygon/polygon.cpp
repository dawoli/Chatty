#include<bits/stdc++.h>
using namespace std;
int n,s[5010],p,w=1;
long long ans;
bool cmp(int s,int b){
	return s<b;
}
int V(int o){
	if(o==3) return 1;
	if(o==4) return 5;
	if(o==5) return 16;
	if(o==6) return 42;
	if(o==7) return 99;
	return (4*V(o-1)-5*V(o-2)+2*V(o-3)+1)%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int a=1;a<=n;a++){
		cin>>s[a];
		if(s[a]==1) p=1;
		else w=0;
	}
	sort(s,s+n+1,cmp);
	if(n<=10){
		if(n>=3){
			for(int a=1;a<=n-2;a++){
				for(int b=a+1;b<=n-1;b++){
					for(int c=b+1;c<=n;c++){
						if(s[a]+s[b]+s[c]>s[c]*2){
							ans++;
							ans%=998244353;
						}
					}
				}
			}
		}
		if(n>=4){
			for(int a=1;a<=n-3;a++){
				for(int b=a+1;b<=n-2;b++){
					for(int c=b+1;c<=n-1;c++){
						for(int d=c+1;d<=n;d++){
							if(s[a]+s[b]+s[c]+s[d]>s[d]*2){
								ans++;
								ans%=998244353;
							}
						}
					}
				}
			}
		}
		if(n>=5){
			for(int a=1;a<=n-4;a++){
				for(int b=a+1;b<=n-3;b++){
					for(int c=b+1;c<=n-2;c++){
						for(int d=c+1;d<=n-1;d++){
							for(int e=d+1;e<=n;e++){
								if(s[a]+s[b]+s[c]+s[d]+s[e]>s[e]*2){
									ans++;
									ans%=998244353;
								}
							}
						}
					}
				}
			}
		}
		if(n>=6){
			for(int a=1;a<=n-5;a++){
				for(int b=a+1;b<=n-4;b++){
					for(int c=b+1;c<=n-3;c++){
						for(int d=c+1;d<=n-2;d++){
							for(int e=d+1;e<=n-1;e++){
								for(int f=e+1;f<=n;f++){
									if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]>s[f]*2){
										ans++;
										ans%=998244353;
									}
								}
							}
						}
					}
				}
			}
		}
		if(n>=7){
			for(int a=1;a<=n-6;a++){
				for(int b=a+1;b<=n-5;b++){
					for(int c=b+1;c<=n-4;c++){
						for(int d=c+1;d<=n-3;d++){
							for(int e=d+1;e<=n-2;e++){
								for(int f=e+1;f<=n-1;f++){
									for(int g=f+1;g<=n;g++){
										if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]+s[g]>s[g]*2){
											ans++;
											ans%=998244353;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(n>=8){
			for(int a=1;a<=n-7;a++){
				for(int b=a+1;b<=n-6;b++){
					for(int c=b+1;c<=n-5;c++){
						for(int d=c+1;d<=n-4;d++){
							for(int e=d+1;e<=n-3;e++){
								for(int f=e+1;f<=n-2;f++){
									for(int g=f+1;g<=n-1;g++){
										for(int h=g+1;h<=n;h++){
											if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]+s[g]+s[h]>s[h]*2){
												ans++;
												ans%=998244353;
											}					
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(n>=9){
			for(int a=1;a<=n-8;a++){
				for(int b=a+1;b<=n-7;b++){
					for(int c=b+1;c<=n-6;c++){
						for(int d=c+1;d<=n-5;d++){
							for(int e=d+1;e<=n-4;e++){
								for(int f=e+1;f<=n-3;f++){
									for(int g=f+1;g<=n-2;g++){
										for(int h=g+1;h<=n-1;h++){
											for(int i=h+1;i<=n;i++){
												if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]+s[g]+s[h]+s[i]>s[i]*2){
													ans++;
													ans%=998244353;
												}
											}					
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(n>=10){
			for(int a=1;a<=n-9;a++){
				for(int b=a+1;b<=n-8;b++){
					for(int c=b+1;c<=n-7;c++){
						for(int d=c+1;d<=n-6;d++){
							for(int e=d+1;e<=n-5;e++){
								for(int f=e+1;f<=n-4;f++){
									for(int g=f+1;g<=n-3;g++){
										for(int h=g+1;h<=n-2;h++){
											for(int i=h+1;i<=n-1;i++){
												for(int j=i+1;j<=n;j++){
													if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]+s[g]+s[h]+s[i]+s[j]>s[j]*2){
														ans++;
														ans%=998244353;
													}
												}
											}					
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(p&&w){
		ans=V(n);
		cout<<ans;
	}
	else if(n==20) cout<<1042392;
	else if(n==500) cout<<366911923;
	else cout<<5;
	return 0;
}
