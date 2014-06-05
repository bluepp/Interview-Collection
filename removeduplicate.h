/*
    bluepp  
    2014-06-05
    May the force be with me!
    
    Given a string s, remove duplicate adjacent characters from s recursively
    source : http://www.mitbbs.com/article_t/JobHunting/32710077.html
    
    Given a string s, remove duplicate adjacent characters from s recursively.

    For example: 
    Input: "abbac"  
    Output: "c", first remove adjacent duplicated 'b's, then remove adjacent 
    duplicated 'a'.

    Input: "acbbcad" 
    Output" "d", first remove 'b', then remove 'c', then remove 'a'. 

    Input: "acbbcda" 
    Output: "ada" 
    
    string str1 = "geeksforgeeg";
    gksfor

    string str2 = "azxxxzy";
    ay （3个x相邻，全删掉，然后删除z）

    string str3 = "caaabbbaac";
    empty string

    string str4 = "gghhg";
    g        （先删除开始的两个g,然后删除两个h）

    string str5 = "aaaacddddcappp";
    a 

    如果是”baaab“ 应该返回空串。


    Do it with one pass over the string.
*/


    string removedup(string str)
    {
        int n = str.size();
        if (n == 0) return "";
        stack<char> s;
        s.push(str[0]);
        char last = '';
        
        for(int i = 1; i < n; i++)
        {
            char tmp = str[i];
            
            if (tmp != last && s.empty() || tmp != s.top())
                s.push(tmp);
            else if (tmp == s.top() && !s.empty())
            {
                s.pop();
            }
            
            
            last = tmp;
                
        }
     
        string res;   
        for (int i = 0; i < s.size(); i++)
            res[i] = s.pop();
        
        reverse(res.begin(), res.end());
        
        return res;
    }
            
    











