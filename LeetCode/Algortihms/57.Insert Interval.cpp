/*
Given a set of non-overlapping intervals, insert a new interval into the intervals
(merge if necessary).

You may assume that the intervals were initially sorted according to their start 
times.
*/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    bool doIntersect(const Interval& interv1, const Interval& interv2) {
        if(interv1.start > interv2.start)
            return doIntersect(interv2, interv1);
        if(interv2.start >= interv1.start && interv2.start <= interv1.end)
            return true;
        return false;
    }
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        for(vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); ++it) {
            if(doIntersect(*it, newInterval)) {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
            }
            else res.push_back(*it);
        }
        vector<Interval>::iterator it = res.begin();
        for(; it != res.end(); ++it) {
            if(it->start > newInterval.start )
                break;
        }
        res.insert(it, newInterval);
        return res;
    }
};
