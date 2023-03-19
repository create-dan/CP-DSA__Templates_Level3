class Twitter {
 private:
  
 // dnyaneshwar - [sumit,sudesh,suyog,shiva,saurabh]
 //dnyaneshwar in sare logo ko follow karta hai
 unordered_map<int,set<int>> fo;
  
 //dnyaneshwar - [{1,"tweet"} , {2,"tweet"}]
 //dnyaneshwar ke sare tweets with time first and then tweet
 unordered_map<int,vector<pair<int,int>>> t;

 long long time;
public:

    Twitter() {
        time =0;
    }
    
    void postTweet(int userId, int tweetId) {
        t[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        

        //time , tweets
        priority_queue<pair<int,int>> mxHeap;

        for(auto it = t[userId].begin();it!=t[userId].end();it++)
        {
            mxHeap.push({it->first,it->second});
        }


        for(auto it1=fo[userId].begin();it1!=fo[userId].end();it1++)
        {
            int user = *it1;
            for(auto it2=t[user].begin();it2!=t[user].end();it2++ )
            {
                mxHeap.push({it2->first,it2->second});
            }
        }

        vector<int> ans;
        int cnt =10;
        while(mxHeap.size() > 0  and cnt--){
             ans.push_back(mxHeap.top().second);
             mxHeap.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
        fo[followerId].insert(followeeId);

        }
    }
    
    void unfollow(int followerId, int followeeId) {
        
        fo[followerId].erase(followeeId);
    }
};

