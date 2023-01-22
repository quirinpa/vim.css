#ifndef SIZES_H
#define SIZES_H
#define BASE_SIZES 4, 8, , 24, 32
#define ALL_SIZES 0, BASE_SIZES, 64, 128, 256
#define VAL_SIZE(a) VAL_SIZE_ ## a
#define VAL_SIZE_0 0px
#define VAL_SIZE_2 2px
#define VAL_SIZE_4 4px
#define VAL_SIZE_8 8px
#define VAL_SIZE_ 16px
#define VAL_SIZE_24 24px
#define VAL_SIZE_32 32px
#define VAL_SIZE_64 64px
#define VAL_SIZE_128 128px
#define VAL_SIZE_256 256px
#define VAL_SIZE_auto auto
#endif
