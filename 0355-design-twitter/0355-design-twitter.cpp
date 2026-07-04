class Twitter {
public:
    int timer;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<vector<int>> pq;
        follows[userId].insert(userId);

        for (int followee : follows[userId]) {

            if (tweets[followee].empty())
                continue;

            int idx = tweets[followee].size() - 1;

            pq.push({
                tweets[followee][idx].first,   // time
                tweets[followee][idx].second,  // tweetId
                followee,                      // user
                idx                           // index
            });
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {

            auto cur = pq.top();
            pq.pop();

            int time = cur[0];
            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];

            ans.push_back(tweetId);

            // Push previous tweet of same user
            if (idx > 0) {
                idx--;

                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */