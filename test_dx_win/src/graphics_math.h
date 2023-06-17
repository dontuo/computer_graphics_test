#ifndef GRAPHICS_MATH_CP
#define GRAPHICS_MATH_H

global f32 Pi32 = 3.141596f;
union v2
{
    struct
    {
        f32 x, y;
    };

    f32 e[2];
};

union v2i
{
    struct
    {
        i32 x, y;
    };

    i32 e[2];
};


union v3
{
    struct
    {
        f32 x, y, z;
    };

    struct
    {
        f32 r, g, b;
    };

    struct
    {
        v2 xy;
        f32 Ignored0;
    };

    struct
    {
        f32 Ignored1;
        v2 yz;
    };

    f32 e[3];
};

union v4
{
    struct
    {
        f32 x, y, z, w;
    };

    struct
    {
        f32 r, g, b, a;
    };

    struct
    {
        v3 xyz;
        f32 Ignored0;
    };

    struct
    {
        v2 xy;
        v2 Ignored1;
    };

    f32 e[4];
};

union m4
{
    v4 v[4];
    f32 e[16];
};

inline m4 PerspectiveMatrix(f32 Fov, f32 AspectRatio, f32 NearZ, f32 FarZ) 
{
    // NOTE: ми очікуємо, що градуси в радіанах
    m4 Result = {};

    f32 FovRadians = (Fov / 360.f) * 2.0f * Pi32;
    Result.v[0].x = 1.0f / (AspectRatio * tan(FovRadians * 0.5f));
    Result.v[1].y = 1.0f / tan(FovRadians * 0.5f);
    Result.v[2].z = -FarZ / (NearZ - FarZ);
    Result.v[3].z = NearZ * FarZ / (NearZ - FarZ);
    Result.v[2].w =1.0f;
    return Result;
}
#endif