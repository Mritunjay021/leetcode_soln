class Solution {
public:
    int compress(vector<char>& v)
    {
        int id=0;
        for(int i=0;i<v.size();)
        {
            char ct=v[i];
            int cnt=0;

            while(i<v.size() && ct==v[i])
            {
                cnt++;
                i++;
            }

            v[id++]=ct;

            if(cnt>1)
            {
                string cntt=to_string(cnt);
                for(char c:cntt)
                {
                    v[id++]=c;
                }
            }
        }
        cout<<id;
        return id;
    }
};

// class Solution {
// public:
//     int compress(vector<char>& ch) 
//     {
//         int index = 0;  // Index to write the compressed characters
//         int i = 0;

//         while (i < ch.size()) 
//         {
//             char currentChar = ch[i];
//             int count = 0;

//             // Count consecutive characters
//             while (i < ch.size() && ch[i] == currentChar) 
//             {
//                 count++;
//                 i++;
//             }

//             // Write the character
//             ch[index++] = currentChar;

//             // Write the count if greater than 1
//             if (count > 1) 
//             {
//                 string countStr = to_string(count);
//                 for (char c : countStr) 
//                 {
//                     ch[index++] = c;
//                 }
//             }
//         }
//         cout<<index;
//         return index;  // Return the new length
//     }
// };
