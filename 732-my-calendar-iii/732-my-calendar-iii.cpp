class MyCalendarThree
{
    public:
        map<int, int> mp;

    MyCalendarThree() {}

    int book(int start, int end)
    {
        mp[start]++;
        mp[end]--;
        int ongoing = 0, k = 0;
        for (auto &v: mp) k = max(k, ongoing += v.second);
        return k;
    }
};

/**
 *Your MyCalendarThree object will be instantiated and called as such:
 *MyCalendarThree* obj = new MyCalendarThree();
 *int param_1 = obj->book(start,end);
 */