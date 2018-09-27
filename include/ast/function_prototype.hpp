#pragma once


#include <iostream> // clog, endl
#include <vector> // vector
#include "types.hpp"
#include "visitor.hpp"


namespace pascalina
{

	/*
	* @brief AST node for function prototypes.
	*/
	class function_prototype
	{
		// Convenience
		using id_type_pairs_impl = std::vector<std::pair<std::vector<std::string>, types::base*>>;
		using id_type_pairs = std::vector<std::pair<std::vector<std::string>, std::unique_ptr<types::base>>>;

		public:
			explicit function_prototype(std::string id, id_type_pairs_impl &&params = {})
				:	m_id(std::move(id))
			{

				for(auto &&e : params) {
					m_params.emplace_back(e.first, std::move(e.second));
				}

				std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl;
			}

			// Getters
			inline const std::string &id() const { return m_id; }
			inline const id_type_pairs &params() const { return m_params; }

			// Accept visitor member function
			llvm::Value *accept(util::visitor &v) const
			{ return v.visit(*this); }
		private:
			std::string m_id;
			id_type_pairs m_params;
	}; // class pascalina::function_prototype

} // namespace pascalina
