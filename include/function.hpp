#pragma once


#include <iostream> // clog, endl
#include <memory> // unique_ptr
#include "statement.hpp"


namespace kk
{

	/* Forward declarations */
	class var;

	/*
	* @brief AST node for function definitions.
	*/
	class function
	{
		public:
			explicit function(std::string id, var *vars, statement *body)
				:	m_id(std::move(id)),
					m_vars(std::move(vars)),
					m_body(std::move(body))
			{ std::clog << "[constructor]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getters
			inline const std::string &id() const { return m_id; }
			inline const var *vars() const { return m_vars.get(); }
			inline const statement *body() const { return m_body.get(); }

			// Accept visitor member function
			void accept(util::visitor &v)
			{ v.visit(*this); }
		private:
			std::string m_id;
			std::unique_ptr<var> m_vars;
			std::unique_ptr<statement> m_body;
	};

} // namespace kk
