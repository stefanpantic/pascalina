#pragma once


#include <iostream> // clog, endl
#include <vector> // vector
#include "visitor.hpp"


namespace pascalina
{

	/*
	* @brief AST node for function prototypes.
	*/
	class function_prototype
	{
		public:
			explicit function_prototype(std::string id, const std::vector<std::string> &params)
				:	m_id(std::move(id)),
					m_params(params)
			{ std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getters
			inline const std::string &id() const { return m_id; }
			inline const std::vector<std::string> &params() const { return m_params; }

			// Accept visitor member function
			void accept(util::visitor &v)
			{ v.visit(*this); }
		private:
			std::string m_id;
			std::vector<std::string> m_params;
	}; // class pascalina::function_prototype

} // namespace pascalina
