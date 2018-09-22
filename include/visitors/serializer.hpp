#pragma once


#include "types.hpp"
#include "ast/visitor.hpp"


namespace pascalina::util
{

	/*
	* @brief Visitor that serializes AST.
	*/
	class serializer : public visitor
	{
		public:
			void visit(const assignment &) override;
			void visit(const binary_operator &) override;
			void visit(const compound &) override;
			void visit(const function_call &) override;
			void visit(const function &) override;
			void visit(const function_prototype &) override;
			void visit(const identifier &) override;
			void visit(const iteration &) override;
			void visit(const literal &) override;
			void visit(const procedure_call &) override;
			void visit(const program &) override;
			void visit(const selection &) override;
			void visit(const unary_operator &) override;
			void visit(const var &) override;
		private:
			std::string serialize_type(const types::base *e) const;
	}; // class pascalina::util::serializer

} // namespace pascalina::util
