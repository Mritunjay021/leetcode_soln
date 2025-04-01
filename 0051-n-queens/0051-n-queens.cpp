class Solution {
public:

    bool solve(vector<string>& board,int r,int c,int n)
    {
        int dr=r;
        int dc=c;

        while(r>=0 && c>=0)
        {
            if(board[r][c]=='Q')
            return false;

            r--;c--;
        }

        r=dr,c=dc;

        while(c>=0)
        {
            if(board[r][c]=='Q')
            return false;

            c--;
        }

        r=dr;c=dc;

        while(r<n && c>=0)
        {
            if(board[r][c]=='Q')
            return false;

            r++;c--;
        }

        return true;
    }

    void func(int col,vector<string>& board,vector<vector<string>>& ans,int n)
    {
        if(col==n)
        ans.push_back(board);

        for(int r=0;r<n;r++)
        {
            if(solve(board,r,col,n))
            {
                board[r][col]='Q';
                func(col+1,board,ans,n);
                board[r][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');

        for(int i=0;i<n;i++)
        board[i]=s;

        func(0,board,ans,n);
        return ans;    
    }
};