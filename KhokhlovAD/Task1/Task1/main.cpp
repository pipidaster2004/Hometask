#include <iostream>
#include<math.h>
#include "Vector.h"

int main() {
	TVector vec(1.1f,2.1f,3.1f);
	TVector vec2(4.1f,4.1f,4.1f);
	std::cout <<"lenght="<< vec.Lenght() << std::endl;
	std::cout <<"cosin="<< vec.Cosin(vec2) << std::endl;
	std::cout << vec;
	std::cout << vec * vec2;
	std::cout<<std::endl;
	std::cin >> vec2;
	std::cout << vec2;
	std::cout << vec;
	vec = vec - vec2;
	std::cout << vec;
	vec = vec2;
	std::cout << vec;
	return 0;
}