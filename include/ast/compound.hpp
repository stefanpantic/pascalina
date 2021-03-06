#pragma once


#include <algorithm> // transform
#include <vector> // vector
#include <memory> // unique_ptr
#include "statement.hpp"


namespace pascalina
{

	/*
	* @brief AST node for compound statement
	*/
	class compound : public statement
	{
		public:
			explicit compound(std::vector<statement*> &&statements)
			{
				for(auto *e : statements) {
					m_statements.emplace_back(std::move(e));
				}

				std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl;
			}

			// Getter
			inline const std::vector<std::unique_ptr<statement>> &statements() const
			{ return m_statements; }

			// Accept visitor member function
			llvm::Value *accept(util::visitor &v) const override
			{ return v.visit(*this); }
		private:
			std::vector<std::unique_ptr<statement>> m_statements;
	}; // class pascalina::compound

} // namespace pascalina
