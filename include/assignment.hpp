#pragma once


#include <iostream> // clog, endl
#include <memory> // unique_ptr
#include "expression.hpp"


namespace pascalina
{

	/* Forward declarations */
	class identifier;

	/*
	* @brief AST node for assignment operation.
	*/
	class assignment : public expression
	{
		public:
			explicit assignment(identifier *id, expression *rhs)
				:	m_id(std::move(id)),
					m_rhs(std::move(rhs))
			{ std::clog << "[constructor]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getters
			inline const identifier *id() const { return m_id.get(); }
			inline const expression *rhs() const { return m_rhs.get(); }

			// Accept visitor member function
			void accept(util::visitor &v) override
			{ v.visit(*this); }
		private:
			std::unique_ptr<identifier> m_id;
			std::unique_ptr<expression> m_rhs;
	}; // class pascalina::assignment

} // namespace pascalina
