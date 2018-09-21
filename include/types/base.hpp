#pragma once


#include <iostream> // clog, endl


namespace pascalina::types
{

	/*
	* @brief Enumerated types.
	*/
	enum class typetag
	{
		integral,
		none,
		real,
		array,
	}; // enum class pascalina::typetag

	/*
	* @brief Base class for type system.
	*/
	class base
	{
		public:
			explicit base(typetag tag)
				:	m_tag(std::move(tag))
			{ std::clog << "[constructor]" << __PRETTY_FUNCTION__ << std::endl; }

			// Virtual destructor
			virtual ~base() {}

			// Getter
			inline const typetag &tag() const { return m_tag; }

			// Virtual clone member function
			virtual base *clone() const = 0;

			// Virtual comparisson operators
			virtual bool operator==(const base&) const = 0;
			virtual bool operator!=(const base&) const = 0;
		private:
			typetag m_tag;
	}; // class pascalina::types::base

} // namespace pascalina
