#pragma once


#include <iostream> // clog, endl
#include <vector> // vector
#include <string> // string
#include <memory> // unique_ptr
#include "expression.hpp"


namespace pascalina
{

	/*
	* @brief AST node for function call expression.
	*/
	class function_call : public expression
	{
		public:
			explicit function_call(std::string id, std::vector<expression*> &&args)
				:	m_id(std::move(id))
			{
				for(auto *e : args) {
					m_args.emplace_back(std::move(e));
				}

				std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl;
			}

			// Getter
			inline const std::string &id() const { return m_id; }
			inline const std::vector<std::unique_ptr<expression>> &args() const { return m_args; }

			// Accept visitor member function
			llvm::Value *accept(util::visitor &v) const override
			{ return v.visit(*this); }
		private:
			std::string m_id;
			std::vector<std::unique_ptr<expression>> m_args;
	}; // class pascalina::expression

} // namespace pascalina
