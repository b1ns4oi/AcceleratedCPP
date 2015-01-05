
#ifndef _GUARD_HCAT_PIC_
#define _GUARD_HCAT_PIC_

#include <ostream>
#include "Pic_base.h"

class HCat_pic : public Pic_base {
	Ptr<Pic_base> left, right;
	HCat_pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r) : left(l), right(r) { }

	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
};


#endif