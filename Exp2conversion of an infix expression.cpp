#include <iostream>
#include <stack>

using namespace std;
class InToPost
{
char input[50];
stack <char> st;
public:
InToPost();
bool isOpertator(char ch);
int getISP();
int getICP(char ch);
void convert();
};
void InToPost::convert()
{
int k=0,icp,isp;
char temp;
while(input[k] !='\0')
{
if(isOpertator(input[k]))
{
if(input[k]=='(')
{
st.push(input[k]);
k++;
}
else
{
if(input[k]== ')')
{

do
{
temp = st.top();
if(temp != '(')
{
cout<<temp;
}
st.pop();
}while(temp != '(');
k++;
}
else
{
icp = getICP(input[k]);
isp = getISP();
if(icp > isp)
{
st.push(input[k]);
k++;
}
else
{
cout<<st.top();
st.pop();
}
}
}

}
else
{
cout<<input[k];

k++;
}
}

while(!st.empty())
{
cout<<st.top();
st.pop();
}
}
InToPost::InToPost()
{
cout<<"\n Enter the infix expression";
cin>>input;
}

bool InToPost::isOpertator(char ch)
{
if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='('||ch==')')
return true;
else
return false;
}
int InToPost::getISP()
{
char ch;
if(!st.empty())
{
ch = st.top();
if(ch == '+'|| ch == '-')
return 1;
if(ch == '*'|| ch == '/')

return 2;
if(ch == '^')
return 3;
if(ch == '(')
return 0;
if(ch == ')')
return -1;
}
return 0;
}
int InToPost::getICP(char ch)
{
if(ch == '+'|| ch == '-')
return 1;
if(ch == '*'|| ch == '/')
return 2;
if(ch == '^')
return 4;
if(ch == '(')
return 5;
if(ch == ')')
return -1;
return 0;
}

int main()
{
InToPost ip;
cout<<"\n The postfix expression is \n";
ip.convert();
return 0;
}
