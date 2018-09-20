#pragma once


namespace pascalina
{

	/*
	* @brief AST node base class.
	*/
	template<typename Visitor>
	class base
	{
		public:
			// Virtual destructor
			virtual ~base() {}

			// Accept visitor member function
			virtual void accept(Visitor &v) = 0;
	}; // class pascalina::base

} // namespace pascalina
