typedef float f32;

#include "win32_graphics.h"

inline v2 V2(f32 Arg) {
	v2 Result = {};
	Result.x = Arg;
	Result.y = Arg;
	return Result;
}

inline v3 V3(f32 x, f32 y, f32 z) {
	v3 Result;
	Result.x = x;
	Result.y = y;
	Result.z = z;

	return Result;
}

inline v2 V2(f32 X, f32 Y) {
	v2 Result = {};
	Result.x = X;
	Result.y = Y;
	return Result;
}

inline v2 operator+(v2 A, v2 B) {
	v2 Result = {};
	Result.x = A.x + B.x;
	Result.y = A.y + B.y;
	return Result;
}

inline v2 operator-(v2 A, v2 B) {
	v2 Result = {};
	Result.x = A.x - B.x;
	Result.y = A.y - B.y;
	return Result;
}

inline v2 operator-(v2 A) {
	v2 Result = {};
	Result.x = -A.x;
	Result.y = -A.y;
	return Result;
}

inline v2 operator*(f32 A, v2 B) {
	v2 Result = {};
	Result.x = A * B.x;
	Result.y = A * B.y;
	return Result;
}


inline v2 operator*(v2 A, v2 B) {
	v2 Result = {};
	Result.x = A.x * B.x;
	Result.y = A.y * B.y;
	return Result;
}
inline v2 operator/(v2 A, f32 B) {
	v2 Result = {};
	Result.x = A.x / B;
	Result.y = A.y / B;
	return Result;
}


//v3 TransformedPos = Points[PointId] + V3(cosf(GlobalState.CurrAngle), sinf(GlobalState.CurrAngle), 0);

inline v3 operator+(v3 a, v3 b) {
	v3 Result = {};
	Result.x = a.x + b.x;
	Result.y = a.y + b.y;
	Result.z = a.z + b.z;
	return Result;
}

inline v3 operator*(v3 a, v3 b) {
	v3 Result = {};
	Result.x = a.x * b.x;
	Result.y = a.y * b.y;
	Result.z = a.z * b.z;
	return Result;
}

inline v3 operator*(f32 a, v3 b) {
	v3 Result = {};
	Result.x = a * b.x;
	Result.y = a * b.y;
	Result.z = a * b.z;
	return Result;
}

inline v3 operator*(v3 b, f32 a) {
	v3 Result = {};
	Result.x = a * b.x;
	Result.y = a * b.y;
	Result.z = a * b.z;
	return Result;
}