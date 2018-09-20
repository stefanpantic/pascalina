#pragma once


namespace kk
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
	}; // class kk::base

} // namespace kk
