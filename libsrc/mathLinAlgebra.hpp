#ifndef MATHLINALGEBRA_HPP
#define MATHLINALGEBRA_HPP

#include <algorithm>
#include <cmath>

#include "mathMatrix.hpp"
#include "mathVector.hpp"

double max (double v1, double v2);
double min (double v1, double v2);
void clampMax (double max, double& value);
void clampMin (double min, double& value);
void clampRange (double b1, double b2, double& value);
bool isWithinRange (double b1, double b2, double value);

// When the rotation matrix is multiplied by a column vector (ie.
// rotnMatrix*column), the points in the column vector will be rotated
// around the origin.
cMatrix rotnTransform (const double rotnRad);

// Determines whether 2 lines intersect or not. If they do, it will
// return true and the intersection point will be in point. If they 
// don't intersect or intersect infinitely, false will be returned
// and point will contain NAN.
bool lineIntersection (const cVector2& p1, const cVector2& d1,
		const cVector2& p2, const cVector2& d2, cVector2& point);

// 2D vector linear algebra functions
double vSqMagnitude (const cVector2& v1);
double vMagnitude (const cVector2& v1);
double vDotProd (const cVector2& v1, const cVector2& v2);
double vAngleRad (const cVector2& v1, const cVector2& v2);
double vAngleDeg (const cVector2& v1, const cVector2& v2);
double vScalProj (const cVector2& projVec, const cVector2& projAxis);
cVector2 vUnitVector (const cVector2& v1);
cVector2 vAbsolute (const cVector2& v1);
cVector2 vNormalR (const cVector2& v1);
cVector2 vNormalL (const cVector2& v1);
cVector2 vVecProj (const cVector2& projVec, const cVector2& projAxis);
cVector2 vRotate (const cVector2& v1, const double& rotnRad);
cVector2 vMirror (const cVector2& v1, const cVector2& vMirror);
cVector3 vCrossProd (const cVector2& v1, const cVector2& v2);

cVector2 intersectionLineLine (const cVector2& pt1, const cVector2& lineDir1,
		const cVector2& pt2, const cVector2& lineDir2);
double distPtToLine (const cVector2& pt, const cVector2& lineDir,
		const cVector2& ptLine);

// 3D vector linear algebra functions
double vSqMagnitude (const cVector3& v1);
double vMagnitude (const cVector3& v1);
cVector3 vUnitVector (const cVector3& v1);
cVector3 vCrossProd (const cVector3& v1, const cVector3& v2);

#endif
