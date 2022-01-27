class Screen {
private:
	unsigned height = 0, width = 0;
	unsigned cursor = 0;
	string contents;
public:
	Screen() = default;
	Screen(unsigned ht, unsigned wd) :
		height(ht), width(wd), contents(ht * wd, ' ') {}
	Screen(unsigned ht, unsigned wd, char c) :
		height(ht), width(wd), contents(ht * wd, c) {}
};
