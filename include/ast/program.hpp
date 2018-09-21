#pragma once

#include <iostream> // clog, endl
#include <memory> // unique_ptr
#include <vector> // vector
#include "base.hpp"
#include "statement.hpp"
#include "visitor.hpp"


namespace pascalina
{

	/* Forwaed declarations */
	class function;
	class var;

	/*
	* @brief AST root for entire program tree.
	*/
	class program
	{
		public:
			explicit program(	std::string id, var *declarations,
								std::vector<function*> subprograms, statement *mainfunc)
				:	m_id(std::move(id)),
					m_declarations(std::move(declarations)),
					m_main(std::move(mainfunc))
			{
				for(auto *e : subprograms) {
					m_subprograms.emplace_back(e);
				}

				std::clog << "[constructor]" << __PRETTY_FUNCTION__ << std::endl;
			}

			// Getters
			inline const std::string &id() const { return m_id; }
			inline const var *declarations() const { return m_declarations.get(); }
			inline const std::vector<std::unique_ptr<function>> &subprograms() const { return m_subprograms; }
			inline const statement *mainfunc() const { return m_main.get(); }

			// Accept visitor member function
			void accept(util::visitor &v)
			{ v.visit(*this); }
		private:
			std::string m_id;
			std::unique_ptr<var> m_declarations;
			std::vector<std::unique_ptr<function>> m_subprograms;
			std::unique_ptr<statement> m_main;
	}; // class pascalina::program

} // namespace pascalina
