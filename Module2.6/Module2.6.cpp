#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> l(10);
	std::generate(l.begin(), l.end(), [n = 0]() mutable { return n++; });
	auto i = l.begin();
	for (i; i != l.end(); i++) {
		std::cout << *i;
	}
	std::cout << std::endl;

	std::transform(l.begin(), l.end(), l.begin(),
		[](const int& ref)
		{
			return ref * 2;
		});
	i = l.begin();
	for (i; i != l.end(); i++) {
		std::cout << *i;
	}
	std::cout << std::endl;

	l.erase(std::remove_if(l.begin(), l.end(), [](const int& value)
		{
			return value > 3;
		}
	), l.end());
	i = l.begin();
	for (i; i != l.end(); i++) {
		std::cout << *i;
	}
	std::cout << std::endl;
}