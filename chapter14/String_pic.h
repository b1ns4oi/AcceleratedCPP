
#ifndef _GUARD_STRING_PIC_
#define _GUARD_STRING_PIC_

#include <string>
#include <vector>
#include <ostream>
#include "Pic_base.h"

class String_pic : public Pic_base {
	std::vector<std::string> data;
	String_pic(const std::vector<std::string>& v) : data(v) { }

	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
};


#endif