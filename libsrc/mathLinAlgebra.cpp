#include "mathLinAlgebra.hpp"

double max (double v1, double v2) {
	if (v1 > v2) return v1;
	return v2;
}

double min (double v1, double v2) {
	if (v1 < v2) return v1;
	return v2;
}

void clampMax (double max, double& value) {
	if (value > max) value = max;
}

void clampMin (double min, double& value) {
	if (value < min) value = min;
}

void clampRange (double b1, double b2, double& value) {
	if (b1 > b2) std::swap(b1,b2);
	clampMin(b1,value);
	clampMax(b2,value);
}

bool isWithinRange (double b1, double b2, double value) {
	if (b1 > b2) std::swap(b1,b2);
	if (value >= b1 && value <= b2) return true;
	return false;
}

cMatrix rotnTransform (const double rotnRad) {
	cMatrix rotnMatrix(2,2);
	rotnMatrix.set(0,0) = std::cos(rotnRad);
	rotnMatrix.set(0,1) = -std::sin(rotnRad);
	rotnMatrix.set(1,0) = std::sin(rotnRad);
	rotnMatrix.set(1,1) = std::cos(rotnRad);
	return rotnMatrix;
}

bool lineIntersection (const cVector2& p1, const cVector2& d1,
		const cVector2& p2, const cVector2& d2, cVector2& point) {
	// Check for zero vectors
	if (d1 == zeroVector2 || d2 == zeroVector2) {
		return false;
	}

	// Check for asymptotes
	bool isL1Asymptotic = false,
		 isL2Asymptotic = false;
	if (d1.getX() == 0.0) {
		isL1Asymptotic = true;
		if (d2.getX() == 0.0) return false;
	}
	else if (d1.getY() == 0.0) {
		isL1Asymptotic = true;
		if (d2.getY() == 0.0) return false;
	}
	if (d2.getX() == 0.0) isL2Asymptotic = true;
	if (d2.getY() == 0.0) isL2Asymptotic = true;

	if (isL1Asymptotic == true && isL2Asymptotic == true) {
		if (d1.getX() == 0.0)
			// d1 is the X-Asymptote
			point.setX(p1.getX());
		else
			// d2 is the X-Asymptote
			point.setX(p2.getX());
		if (d1.getY() == 0.0)
			// d1 is the Y-Asymptote
			point.setY(p1.getY());
		else
			// d2 is the Y-Asymptote
			point.setY(p2.getY());
		return true;
	}

	// One line is asymptotic, the other isn't
	double m1,
		   m2,
		   b1,
		   b2;
	if (isL1Asymptotic == true) {
		m2 = d2.getY()/d2.getX();
		b2 = p2.getY()-(m2*p2.getX());
		if (d1.getX() == 0.0) {
			point.setX(p1.getX());
			point.setY(m2*point.getX()+b2);
		}
		else {
			point.setY(p1.getY());
			point.setX((point.getY()-b2)/m2);
		}
		return true;
	}
	else if (isL2Asymptotic == true) {
		m1 = d1.getY()/d1.getX();
		b1 = p1.getY()-(m1*p1.getX());
		if (d2.getX() == 0.0) {
			point.setX(p2.getX());
			point.setY(m1*point.getX()+b1);
		}
		else {
			point.setY(p2.getY());
			point.setX((point.getY()-b1)/m1);
		}
		return true;
	}

	// Regular lines
	m1 = d1.getY()/d1.getX();
	m2 = d2.getY()/d2.getX();
	// Check if the lines intersect at all, or infinitely many times
	if (m1 == m2) return false;
	b1 = p1.getY()-(m1*p1.getX()),
	b2 = p2.getY()-(m2*p2.getX());
	point.setX((b2-b1)/(m1-m2));
	point.setY((m1*point.getX())+b1);
	return true;
}

double vSqMagnitude (const cVector2& v1) {
	double sqSum = 0;
	int numRows = 0,
		numCols = 0;
	v1.getSize(&numRows,&numCols);
	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numCols; ++j) {
			sqSum += v1.get(i,j)*v1.get(i,j);
		}
	}
	return sqSum;
};

double vMagnitude (const cVector2& v1) {
	return std::sqrt(vSqMagnitude(v1));
}

double vDotProd (const cVector2& v1, const cVector2& v2) {
	int rows, cols;
	v1.getSize(&rows,&cols);
	if (rows != v2.getRowSize() || cols != v2.getColSize()) {
		throw std::range_error("Matrix dimensions are wrong");
	}
	double dotProduct = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			dotProduct += v1.get(i,j)*v2.get(i,j);
		}
	}
	return dotProduct;
}

double vAngleRad (const cVector2& v1, const cVector2& v2) {
	return std::acos(vDotProd(v1,v2)/(vMagnitude(v1)*vMagnitude(v2)));
}

double vAngleDeg (const cVector2& v1, const cVector2& v2) {
	return vAngleRad(v1,v2)*RAD_TO_DEG;
}

double vScalProj (const cVector2& projVec, const cVector2& projAxis) {
	cVector2 unitProjAxis = vUnitVector(projAxis);
	return vDotProd(projVec,unitProjAxis);
}

