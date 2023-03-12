#include <iostream>
#include<bits/stdc++.h>
using namespace std;



int precedence(char op){
	if(op == '+'||op == '-')
	return 1;
	if(op == '*'||op == '/')
	return 2;
	return 0;
}

// Function to perform arithmetic operations.
long double applyOp(double a, double b, char op){
	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return double(a) / double(b);
	}
}

// Function that returns value of
// expression after evaluation.
long double evaluate(string tokens){
	int i;
	stack <long double> values;
	stack <char> ops;
	for(i = 0; i < tokens.length(); i++){
		if(tokens[i] == ' ')
			continue;
		else if(tokens[i] == '('){
			ops.push(tokens[i]);
		}
		else if(isdigit(tokens[i])){
			int val = 0;
			while(i < tokens.length() &&
						isdigit(tokens[i]))
			{
				val = (val*10) + (tokens[i]-'0');
				i++;
			}
			
			values.push(val);
			i--;
		}
		else if(tokens[i] == ')')
		{
			while(!ops.empty() && ops.top() != '(')
			{
				long double val2 = values.top();
				values.pop();
				
			long double val1 = values.top();
				values.pop();
				
				char op = ops.top();
				ops.pop();
				
				values.push(applyOp(val1, val2, op));
			}
			if(!ops.empty())
			ops.pop();
		}
		else
		{
			while(!ops.empty() && precedence(ops.top())
								>= precedence(tokens[i])){
				long double val2 = values.top();
				values.pop();
				
				long double val1 = values.top();
				values.pop();
				
				char op = ops.top();
				ops.pop();
				
				values.push(applyOp(val1, val2, op));
			}
			ops.push(tokens[i]);
		}
	}
	while(!ops.empty()){
		long double val2 = values.top();
		values.pop();
				
		long double val1 = values.top();
		values.pop();
				
		char op = ops.top();
		ops.pop();
				
		values.push(applyOp(val1, val2, op));
	}
	return  values.top();
}
int main() 
{
    unordered_map<string,char>m;
    unordered_map<string,char>op;
    m["zero"] = '0';
    m["one"] = '1';
    m["two"] = '2';
    m["three"] = '3';
    m["four"] = '4';
    m["five"] = '5';
    m["six"] = '6';
    m["seven"] = '7';
    m["eight"] = '8';
    m["nine"] = '9';
    m["multiple"]='*';
    m["substract"]='-';
    m["plus"]='+';
    m["equals"]='=';
    m["division"]='/';
    int count=0;
    int t;
    cin>>t;
        while(t--)
        {
            string new_string="";
            string s;
            s="6 + 2 * nine / 2 equals 105";
            // getline(cin, s, ' ');
            for(int i=0;i<s.length();i++)
            {
                if((s[i]=='e' and s[i+1]=='q') ||s[i]=='=')
                break;
                string p;
                while(s[i]!=' ')
                {
                    p+=s[i];
                    i++;
                }
                if(m.find(p)!=m.end())
                {
                    new_string+=m[p];
                    new_string+=' ';
                }
                else
                {
                    new_string+=p;
                    new_string+=' ';
                }
            }
            new_string.pop_back();
            // cout<<new_string<<" ";
            int i=s.length()-1;
            string z="";
            int flag=0;
            while(s[i]!=' ')
            {
                z+=s[i];
               
                if(s[i]=='.')
                flag++;
                i--;
            }
             reverse(z.begin(),z.end());
             double output=stod(z);
            // cout<<fixed<<setprecision(16)<<evaluate(new_string);
            // string str=to_string(evaluate(new_string));
            double eval=evaluate(new_string);
            cout<<"case #"<<++count<<":";
            if(output==eval)
            {
                cout<<"true"<<endl;
            }
            else
            {
                cout<<"false"<<endl;
            }
        }
	return 0;
}
