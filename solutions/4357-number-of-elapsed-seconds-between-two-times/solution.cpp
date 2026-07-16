class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int hr = stoi(endTime.substr(0, 2)) - stoi(startTime.substr(0 , 2));
        int min = stoi(endTime.substr(3, 2)) - stoi(startTime.substr(3 , 2));
        int sec = stoi(endTime.substr(6, 2)) - stoi(startTime.substr(6 , 2));


        int ans = 0;

        if(hr<0) hr += 24;
        ans += hr*60*60;
        ans += min*60;
        ans += sec;

        return ans;


    }
};

/*

22:50:10 -> 03:10:10 here hr = 3 - 22 = -19 
                     here min = 10 - 50 = -40 


*/