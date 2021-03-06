#pragma once


#include <iostream> // clog, endl
#include <memory> // unique_ptr
#include "expression.hpp"
#include "statement.hpp"


namespace pascalina
{

	/* Forward declarations */
	class identifier;

	/*
	* @brief AST node for assignment operation.
	*/
	class assignment : public statement
	{
		public:
			explicit assignment(identifier *id, expression *rhs)
				:	m_id(std::move(id)),
					m_rhs(std::move(rhs))
			{ std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getters
			inline const identifier *id() const { return m_id.get(); }
			inline const expression *rhs() const { return m_rhs.get(); }

			// Accept visitor member function
			llvm::Value *accept(util::visitor &v) const override
			{ return v.visit(*this); }
		private:
			std::unique_ptr<identifier> m_id;
			std::unique_ptr<expression> m_rhs;
	}; // class pascalina::assignment

} // namespace pascalina
