#ifndef STACK_H
#define STACK_H

struct Position
{
	char x;
	char y;
};

struct Stack
{
	unsigned char last_element;
	Position space[LIST_SIZE];
};

Stack stack;

void stack_init();
void stack_push(Position element);
Position stack_pop();
unsigned char stack_length();
Position get_top();


void stack_init()
{
	stack.last_element = 0;
	
	Position tmp;
	tmp.x = -1;
	tmp.y = -1;
		
	ArrayInit(stack.space, tmp, LIST_SIZE);	
}

void stack_push(Position element)
{
	stack.space[stack.last_element] = element;
	stack.last_element += 1;
}

Position stack_pop()
{
	if (stack.last_element > 0)
	{
		stack.last_element -= 1;
		return stack.space[stack.last_element];
	}
	else
	{
		Position tmp;
		tmp.x = -1;
		tmp.y = -1;
		
		return tmp;
	}	
}

unsigned char stack_length()
{
	return stack.last_element;
}

Position get_top()
{
	return stack.space[stack.last_element - 1];
}

#endif
