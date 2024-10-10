class Solution {
public:

    int func(string time)
    {
        int hours = stoi(time.substr(0, 2));  
        int minutes = stoi(time.substr(3));  
        return hours * 60 + minutes;
    }

    int convertTime(string cur, string cor) 
    {
        int h1=func(cur);
        
        int h2=func(cor);

        h2-=h1;

        int op=0;
        op=h2/60;
        h2=h2%60;
        op+=h2/15;
        h2=h2%15;
        op+=h2/5;
        h2=h2%5;
        op+=h2;
        return op;

    }
};