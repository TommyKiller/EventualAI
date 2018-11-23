#ifndef ID_H
#define ID_H


#include <iostream>
#include <string>


namespace Identity
{
	class ID
	{
	private:
		std::string _id_;

	public:
		ID(std::string id);

		ID(ID &);

		bool operator==(const ID &) const;

		friend std::ostream & operator<<(std::ostream&, const ID &);

		virtual ~ID() = 0;

	};
}


#endif
