#include <iostream>
#include <vector>
#include "ast.hpp"
#include "types.hpp"

int
main(void)
{
	pascalina::binary_operator(	pascalina::binary::plus, new pascalina::identifier("name"),
			new pascalina::literal(10));

	std::cout << (pascalina::types::integral() == pascalina::types::integral()) << std::endl;

	auto 	a1{pascalina::types::array(new pascalina::types::integral, 10)},
			a2{pascalina::types::array(new pascalina::types::integral, 10)},
			a3{pascalina::types::array(new pascalina::types::integral, 15)};


	std::cout << (a1 == a2) << std::endl;
	std::cout << (a3 == a2) << std::endl;

	pascalina::program("main", new pascalina::var({}), {}, new pascalina::compound({}));

	return 0;
}
