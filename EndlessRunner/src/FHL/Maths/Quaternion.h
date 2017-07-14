#ifndef FHL_QUATERNION_H
#define FHL_QUATERNION_H

#include <FHL/Maths/vectors.h>
#include <FHL/Maths/Mat4.h>

namespace fhl
{

	class Quaternion
	{
	public:
		constexpr Quaternion() : m_xyzw(0, 0, 0, 1) {}
		Quaternion(float _x, float _y, float _z, float _angle);
		Quaternion(const Vec3f & _axis, float _angle) : Quaternion(_axis.x(), _axis.y(), _axis.z(), _angle) {}

		Quaternion operator*(Quaternion _other) const;
		Quaternion & operator*=(const Quaternion & _other);

		constexpr bool operator==(const Quaternion & _other) { return m_xyzw == _other.m_xyzw; }
		constexpr bool operator!=(const Quaternion & _other) { return m_xyzw != _other.m_xyzw; }

		Vec3f getAxis() const;
		float getAngle() const;
		Vec4f asVec4() const { return m_xyzw; }
		Mat4 toMat4() const;

		float length() const;
		float dot(const Quaternion & _other) const;
		Quaternion normalized() const;
		Quaternion inverted() const;
		Quaternion conjugate() const;

		constexpr static Quaternion identity() { return Quaternion(); }

	private:
		Vec4f m_xyzw;
	};

}

#endif
