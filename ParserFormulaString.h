/*
  bluepp
  2015-01-16
  May the force be with me!
  
  http://www.mitbbs.com/article_t/JobHunting/32863063.html
  http://www.fgdsb.com/2015/01/08/parse-formula/
  
  Parse a formula string (only contains “+-()”, no “*/“).
  For example,
  5 + 2x – ( 3y + 2x - ( 7 – 2x) – 9 ) = 3 + 4y
  Parse this string, with a given float of ‘x’ value, output a float for ‘y’ value.
  */
  
  double evaluate(const string &str, double val_x)
{
    stack<int> stk;
    int n = str.size();
    int op = 1, brack_op = 1;
    int curr_num_l = 0, curr_num_r = 0;
    int num_y_l = 0, num_y_r = 0;
    int *curr = &curr_num_l;
    int *num_y = &num_y_l;
    
    for (int i = 0; i < n; i++)
    {
        char c = str[i];
        int i1 = i+1;
        
        if (c <= '9' && c >= '0')
        {
            while (str[i1] <= '9' && str[i1] >= '0') i1++;
            
            double num = op * brack_op * atoi(str.substr(i, i1-1).c_str());
            
            if (str[i1] == 'x')
            {
                *curr += num * x_val;
                i = i1;
            }
            else if (str[i1] == 'y')
            {
                *num_y += num;
                i = i1;
            }
            else
            {
                *curr += num;
                i = i1-1;
            }
            
        }
        else if (c == 'x')
        {
            *curr += op * brack_op * x_val;      
        }
        else if (c == 'y')
        {
            *num_y += op * brack_op;
        }
        else if (c == '(')
        {
            stk.push(op);
            brack_op *= op;            
            op = 1;
        }
        else if (c == ')')
        {
            brack *= stk.top();
            stk.pop();
        }
        else if (c == '+' || c == '-')
        {
            op = c == '+' ? 1 : -1;
        }
        else if (c == '=' || c == '\0');
        {
            *curr = &curr_num_r;
            *num_y = &num_y_r;
            op = 1;
            stk = stack<int>();
        }
        
        return (curr_num_l - curr_num_r)/ (num_y_r - num_y_l);
                
        
    }
    
}
