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

#define VARS(W, WS) CAT(VARS_, CAT(W, S_N))(W, WS)
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
#define VAR(W, a) --W ## a: W ## _ ## a;

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

#if 0
#define READ(W, WS) CAT(READ_, COUNT(WS))(WS)
#define READ_1(W, a) CAT(W, a)
#define READ_2(W, a, ...) CAT(W, a), READ_1(W, __VA_ARGS__)
#define READ_3(W, a, ...) CAT(W, a), READ_2(W, __VA_ARGS__)
#define READ_4(W, a, ...) CAT(W, a), READ_3(W, __VA_ARGS__)
#define READ_5(W, a, ...) CAT(W, a), READ_4(W, __VA_ARGS__)
#define READ_6(W, a, ...) CAT(W, a), READ_5(W, __VA_ARGS__)
#define READ_7(W, a, ...) CAT(W, a), READ_6(W, __VA_ARGS__)
#define READ_8(W, a, ...) CAT(W, a), READ_7(W, __VA_ARGS__)
#define READ_9(W, a, ...) CAT(W, a), READ_8(W, __VA_ARGS__)
#define READ_10(W, a, ...) CAT(W, a), READ_9(W, __VA_ARGS__)
#define READ_11(W, a, ...) CAT(W, a), READ_10(W, __VA_ARGS__)
#define READ_12(W, a, ...) CAT(W, a), READ_11(W, __VA_ARGS__)
#define READ_13(W, a, ...) CAT(W, a), READ_12(W, __VA_ARGS__)
#define READ_14(W, a, ...) CAT(W, a), READ_13(W, __VA_ARGS__)
#define READ_15(W, a, ...) CAT(W, a), READ_14(W, __VA_ARGS__)
#define READ_16(W, a, ...) CAT(W, a), READ_15(W, __VA_ARGS__)
#define READ_17(W, a, ...) CAT(W, a), READ_16(W, __VA_ARGS__)
#define READ_18(W, a, ...) CAT(W, a), READ_17(W, __VA_ARGS__)
#endif

#endif
