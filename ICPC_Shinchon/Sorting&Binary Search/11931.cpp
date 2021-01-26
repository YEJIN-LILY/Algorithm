#include <iostream>
#include <vector>
using namespace std;

#define ll int

ll arr[1000000];
ll tmp[1000000];

ll n;

void merge(ll left,ll mid,ll right){
	ll i=left;
	ll j=mid+1;
	ll t=0;
	
	while(i<=mid&&j<=right){
		if(arr[i]<=arr[j])
			tmp[t++]=arr[j++];
		else
			tmp[t++]=arr[i++];
	}
	
	while(i<=mid)
		tmp[t++]=arr[i++];
	while(j<=right)
		tmp[t++]=arr[j++];
	
	i=left;
	t=0;
	
	while(i<=right){
		arr[i++]=tmp[t++];
	}
	
}

void mergeSort(ll left,ll right){
	if(left<right){
		ll mid=(left+right)/2;
		
		mergeSort(left,mid);
		mergeSort(mid+1,right);
		merge(left,mid,right);
	}
}

int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0), cout.tie(0);
	
	scanf("%d",&n);
	
	for(ll i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	mergeSort(0,n-1);
	
	for(ll i=0;i<n;i++)
		printf("%d\n",arr[i]);
}
