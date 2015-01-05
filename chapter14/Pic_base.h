#ifndef _GUARD_PIC_BASE_
#define _GUARD_PIC_BASE_

#include <string>
#include <vector>
#include <ostream>

class Pic_base {
	typedef std::vector<string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;

	virtual wd_sz width() const = 0;
	virtual ht_sz height() const = 0;
	virtual void display(const std::ostream&, ht_sz, bool) const = 0;
};



#endif