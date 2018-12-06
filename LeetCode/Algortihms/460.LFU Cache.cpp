/**
Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Follow up:
Could you do both operations in O(1) time complexity?
  */

struct info {
    int value;
    list<pair<int, list<int> > >::iterator it_pair;
    list<int>::iterator it_key;
};
class LFUCache {
    int cap_;
    list<pair<int, list<int> > > list_;
    unordered_map<int, info> map_;

    void visit(unordered_map<int, info>::iterator it) {
        auto it_pair = it->second.it_pair;
        auto it_key = it->second.it_key;
        int key = *it_key;
        int count = it_pair->first+1;

        it_pair->second.erase(it_key);
        if(it_pair->second.size() == 0)
            it_pair = list_.erase(it_pair);
        else
            advance(it_pair, 1);
        if(it_pair == list_.end() || it_pair->first != count)
            it_pair = list_.insert(it_pair, {count, {key}});
        else
            it_pair->second.push_back(key);
        it->second.it_pair = it_pair;
        it->second.it_key = prev(it_pair->second.end());
    }
public:
    LFUCache(int capacity) {
        cap_ = capacity;
    }

    int get(int key) {
        auto it = map_.find(key);
        if(it == map_.end())    return -1;
        else {
            visit(it);
            return it->second.value;
        }
    }

    void put(int key, int value) {
        auto it = map_.find(key);
        if(it != map_.end()) {
            visit(it);
            it->second.value = value;
        } else {
            if(cap_  == 0) return;

            if(map_.size() == cap_) {//delete least frequent least recent
                auto it = list_.front().second.begin();
                map_.erase(*it);
                list_.front().second.erase(it);

                if(list_.front().second.size() == 0)
                    list_.erase(list_.begin());
            }

            if(list_.empty() || list_.front().first != 1)
                list_.push_front({1, {key}});
            else {
                list_.front().second.push_back(key);
            }
            map_[key] = {value, list_.begin(), prev(list_.front().second.end())};
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
