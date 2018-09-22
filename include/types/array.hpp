#pragma once


#include <iostream> // clog, endl
#include <memory> // unique_ptr
#include "base.hpp"


namespace pascalina::types
{

	/*
	* @brief AST node for array type.
	*/
	class array : public base
	{
		public:
			explicit array(base *underlying, size_t size)
				:	base(typetag::array),
					m_underlying(std::move(underlying)),
					m_size(std::move(size))
			{ std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getters
			inline const base *underlying() const { return m_underlying.get(); }
			inline const size_t &size() const { return m_size; }

			// Overrided clone member function
			base *clone() const override
			{
				return new array(m_underlying->clone(), m_size);
			}

			// Comparission operators
			bool operator==(const base &other) const override
			{
				if(tag() == other.tag()) {
					std::unique_ptr<array> casted{dynamic_cast<array*>(other.clone())};
					return 	m_size == casted->m_size &&
							underlying()->tag() == casted->underlying()->tag();
				}

				return false;
			}

			bool operator!=(const base &other) const override
			{
				return !(*this == other);
			}
		private:
			std::unique_ptr<base> m_underlying;
			size_t m_size;
	}; // class pascalina::types::array


} // namespace pascalina::types
