// https://practice.geeksforgeeks.org/problems/vertical-sum/1
//https://www.youtube.com/watch?v=2umxe52-4yQ&ab_channel=CodeFromScratch-KeertiPurswani

class Solution{
  public:
  
     //root =0
    //left - neg
    //right - pos
    
    void helper(Node *root, int dist , map<int,int> &mp)
    {
        mp[dist]+=root->data;
        if(root->left) helper(root->left,dist-1,mp);
        if(root->right) helper(root->right,dist+1,mp);
    }
  
    vector <int> verticalSum(Node *root) {


       //dist , sum
       map<int,int> mp;
       
       helper(root,0,mp);
       vector<int> ans;
       for(auto i : mp)
       {
           ans.push_back(i.second);
       }
       
       return ans;
       
    }
};
