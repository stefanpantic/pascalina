#pragma once


#include <algorithm> // transform
#include <vector> // vector
#include <memory> // unique_ptr
#include "statement.hpp"


namespace kk
{

	/*
	* @brief AST node for compound statement
	*/
	class compound : public statement
	{
		public:
			explicit compound(const std::vector<statement*> statements)
			{
				for(auto &&e : statements) {
					m_statements.emplace_back(std::move(e));
				}

				std::clog << "[constructor]" << __PRETTY_FUNCTION__ << std::endl;
			}

			// Getter
			const std::vector<std::unique_ptr<statement>> &statements() const
			{ return m_statements; }

			// Accept visitor member function
			void accept(util::visitor &v) override
			{ v.visit(*this); }
		private:
			std::vector<std::unique_ptr<statement>> m_statements;
	}; // class kk::compound

} // namespace kk