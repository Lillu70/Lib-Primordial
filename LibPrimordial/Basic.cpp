

// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================



SIG f64 Max(f64 a, f64 b)
{
    f64 result = (a > b)? a: b;
    return result;
}


SIG f64 Min(f64 a, f64 b)
{
    f64 result = (a < b)? a: b;
    return result;
}


SIG f64 Abs(f64 value)
{
    f64 result = (value >= 0)? value: value * -1;
    return result;}


SIG f32 Max(f32 a, f32 b)
{
    f32 result = (a > b)? a: b;
    return result;
}


SIG f32 Min(f32 a, f32 b)
{
    f32 result = (a < b)? a: b;
    return result;
}


SIG f32 Abs(f32 value)
{
    f32 result = (value >= 0)? value: value * -1;
    return result;}


SIG s64 Max(s64 a, s64 b)
{
    s64 result = (a > b)? a: b;
    return result;
}


SIG s64 Min(s64 a, s64 b)
{
    s64 result = (a < b)? a: b;
    return result;
}


SIG s64 Abs(s64 value)
{
    s64 result = (value >= 0)? value: value * -1;
    return result;}


SIG s32 Max(s32 a, s32 b)
{
    s32 result = (a > b)? a: b;
    return result;
}


SIG s32 Min(s32 a, s32 b)
{
    s32 result = (a < b)? a: b;
    return result;
}


SIG s32 Abs(s32 value)
{
    s32 result = (value >= 0)? value: value * -1;
    return result;}


SIG s16 Max(s16 a, s16 b)
{
    s16 result = (a > b)? a: b;
    return result;
}


SIG s16 Min(s16 a, s16 b)
{
    s16 result = (a < b)? a: b;
    return result;
}


SIG s16 Abs(s16 value)
{
    s16 result = (value >= 0)? value: value * -1;
    return result;}


SIG s8 Max(s8 a, s8 b)
{
    s8 result = (a > b)? a: b;
    return result;
}


SIG s8 Min(s8 a, s8 b)
{
    s8 result = (a < b)? a: b;
    return result;
}


SIG s8 Abs(s8 value)
{
    s8 result = (value >= 0)? value: value * -1;
    return result;}


SIG u64 Max(u64 a, u64 b)
{
    u64 result = (a > b)? a: b;
    return result;
}


SIG u64 Min(u64 a, u64 b)
{
    u64 result = (a < b)? a: b;
    return result;
}


SIG u32 Max(u32 a, u32 b)
{
    u32 result = (a > b)? a: b;
    return result;
}


SIG u32 Min(u32 a, u32 b)
{
    u32 result = (a < b)? a: b;
    return result;
}


SIG u16 Max(u16 a, u16 b)
{
    u16 result = (a > b)? a: b;
    return result;
}


SIG u16 Min(u16 a, u16 b)
{
    u16 result = (a < b)? a: b;
    return result;
}


SIG u8 Max(u8 a, u8 b)
{
    u8 result = (a > b)? a: b;
    return result;
}


SIG u8 Min(u8 a, u8 b)
{
    u8 result = (a < b)? a: b;
    return result;
}


SIG u64 Square(u64 v)
{
    u64 result = v * v;
    return result;
}


SIG u64 Cube(u64 v)
{
    u64 result = v * v * v;
    return result;
}


SIG u64 Kilobytes(u64 v)
{
    u64 result = v * 1024;
    return result;
}


SIG u64 Megabytes(u64 v)
{
    u64 result = v * Square(Kilobytes(1));
    return result;
}


SIG u64 Gigabytes(u64 v)
{
    u64 result = v * Cube(Kilobytes(1));
    return result;
}


SIG void Mem_Zero(void* ptr, u64 count)
{
    u8* begin = (u8*)ptr;
    u8* end = begin + count;
    
    for(u8* p = begin; p < end; ++p)
    {
        *p = 0;
    }
}


SIG void Mem_Copy(void* dest, void* src, u64 count)
{
    for(char* a = (char*)dest, *b = (char*)src; a < (char*)dest + count; ++a, ++b)
    {
        *a = *b;
    }
}