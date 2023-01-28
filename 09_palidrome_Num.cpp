// check if the palidrome number is same or not.
class Solution {
public:
    bool isPalindrome(int x) {
        // approach 1st
        // string ans;
        // int checkNum=x;
        // while(x){
        //     int digit=x%10;
        //     ans+=digit;
        //     x=x/10;
        // }
        // if(checkNum<0){
        //     ans+='-';
        // }
        // int i=0,j=ans.size()-1;
        // while(i<j){
        //     if(ans[i++]!=ans[j--]){
        //         return false;
        //     }
        // }
        // return true;

        // approach 2nd
        if (x<0) return false;
        long int temp=x;
        long int sum=0;
        while(x){
            sum=(sum*10)+(x%10);
            x=x/10;
        }

        if(temp!=sum){
            return false;
        }else{
            return true;
        }
    }
};