#include <bits/stdc++.h>
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        // Brutte Force approach
    // for(int i=0; i<arr.size(); i++){
    //     if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) return i;
    // }
    // return -1;

    //Optimal approach usiing binary search

    int left = 0, right = arr.size() - 1;

    while(left<right){
        int mid = left + (right - left) / 2;
        
        if (arr[mid] > arr[mid + 1]){
            right = mid;
        }
        else left = mid + 1;
    }

    return left; // right also can be returned
    }
};