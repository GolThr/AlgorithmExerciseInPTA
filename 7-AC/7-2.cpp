#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<2*n;i++){    //输入两个数组，a是原数组，b是中间数组
		if(i<n){
			cin>>a[i];
		}
		else{
			cin>>b[i-n];
		}
	}
	int pos,flag,count=0;
	for(int i=0;i<n-1;i++){
		count++;
		if(b[i]>b[i+1]){    //找到第一个未按非递减排序的位置，pos是排序了pos个数
			pos=i+1;
			for(int j=pos;j<n;j++){//如果后边未排序数都和同位置的原数
                                                //组数相同则是插入排序，否则归并
				count++;
				if(a[j]!=b[j]){
					flag=0;
					break;
				}
			}
			if(count==n){
				flag=1;
			}
			break;
		}
	}
	if(flag){
		cout<<"Insertion Sort"<<endl;
		sort(b,b+pos+1);
		for(int i=0;i<n-1;i++){
			cout<<b[i]<<" ";
		}
		cout<<b[n-1];
	}
	else{
		cout<<"Merge Sort"<<endl;
		int pos1=1;
		for(int i=pos;i<n-1;i++){
			if(b[i]<b[i+1]){
				pos1++;
			}
			else{
				break;
			}
		}
		int pos2=pos<pos1?pos:pos1;
		for(int i=0;i<=n-2*pos2;i=i+2*pos2){
			sort(b+i,b+i+2*pos2);
		}
		int pos3=n/(2*pos2)*(2*pos2);
		if(n%(2*pos2)!=0){
			sort(b+pos3,b+n);
		}
		for(int i=0;i<n-1;i++){
			cout<<b[i]<<" ";
		}
		cout<<b[n-1];
	}
}