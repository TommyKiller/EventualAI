#ifndef EVENT_H
#define EVENT_H


#include "Delegate.h"


namespace Events
{
	class Event
	{
	private:
		struct Node
		{
			Delegate _data;
			Node *_next;

			Node(Delegate data, Node *next) :
				_data(data),
				_next(next)
			{
			}
		};

		class NodeIterator
		{
		private:
			Node *_node;

		public:
			NodeIterator(Node *node)
				: _node(node)
			{
			}

			bool HasNext() const
			{
				return (_node) ? true : false;
			}

			Delegate& GetNext()
			{
				Delegate & delegate = _node->_data;
				_node = _node->_next;

				return delegate;
			}
		};

		Node *_first_node;
		Node *_last_node;

		void Push(const Delegate & data)
		{
			if (_last_node)
			{
				bool subscribed = false;
				NodeIterator iterator(_first_node);

				while (iterator.HasNext())
				{
					if (iterator.GetNext() == data)
					{
						subscribed = true;
					}
				}

				if (!subscribed)
				{
					Node *temp_node = new Node(data, nullptr);
					_last_node->_next = temp_node;
					_last_node = temp_node;
				}
			}
			else
			{
				Node *temp_node = new Node(data, nullptr);
				_first_node = temp_node;
				_last_node = temp_node;
			}
		}

		void Remove(const Delegate & data)
		{
			Node *current_node = _first_node;
			Node *previous_node = _first_node;

			while (current_node)
			{
				if (current_node->_data == data)
				{
					if (current_node == _first_node)
					{
						_first_node = current_node->_next;
						previous_node = current_node->_next;
					}
					else
					{
						previous_node->_next = current_node->_next;
					}

					Node *temp_node = current_node->_next;
					delete current_node;
					current_node = temp_node;
				}
				else
				{
					previous_node = current_node;
					current_node = current_node->_next;
				}
			}

			_last_node = previous_node;
		}

	public:
		Event()
			: _first_node(nullptr),
			_last_node(nullptr)
		{
		}

		Event(const Event &) = delete;

		void operator=(const Event &) = delete;

		Event & operator+= (const Delegate & delegate)
		{
			Push(delegate);
			return *this;
		}

		Event & operator-= (const Delegate & delegate)
		{
			Remove(delegate);
			return *this;
		}

		template <class ...Args>
		void operator()(Args... args)
		{
			NodeIterator iterator(_first_node);
			Delegate delegate;

			while (iterator.HasNext())
			{
				delegate = iterator.GetNext();
				delegate(args...);
			}
		}

		~Event()
		{
			Node *current_node = _first_node;

			while (current_node)
			{
				Node *temp_node = current_node->_next;
				delete current_node;
				current_node = temp_node;
			}
		}
	};
}


#endif
