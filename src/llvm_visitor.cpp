#include "llvm_visitor.hpp"
#include "ast.hpp"


namespace pascalina::llvm
{

	/*
	* @brief Builds instance of pascalina::llvm::visitor.
	*/
	visitor::visitor(symtable &&table)
	{ std::clog << "[[34mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl; }

	/*
	* @brief Implementation of llvm visitation member functions.
	*/
	void visitor::visit(const assignment &node) {}
	void visitor::visit(const binary_operator &node) {}
	void visitor::visit(const compound &node) {}
	void visitor::visit(const function_call &node) {}
	void visitor::visit(const function &node) {}
	void visitor::visit(const function_prototype &node) {}
	void visitor::visit(const identifier &node) {}
	void visitor::visit(const iteration &node) {}
	void visitor::visit(const literal &node) {}
	void visitor::visit(const procedure_call &node) {}
	void visitor::visit(const program &node) {}
	void visitor::visit(const selection &node) {}
	void visitor::visit(const unary_operator &node) {}
	void visitor::visit(const var &node) {}

} // namespace pascalina::llvm
