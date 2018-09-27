#pragma once


#include <algorithm> // transform
#include <vector> // vector
#include <memory> // unique_ptr
#include "expression.hpp"
#include "statement.hpp"


namespace pascalina
{

	/*
	* @brief AST node for array modify statement
	*/
	class array_modify : public statement
	{
		public:
			explicit array_modify(std::string id, expression *index, expression *val)
				:	m_id(std::move(id)),
					m_index(std::move(index)),
					m_val(std::move(val))
			{
				std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl;
			}

			// Getter
			inline const std::string id() const { return m_id; }
			inline const expression *index() const { return m_index.get(); }
			inline const expression *val() const { return m_val.get(); }

			// Accept visitor member function
			llvm::Value *accept(util::visitor &v) const override
			{ return v.visit(*this); }
		private:
			std::string m_id;
			std::unique_ptr<expression> m_index, m_val;
	}; // class pascalina::array_modify

} // namespace pascalina
