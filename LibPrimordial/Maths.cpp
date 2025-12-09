

// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================

#define BITS_IN_A_BYTE 8

#if X86

union __declspec(intrin_type) __declspec(align(16)) __m128 
{
     f32 m128_f32[4];
     u64 m128_u64[2];
     s8  m128_i8[16];
     s16 m128_i16[8];
     s32 m128_i32[4];
     s64 m128_i64[2];
     u8  m128_u8[16];
     u16 m128_u16[8];
     u32 m128_u32[4];
};


static_assert(sizeof(__m128) == (128 / BITS_IN_A_BYTE));


extern "C" __m128 _mm_sqrt_ss(__m128 _A);


SIG f32 Square_Root(f32 v)
{
	__m128 value  = {v};
	__m128 sqrt = _mm_sqrt_ss(value);

	f32 result = sqrt.m128_f32[0];

	return result;
}

#endif


u64 Power(u64 base, u64 exp)
{
    u64 result = 1;
    for(;;)
    {
        if (exp & 1)
        {
            result *= base;
        }
        
        exp >>= 1;
        
        if (!exp)
        {
            break;
        }
        
        base *= base;
    }
    
    return result;
}


SIG u32 Random_PCG(u32 seed) 
{
    u32 word = ((seed >> ((seed >> 28u) + 4u)) ^ seed) * 277803737u;
    u32 result = (word >> 22u) ^ word;
    return result;
}


SIG u32 Random_PCG(u32* pcg_state) 
{
    Assert(pcg_state);

    u32 state = *pcg_state;
    *pcg_state = *pcg_state * 747796405u + 2891336453u;
    u32 result = Random_PCG(state);
    return result;
}


SIG f32 Fraction(f32 v)
{
    s32 t = s32(v);
    f32 result = v - f32(t);
    return result;
}


// Round to nearest integer.
SIG s32 Round_To_S32(f32 v)
{
    f32 r = (v >= 0)? 0.5f : - 0.5f;

    s32 result = s32(v + r);
    return result;
}


// Round to nearest integer.
SIG f32 Round(f32 v)
{
    f32 result = (f32)Round_To_S32(v);
    return result;
}


// Rounds towards positive infinity.
SIG f32 Round_Up(f32 v)
{
    f32 f = Fraction(v);
    f32 result = v - f;
    if(result < v)
    {
        result += 1;
    }

    return result;
}


SIG s32 Digits(s32 v)
{
    u64 x = (u64)Abs(v);
    u64 exp = 0;
    for(;;)
    {
        exp += 1;
        u64 p = Power(10, exp);
        if(x < p)
        {
            break;
        }
    }
    
    s32 result = s32(exp);
    return result;
}