#ifndef _GUARD_FRAME_PIC_
#define _GUARD_FRAME_PIC_

#include <ostream>
#include "Pic_base.h"

class Frame_pic : public Pic_base {
	// friend declaration
	//friend Picture frame(const Picture&);

	Ptr<Pic_base> p;
	Frame_pic(const Ptr<Pic_base>& pic) : p(pic) { }

	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
};


#endif