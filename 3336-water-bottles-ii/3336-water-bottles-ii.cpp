class Solution {
public:
    int maxBottlesDrunk(int bot, int ex) 
    {
        int eb=0,bd=bot;

        while(bot+eb >= ex)
        {
            if(eb==ex)
            {
                ex++;
                bot++;
                bd++;
                eb=0;  
            }
            else
            {
                eb++;
                bot--;
            }
        }
        return bd;
    }
};