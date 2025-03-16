class Solution {
public:
    long long func(long long mid, vector<int>& ranks) {
        long long c = 0;
        for(auto r : ranks) {
            c += sqrt(mid/r);
        }
        return c;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0;
        long long r = (long long)ranks[0] * (long long)cars * (long long)cars;
        long long res = -1;

        while(l <= r) {
            long long mid = (l + r) / 2;
            
            long long cr = func(mid, ranks);

            if(cr >= cars) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }    
        return res;
    }
};