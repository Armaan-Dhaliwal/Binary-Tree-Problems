#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void inorder(vector<int> a, vector<int> &v,int n, int index)
{
    if(index >= n)
        return;
    inorder(a, v, n, 2 * index + 1);
     
    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}

int minimumSwaps(vector<int>&arr, int n) {
	vector<int> v;
	inorder(arr,v,n, 0);
	vector<pair<int,int>> vec;
	for(int i=0;i<n;i++){
		vec.push_back({v[i],i});
	}

	sort(vec.begin(),vec.end());
	int counter=0;
	for(int i=0;i<n;i++){
		if(vec[i].second==i){
			continue;
		}
		else{
			counter++;
			swap(vec[i],vec[vec[i].second]);
			i--;
		}
	}
	return counter;
}