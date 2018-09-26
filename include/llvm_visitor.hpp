#pragma once


#include <iostream> // clog, endl
#include <memory> // unique_ptr
#include <unordered_map> // unordered_map
#include <vector> // vector
#include <string> // string
#include "ast/visitor.hpp"
#include "types.hpp"


namespace pascalina::llvm
{

	/*
	* @brief Visitor that traverses the tree and compiles it to LLVM IR code.
	*/
	class visitor : public util::visitor
	{
		using symtable = std::unordered_map<std::string, std::unordered_map<std::string, std::unique_ptr<pascalina::types::base>>>;
		public:
			explicit visitor(symtable &&);

			void visit(const assignment &) override;
			void visit(const binary_operator &) override;
			void visit(const compound &) override;
			void visit(const function_call &) override;
			void visit(const function &) override;
			void visit(const function_prototype &) override;
			void visit(const identifier &) override;
			void visit(const iteration &) override;
			void visit(const literal &) override;
			void visit(const procedure_call &) override;
			void visit(const program &) override;
			void visit(const selection &) override;
			void visit(const unary_operator &) override;
			void visit(const var &) override;
		private:
			// TODO: alloca table.
			// TODO: local llvm::Value*
	}; // class pascalina::llvm::visitor

} // namespace pascalina::llvm
