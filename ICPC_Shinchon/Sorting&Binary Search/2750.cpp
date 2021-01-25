#include <iostream>

using namespace std;

int n;
int tmp[1100];
int arr[1100];

void merge(int left,int mid,int right){
	int i=left; //왼쪽 배열 인덱스
	int j=mid+1; //오른쪽 배열 인덱스
	int t=0; //정렬한 배열의 인덱스
	
	while(i<=mid&&j<=right){
		if(arr[i]<=arr[j]){
			tmp[t++]=arr[i++];
		}else
			tmp[t++]=arr[j++];
	}
	
	while(i<=mid) //왼쪽 배열 원소들 남은 경우
		tmp[t++]=arr[i++];
	while(j<=right)
		tmp[t++]=arr[j++];
	
	i=left;
	t=0;
	while(i<=right)
		arr[i++]=tmp[t++]; 
}

void mergeSort(int left,int right){
	
	if(left<right){
		int mid=(left+right)/2;
	
		mergeSort(left,mid);
		mergeSort(mid+1,right);
		merge(left,mid,right);
	}
	
	
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	mergeSort(0,n-1);
	
	for(int i=0;i<n;i++)
		cout<<result[i]<<endl;
}
