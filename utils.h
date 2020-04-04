#ifndef CAT

#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define DECLARE(W, WS) CAT(DECLARE_, CAT(W, S_N))(W, WS)
#define DECLARE_1(W, a) DECLARE_ ## W(a)
#define DECLARE_2(W, a, ...) DECLARE_ ## W(a) DECLARE_1(W, __VA_ARGS__)
#define DECLARE_3(W, a, ...) DECLARE_ ## W(a) DECLARE_2(W, __VA_ARGS__)
#define DECLARE_4(W, a, ...) DECLARE_ ## W(a) DECLARE_3(W, __VA_ARGS__)
#define DECLARE_5(W, a, ...) DECLARE_ ## W(a) DECLARE_4(W, __VA_ARGS__)
#define DECLARE_6(W, a, ...) DECLARE_ ## W(a) DECLARE_5(W, __VA_ARGS__)
#define DECLARE_7(W, a, ...) DECLARE_ ## W(a) DECLARE_6(W, __VA_ARGS__)
#define DECLARE_8(W, a, ...) DECLARE_ ## W(a) DECLARE_7(W, __VA_ARGS__)
#define DECLARE_9(W, a, ...) DECLARE_ ## W(a) DECLARE_8(W, __VA_ARGS__)
#define DECLARE_10(W, a, ...) DECLARE_ ## W(a) DECLARE_9(W, __VA_ARGS__)
#define DECLARE_11(W, a, ...) DECLARE_ ## W(a) DECLARE_10(W, __VA_ARGS__)
#define DECLARE_12(W, a, ...) DECLARE_ ## W(a) DECLARE_11(W, __VA_ARGS__)

#define CALL(n, pre, ...) CALL_ ## n(pre, __VA_ARGS__)
#define CALL_1(pre, a) pre(a)
#define CALL_2(pre, a, ...) pre(a) CALL_1(pre, __VA_ARGS__)
#define CALL_3(pre, a, ...) pre(a) CALL_2(pre, __VA_ARGS__)
#define CALL_4(pre, a, ...) pre(a) CALL_3(pre, __VA_ARGS__)
#define CALL_5(pre, a, ...) pre(a) CALL_4(pre, __VA_ARGS__)
#define CALL_6(pre, a, ...) pre(a) CALL_5(pre, __VA_ARGS__)
#define CALL_7(pre, a, ...) pre(a) CALL_6(pre, __VA_ARGS__)
#define CALL_8(pre, a, ...) pre(a) CALL_7(pre, __VA_ARGS__)
#define CALL_9(pre, a, ...) pre(a) CALL_8(pre, __VA_ARGS__)
#define CALL_10(pre, a, ...) pre(a) CALL_9(pre, __VA_ARGS__)
#define CALL_11(pre, a, ...) pre(a) CALL_10(pre, __VA_ARGS__)
#define CALL_12(pre, a, ...) pre(a) CALL_11(pre, __VA_ARGS__)
#define CALL_13(pre, a, ...) pre(a) CALL_12(pre, __VA_ARGS__)
#define CALL_14(pre, a, ...) pre(a) CALL_13(pre, __VA_ARGS__)
#define CALL_15(pre, a, ...) pre(a) CALL_14(pre, __VA_ARGS__)
#define CALL_16(pre, a, ...) pre(a) CALL_15(pre, __VA_ARGS__)

#endif
