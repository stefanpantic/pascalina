#include <llvm/IR/Verifier.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include "ast/visitor.hpp"
#include "visitor.hpp"


namespace pascalina
{

	/*
	* @brief Builds instance of pascalina::visitor.
	*/
	visitor::visitor(symtable &&table)
		:	m_table(std::move(table)),
			llvm_builder(llvm_context),
			m_scope("__global__")
	{
		// Create a new llvm::Module instance
		llvm_module = std::make_unique<llvm::Module>("__pascalina__", llvm_context);
		// Create a new pass manager attached to llvm_module
		llvm_pass_manager = std::make_unique<llvm::legacy::FunctionPassManager>(llvm_module.get());
		// Do some magic optimizations
		llvm_pass_manager->add(llvm::createInstructionCombiningPass());
		// Reassociate expressions
		llvm_pass_manager->add(llvm::createReassociatePass());
		// Eliminate common subexpressions
		llvm_pass_manager->add(llvm::createNewGVNPass());
		// Simplify control flow graph
		llvm_pass_manager->add(llvm::createCFGSimplificationPass());
		// Add mem2reg pass (promotes allocas to registers)
		llvm_pass_manager->add(llvm::createDemoteRegisterToMemoryPass());
		// Initialize the pass manager
		llvm_pass_manager->doInitialization();

		// Initialize alloca table
		for(auto &&e1 : m_table) {
			for(auto &&e2 : e1.second) {
				llvm_named_values[e1.first][e2.first] = nullptr;
				std::cout << e1.first << ": " << e2.first << std::endl;
			}
		}

		std::clog << "[[34mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl;
	}


	llvm::Value *visitor::visit(const assignment &n)
	{
		// Generate code for right hand side of operation
		auto rhs{n.rhs()->accept(*this)};

		// Lookup local variable name
		if(llvm_named_values[m_scope].end() != llvm_named_values[m_scope].find(n.id()->id())) {
			auto alloca{llvm_named_values[m_scope][n.id()->id()]};
			llvm_builder.CreateStore(rhs, alloca);
		} else {
			llvm::GlobalVariable* global{llvm_module->getNamedGlobal(n.id()->id())};
			llvm_builder.CreateStore(rhs, global);
		}

		// Return value
		return rhs;
	}

	llvm::Value *visitor::visit(const binary_operator &n)
	{
		// Generate code for left and right hand sides of operator
		auto lhs{n.lhs()->accept(*this)}, rhs{n.rhs()->accept(*this)};

		if(lhs->getType() == llvm::Type::getInt32Ty(llvm_context)) {
			lhs = llvm_builder.CreateSIToFP(lhs, llvm::Type::getDoubleTy(llvm_context));
		}

		if(rhs->getType() == llvm::Type::getInt32Ty(llvm_context)) {
			rhs = llvm_builder.CreateSIToFP(rhs, llvm::Type::getDoubleTy(llvm_context));
		}

		// Generate code based on operator
		switch(n.op())
		{
			case binary::divides:
				return llvm_builder.CreateFDiv(lhs, rhs);
			case binary::equal_to:
				return llvm_builder.CreateFCmpUEQ(lhs, rhs);
			case binary::greater:
				return llvm_builder.CreateFCmpUGT(lhs, rhs);
			case binary::greater_equal:
				return llvm_builder.CreateFCmpUGE(lhs, rhs);
			case binary::less:
				return llvm_builder.CreateFCmpULT(lhs, rhs);
			case binary::less_equal:
				return llvm_builder.CreateFCmpULE(lhs, rhs);
			case binary::minus:
				return llvm_builder.CreateFSub(lhs, rhs);
			case binary::multiplies:
				return llvm_builder.CreateFMul(lhs, rhs);
			case binary::not_equal_to:
				return llvm_builder.CreateFCmpUNE(lhs, rhs);
			case binary::plus:
				return llvm_builder.CreateFAdd(lhs, rhs);
		}
	}

	llvm::Value *visitor::visit(const compound &)
	{}

	llvm::Value *visitor::visit(const function_call &)
	{}

	llvm::Value *visitor::visit(const function &)
	{}

	llvm::Value *visitor::visit(const function_prototype &)
	{}

	llvm::Value *visitor::visit(const identifier &n)
	{
		if(llvm_named_values[m_scope].end() != llvm_named_values[m_scope].find(n.id())) {
			// Load local alloca
			auto alloca{llvm_named_values[m_scope][n.id()]};
			return llvm_builder.CreateLoad(alloca);
		} else {
			// Load global variable
			return llvm_module->getNamedGlobal(n.id());
		}
	}

	llvm::Value *visitor::visit(const iteration &)
	{}

	llvm::Value *visitor::visit(const literal &n)
	{
		return llvm::ConstantFP::get(llvm_context, llvm::APFloat(n.val()));
	}

	llvm::Value *visitor::visit(const procedure_call &)
	{}

	llvm::Value *visitor::visit(const program &)
	{}

	llvm::Value *visitor::visit(const selection &)
	{}

	llvm::Value *visitor::visit(const unary_operator &)
	{}

	llvm::Value *visitor::visit(const var &)
	{}

	/*
	* @brief Create int alloca.
	*/
	llvm::AllocaInst *visitor::make_integer_alloca(llvm::Function *f, const std::string &id)
	{
		llvm::IRBuilder builder(&f->getEntryBlock(), f->getEntryBlock().begin());
		return builder.CreateAlloca(llvm::Type::getInt32Ty(llvm_context), 0, id.c_str());
	}

	/*
	* @brief Create double alloca.
	*/
	llvm::AllocaInst *visitor::make_floating_alloca(llvm::Function *f, const std::string &id)
	{
		llvm::IRBuilder builder(&f->getEntryBlock(), f->getEntryBlock().begin());
		return builder.CreateAlloca(llvm::Type::getDoubleTy(llvm_context), 0, id.c_str());
	}
} // namespace pascalina
