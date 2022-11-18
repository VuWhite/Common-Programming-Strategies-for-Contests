#include <iostream>
using namespace std;
int Euclidean(int x,int y){

	while(x%y!=0){
		int r=x%y;
		x=y;
		y=r;
	}
	return y;
}
const int N=200010;
int st[5][4*N],arr[N];
int query(int q,int p, int l, int r, int ql, int qr){
	if(ql>r||qr<l){
		if(q==0)
			return 0;
		else if(q==1)
			return 1000000;
		else if(q==4)
			return 1;
	}
	if(ql<=l&&qr>=r)
		return st[q][p];
	int m=l+((r-l)>>1);
	if(q==0)
		return query(q,2*p,l,m,ql,qr)+query(q,2*p+1,m+1,r,ql,qr);
	if(q==1)
		return min(query(q,2*p,l,m,ql,qr),query(q,2*p+1,m+1,r,ql,qr));
	if(q==2){
		if(!(ql>m||qr<l)&&!(ql>r||qr<m+1))
			return Euclidean(query(q,2*p,l,m,ql,qr),query(q,2*p+1,m+1,r,ql,qr));
		else if(!(ql>m||qr<l))
			return query(q,2*p,l,m,ql,qr);
		else if(!(ql>r||qr<l))
			return query(q,2*p+1,m+1,r,ql,qr);
	}
	if(q==3){
		if(!(ql>m||qr<l)&&!(ql>r||qr<m+1))
			return query(q,2*p,l,m,ql,qr)^query(q,2*p+1,m+1,r,ql,qr);
		else if(!(ql>m||qr<l))
			return query(q,2*p,l,m,ql,qr);
		else if(!(ql>r||qr<l))
			return query(q,2*p+1,m+1,r,ql,qr);
	}
		
	if(q==4)
		return query(q,2*p,l,m,ql,qr)*query(q,2*p+1,m+1,r,ql,qr)%10007;
}
void update(int q,int p, int l, int r, int idx, int val){
	if(l==r){
		st[q][p]=val;
		return;
	}
	int m=l+((r-l)>>1);
	if(idx<=m)
		update(q,p*2,l,m,idx,val);
	else
		update(q,2*p+1,m+1,r,idx,val);
	if(q==0)
		st[q][p]=st[q][p*2]+st[q][p*2+1];
	else if(q==1)
		st[q][p]=min(st[q][p*2],st[q][p*2+1]);
	else if(q==2)
		st[q][p]=Euclidean(st[q][p*2],st[q][p*2+1]);
	else if(q==3)
		st[q][p]=st[q][p*2]^st[q][p*2+1];
	else
		st[q][p]=st[q][p*2]*st[q][p*2+1]%10007;
	return;
}
void build(int q,int p, int l, int r){
	if(l==r){
		st[q][p]=arr[l];
		return;
	}
	int m = l+((r-l)>>1);
	build(q,p*2,l,m),build(q,2*p+1,m+1,r);
	if(q==0)
		st[q][p]=st[q][p*2]+st[q][p*2+1];
	else if(q==1)
		st[q][p]=min(st[q][p*2],st[q][p*2+1]);
	else if(q==2)
		st[q][p]=Euclidean(st[q][p*2],st[q][p*2+1]);
	else if(q==3)
		st[q][p]=st[q][p*2]^st[q][p*2+1];
	else
		st[q][p]=st[q][p*2]*st[q][p*2+1]%10007;
	return;
}
int main(){
	int n,q; cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<=4*n;i++){
		st[4][i]=1;
		st[1][i]=100000;
	}
	for(int i=1;i<5;i++){
		build(i,1,1,n);
	}
	for(int i=0;i<q;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1){
			for(int i=1;i<5;i++)
				update(i,1,1,n,b,c);
		}
		else
			cout<<query(a-1,1,1,n,b,c)<<endl;
	}
	return 0;
}
