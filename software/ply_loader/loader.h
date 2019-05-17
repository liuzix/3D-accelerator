#pragma once

#include <array>
#include <vector>
#include <math.h>

using namespace std;

class Vec3 {

public:
	Vec3() : X(0), Y(0), Z(0) {}
	Vec3(double X_, double Y_, double Z_) : X(X_), Y(Y_), Z(Z_) {}

	Vec3 operator+(const Vec3& right) const {
		return Vec3(this->X + right.X, this->Y + right.Y, this->Z + right.Z);
	}

	Vec3 operator-(const Vec3& right) const {
		return Vec3(this->X - right.X, this->Y - right.Y, this->Z - right.Z);
	}

	Vec3 operator-() {
		return Vec3(-this->X, -this->Y, -this->Z);
	}

	void operator=(const Vec3& right) {
		this->X = right.X;
		this->Y = right.Y;
		this->Z = right.Z;
	}

	void load(const array<double, 3>& a) {
		this->X = a[0];
		this->Y = a[1];
		this->Z = a[2];
	}

	Vec3 crossProduct(const Vec3& v2) {
		return Vec3(this->Y*v2.Z - this->Z*v2.Y,
					this->Z*v2.X - this->X*v2.Z,
					this->X*v2.Y - this->Y*v2.X);
	}

	double dotProduct(const Vec3& v2) {
		return (this->X*v2.X + this->Y*v2.Y + this->Z*v2.Z);
	}

    void normalize() {
        double x = X, y = Y, z = Y;
        X = X/sqrt(x*x + y*y + z*z);
        Y = Y/sqrt(x*x + y*y + z*z);
        Z = Z/sqrt(x*x + y*y + z*z);
    }

	double X, Y, Z;
};
