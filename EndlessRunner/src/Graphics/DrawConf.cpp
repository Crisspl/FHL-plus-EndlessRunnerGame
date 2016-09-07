#include "DrawConf.h"

namespace fhl
{

DrawConf DrawConf::Default;

DrawConf::DrawConf(const Transform & _transform, Texture * _texture)
	: transform(_transform)
	 // texture(_texture)
{
}

DrawConf::DrawConf(const Transform & _t)
	: DrawConf(_t, nullptr)
{
}

DrawConf::DrawConf(Texture * _t)
	: DrawConf(Transform(), _t)
{
}

DrawConf::DrawConf()
	: DrawConf(Transform(), nullptr)
{
}

DrawConf & DrawConf::operator+=(const Transform & _t)
{
	transform = _t;
	return *this;
}
/*
DrawConf & DrawConf::operator+=(Texture * const _t)
{
	texture = _t;
	return *this;
}
*/
bool DrawConf::operator==(const DrawConf & _other) const
{
	if (this == &_other) 
		return true;
	return transform == _other.transform;
}

bool DrawConf::operator!=(const DrawConf & _other) const
{
	return !(*this == _other);
}


} // ns