#ifndef CAT

#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define COUNT(...) \
	         PP_NARG_(__VA_ARGS__, PP_RSEQ_N())
#define PP_NARG_(...) \
	PP_ARG_N(__VA_ARGS__)
#define PP_ARG_N( \
		_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, \
		_11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
		_21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
		_31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
		_41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
		_51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
		_61, _62, _63, N, ...) N

#define PP_RSEQ_N() \
	63,62,61,60, \
	59,58,57,56,55,54,53,52,51,50, \
	49,48,47,46,45,44,43,42,41,40, \
	39,38,37,36,35,34,33,32,31,30, \
	29,28,27,26,25,24,23,22,21,20, \
	19,18,17,16,15,14,13,12,11,10, \
	9,8,7,6,5,4,3,2,1,0

#define VARS(W, ...) CAT(VARS_, COUNT(__VA_ARGS__))(W, __VA_ARGS__)
#define VARS_1(W, a) VAR(W, a)
#define VARS_2(W, a, ...) VAR(W, a) VARS_1(W, __VA_ARGS__)
#define VARS_3(W, a, ...) VAR(W, a) VARS_2(W, __VA_ARGS__)
#define VARS_4(W, a, ...) VAR(W, a) VARS_3(W, __VA_ARGS__)
#define VARS_5(W, a, ...) VAR(W, a) VARS_4(W, __VA_ARGS__)
#define VARS_6(W, a, ...) VAR(W, a) VARS_5(W, __VA_ARGS__)
#define VARS_7(W, a, ...) VAR(W, a) VARS_6(W, __VA_ARGS__)
#define VARS_8(W, a, ...) VAR(W, a) VARS_7(W, __VA_ARGS__)
#define VARS_9(W, a, ...) VAR(W, a) VARS_8(W, __VA_ARGS__)
#define VARS_10(W, a, ...) VAR(W, a) VARS_9(W, __VA_ARGS__)
#define VARS_11(W, a, ...) VAR(W, a) VARS_10(W, __VA_ARGS__)
#define VARS_12(W, a, ...) VAR(W, a) VARS_11(W, __VA_ARGS__)
#define VARS_13(W, a, ...) VAR(W, a) VARS_12(W, __VA_ARGS__)
#define VARS_14(W, a, ...) VAR(W, a) VARS_13(W, __VA_ARGS__)
#define VARS_15(W, a, ...) VAR(W, a) VARS_14(W, __VA_ARGS__)
#define VARS_16(W, a, ...) VAR(W, a) VARS_15(W, __VA_ARGS__)
#define VARS_17(W, a, ...) VAR(W, a) VARS_16(W, __VA_ARGS__)
#define VARS_18(W, a, ...) VAR(W, a) VARS_17(W, __VA_ARGS__)
#define VARS_19(W, a, ...) VAR(W, a) VARS_18(W, __VA_ARGS__)
#define VARS_20(W, a, ...) VAR(W, a) VARS_19(W, __VA_ARGS__)
#define VARS_21(W, a, ...) VAR(W, a) VARS_20(W, __VA_ARGS__)
#define VARS_22(W, a, ...) VAR(W, a) VARS_21(W, __VA_ARGS__)
#define VARS_23(W, a, ...) VAR(W, a) VARS_22(W, __VA_ARGS__)
#define VARS_24(W, a, ...) VAR(W, a) VARS_23(W, __VA_ARGS__)
#define VARS_25(W, a, ...) VAR(W, a) VARS_24(W, __VA_ARGS__)
#define VARS_26(W, a, ...) VAR(W, a) VARS_25(W, __VA_ARGS__)
#define VARS_27(W, a, ...) VAR(W, a) VARS_26(W, __VA_ARGS__)
#define VARS_28(W, a, ...) VAR(W, a) VARS_27(W, __VA_ARGS__)
#define VARS_29(W, a, ...) VAR(W, a) VARS_28(W, __VA_ARGS__)
#define VARS_30(W, a, ...) VAR(W, a) VARS_29(W, __VA_ARGS__)
#define VARS_31(W, a, ...) VAR(W, a) VARS_30(W, __VA_ARGS__)
#define VARS_32(W, a, ...) VAR(W, a) VARS_31(W, __VA_ARGS__)
#define VAR(W, a) --W ## a: VAL(W, a);

