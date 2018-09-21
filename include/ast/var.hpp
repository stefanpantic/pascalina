#pragma once


#include <string>
#include <vector>
#include "statement.hpp"


namespace pascalina
{

	/*
	* @brief AST node for var statement.
	*/
	class var : public statement
	{
		public:
			explicit var(const std::vector<std::string> &ids)
				:	m_ids(ids)
			{ std::clog << "[constructor]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getter
			inline const std::vector<std::string> &ids() const { return m_ids; }

			// Accept visitor member function
			void accept(util::visitor &v) override
			{ v.visit(*this); }
		private:
			std::vector<std::string> m_ids;
	}; // class pascalina::var

} // namespace pascalina
