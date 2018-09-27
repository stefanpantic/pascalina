#pragma once


#include <algorithm> // transform
#include <vector> // vector
#include <memory> // unique_ptr
#include "expression.hpp"


namespace pascalina
{

	/*
	* @brief AST node for array_index statement
	*/
	class array_index : public expression
	{
		public:
			explicit array_index(std::string id, expression *index)
				:	m_id(std::move(id)),
					m_index(std::move(index))
			{
				std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl;
			}

			// Getter
			inline const std::string id() const { return m_id; }
			inline const expression *index() const { return m_index.get(); }

			// Accept visitor member function
			llvm::Value *accept(util::visitor &v) const override
			{ return v.visit(*this); }
		private:
			std::string m_id;
			std::unique_ptr<expression> m_index;
	}; // class pascalina::array_index

} // namespace pascalina
