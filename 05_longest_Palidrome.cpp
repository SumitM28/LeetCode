// find longest palidrome string
#include <iostream>
#include <vector>
using namespace std;

string longestPalidromeStr(string s)
{
    // find all the possible substring
    vector<string> temp;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            string tempStr="";
            for (int k = i; k <= j; k++)
            {
                tempStr+=s[k];
            }
            temp.push_back(tempStr);
        }
    }

    int max=0;
    string ans;
    for(int i=0;i<temp.size();i++){
        string data=temp[i];
        bool flag=true;
        int k=0,j=data.size()-1;
        while (k<=j)
        {
            if(max<data.size()){
                if(data[k++]!=data[j--]){
                    flag=false;
                }
            }
        }
        if(flag==true){
            max=data.size();
            ans=data;
        }
    }
    return ans;
}

int main()
{

    string s = "babad";
    int n = s.size();
    cout<<longestPalidromeStr(s);
}