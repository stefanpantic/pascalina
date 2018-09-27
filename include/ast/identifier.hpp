#pragma once


#include <string> // string
#include "expression.hpp"


namespace pascalina
{

	/*
	* @brief AST node for identifier.
	*/
	class identifier : public expression
	{
		public:
			explicit identifier(std::string id)
				:	m_id(std::move(id))
			{ std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl; }

			// ID getter
			inline const std::string &id() const { return m_id; }

			// Accept visitor member function
			llvm::Value *accept(util::visitor &v) const override
			{ return v.visit(*this); }
		private:
			std::string m_id;
	}; // class pascalina::identifier

} // namespace pascalina
