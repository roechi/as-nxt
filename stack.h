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

void stack_init();
void stack_push(Position element);
Position stack_pop();
unsigned char stack_length();
