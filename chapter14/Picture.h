
#ifndef _GUARD_PICTURE_
#define _GUARD_PICTURE_

#include <string>
#include <vector>
#include <ostream>
#include "Ptr.h"
#include "Pic_base.h"
#include "Frame_pic.h"
#include "VCat_pic.h"
#include "HCat_pic.h"
#include "String_pic.h"

class Picture {
public:
	// friend declaration
	friend Picture frame(const Picture&);
	friend Picture hcat(const Picture& p1, const Picture& p2);
	friend Picture vcat(const Picture&, const Picture&);

	Picture(const std::vector<std::string>& = std::vector<std::string>());
	Picture(Pic_base* ptr) : p(ptr) { }

private:
	Ptr<Pic_base> p;
};

// Q: can I eliminate " = std::vector<std::string>()" ?
Picture::Picture(const std::vector<std::string>& vec = std::vector<std::string>()) : p(new String_pic(vec)) { }

Picture frame(const Picture& pic)
{
	return new Frame_pic(pic.p);
}

Picture hcat(const Picture& p1, const Picture& p2)
{
	return new HCat_pic(p1.p, p2.p);
}

Picture vcat(const Picture& p1, const Picture& p2)
{
	return new VCat_pic(p1.p, p2.p);
}

std::ostream& operator<<(std::ostream&, const Picture&);


#endif