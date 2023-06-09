#pragma once
#include <cmath>
using namespace std;
#include "win32_graphics.h"

inline i64 Sign(i64 X)
{
	i64 Result = (X > 0) - (X < 0);
	return Result;
}

inline v2 V2(f32 Arg) {
	v2 Result = {};
	Result.x = Arg;
	Result.y = Arg;
	return Result;
}

inline v2i V2I(f32 X, f32 Y) {
	v2i Result = {};
	Result.x = X;
	Result.y = Y;
	return Result;
}

inline v2i V2I(v2 X) {
	v2i Result = {};
	Result.x = (i32)X.x;
	Result.y = (i32)X.y;
	return Result;
}

inline v2i V2I_F24_8(v2 X) {
	v2i Result = {};
	Result.x = (i32)round(X.x * 256.f);
	Result.y = (i32)round(X.y * 256.f);
	return Result;
}

inline v2i operator+(v2i A, v2i B) {
	v2i Result = {};
	Result.x = A.x + B.x;
	Result.y = A.y + B.y;
	return Result;
}

inline v2i operator-(v2i A, v2i B) {
	v2i Result = {};
	Result.x = A.x - B.x;
	Result.y = A.y - B.y;
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

inline v2 operator*(v2 B, f32 A) {
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

inline v2 operator/= (v2 &A, f32 B) {
	A = A / B;
	return A;
}

inline v2 operator*= (v2& A, f32 B) {
	A = A * B;
	return A;
}

//v3 TransformedPos = Points[PointId] + V3(cosf(GlobalState.CurrAngle), sinf(GlobalState.CurrAngle), 0);

inline v3 operator+(v3 a, v3 b) {
	v3 Result = {};
	Result.x = a.x + b.x;
	Result.y = a.y + b.y;
	Result.z = a.z + b.z;
	return Result;
}

inline v3 operator-(v3 a, v3 b) {
	v3 Result = {};
	Result.x = a.x - b.x;
	Result.y = a.y - b.y;
	Result.z = a.z - b.z;
	return Result;
}

inline v3 operator-(v3 a) {
	v3 Result = {};
	Result.x = -a.x;
	Result.y = -a.y;
	Result.z = -a.z;
	return Result;
}

inline v3 operator+=(v3& a, v3 b) {
	a = a + b;
	return a;
}

inline v3 operator-=(v3& a, v3 b) {
	a = a - b;
	return a;
}


inline v3 operator*(v3 a, v3 b) {
	v3 Result = {};
	Result.x = a.x * b.x;
	Result.y = a.y * b.y;
	Result.z = a.z * b.z;
	return Result;
}

inline v3 operator*(v3 a, f32 b) {
	v3 Result = {};
	Result.x = a.x * b;
	Result.y = a.y * b;
	Result.z = a.z * b;
	return Result;
}

inline v3 operator*=(v3 &a, f32 b) {
	a = a * b;
	return a;
}

inline v3 operator*(f32 a, v3 b) {
	v3 Result = {};
	Result.x = a * b.x;
	Result.y = a * b.y;
	Result.z = a * b.z;
	return Result;
}



inline v3 operator/(v3 b, f32 a) {
	v3 Result = {};
	Result.x = b.x / a;
	Result.y = b.y / a;
	Result.z = b.z / a;
	return Result;
}

inline v3 operator/=(v3& a, f32 b) {
	a = a / b;
	return a;
}


inline v3 Normalize(v3 A)
{
	f32 Lenght = sqrt(A.x * A.x + A.y * A.y + A.z * A.z);
	v3 Result = A / Lenght;
	return Result;
}

inline v3 Lerp(v3 A, v3 B, f32 T)
{
	v3 Result = (1.0f - T) * A + T * B;
	return Result;
}

inline v4 V4(f32 X, f32 Y, f32 Z, f32 W)
{
	v4 Result = {};
	Result.x = X;
	Result.y = Y;
	Result.z = Z;
	Result.w = W;
	return Result;
}

inline v4 V4(v3 A, f32 W)
{
	v4 Result = {};
	Result.xyz = A;
	Result.w = W;
	return Result;
}

inline v4 operator+ (v4 A, v4 B)
{
	v4 Result = {};

	Result.x = A.x + B.x;
	Result.y = A.y + B.y;
	Result.z = A.z + B.z;
	Result.w = A.w + B.w;

	return Result;
}

inline v4 operator+ (v4 A, f32 B)
{
	v4 Result = {};

	Result.x = A.x + B;
	Result.y = A.y + B;
	Result.z = A.z + B;
	Result.w = A.w + B;

	return Result;
}

inline v4 operator* (v4 A, f32 B)
{
	v4 Result = {};

	Result.x = A.x * B;
	Result.y = A.y * B;
	Result.z = A.z * B;
	Result.w = A.w * B;

	return Result;
}

inline v4 operator* (f32 B, v4 A)
{
	v4 Result = {};

	Result.x = A.x * B;
	Result.y = A.y * B;
	Result.z = A.z * B;
	Result.w = A.w * B;

	return Result;
}




//
// NOTE: M4
//

inline m4 IdentityM4()
{
	m4 Result = {};
	Result.v[0].x = 1.0f;
	Result.v[1].y = 1.0f;
	Result.v[2].z = 1.0f;
	Result.v[3].w = 1.0f;
	return Result;
}

inline v4 operator*(m4 A, v4 B)
{
	v4 Result = A.v[0] * B.x + A.v[1] * B.y + A.v[2] * B.z + A.v[3] * B.w;
	return Result;
}

inline m4 operator*(m4 A, m4 B)
{
	m4 Result = {};
	Result.v[0] = A * B.v[0];
	Result.v[1] = A * B.v[1];
	Result.v[2] = A * B.v[2];
	Result.v[3] = A * B.v[3];
	return Result;
}

inline m4 ScaleMatrix(f32 X, f32 Y, f32 Z)
{
	m4 Result = IdentityM4();
	Result.v[0].x = X;
	Result.v[1].y = Y;
	Result.v[2].z = Z;
	return Result;
}

inline m4 RotationMatrix(f32 X, f32 Y, f32 Z)
{
	m4 Result = {};

	m4 RotateX = IdentityM4();
	RotateX.v[1].y = cos(X);
	RotateX.v[2].y = -sin(X);
	RotateX.v[1].z = sin(X);
	RotateX.v[2].z = cos(X);

	m4 RotateY = IdentityM4();
	RotateY.v[0].x = cos(Y);
	RotateY.v[2].x = -sin(Y);
	RotateY.v[0].z = sin(Y);
	RotateY.v[2].z = cos(Y);

	m4 RotateZ = IdentityM4();
	RotateZ.v[0].x = cos(Z);
	RotateZ.v[1].x = -sin(Z);
	RotateZ.v[0].y = sin(Z);
	RotateZ.v[1].y = cos(Z);

	Result = RotateZ * RotateY * RotateX;
	return Result;
}

inline m4 TranslationMatrix(f32 X, f32 Y, f32 Z)
{
	m4 Result = IdentityM4();
	Result.v[3].xyz = V3(X, Y, Z);
	return Result;
}

inline m4 TranslationMatrix(v3 Pos)
{
	m4 Result = TranslationMatrix(Pos.x, Pos.y, Pos.z);

	return Result;
}