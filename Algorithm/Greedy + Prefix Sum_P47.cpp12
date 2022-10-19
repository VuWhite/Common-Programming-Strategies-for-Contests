#include <iostream>
#include<cstdio>
using namespace std;
int n,a[100005],r[100005]={0},last=0,ene[100005],j;
long long sum=0;
void solve(){
	for(int i=1;i<=n;i++){
		cin>>a[i]>>r[i];
		for(j=last+1;j<=r[i];j++){
			sum+=a[j];
		}
		last=j-1;
		sum-=a[i]*5;
		if(sum<0){
			cout<<-1<<endl;
			return;
		}
	}
	for(j=last+1;j<=n;j++){
		sum+=a[j];
	}
	printf("%lf", sum/5.0);
	return;
}
int main(){
	cin>>n>>sum;
	solve();
	return 0;
}
