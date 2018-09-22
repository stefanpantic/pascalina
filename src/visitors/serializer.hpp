#include <algorithm> // copy
#include <iterator> // ostream_iterator
#include <iostream> // clog, cerr, endl
#include "ast.hpp"
#include "visitors/serializer.hpp"


namespace pascalina::util
{

	/*
	* @brief Visit AST node member functions:
	*/
	// @{
	void serializer::visit(const assignment &)
	{

	}

	void serializer::visit(const binary_operator &)
	{

	}

	void serializer::visit(const compound &)
	{

	}

	void serializer::visit(const function_call &)
	{

	}

	void serializer::visit(const function &)
	{

	}

	void serializer::visit(const function_prototype &)
	{

	}

	void serializer::visit(const identifier &)
	{

	}

	void serializer::visit(const iteration &)
	{

	}

	void serializer::visit(const literal &)
	{

	}

	void serializer::visit(const procedure_call &)
	{

	}

	void serializer::visit(const program &e)
	{
		std::clog << "[[34mvisitor::serializer[0m]" << __PRETTY_FUNCTION__ << std::endl;

		// Print program ID
		std::cout << "program " << e.id() << ";" << std::endl;
		// Visit global declarations
		e.declarations()->accept(*this);
		// Visit subprograms
		for(auto &&x : e.subprograms()) {
			x->accept(*this);
		}
		// Visit main function
		e.mainfunc()->accept(*this);
	}

	void serializer::visit(const selection &)
	{

	}

	void serializer::visit(const unary_operator &)
	{

	}

	void serializer::visit(const var &e)
	{
		// Serialize VAR token.
		std::cout << "var" << std::endl;
		// Serialize variables and their types.
		for(auto &&x : e.ids()) {
			std::copy(x.first.begin(), x.first.end() - 1, std::ostream_iterator<std::string>(std::cout, ", "));
			std::cout << x.first.back();
			std::cout << ": " + serialize_type(x.second.get()) + ";" << std::endl;
		}
	}
	// @}

	/*
	* @brief Serialize a type based on it's tag.
	*/
	std::string serializer::serialize_type(const types::base *e) const
	{
		switch(e->tag())
		{
			case types::typetag::integral:
				return "Integer";
			case types::typetag::real:
				return "Real";
			case types::typetag::array: {
					std::unique_ptr<const types::array> casted{dynamic_cast<const types::array*>(e->clone())};
					return 	"array [1.." + std::to_string(casted->size()) +
							"] of " + serialize_type(casted->underlying());
				}
			default:
				return "";
		}
	}

} // namespace pascalina::util