#define CALL(D, ...) CAT(CALL_, COUNT(__VA_ARGS__))(D, __VA_ARGS__)
#define CALL_1(D, a) D(a)
#define CALL_2(D, a, ...) D(a) CALL_1(D, __VA_ARGS__)
#define CALL_3(D, a, ...) D(a) CALL_2(D, __VA_ARGS__)
#define CALL_4(D, a, ...) D(a) CALL_3(D, __VA_ARGS__)
#define CALL_5(D, a, ...) D(a) CALL_4(D, __VA_ARGS__)
#define CALL_6(D, a, ...) D(a) CALL_5(D, __VA_ARGS__)
#define CALL_7(D, a, ...) D(a) CALL_6(D, __VA_ARGS__)
#define CALL_8(D, a, ...) D(a) CALL_7(D, __VA_ARGS__)
#define CALL_9(D, a, ...) D(a) CALL_8(D, __VA_ARGS__)
#define CALL_10(D, a, ...) D(a) CALL_9(D, __VA_ARGS__)
#define CALL_11(D, a, ...) D(a) CALL_10(D, __VA_ARGS__)
#define CALL_12(D, a, ...) D(a) CALL_11(D, __VA_ARGS__)
#define CALL_13(D, a, ...) D(a) CALL_12(D, __VA_ARGS__)
#define CALL_14(D, a, ...) D(a) CALL_13(D, __VA_ARGS__)
#define CALL_15(D, a, ...) D(a) CALL_14(D, __VA_ARGS__)
#define CALL_16(D, a, ...) D(a) CALL_15(D, __VA_ARGS__)
#define CALL_17(D, a, ...) D(a) CALL_16(D, __VA_ARGS__)
#define CALL_18(D, a, ...) D(a) CALL_17(D, __VA_ARGS__)
#define CALL_19(D, a, ...) D(a) CALL_18(D, __VA_ARGS__)
#define CALL_20(D, a, ...) D(a) CALL_19(D, __VA_ARGS__)
#define CALL_21(D, a, ...) D(a) CALL_20(D, __VA_ARGS__)
#define CALL_22(D, a, ...) D(a) CALL_21(D, __VA_ARGS__)
#define CALL_23(D, a, ...) D(a) CALL_22(D, __VA_ARGS__)
#define CALL_24(D, a, ...) D(a) CALL_23(D, __VA_ARGS__)
#define CALL_25(D, a, ...) D(a) CALL_24(D, __VA_ARGS__)
#define CALL_26(D, a, ...) D(a) CALL_25(D, __VA_ARGS__)
#define CALL_27(D, a, ...) D(a) CALL_26(D, __VA_ARGS__)
#define CALL_28(D, a, ...) D(a) CALL_27(D, __VA_ARGS__)
#define CALL_29(D, a, ...) D(a) CALL_28(D, __VA_ARGS__)
#define CALL_30(D, a, ...) D(a) CALL_29(D, __VA_ARGS__)
#define CALL_31(D, a, ...) D(a) CALL_30(D, __VA_ARGS__)
#define CALL_32(D, a, ...) D(a) CALL_31(D, __VA_ARGS__)

