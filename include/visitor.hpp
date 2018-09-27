#pragma once


#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <vector>
#include <unordered_map>
#include "ast.hpp"
#include "types.hpp"


namespace pascalina
{

	/*
	* @brief Visitor base class for AST nodes.
	*/
	class visitor : public util::visitor
	{
		// Convenience
		using symtable = std::unordered_map<std::string, std::unordered_map<std::string, std::unique_ptr<pascalina::types::base>>>;
		using alloca_table = std::unordered_map<std::string, std::unordered_map<std::string, llvm::AllocaInst*>>;

		public:
			explicit visitor(symtable &&table);

			llvm::Value *visit(const assignment &) override;
			llvm::Value *visit(const binary_operator &) override;
			llvm::Value *visit(const compound &) override;
			llvm::Value *visit(const function_call &) override;
			llvm::Value *visit(const function &) override;
			llvm::Value *visit(const function_prototype &) override;
			llvm::Value *visit(const identifier &) override;
			llvm::Value *visit(const iteration &) override;
			llvm::Value *visit(const literal &) override;
			llvm::Value *visit(const none &) override;
			llvm::Value *visit(const procedure_call &) override;
			llvm::Value *visit(const program &) override;
			llvm::Value *visit(const selection &) override;
			llvm::Value *visit(const unary_operator &) override;
			llvm::Value *visit(const var &) override;
		private:
			// Create allocas
			llvm::AllocaInst *make_integer_alloca(llvm::Function *f, const std::string &id);
			llvm::AllocaInst *make_floating_alloca(llvm::Function *f, const std::string &id);
			//llvm::AllocaInst *make_array_alloca(llvm::Function *f, const std::string &id, size_t size);
		private:
			// Symbol table
			symtable m_table;

			// LLVM junk
			llvm::LLVMContext llvm_context;
			llvm::IRBuilder<> llvm_builder;
			std::unique_ptr<llvm::Module> llvm_module;
			std::unique_ptr<llvm::legacy::FunctionPassManager> llvm_pass_manager;
			alloca_table llvm_named_values;
			std::unordered_map<std::string, llvm::Function*> llvm_functions;

			// Scope
			std::string m_scope;
	}; // class pascalina::util::visitor

} // namespace pascalina



