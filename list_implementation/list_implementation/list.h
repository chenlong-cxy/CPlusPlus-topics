#pragma once

namespace cl
{
	template<T>
	struct _list_node
	{
		_list_node(const T& val = T())
		:_val(val)
		, _prev(nullptr)
		, _next(nullptr)
		{}

		T _val;
		_list_node<T>* _prev;
		_list_node<T>* _next;
	};



	template<class T>
	class list
	{
	public:
		typedef _list_node<T> node;

	private:
		node* _head;
	};
}