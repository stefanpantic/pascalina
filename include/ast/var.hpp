#pragma once


#include <string>
#include <vector>
#include "types.hpp"
#include "statement.hpp"


namespace pascalina
{

	/*
	* @brief AST node for var statement.
	*/
	class var : public statement
	{
		// Convenience
		using id_type_pairs_impl = std::vector<std::pair<std::vector<std::string>, types::base*>>;
		using id_type_pairs = std::vector<std::pair<std::vector<std::string>, std::unique_ptr<types::base>>>;

		public:
			explicit var(id_type_pairs_impl &&ids = {})
			{
				for(auto &&e : ids) {
					m_ids.emplace_back(e.first, std::move(e.second));
				}

				std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl;
			}

			// Getter
			inline const id_type_pairs &ids() const { return m_ids; }

			// Accept visitor member function
			llvm::Value *accept(util::visitor &v) const override
			{ return v.visit(*this); }
		private:
			id_type_pairs m_ids;
	}; // class pascalina::var

} // namespace pascalina