cVector2 vUnitVector (const cVector2& v1) {
	cVector2 tmpVec(v1);
	double mag = vMagnitude(v1);
	if (mag == 0.0) {
		throw std::runtime_error("Vector magnitude is 0.");
	}
	tmpVec *= 1.0/mag;
	return tmpVec;
}

cVector2 vAbsolute (const cVector2& v1) {
	return cVector2(std::abs(v1.get(0,0)),std::abs(v1.get(1,0)));
}

cVector2 vNormalR (const cVector2& v1) {
	return vUnitVector(cVector2(v1.get(1,0),-v1.get(0,0)));
}

cVector2 vNormalL (const cVector2& v1) {
	return vUnitVector(cVector2(-v1.get(1,0),v1.get(0,0)));
}

cVector2 vVecProj (const cVector2& projVec, const cVector2& projAxis) {
	// Scalar Projection: s = A dot uB, s = scalar projection, A
	// projected Vector, uB = unit vector of axis
	// Vector Projection: v = s * uB
	cVector2 unitProjAxis = vUnitVector(projAxis);
	return cVector2((vDotProd(projVec,unitProjAxis)*unitProjAxis));
}

cVector2 vRotate (const cVector2& v1, const double& rotRad) {
	cMatrix rotMatrix(2,2);
	rotMatrix.set(0,0) = std::cos(rotRad);
	rotMatrix.set(0,1) = -std::sin(rotRad);
	rotMatrix.set(1,0) = -rotMatrix.get(0,1);
	rotMatrix.set(1,1) = rotMatrix.get(0,0);
	return cVector2(rotMatrix*v1);
}

cVector2 vMirror (const cVector2& v1, const cVector2& vMirror) {
	return cVector2((2*vVecProj(v1,vMirror))-v1);
}

cVector3 vCrossProd (const cVector2& v1, const cVector2& v2) {
	return vCrossProd(cVector3(v1),cVector3(v2));
}

cVector2 intersectionLineLine (const cVector2& pt1, const cVector2& lineDir1,
		const cVector2& pt2, const cVector2& lineDir2) {
	double m1, m2, b1, b2, xInt, yInt;
	m1 = m2 = b1 = b2 = xInt = yInt = std::nan("");
	if ((lineDir1.getX() == 0 && lineDir2.getX() == 0) ||
			(lineDir1.getY() == 0 && lineDir2.getY() == 0))
		// throw an error, lines are parallel
		throw std::runtime_error("Lines are parallel");
	if (lineDir1.getX() == 0) {
		// Vertical asymptote
		xInt = pt1.getX();
		m1 = 1;
		b1 = 0;
	}
	if (lineDir1.getY() == 0) {
		// Horizontal asymptote
		yInt = pt1.getY();
		m1 = 0;
	}
	if (lineDir2.getX() == 0) {
		// Vertical asymptote
		xInt = pt2.getX();
		m2 = 1;
		b2 = 0;
	}
	if (lineDir2.getY() == 0) {
		// Horizontal asymptote
		yInt = pt2.getY();
		m2 = 0;
	}
	if (std::isnan(m1) == true)
		m1 = lineDir1.getY()/lineDir1.getX();
	if (std::isnan(m2) == true)
		m2 = lineDir2.getY()/lineDir2.getX();
	if (m1 == m2)
		throw std::runtime_error("Lines are parallel");
	if (std::isnan(b1) == true)
		b1 = pt1.getY()-m1*pt1.getX();
	if (std::isnan(b2) == true)
		b2 = pt2.getY()-m2*pt2.getX();
	if (std::isnan(xInt) == true && std::isnan(yInt) == true) {
		xInt = (b2-b1)/(m1-m2);
		yInt = m1*xInt+b1;
	}
	if (std::isnan(xInt) == false && std::isnan(yInt) == true) {
		yInt = m1*xInt+b1;
	}
	if (std::isnan(xInt) == true && std::isnan(yInt) == false) {
		xInt = (yInt-b1)/m1;
	}
	return cVector2(xInt,yInt);
}

double distPtToLine (const cVector2& pt, const cVector2& lineDir,
		const cVector2& ptLine) {
	cVector2 normDir = vNormalR(lineDir);
	return vMagnitude(intersectionLineLine(pt,normDir,ptLine,lineDir));
}

double vSqMagnitude (const cVector3& v1) {
	return std::pow(v1.getX(),2) + pow(v1.getY(),2) + pow(v1.getZ(),2);
}

double vMagnitude (const cVector3& v1) {
	return std::sqrt(vSqMagnitude(v1));
}

cVector3 vUnitVector (const cVector3& v1) {
	cVector3 tmpVec(v1);
	double mag = vMagnitude(v1);
	if (mag == 0.0) {
		throw std::runtime_error("Vector magnitude is 0.");
	}
	tmpVec *= 1.0/mag;
	return tmpVec;
}

cVector3 vCrossProd (const cVector3& v1, const cVector3& v2) {
	cVector3 tmpVctr;
	tmpVctr.setX(v1.getY()*v2.getZ() - v1.getZ()*v2.getY());
	tmpVctr.setY(v1.getZ()*v2.getX() - v1.getX()*v2.getZ());
	tmpVctr.setZ(v1.getX()*v2.getY() - v1.getY()*v2.getX());
	return tmpVctr;
}
