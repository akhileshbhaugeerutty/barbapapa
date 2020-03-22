class Stack {
	char *v;
	int top;
	int max_size;
public:
	class Underflow{};
	class Overflow{};
	class Bad_size{};
	
	Stack(int);
	~Stack();
	
	void push(char c);
	char pop();
	
	void affiche();
};
