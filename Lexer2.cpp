#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

enum tokentype{
    NUMBER,     
    PLUS,       
    MINUS,      
    MUL,        
    DIV,        
    POW,        
    LPAREN,     
    RPAREN,     
    COMMA,      
    FUNCTION,   
    END
};
struct token{
    tokentype type;
    string val;
};

vector<token> lexer(string input){
    vector<token> Tokens;

    for(int i=0;i<input.size();++i){
        char c=input[i];

        if(isdigit(c) || c=='.'){
            string numstr;
            bool hasdot = false;
            while(i<input.size() && (isdigit(input[i]) || input[i]=='.')){
                if(hasdot){
                    if(input[i]=='.'){
                        cerr<<"Invalid number format"<<endl;
                        break;
                    }
                }
                if(input[i]=='.'){
                    hasdot=true;

                }
                numstr+=input[i];
                ++i;

            }
            Tokens.push_back({NUMBER,numstr});
            --i;

        }else if(c=='+'){
            Tokens.push_back({PLUS,"+"});
        }else if(c=='-'){
            Tokens.push_back({MINUS,"-"});
        }else if(c=='*'){
            Tokens.push_back({MUL,"*"});
        }else if(c=='/'){
            Tokens.push_back({DIV,"/"});
        }else if(c=='('){
            Tokens.push_back({LPAREN,"("});
        }else if(c==')'){
            Tokens.push_back({RPAREN,")"});
        }else if(c==' '){
            continue;
        }else if(isalpha(c)){
            string funcstr;
            while(i<input.size() && (isalpha(input[i]))){
                funcstr+=input[i];
                ++i;
            }
            Tokens.push_back({FUNCTION,funcstr});
            --i;
        }else{
            cerr<<"Unknown char"<<c<<endl;
        }
    }
    return Tokens;
}
int main(){
    string Title = "3+2-((16*(9+9))/(2+8))";
    vector<token> tokenized=lexer(Title);
    for(const token& i: tokenized){
        cout<<"The value is: "<<i.val<<" which is of type "<<i.type<<endl;
    }
}