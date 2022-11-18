#include <iostream>
using namespace std;
const int N=200010;
int st[4*N],arr[N];
int query(int p, int l, int r, int ql, int qr){
	if(ql>r||qr<l)
		return 0;
	if(ql<=l&&qr>=r)
		return st[p];
	int m=l+((r-l)>>1);
	return query(2*p,l,m,ql,qr)+query(2*p+1,m+1,r,ql,qr);
}
void update(int p, int l, int r, int idx, int val){
	if(l==r){
		st[p]=val;
		return;
	}
	int m=l+((r-l)>>1);
	if(idx<=m)
		update(p*2,l,m,idx,val);
	else
		update(2*p+1,m+1,r,idx,val);
	st[p]=st[2*p]+st[2*p+1];
	return;
}
void build(int p, int l, int r){
	if(l==r){
		st[p]=arr[l];
		return;
	}
	int m = l+((r-l)>>1);
	build(p*2,l,m),build(2*p+1,m+1,r);
	st[p]=st[p*2]+st[p*2+1];
	return;
}
int main(){
	int n,q; cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	build(1,1,n);
	for(int i=0;i<q;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1)
			update(1,1,n,b,c);
		else
			cout<<query(1,1,n,b,c)<<endl;
	}
	return 0;
}
