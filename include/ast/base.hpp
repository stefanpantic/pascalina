#pragma once


#include <llvm/IR/Value.h>


namespace pascalina
{

	/*
	* @brief AST node base class.
	*/
	template<typename Visitor>
	class base
	{
		public:
			// Virtual destructor
			virtual ~base() {}

			// Accept visitor member function
			virtual llvm::Value *accept(Visitor &v) const = 0;
	}; // class pascalina::base

} // namespace pascalina
