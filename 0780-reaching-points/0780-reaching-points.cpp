class Solution {
public:

    bool func(int sx,int sy,int tx,int ty,vector<vector<int>> & dp)
    {
        if(sx>tx || sy>ty)
        return false;
        if(sx==tx && sy==ty)
        return true;
        if(dp[sx][sy]!=-1)
        return dp[sx][sy];
        bool l=func(sx+sy,sy,tx,ty,dp);
        bool r=func(sx,sx+sy,tx,ty,dp);
        return l|r;
    }

    // vector<vector<int>> dp(tx+1,vector<int>(ty+1,-1));
        // return func(sx,sy,tx,ty,dp); 

    bool reachingPoints(int sx, int sy, int tx, int ty) 
    {
         
        while(tx>=sx && ty>=sy)
        {
            if (tx > ty) 
            {
                if (ty > sy)
                tx %= ty;
                else
                return (tx - sx) % ty == 0;  
            }
            else
            {
                if (tx > sx)
                
                ty %= tx;
                else
                return (ty - sy) % tx == 0;
            }
        }  
        return (tx==sx && ty==sy);
    }
};


// DP cannot be used as the dp table for 10^9 will bw too large using unecessary space
// bool func(int sx,int sy,int tx,int ty,vector<vector<int>> & dp)
//     {
//         if(tx<sx || ty<sy)
//         return false;
//         if(sx==tx || sy ==ty)
//         return true;
//         if(dp[tx][ty]!=-1)
//         return dp[tx][ty];
//         bool l,r;
//         if(tx>ty)
//         return dp[tx][ty]=func(sx,sy,tx-ty,ty,dp);
//         else
//         return dp[tx][ty]=func(sx,sy,tx,ty-tx,dp);

//     }