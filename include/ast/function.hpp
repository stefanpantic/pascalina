#pragma once


#include <iostream> // clog, endl
#include <memory> // unique_ptr
#include "statement.hpp"
#include "function_prototype.hpp"


namespace pascalina
{

	/* Forward declarations */
	class var;

	/*
	* @brief AST node for function definitions.
	*/
	class function
	{
		public:
			explicit function(function_prototype *proto, var *vars, statement *body)
				:	m_proto(std::move(proto)),
					m_vars(std::move(vars)),
					m_body(std::move(body))
			{ std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getters
			inline const function_prototype *proto() const { return m_proto.get(); }
			inline const var *vars() const { return m_vars.get(); }
			inline const statement *body() const { return m_body.get(); }

			// Accept visitor member function
			void accept(util::visitor &v)
			{ v.visit(*this); }
		private:
			std::unique_ptr<function_prototype> m_proto;
			std::unique_ptr<var> m_vars;
			std::unique_ptr<statement> m_body;
	};

} // namespace pascalina
