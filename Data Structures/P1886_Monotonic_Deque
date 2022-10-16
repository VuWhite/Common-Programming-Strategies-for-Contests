#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;
int n,k,a[1000004],q1[1000004],head=1,tail=0;
void read(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
}
void max_deque(){
	for(int i=1;i<=n;i++){
		while(head<=tail&&a[q1[tail]]<=a[i]){
			tail--;
		}
		q1[++tail]=i;
		while(q1[head]<=i-k){
			head++;
		}
		if(i>=k){
			cout<<a[q1[head]];
		if(i==n)
			cout<<endl;
		else
			cout<<' ';			
		}
	}
	return;
}
void min_deque(){
	for(int i=1;i<=n;i++){
		while(head<=tail&&a[q1[tail]]>=a[i]){
			tail--;
		}
		q1[++tail]=i;
		while(q1[head]<=i-k){
			head++;
		}
		if(i>=k){
			cout<<a[q1[head]];
		if(i==n)
			cout<<endl;
		else
			cout<<' ';			
		}
	}
	return;
}
int main(){
	read();
	min_deque();
	head=1,tail=0;
	max_deque();
	return 0;
}	
