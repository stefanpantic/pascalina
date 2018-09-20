#pragma once


#include <iostream> // clog, endl
#include <vector> // vector
#include <string> // string
#include <memory> // unique_ptr
#include "expression.hpp"


namespace kk
{

	/*
	* @brief AST node for function call expression.
	*/
	class function_call : public expression
	{
		public:
			explicit function_call(std::string id, std::vector<expression*> args)
				:	m_id(std::move(id))
			{ 
				for(auto &&e : args) {
					m_args.emplace_back(std::move(e));
				}

				std::clog << "[constructor]" << __PRETTY_FUNCTION__ << std::endl; 
			}

			// Getter
			inline const std::string &id() const { return m_id; }
			inline const std::vector<std::unique_ptr<expression>> &args() const { return m_args; }

			// Accept visitor member function
			void accept(util::visitor &v) override
			{ v.visit(*this); }
		private:
			std::string m_id;
			std::vector<std::unique_ptr<expression>> m_args;
	}; // class kk::expression

} // namespace kk
