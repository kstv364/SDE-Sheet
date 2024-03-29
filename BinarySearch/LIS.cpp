#include<bits/stdc++.h>


int longestIncreasingSubsequence(int arr[], int n)
{

    vector<int> temp;
    temp.push_back(arr[0]);
    int len=1;
    for(int i=1;i<n;i++){
        if(temp.back() < arr[i]){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[idx] = arr[i];
        }
    }
    return len;

}
