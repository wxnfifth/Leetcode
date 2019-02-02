class TopVotedCandidate {
    map<int,int> mp;//first is t, second is who wins
    
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        //preprocess at each time who is leading
        map<int,int> vote;
        int max_vote = 0;
        int max_person = -1;
        for (int i = 0; i < persons.size(); ++i) {
            vote[persons[i]]++;
            if (vote[persons[i]] >= max_vote) {
                mp[times[i]] = persons[i];
                max_vote = vote[persons[i]];
                max_person = persons[i];
            } else {
                mp[times[i]] = max_person;
            }
        }
    }
    
    int q(int t) {
        auto it = mp.upper_bound(t);
        it = prev(it);
        return it->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
