#ifndef DELEGATE_H
#define DELEGATE_H


namespace Events
{
	class Delegate
	{
	private:
		struct Object {};
		typedef void (Object::*Method)();

		Object *_ptrobject;
		Method _ptrmethod;

	public:
		Delegate()
			: _ptrobject(nullptr),
			_ptrmethod(nullptr)
		{
		}

		template <class Owner, class ...Args>
		Delegate(Owner *owner, void (Owner::*func)(Args...))
		{
			_ptrobject = reinterpret_cast<Object*>(owner);
			_ptrmethod = reinterpret_cast<Method>(func);
		}

		template <class ...Args>
		void operator()(Args... args)
		{
			typedef void (Object::*Method)(Args...);
			Method func = reinterpret_cast<Method>(_ptrmethod);

			if (_ptrobject && func)
				(_ptrobject->*func)(args...);
		}

		bool operator!()
		{
			return (!_ptrobject || !_ptrmethod);
		}

		bool operator==(const Delegate & delegate)
		{
			return (_ptrobject == delegate._ptrobject && _ptrmethod == delegate._ptrmethod);
		}

		bool operator!=(const Delegate & delegate)
		{
			return !(*this == delegate);
		}

	};
}


#endif
