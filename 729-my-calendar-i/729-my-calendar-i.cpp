class MyCalendar {
private:
    set<pair<int, int>> bookings;
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        if(bookings.empty()) {
            bookings.insert({start, end});
            return true;
        }
        auto lb = bookings.lower_bound({start, INT_MIN});
        // auto ub = bookings.upper_bound({start, INT_MIN});
        if(lb == bookings.end()) {
            lb = prev(lb);
            if(start >= lb->first && start < lb->second) return false;
            bookings.insert({start, end});
            return true;
        } else if(start < lb->first) {
            if(end > lb->first) return false;
            lb = prev(lb);
            if(start >= lb->first && start < lb->second) return false;
            bookings.insert({start, end});
            return true;
        } else return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */