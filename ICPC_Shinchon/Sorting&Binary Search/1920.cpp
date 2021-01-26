#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k;
int arr[100000];


int binary_search(int answer){
	int high=n-1;
	int low=0;
	
	while(low<=high){
		int mid=(low+high)/2;
		
		if(arr[mid]==answer)
			return 1;
		if(arr[mid]>answer)
			high=mid-1;
		else
			low=mid+1;
	}
	
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	sort(arr,arr+n);
	
	cin>>m;
	
	for(int i=0;i<m;i++){
		cin>>k;
		
		cout<<binary_search(k)<<"\n";
		
	}
	
}
