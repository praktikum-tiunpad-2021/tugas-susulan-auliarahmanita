#include "problem_a.hpp"

using namespace strukdat::stack;

template <typename T>
int getMax(Stack<T> Top) {
    Stack<T> gtmx = Top;
    T temp = gtmx -> data;
    while(gtmx != nullptr){
        if(gtmx->data > temp)
            temp = gtmx->data;
        gtmx = gtmx->next;
    }

    return temp;
}

template <typename T>
int getEqualStack(Stack<T> Top1, Stack<T> Top2, Stack<T> Top3)
{
     int temp = 0, hasil = 0;
    pointer<int> gtestck;
    while(!isEmpty(Top1)){
        gtestck = pop(Top1, gtestck);
        temp += gtestck->data;
    }

    hasil = temp;
    temp = 0;
    while(!isEmpty(Top2)){
        gtestck = pop(Top2, gtestck);
        temp += gtestck->data;
    }

    hasil = temp < hasil ? temp : hasil;
    temp = 0;
    while(!isEmpty(Top3)){
        gtestck = pop(Top3, gtestck);
        temp += gtestck->data;
    }

    hasil = temp < hasil ? temp : hasil;
    temp = 0;
    return hasil;
}

bool isBracketBalanced(std::string expression)
{ 
    Stack<char> Top;
    pointer<char> temp;
    pointer<char> del;
    Top = createStack(Top);
    if(expression.length() % 2 == 1)
        return false;
    for(int i = 0; i < expression.length() ; i++)
    {
        if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            createElement(temp, expression[i]);
            Top = push(Top, temp);
        }
        else if(expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            if(isEmpty(Top)){
                return false;
            }

            if(peek(Top) == '(' && expression[i] == ')'){
                pop(Top, del);
            }

            else if(peek(Top) == '[' && expression[i] == ']'){
                pop(Top, del);
            }

            else if(peek(Top) == '{' && expression[i] == '}'){
                pop(Top, del);
            }

            else{
                return false;
            }
        }
    }
    if(isEmpty(Top)){
        return true;

    }
    else{
        return false;
    }
}