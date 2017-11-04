#ifndef MATHVECTOR_HPP
#define MATHVECTOR_HPP

#include <cassert>
#include <cmath>
#include <limits>
#include <stdexcept>

#include "mathConstants.hpp"
#include "mathMatrix.hpp"

class cVector2: public cMatrix {
	public:
		cVector2 (void);
		cVector2 (double x, double y);
		cVector2 (const cVector2& vector);
		cVector2 (const cMatrix& matrix);

		double getX (void) const;
		double getY (void) const;
		void setX (double x);
		void setY (double y);
};

// This is untested in the unit test
class cVector3 : public cMatrix {
	public:
		cVector3 (void);
		cVector3 (double x, double y, double z);
		cVector3 (const cVector2& vector);
		cVector3 (const cVector3& vector);
		cVector3 (const cMatrix& matrix);

		double getX (void) const;
		double getY (void) const;
		double getZ (void) const;
		void setX (double x);
		void setY (double y);
		void setZ (double z);
};

// This is not tested yet
class cVector4 : public cMatrix {
	public:
		cVector4 (void);
		cVector4 (double w, double x, double y, double z);
		cVector4 (const cVector2& vector);
		cVector4 (const cVector3& vector);
		cVector4 (const cVector4& vector);
		cVector4 (const cMatrix& matrix);

		double getW (void) const;
		double getX (void) const;
		double getY (void) const;
		double getZ (void) const;
		void setW (double w);
		void setX (double x);
		void setY (double y);
		void setZ (double z);
};

const cVector2 zeroVector2(0.0,0.0);
const cVector3 zeroVector3(0.0,0.0,0.0);
const cVector4 zeroVector4(0.0,0.0,0.0,0.0);

#endif