#define CALL1(D, b, ...) CAT(CALL1_, COUNT(__VA_ARGS__))(D, b, __VA_ARGS__)
#define CALL1_1(D, b, a) D(b, a)
#define CALL1_2(D, b, a, ...) D(b, a) CALL1_1(D, b, __VA_ARGS__)
#define CALL1_3(D, b, a, ...) D(b, a) CALL1_2(D, b, __VA_ARGS__)
#define CALL1_4(D, b, a, ...) D(b, a) CALL1_3(D, b, __VA_ARGS__)
#define CALL1_5(D, b, a, ...) D(b, a) CALL1_4(D, b, __VA_ARGS__)
#define CALL1_6(D, b, a, ...) D(b, a) CALL1_5(D, b, __VA_ARGS__)
#define CALL1_7(D, b, a, ...) D(b, a) CALL1_6(D, b, __VA_ARGS__)
#define CALL1_8(D, b, a, ...) D(b, a) CALL1_7(D, b, __VA_ARGS__)
#define CALL1_9(D, b, a, ...) D(b, a) CALL1_8(D, b, __VA_ARGS__)
#define CALL1_10(D, b, a, ...) D(b, a) CALL1_9(D, b, __VA_ARGS__)
#define CALL1_11(D, b, a, ...) D(b, a) CALL1_10(D, b, __VA_ARGS__)
#define CALL1_12(D, b, a, ...) D(b, a) CALL1_11(D, b, __VA_ARGS__)
#define CALL1_13(D, b, a, ...) D(b, a) CALL1_12(D, b, __VA_ARGS__)
#define CALL1_14(D, b, a, ...) D(b, a) CALL1_13(D, b, __VA_ARGS__)
#define CALL1_15(D, b, a, ...) D(b, a) CALL1_14(D, b, __VA_ARGS__)
#define CALL1_16(D, b, a, ...) D(b, a) CALL1_15(D, b, __VA_ARGS__)
#define CALL1_17(D, b, a, ...) D(b, a) CALL1_16(D, b, __VA_ARGS__)
#define CALL1_18(D, b, a, ...) D(b, a) CALL1_17(D, b, __VA_ARGS__)
#define CALL1_19(D, b, a, ...) D(b, a) CALL1_18(D, b, __VA_ARGS__)
#define CALL1_20(D, b, a, ...) D(b, a) CALL1_19(D, b, __VA_ARGS__)
#define CALL1_21(D, b, a, ...) D(b, a) CALL1_20(D, b, __VA_ARGS__)
#define CALL1_22(D, b, a, ...) D(b, a) CALL1_21(D, b, __VA_ARGS__)
#define CALL1_23(D, b, a, ...) D(b, a) CALL1_22(D, b, __VA_ARGS__)
#define CALL1_24(D, b, a, ...) D(b, a) CALL1_23(D, b, __VA_ARGS__)
#define CALL1_25(D, b, a, ...) D(b, a) CALL1_24(D, b, __VA_ARGS__)
#define CALL1_26(D, b, a, ...) D(b, a) CALL1_25(D, b, __VA_ARGS__)
#define CALL1_27(D, b, a, ...) D(b, a) CALL1_26(D, b, __VA_ARGS__)
#define CALL1_28(D, b, a, ...) D(b, a) CALL1_27(D, b, __VA_ARGS__)
#define CALL1_29(D, b, a, ...) D(b, a) CALL1_28(D, b, __VA_ARGS__)
#define CALL1_30(D, b, a, ...) D(b, a) CALL1_29(D, b, __VA_ARGS__)
#define CALL1_31(D, b, a, ...) D(b, a) CALL1_30(D, b, __VA_ARGS__)
#define CALL1_32(D, b, a, ...) D(b, a) CALL1_31(D, b, __VA_ARGS__)

#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define NC(...) CAT(NC_, COUNT(__VA_ARGS__))(__VA_ARGS__)
#define NC_2(a, b) a ## b
#define NC_3(a, b, c) a ## b ## c
#define NC_4(a, b, c, d) a ## b ## c ## d
#define NC_5(a, b, c, d, e) a ## b ## c ## d ## e
#define NC_6(a, b, c, d, e, f) a ## b ## c ## d ## e ## f
#define NC_7(a, b, c, d, e, f, g) a ## b ## c ## d ## e ## f ## g
#define NC_8(a, b, c, d, e, f, g, h) a ## b ## c ## d ## e ## f ## g ## h
#define NC_9(a, b, c, d, e, f, g, h, j) a ## b ## c ## d ## e ## f ## g ## h ## j
#define NC_10(a, b, c, d, e, f, g, h, j, k) a ## b ## c ## d ## e ## f ## g ## h ## j ## k

#endif
