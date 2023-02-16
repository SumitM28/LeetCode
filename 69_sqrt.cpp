// find sqrt of x without any function
#include<bits/stdc++.h>
using namespace std;


int mySqrt(int x){
    // usign linear search
    // if(x==0) return 0;

    // int i=1;
    // for(i;i<=x/i;i++){
    //     if(i==x/i) return i;
    // }
    // return i-1;


    // usign binary search
    int s=1,e=x;
    int ans=0;
    while(s<=e){
        int mid=s+(e-s)/2;

        if(mid==x/mid){
            return mid;
        }
        else if(mid < x/mid){
            s=mid+1;
            ans=mid;
        }else{
            e=mid-1;
        }
    }
    return ans;

}