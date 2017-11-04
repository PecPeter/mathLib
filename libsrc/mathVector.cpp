#include "mathVector.hpp"

cVector2::cVector2 (void): cMatrix(2,1) {}

cVector2::cVector2 (double x, double y): cMatrix(2,1) {
	set(0,0) = x;
	set(1,0) = y;
}

cVector2::cVector2 (const cVector2& vector): cMatrix(vector) {}

cVector2::cVector2 (const cMatrix& matrix): cMatrix(2,1) {
	matrix.getSize(&nRows_,&nCols_);
	if (nRows_ != 2 && nCols_ != 1)
		throw std::range_error("Matrix dimensions are wrong");
	set(0,0) = matrix.get(0,0);
	set(1,0) = matrix.get(1,0);
}

double cVector2::getX (void) const {
	return get(0,0);
}

double cVector2::getY (void) const {
	return get(1,0);
}

void cVector2::setX (double x) {
	set(0,0) = x;
}

void cVector2::setY (double y) {
	set(1,0) = y;
}

cVector3::cVector3 (void): cMatrix(3,1) {}

cVector3::cVector3 (double x, double y, double z): cMatrix(3,1) {
	set(0,0) = x;
	set(1,0) = y;
	set(2,0) = z;
}

cVector3::cVector3 (const cVector2& vector): cMatrix(3,1) {
	set(0,0) = vector.getX();
	set(1,0) = vector.getY();
	set(2,0) = 0;
}

cVector3::cVector3 (const cVector3& vector): cMatrix(vector) {}

cVector3::cVector3 (const cMatrix& matrix): cMatrix(3,1) {
	matrix.getSize(&nRows_,&nCols_);
	if (nRows_ != 3 && nCols_ != 1)
		throw std::range_error("Matrix dimensions are wrong");
	set(0,0) = matrix.get(0,0);
	set(1,0) = matrix.get(1,0);
	set(2,0) = matrix.get(2,0);
}

double cVector3::getX (void) const {
	return get(0,0);
}

double cVector3::getY (void) const {
	return get(1,0);
}

double cVector3::getZ (void) const {
	return get(2,0);
}

void cVector3::setX (double x) {
	set(0,0) = x;
}

void cVector3::setY (double y) {
	set(1,0) = y;
}

void cVector3::setZ (double z) {
	set(2,0) = z;
}

cVector4::cVector4 (void): cMatrix(4,1) {}

cVector4::cVector4 (double w, double x, double y, double z): cMatrix(4,1) {
	set(0,0) = w;
	set(1,0) = x;
	set(2,0) = y;
	set(3,0) = z;
}

cVector4::cVector4 (const cVector2& vector): cMatrix(4,1) {
	set(0,0) = vector.getX();
	set(1,0) = vector.getY();
	set(2,0) = 0;
	set(3,0) = 0;
}

cVector4::cVector4 (const cVector3& vector): cMatrix(4,1) {
	set(0,0) = vector.getX();
	set(1,0) = vector.getY();
	set(2,0) = vector.getZ();
	set(3,0) = 0;
}

cVector4::cVector4 (const cVector4& vector): cMatrix(vector) {}

cVector4::cVector4 (const cMatrix& matrix): cMatrix(4,1) {
	matrix.getSize(&nRows_,&nCols_);
	if (nRows_ != 4 && nCols_ != 1)
		throw std::range_error("Matrix dimensions are wrong");
	set(0,0) = matrix.get(0,0);
	set(1,0) = matrix.get(1,0);
	set(2,0) = matrix.get(2,0);
	set(3,0) = matrix.get(3,0);
}

double cVector4::getW (void) const {
	return get(0,0);
}

double cVector4::getX (void) const {
	return get(1,0);
}

double cVector4::getY (void) const {
	return get(2,0);
}

double cVector4::getZ (void) const {
	return get(3,0);
}

void cVector4::setW (double w) {
	set(0,0) = w;
}

void cVector4::setX (double x) {
	set(1,0) = x;
}

void cVector4::setY (double y) {
	set(2,0) = y;
}

void cVector4::setZ (double z) {
	set(3,0) = z;
}
