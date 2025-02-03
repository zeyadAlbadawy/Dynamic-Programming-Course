class RandomizedSet {
public:
    map<int, int> mp;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        auto itr = mp.find(val);
        nums[itr->second] = nums.back();
        nums.pop_back();
        mp[nums[itr->second]] = itr->second;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */