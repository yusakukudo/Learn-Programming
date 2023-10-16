//Question
//Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
/*
Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:

Input: rowIndex = 0
Output: [1]

Example 3:

Input: rowIndex = 1
Output: [1,1]

 

Constraints:

    0 <= rowIndex <= 33
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> Reqrow(int rowIndex,vector<int> prev,int     currindex) {
  vector<int> currentvec(currindex);
  currentvec[0]=1;
  currentvec[currindex-1]=1;
  for(int i=0;i<prev.size()-1;i++){
    currentvec[i+1]=prev[i]+prev[i+1];
  }
  
  if(currindex>rowIndex){
    return currentvec;
  }
  return Reqrow(rowIndex,currentvec,currindex+1);
}
vector<int> getRow(int rowIndex) {
  vector<int> ans;
  vector<int> a0={1} ;
  vector<int> a1={1,1} ;
  if(rowIndex==0){
    return a0;
  }
  if(rowIndex==1){
    return a1;
  }
  int currindex=3;
  ans=Reqrow(rowIndex,a1,currindex);
  return ans;
}

int main() {
  int n;
  cin>>n;
  vector<int> lets=getRow(n);
  for(int i=0;i<lets.size();i++){
    cout<<lets[i]<<"  ";
  }
}  



