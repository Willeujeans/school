#include <fstream>
#include <iostream>
#include <time.h>
#include <stack>
#include <queue>
#include <string>
using namespace std;

/*
 Function EvaluatePostFix(){
    Starting at the leftmost side{
        If(character is an operand){
            push onto stack
        }
        If(character is an operator){
            pull top two operands from stack{
                operand1 = top;
                operand2 = secondTop;
            }
            execute operation on the operands{
               result = operand1 [operation] operand2
            }
            push result onto operand stack
        }
        When queue is empty{
            top value of stack is the result.
        }
    }
}
*/

//Checks if character is a number or a operator
bool isOperand(char ch){
    return !(ch == '+' || ch=='-' || ch== '*' || ch=='/');
}

//Executes the given operation on two numbers
int executeOperation(int num1, char operation, int num2){
    cout << endl;
    int result = 0;
    if(operation == '+'){
        result = num2 + num1;
    }
    else if(operation == '-'){
        result = num2 - num1;
    }
    else if(operation == '*'){
        result = num2 * num1;
    }
    else if(operation == '/'){
        result = num2 / num1;
    }
    cout << num2 << operation << num1 << endl;
    return result;
}

int evalPostfix(std::queue<char> expression){
    std::stack<int> expressionStack;
    while(!expression.empty()){ //While our queue still has elements to be popped
        if(isOperand(expression.front())){ //The character is an operand
            int number = expression.front() - '0'; //converting into an integer
            expressionStack.push(number); //Pushing onto the stack
        }else{ //The character is an Operator
            int number1 = expressionStack.top(); //pulls one number
            expressionStack.pop();
            int number2 = expressionStack.top(); //pulls second number
            expressionStack.pop();
            expressionStack.push(executeOperation(number1, expression.front(), number2));//operates, and pushes onto the stack
        }
        expression.pop(); //Moving along the Queue
    }
    return expressionStack.top(); //Queue is empty so we return the stack as the expression's answer
}

int main() {
    std::queue<char> queue1, queue2;
    //basic simple addition
    queue1.push('1');
    queue1.push('2');
    queue1.push('+'); //12+ -> 1+2 second number operation first number
    cout<<"Queue1 evaluates to "<<evalPostfix(queue1)<<std::endl;
    queue2.push('5');
    queue2.push('6');
    queue2.push('7');
    queue2.push('+');
    queue2.push('1');
    queue2.push('2');
    queue2.push('+');
    queue2.push('-');
    queue2.push('*');
    queue2.push('4');
    queue2.push('/');
    cout<<"Queue2 evaluates to " << evalPostfix(queue2) << std::endl;
    return 0;
}
