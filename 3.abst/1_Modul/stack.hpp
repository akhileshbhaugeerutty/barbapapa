namespace Stack {
	struct Rep;
	typedef Rep& stack;
	
	stack create();
	void destroy(stack s);
	
	void push(stack s, char c);
	char pop(stack s);
	
	class Overflow{};
	class Underflow{};
}
