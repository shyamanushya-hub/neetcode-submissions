/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        auto sortFunc = [](const Interval& i1, const Interval& i2) {return i1.start < i2 .start;}; 
        std::sort(intervals.begin(), intervals.end(), sortFunc);

        for(int i = intervals.size()-1; i > 0; --i) {
            if(intervals[i].start < intervals[i-1].end)
                return false;
        }

        return true;
    }
};
