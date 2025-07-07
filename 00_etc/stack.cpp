
#include <iostream>
using namespace std;

class Stack {
    
int* array;
int nTop;
int nCapacity;

    
Stack() {

    array = new int[1];
    nTop = -1;
    nCapacity = 0;
    
}
void push(int input)
{
    if(nTop = nCapacity)
    {
        upscale();
    }
    array[++nTop] = input;
    
}
bool isEmpty()
{
    return nTop < 0 ; true : false;
}
void upscale()
{
    
    int* temp = new int[(nCapacity+1) * 2];
    
    memcpy(temp,array,(nCapacity+1)*sizeof(int));
    
    array = temp;
    
    nCapacity = (nCapacity+1) * 2 - 1;
    
} 
void pop()
{
    if(!isEmpty()) 
    { 
      int result = array[nTop];
      nTop--;
      cout << result << endl;
    }
    else
    {
      cout << -1 << endl;
    }
    
}   
void top()
{
    if(!isEmpty()) 
    { 
      int result = array[nTop];
      cout << result << endl;
    }
    else
    {
      cout << -1 << endl;
    }
    
}
void size()
{
    if(!isEmpty()) 
    { 
      int result = top + 1;
      cout << result << endl;
    }
    else
    {
      cout << -1 << endl;
    }
}
};
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    Stack* st = new Stack();
    String s;
    
    for(int i = 0 ; i <= n ; i ++)
    {
        getline(cin,s)
        if(s.find("push")!=string::npos)
        {
            int sum = 0;
            for(int j = 5; j <= s.size() ; j++)
            {
                if(!(s[j] >= '0' && s[j] <= '9'))
                {
                    break;
                }
                sum *= 10;
                sum += static_cast<int>(s[j]-'0') ;
            }
            st->push(sum);
        }
        else if(s.find("pop")!=string::npos)
        {
            st->pop();
        }
        else if(s.find("top")!=string::npos)
        {
            st->top();
        }
        else if(s.find("empty")!=string::npos)
        {
            cout << st->isEmpty() << endl;
        }
        else if(s.find("size")!=string::npos)
        {
            st->size();
        }
        
    }

    return 0;
}