
#ifndef _GUARD_VCAT_PIC_
#define _GUARD_VCAT_PIC_

#include <ostream>
#include "Pic_base.h"

class VCat_pic : public Pic_base {
	Ptr<Pic_base> top, bottom;
	VCat_pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b) : top(t), bottom(b) { }

	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
};


#endif