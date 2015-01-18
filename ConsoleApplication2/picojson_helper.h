#pragma once

// Calculate the count of arguments.
#define PICOJSON_NUM_VA_ARGS_I(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11,   \
                               _12, _13, _14, _15, _16, _17, _18, _19, _20,    \
                               _21, _22, _23, _24, _25, _26, _27, _28, _29,    \
                               _30, _31, N, ...)                               \
  N
#define PICOJSON_NUM_VA_ARGS_I_(tuple) PICOJSON_NUM_VA_ARGS_I tuple
#define PICOJSON_NUM_VA_ARGS(...)                                              \
  PICOJSON_NUM_VA_ARGS_I_((__VA_ARGS__, 31, 30, 29, 28, 27, 26, 25, 24, 23,    \
                           22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
                           9, 8, 7, 6, 5, 4, 3, 2, 1))

#define PICOJSON_DEFINE_PACK_1(obj, a1) PICOJSON_DEFINE_PACK_ITEM(obj, a1)

#define PICOJSON_DEFINE_UNPACK_1(obj, a1) PICOJSON_DEFINE_UNPACK_ITEM(obj, a1)

#define PICOJSON_DEFINE_PACK_2(obj, a1, a2)                                    \
  PICOJSON_DEFINE_PACK_2_I_((obj, a1, a2))
#define PICOJSON_DEFINE_PACK_2_I_(tuple) PICOJSON_DEFINE_PACK_2_I tuple
#define PICOJSON_DEFINE_PACK_2_I(obj, a1, a2)                                  \
  PICOJSON_DEFINE_PACK_1(obj, a1)                                              \
  PICOJSON_DEFINE_PACK_ITEM(obj, a2)

#define PICOJSON_DEFINE_UNPACK_2(obj, a1, a2)                                  \
  PICOJSON_DEFINE_UNPACK_2_I_((obj, a1, a2))
#define PICOJSON_DEFINE_UNPACK_2_I_(tuple) PICOJSON_DEFINE_UNPACK_2_I tuple
#define PICOJSON_DEFINE_UNPACK_2_I(obj, a1, a2)                                \
  PICOJSON_DEFINE_UNPACK_1(obj, a1)                                            \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a2)

#define PICOJSON_DEFINE_PACK_3(obj, a1, a2, a3)                                \
  PICOJSON_DEFINE_PACK_3_I_((obj, a1, a2, a3))
#define PICOJSON_DEFINE_PACK_3_I_(tuple) PICOJSON_DEFINE_PACK_3_I tuple
#define PICOJSON_DEFINE_PACK_3_I(obj, a1, a2, a3)                              \
  PICOJSON_DEFINE_PACK_2(obj, a1, a2)                                          \
  PICOJSON_DEFINE_PACK_ITEM(obj, a3)

#define PICOJSON_DEFINE_UNPACK_3(obj, a1, a2, a3)                              \
  PICOJSON_DEFINE_UNPACK_3_I_((obj, a1, a2, a3))
#define PICOJSON_DEFINE_UNPACK_3_I_(tuple) PICOJSON_DEFINE_UNPACK_3_I tuple
#define PICOJSON_DEFINE_UNPACK_3_I(obj, a1, a2, a3)                            \
  PICOJSON_DEFINE_UNPACK_2(obj, a1, a2)                                        \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a3)

#define PICOJSON_DEFINE_PACK_4(obj, a1, a2, a3, a4)                            \
  PICOJSON_DEFINE_PACK_4_I_((obj, a1, a2, a3, a4))
#define PICOJSON_DEFINE_PACK_4_I_(tuple) PICOJSON_DEFINE_PACK_4_I tuple
#define PICOJSON_DEFINE_PACK_4_I(obj, a1, a2, a3, a4)                          \
  PICOJSON_DEFINE_PACK_3(obj, a1, a2, a3)                                      \
  PICOJSON_DEFINE_PACK_ITEM(obj, a4)

#define PICOJSON_DEFINE_UNPACK_4(obj, a1, a2, a3, a4)                          \
  PICOJSON_DEFINE_UNPACK_4_I_((obj, a1, a2, a3, a4))
#define PICOJSON_DEFINE_UNPACK_4_I_(tuple) PICOJSON_DEFINE_UNPACK_4_I tuple
#define PICOJSON_DEFINE_UNPACK_4_I(obj, a1, a2, a3, a4)                        \
  PICOJSON_DEFINE_UNPACK_3(obj, a1, a2, a3)                                    \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a4)

#define PICOJSON_DEFINE_PACK_5(obj, a1, a2, a3, a4, a5)                        \
  PICOJSON_DEFINE_PACK_5_I_((obj, a1, a2, a3, a4, a5))
#define PICOJSON_DEFINE_PACK_5_I_(tuple) PICOJSON_DEFINE_PACK_5_I tuple
#define PICOJSON_DEFINE_PACK_5_I(obj, a1, a2, a3, a4, a5)                      \
  PICOJSON_DEFINE_PACK_4(obj, a1, a2, a3, a4)                                  \
  PICOJSON_DEFINE_PACK_ITEM(obj, a5)

#define PICOJSON_DEFINE_UNPACK_5(obj, a1, a2, a3, a4, a5)                      \
  PICOJSON_DEFINE_UNPACK_5_I_((obj, a1, a2, a3, a4, a5))
#define PICOJSON_DEFINE_UNPACK_5_I_(tuple) PICOJSON_DEFINE_UNPACK_5_I tuple
#define PICOJSON_DEFINE_UNPACK_5_I(obj, a1, a2, a3, a4, a5)                    \
  PICOJSON_DEFINE_UNPACK_4(obj, a1, a2, a3, a4)                                \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a5)

#define PICOJSON_DEFINE_PACK_6(obj, a1, a2, a3, a4, a5, a6)                    \
  PICOJSON_DEFINE_PACK_6_I_((obj, a1, a2, a3, a4, a5, a6))
#define PICOJSON_DEFINE_PACK_6_I_(tuple) PICOJSON_DEFINE_PACK_6_I tuple
#define PICOJSON_DEFINE_PACK_6_I(obj, a1, a2, a3, a4, a5, a6)                  \
  PICOJSON_DEFINE_PACK_5(obj, a1, a2, a3, a4, a5)                              \
  PICOJSON_DEFINE_PACK_ITEM(obj, a6)

#define PICOJSON_DEFINE_UNPACK_6(obj, a1, a2, a3, a4, a5, a6)                  \
  PICOJSON_DEFINE_UNPACK_6_I_((obj, a1, a2, a3, a4, a5, a6))
#define PICOJSON_DEFINE_UNPACK_6_I_(tuple) PICOJSON_DEFINE_UNPACK_6_I tuple
#define PICOJSON_DEFINE_UNPACK_6_I(obj, a1, a2, a3, a4, a5, a6)                \
  PICOJSON_DEFINE_UNPACK_5(obj, a1, a2, a3, a4, a5)                            \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a6)

#define PICOJSON_DEFINE_PACK_7(obj, a1, a2, a3, a4, a5, a6, a7)                \
  PICOJSON_DEFINE_PACK_7_I_((obj, a1, a2, a3, a4, a5, a6, a7))
#define PICOJSON_DEFINE_PACK_7_I_(tuple) PICOJSON_DEFINE_PACK_7_I tuple
#define PICOJSON_DEFINE_PACK_7_I(obj, a1, a2, a3, a4, a5, a6, a7)              \
  PICOJSON_DEFINE_PACK_6(obj, a1, a2, a3, a4, a5, a6)                          \
  PICOJSON_DEFINE_PACK_ITEM(obj, a7)

#define PICOJSON_DEFINE_UNPACK_7(obj, a1, a2, a3, a4, a5, a6, a7)              \
  PICOJSON_DEFINE_UNPACK_7_I_((obj, a1, a2, a3, a4, a5, a6, a7))
#define PICOJSON_DEFINE_UNPACK_7_I_(tuple) PICOJSON_DEFINE_UNPACK_7_I tuple
#define PICOJSON_DEFINE_UNPACK_7_I(obj, a1, a2, a3, a4, a5, a6, a7)            \
  PICOJSON_DEFINE_UNPACK_6(obj, a1, a2, a3, a4, a5, a6)                        \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a7)

#define PICOJSON_DEFINE_PACK_8(obj, a1, a2, a3, a4, a5, a6, a7, a8)            \
  PICOJSON_DEFINE_PACK_8_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8))
#define PICOJSON_DEFINE_PACK_8_I_(tuple) PICOJSON_DEFINE_PACK_8_I tuple
#define PICOJSON_DEFINE_PACK_8_I(obj, a1, a2, a3, a4, a5, a6, a7, a8)          \
  PICOJSON_DEFINE_PACK_7(obj, a1, a2, a3, a4, a5, a6, a7)                      \
  PICOJSON_DEFINE_PACK_ITEM(obj, a8)

#define PICOJSON_DEFINE_UNPACK_8(obj, a1, a2, a3, a4, a5, a6, a7, a8)          \
  PICOJSON_DEFINE_UNPACK_8_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8))
#define PICOJSON_DEFINE_UNPACK_8_I_(tuple) PICOJSON_DEFINE_UNPACK_8_I tuple
#define PICOJSON_DEFINE_UNPACK_8_I(obj, a1, a2, a3, a4, a5, a6, a7, a8)        \
  PICOJSON_DEFINE_UNPACK_7(obj, a1, a2, a3, a4, a5, a6, a7)                    \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a8)

#define PICOJSON_DEFINE_PACK_9(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9)        \
  PICOJSON_DEFINE_PACK_9_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9))
#define PICOJSON_DEFINE_PACK_9_I_(tuple) PICOJSON_DEFINE_PACK_9_I tuple
#define PICOJSON_DEFINE_PACK_9_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9)      \
  PICOJSON_DEFINE_PACK_8(obj, a1, a2, a3, a4, a5, a6, a7, a8)                  \
  PICOJSON_DEFINE_PACK_ITEM(obj, a9)

#define PICOJSON_DEFINE_UNPACK_9(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9)      \
  PICOJSON_DEFINE_UNPACK_9_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9))
#define PICOJSON_DEFINE_UNPACK_9_I_(tuple) PICOJSON_DEFINE_UNPACK_9_I tuple
#define PICOJSON_DEFINE_UNPACK_9_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9)    \
  PICOJSON_DEFINE_UNPACK_8(obj, a1, a2, a3, a4, a5, a6, a7, a8)                \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a9)

#define PICOJSON_DEFINE_PACK_10(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10)  \
  PICOJSON_DEFINE_PACK_10_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10))
#define PICOJSON_DEFINE_PACK_10_I_(tuple) PICOJSON_DEFINE_PACK_10_I tuple
#define PICOJSON_DEFINE_PACK_10_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10)                                         \
  PICOJSON_DEFINE_PACK_9(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9)              \
  PICOJSON_DEFINE_PACK_ITEM(obj, a10)

#define PICOJSON_DEFINE_UNPACK_10(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10)                                         \
  PICOJSON_DEFINE_UNPACK_10_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10))
#define PICOJSON_DEFINE_UNPACK_10_I_(tuple) PICOJSON_DEFINE_UNPACK_10_I tuple
#define PICOJSON_DEFINE_UNPACK_10_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10)                                       \
  PICOJSON_DEFINE_UNPACK_9(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9)            \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a10)

#define PICOJSON_DEFINE_PACK_11(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11)                                           \
  PICOJSON_DEFINE_PACK_11_I_(                                                  \
      (obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11))
#define PICOJSON_DEFINE_PACK_11_I_(tuple) PICOJSON_DEFINE_PACK_11_I tuple
#define PICOJSON_DEFINE_PACK_11_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11)                                    \
  PICOJSON_DEFINE_PACK_10(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10)        \
  PICOJSON_DEFINE_PACK_ITEM(obj, a11)

#define PICOJSON_DEFINE_UNPACK_11(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11)                                    \
  PICOJSON_DEFINE_UNPACK_11_I_(                                                \
      (obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11))
#define PICOJSON_DEFINE_UNPACK_11_I_(tuple) PICOJSON_DEFINE_UNPACK_11_I tuple
#define PICOJSON_DEFINE_UNPACK_11_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11)                                  \
  PICOJSON_DEFINE_UNPACK_10(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10)      \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a11)

#define PICOJSON_DEFINE_PACK_12(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12)                                      \
  PICOJSON_DEFINE_PACK_12_I_(                                                  \
      (obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12))
#define PICOJSON_DEFINE_PACK_12_I_(tuple) PICOJSON_DEFINE_PACK_12_I tuple
#define PICOJSON_DEFINE_PACK_12_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12)                               \
  PICOJSON_DEFINE_PACK_11(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)   \
  PICOJSON_DEFINE_PACK_ITEM(obj, a12)

#define PICOJSON_DEFINE_UNPACK_12(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12)                               \
  PICOJSON_DEFINE_UNPACK_12_I_(                                                \
      (obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12))
#define PICOJSON_DEFINE_UNPACK_12_I_(tuple) PICOJSON_DEFINE_UNPACK_12_I tuple
#define PICOJSON_DEFINE_UNPACK_12_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12)                             \
  PICOJSON_DEFINE_UNPACK_11(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a12)

#define PICOJSON_DEFINE_PACK_13(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13)                                 \
  PICOJSON_DEFINE_PACK_13_I_(                                                  \
      (obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13))
#define PICOJSON_DEFINE_PACK_13_I_(tuple) PICOJSON_DEFINE_PACK_13_I tuple
#define PICOJSON_DEFINE_PACK_13_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13)                          \
  PICOJSON_DEFINE_PACK_12(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12)                                                 \
  PICOJSON_DEFINE_PACK_ITEM(obj, a13)

#define PICOJSON_DEFINE_UNPACK_13(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13)                          \
  PICOJSON_DEFINE_UNPACK_13_I_(                                                \
      (obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13))
#define PICOJSON_DEFINE_UNPACK_13_I_(tuple) PICOJSON_DEFINE_UNPACK_13_I tuple
#define PICOJSON_DEFINE_UNPACK_13_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13)                        \
  PICOJSON_DEFINE_UNPACK_12(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12)                                               \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a13)

#define PICOJSON_DEFINE_PACK_14(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14)                            \
  PICOJSON_DEFINE_PACK_14_I_(                                                  \
      (obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14))
#define PICOJSON_DEFINE_PACK_14_I_(tuple) PICOJSON_DEFINE_PACK_14_I tuple
#define PICOJSON_DEFINE_PACK_14_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14)                     \
  PICOJSON_DEFINE_PACK_13(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13)                                            \
  PICOJSON_DEFINE_PACK_ITEM(obj, a14)

#define PICOJSON_DEFINE_UNPACK_14(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14)                     \
  PICOJSON_DEFINE_UNPACK_14_I_(                                                \
      (obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14))
#define PICOJSON_DEFINE_UNPACK_14_I_(tuple) PICOJSON_DEFINE_UNPACK_14_I tuple
#define PICOJSON_DEFINE_UNPACK_14_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14)                   \
  PICOJSON_DEFINE_UNPACK_13(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13)                                          \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a14)

#define PICOJSON_DEFINE_PACK_15(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15)                       \
  PICOJSON_DEFINE_PACK_15_I_(                                                  \
      (obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15))
#define PICOJSON_DEFINE_PACK_15_I_(tuple) PICOJSON_DEFINE_PACK_15_I tuple
#define PICOJSON_DEFINE_PACK_15_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15)                \
  PICOJSON_DEFINE_PACK_14(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14)                                       \
  PICOJSON_DEFINE_PACK_ITEM(obj, a15)

#define PICOJSON_DEFINE_UNPACK_15(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15)                \
  PICOJSON_DEFINE_UNPACK_15_I_(                                                \
      (obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15))
#define PICOJSON_DEFINE_UNPACK_15_I_(tuple) PICOJSON_DEFINE_UNPACK_15_I tuple
#define PICOJSON_DEFINE_UNPACK_15_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15)              \
  PICOJSON_DEFINE_UNPACK_14(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14)                                     \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a15)

#define PICOJSON_DEFINE_PACK_16(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16)                  \
  PICOJSON_DEFINE_PACK_16_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16))
#define PICOJSON_DEFINE_PACK_16_I_(tuple) PICOJSON_DEFINE_PACK_16_I tuple
#define PICOJSON_DEFINE_PACK_16_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16)           \
  PICOJSON_DEFINE_PACK_15(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15)                                  \
  PICOJSON_DEFINE_PACK_ITEM(obj, a16)

#define PICOJSON_DEFINE_UNPACK_16(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16)           \
  PICOJSON_DEFINE_UNPACK_16_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16))
#define PICOJSON_DEFINE_UNPACK_16_I_(tuple) PICOJSON_DEFINE_UNPACK_16_I tuple
#define PICOJSON_DEFINE_UNPACK_16_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16)         \
  PICOJSON_DEFINE_UNPACK_15(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15)                                \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a16)

#define PICOJSON_DEFINE_PACK_17(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17)             \
  PICOJSON_DEFINE_PACK_17_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16, a17))
#define PICOJSON_DEFINE_PACK_17_I_(tuple) PICOJSON_DEFINE_PACK_17_I tuple
#define PICOJSON_DEFINE_PACK_17_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17)      \
  PICOJSON_DEFINE_PACK_16(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16)                             \
  PICOJSON_DEFINE_PACK_ITEM(obj, a17)

#define PICOJSON_DEFINE_UNPACK_17(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17)      \
  PICOJSON_DEFINE_UNPACK_17_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17))
#define PICOJSON_DEFINE_UNPACK_17_I_(tuple) PICOJSON_DEFINE_UNPACK_17_I tuple
#define PICOJSON_DEFINE_UNPACK_17_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17)    \
  PICOJSON_DEFINE_UNPACK_16(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16)                           \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a17)

#define PICOJSON_DEFINE_PACK_18(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18)        \
  PICOJSON_DEFINE_PACK_18_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16, a17, a18))
#define PICOJSON_DEFINE_PACK_18_I_(tuple) PICOJSON_DEFINE_PACK_18_I tuple
#define PICOJSON_DEFINE_PACK_18_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18) \
  PICOJSON_DEFINE_PACK_17(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16, a17)                        \
  PICOJSON_DEFINE_PACK_ITEM(obj, a18)

#define PICOJSON_DEFINE_UNPACK_18(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18) \
  PICOJSON_DEFINE_UNPACK_18_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18))
#define PICOJSON_DEFINE_UNPACK_18_I_(tuple) PICOJSON_DEFINE_UNPACK_18_I tuple
#define PICOJSON_DEFINE_UNPACK_18_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17,    \
                                    a18)                                       \
  PICOJSON_DEFINE_UNPACK_17(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16, a17)                      \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a18)

#define PICOJSON_DEFINE_PACK_19(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19)   \
  PICOJSON_DEFINE_PACK_19_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16, a17, a18, a19))
#define PICOJSON_DEFINE_PACK_19_I_(tuple) PICOJSON_DEFINE_PACK_19_I tuple
#define PICOJSON_DEFINE_PACK_19_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19)                                         \
  PICOJSON_DEFINE_PACK_18(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16, a17, a18)                   \
  PICOJSON_DEFINE_PACK_ITEM(obj, a19)

#define PICOJSON_DEFINE_UNPACK_19(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19)                                         \
  PICOJSON_DEFINE_UNPACK_19_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19))
#define PICOJSON_DEFINE_UNPACK_19_I_(tuple) PICOJSON_DEFINE_UNPACK_19_I tuple
#define PICOJSON_DEFINE_UNPACK_19_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17,    \
                                    a18, a19)                                  \
  PICOJSON_DEFINE_UNPACK_18(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16, a17, a18)                 \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a19)

#define PICOJSON_DEFINE_PACK_20(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20)                                           \
  PICOJSON_DEFINE_PACK_20_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16, a17, a18, a19,     \
                              a20))
#define PICOJSON_DEFINE_PACK_20_I_(tuple) PICOJSON_DEFINE_PACK_20_I tuple
#define PICOJSON_DEFINE_PACK_20_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20)                                    \
  PICOJSON_DEFINE_PACK_19(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16, a17, a18, a19)              \
  PICOJSON_DEFINE_PACK_ITEM(obj, a20)

#define PICOJSON_DEFINE_UNPACK_20(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20)                                    \
  PICOJSON_DEFINE_UNPACK_20_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20))
#define PICOJSON_DEFINE_UNPACK_20_I_(tuple) PICOJSON_DEFINE_UNPACK_20_I tuple
#define PICOJSON_DEFINE_UNPACK_20_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17,    \
                                    a18, a19, a20)                             \
  PICOJSON_DEFINE_UNPACK_19(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16, a17, a18, a19)            \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a20)

#define PICOJSON_DEFINE_PACK_21(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21)                                      \
  PICOJSON_DEFINE_PACK_21_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16, a17, a18, a19,     \
                              a20, a21))
#define PICOJSON_DEFINE_PACK_21_I_(tuple) PICOJSON_DEFINE_PACK_21_I tuple
#define PICOJSON_DEFINE_PACK_21_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21)                               \
  PICOJSON_DEFINE_PACK_20(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16, a17, a18, a19, a20)         \
  PICOJSON_DEFINE_PACK_ITEM(obj, a21)

#define PICOJSON_DEFINE_UNPACK_21(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21)                               \
  PICOJSON_DEFINE_UNPACK_21_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21))
#define PICOJSON_DEFINE_UNPACK_21_I_(tuple) PICOJSON_DEFINE_UNPACK_21_I tuple
#define PICOJSON_DEFINE_UNPACK_21_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17,    \
                                    a18, a19, a20, a21)                        \
  PICOJSON_DEFINE_UNPACK_20(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16, a17, a18, a19, a20)       \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a21)

#define PICOJSON_DEFINE_PACK_22(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22)                                 \
  PICOJSON_DEFINE_PACK_22_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16, a17, a18, a19,     \
                              a20, a21, a22))
#define PICOJSON_DEFINE_PACK_22_I_(tuple) PICOJSON_DEFINE_PACK_22_I tuple
#define PICOJSON_DEFINE_PACK_22_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22)                          \
  PICOJSON_DEFINE_PACK_21(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16, a17, a18, a19, a20, a21)    \
  PICOJSON_DEFINE_PACK_ITEM(obj, a22)

#define PICOJSON_DEFINE_UNPACK_22(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22)                          \
  PICOJSON_DEFINE_UNPACK_22_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22))
#define PICOJSON_DEFINE_UNPACK_22_I_(tuple) PICOJSON_DEFINE_UNPACK_22_I tuple
#define PICOJSON_DEFINE_UNPACK_22_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17,    \
                                    a18, a19, a20, a21, a22)                   \
  PICOJSON_DEFINE_UNPACK_21(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16, a17, a18, a19, a20, a21)  \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a22)

#define PICOJSON_DEFINE_PACK_23(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23)                            \
  PICOJSON_DEFINE_PACK_23_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16, a17, a18, a19,     \
                              a20, a21, a22, a23))
#define PICOJSON_DEFINE_PACK_23_I_(tuple) PICOJSON_DEFINE_PACK_23_I tuple
#define PICOJSON_DEFINE_PACK_23_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23)                     \
  PICOJSON_DEFINE_PACK_22(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,    \
                          a22)                                                 \
  PICOJSON_DEFINE_PACK_ITEM(obj, a23)

#define PICOJSON_DEFINE_UNPACK_23(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23)                     \
  PICOJSON_DEFINE_UNPACK_23_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23))
#define PICOJSON_DEFINE_UNPACK_23_I_(tuple) PICOJSON_DEFINE_UNPACK_23_I tuple
#define PICOJSON_DEFINE_UNPACK_23_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17,    \
                                    a18, a19, a20, a21, a22, a23)              \
  PICOJSON_DEFINE_UNPACK_22(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,  \
                            a22)                                               \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a23)

#define PICOJSON_DEFINE_PACK_24(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24)                       \
  PICOJSON_DEFINE_PACK_24_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16, a17, a18, a19,     \
                              a20, a21, a22, a23, a24))
#define PICOJSON_DEFINE_PACK_24_I_(tuple) PICOJSON_DEFINE_PACK_24_I tuple
#define PICOJSON_DEFINE_PACK_24_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24)                \
  PICOJSON_DEFINE_PACK_23(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,    \
                          a22, a23)                                            \
  PICOJSON_DEFINE_PACK_ITEM(obj, a24)

#define PICOJSON_DEFINE_UNPACK_24(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24)                \
  PICOJSON_DEFINE_UNPACK_24_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24))
#define PICOJSON_DEFINE_UNPACK_24_I_(tuple) PICOJSON_DEFINE_UNPACK_24_I tuple
#define PICOJSON_DEFINE_UNPACK_24_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17,    \
                                    a18, a19, a20, a21, a22, a23, a24)         \
  PICOJSON_DEFINE_UNPACK_23(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,  \
                            a22, a23)                                          \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a24)

#define PICOJSON_DEFINE_PACK_25(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24, a25)                  \
  PICOJSON_DEFINE_PACK_25_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16, a17, a18, a19,     \
                              a20, a21, a22, a23, a24, a25))
#define PICOJSON_DEFINE_PACK_25_I_(tuple) PICOJSON_DEFINE_PACK_25_I tuple
#define PICOJSON_DEFINE_PACK_25_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24, a25)           \
  PICOJSON_DEFINE_PACK_24(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,    \
                          a22, a23, a24)                                       \
  PICOJSON_DEFINE_PACK_ITEM(obj, a25)

#define PICOJSON_DEFINE_UNPACK_25(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24, a25)           \
  PICOJSON_DEFINE_UNPACK_25_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24, a25))
#define PICOJSON_DEFINE_UNPACK_25_I_(tuple) PICOJSON_DEFINE_UNPACK_25_I tuple
#define PICOJSON_DEFINE_UNPACK_25_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17,    \
                                    a18, a19, a20, a21, a22, a23, a24, a25)    \
  PICOJSON_DEFINE_UNPACK_24(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,  \
                            a22, a23, a24)                                     \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a25)

#define PICOJSON_DEFINE_PACK_26(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24, a25, a26)             \
  PICOJSON_DEFINE_PACK_26_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16, a17, a18, a19,     \
                              a20, a21, a22, a23, a24, a25, a26))
#define PICOJSON_DEFINE_PACK_26_I_(tuple) PICOJSON_DEFINE_PACK_26_I tuple
#define PICOJSON_DEFINE_PACK_26_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24, a25, a26)      \
  PICOJSON_DEFINE_PACK_25(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,    \
                          a22, a23, a24, a25)                                  \
  PICOJSON_DEFINE_PACK_ITEM(obj, a26)

#define PICOJSON_DEFINE_UNPACK_26(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24, a25, a26)      \
  PICOJSON_DEFINE_UNPACK_26_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24, a25, a26))
#define PICOJSON_DEFINE_UNPACK_26_I_(tuple) PICOJSON_DEFINE_UNPACK_26_I tuple
#define PICOJSON_DEFINE_UNPACK_26_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17,    \
                                    a18, a19, a20, a21, a22, a23, a24, a25,    \
                                    a26)                                       \
  PICOJSON_DEFINE_UNPACK_25(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,  \
                            a22, a23, a24, a25)                                \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a26)

#define PICOJSON_DEFINE_PACK_27(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24, a25, a26, a27)        \
  PICOJSON_DEFINE_PACK_27_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16, a17, a18, a19,     \
                              a20, a21, a22, a23, a24, a25, a26, a27))
#define PICOJSON_DEFINE_PACK_27_I_(tuple) PICOJSON_DEFINE_PACK_27_I tuple
#define PICOJSON_DEFINE_PACK_27_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24, a25, a26, a27) \
  PICOJSON_DEFINE_PACK_26(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,    \
                          a22, a23, a24, a25, a26)                             \
  PICOJSON_DEFINE_PACK_ITEM(obj, a27)

#define PICOJSON_DEFINE_UNPACK_27(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24, a25, a26, a27) \
  PICOJSON_DEFINE_UNPACK_27_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24, a25, a26, a27))
#define PICOJSON_DEFINE_UNPACK_27_I_(tuple) PICOJSON_DEFINE_UNPACK_27_I tuple
#define PICOJSON_DEFINE_UNPACK_27_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17,    \
                                    a18, a19, a20, a21, a22, a23, a24, a25,    \
                                    a26, a27)                                  \
  PICOJSON_DEFINE_UNPACK_26(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,  \
                            a22, a23, a24, a25, a26)                           \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a27)

#define PICOJSON_DEFINE_PACK_28(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24, a25, a26, a27, a28)   \
  PICOJSON_DEFINE_PACK_28_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16, a17, a18, a19,     \
                              a20, a21, a22, a23, a24, a25, a26, a27, a28))
#define PICOJSON_DEFINE_PACK_28_I_(tuple) PICOJSON_DEFINE_PACK_28_I tuple
#define PICOJSON_DEFINE_PACK_28_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24, a25, a26, a27, \
                                  a28)                                         \
  PICOJSON_DEFINE_PACK_27(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,    \
                          a22, a23, a24, a25, a26, a27)                        \
  PICOJSON_DEFINE_PACK_ITEM(obj, a28)

#define PICOJSON_DEFINE_UNPACK_28(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24, a25, a26, a27, \
                                  a28)                                         \
  PICOJSON_DEFINE_UNPACK_28_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24, a25, a26, a27, a28))
#define PICOJSON_DEFINE_UNPACK_28_I_(tuple) PICOJSON_DEFINE_UNPACK_28_I tuple
#define PICOJSON_DEFINE_UNPACK_28_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17,    \
                                    a18, a19, a20, a21, a22, a23, a24, a25,    \
                                    a26, a27, a28)                             \
  PICOJSON_DEFINE_UNPACK_27(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,  \
                            a22, a23, a24, a25, a26, a27)                      \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a28)

#define PICOJSON_DEFINE_PACK_29(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24, a25, a26, a27, a28,   \
                                a29)                                           \
  PICOJSON_DEFINE_PACK_29_I_(                                                  \
      (obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15,  \
       a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29))
#define PICOJSON_DEFINE_PACK_29_I_(tuple) PICOJSON_DEFINE_PACK_29_I tuple
#define PICOJSON_DEFINE_PACK_29_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24, a25, a26, a27, \
                                  a28, a29)                                    \
  PICOJSON_DEFINE_PACK_28(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,    \
                          a22, a23, a24, a25, a26, a27, a28)                   \
  PICOJSON_DEFINE_PACK_ITEM(obj, a29)

#define PICOJSON_DEFINE_UNPACK_29(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24, a25, a26, a27, \
                                  a28, a29)                                    \
  PICOJSON_DEFINE_UNPACK_29_I_(                                                \
      (obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15,  \
       a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29))
#define PICOJSON_DEFINE_UNPACK_29_I_(tuple) PICOJSON_DEFINE_UNPACK_29_I tuple
#define PICOJSON_DEFINE_UNPACK_29_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17,    \
                                    a18, a19, a20, a21, a22, a23, a24, a25,    \
                                    a26, a27, a28, a29)                        \
  PICOJSON_DEFINE_UNPACK_28(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,  \
                            a22, a23, a24, a25, a26, a27, a28)                 \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a29)

#define PICOJSON_DEFINE_PACK_30(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24, a25, a26, a27, a28,   \
                                a29, a30)                                      \
  PICOJSON_DEFINE_PACK_30_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16, a17, a18, a19,     \
                              a20, a21, a22, a23, a24, a25, a26, a27, a28,     \
                              a29, a30))
#define PICOJSON_DEFINE_PACK_30_I_(tuple) PICOJSON_DEFINE_PACK_30_I tuple
#define PICOJSON_DEFINE_PACK_30_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24, a25, a26, a27, \
                                  a28, a29, a30)                               \
  PICOJSON_DEFINE_PACK_29(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,    \
                          a22, a23, a24, a25, a26, a27, a28, a29)              \
  PICOJSON_DEFINE_PACK_ITEM(obj, a30)

#define PICOJSON_DEFINE_UNPACK_30(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24, a25, a26, a27, \
                                  a28, a29, a30)                               \
  PICOJSON_DEFINE_UNPACK_30_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24, a25, a26, a27, a28,   \
                                a29, a30))
#define PICOJSON_DEFINE_UNPACK_30_I_(tuple) PICOJSON_DEFINE_UNPACK_30_I tuple
#define PICOJSON_DEFINE_UNPACK_30_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17,    \
                                    a18, a19, a20, a21, a22, a23, a24, a25,    \
                                    a26, a27, a28, a29, a30)                   \
  PICOJSON_DEFINE_UNPACK_29(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,  \
                            a22, a23, a24, a25, a26, a27, a28, a29)            \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a30)

#define PICOJSON_DEFINE_PACK_31(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24, a25, a26, a27, a28,   \
                                a29, a30, a31)                                 \
  PICOJSON_DEFINE_PACK_31_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,    \
                              a11, a12, a13, a14, a15, a16, a17, a18, a19,     \
                              a20, a21, a22, a23, a24, a25, a26, a27, a28,     \
                              a29, a30, a31))
#define PICOJSON_DEFINE_PACK_31_I_(tuple) PICOJSON_DEFINE_PACK_31_I tuple
#define PICOJSON_DEFINE_PACK_31_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24, a25, a26, a27, \
                                  a28, a29, a30, a31)                          \
  PICOJSON_DEFINE_PACK_30(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11,   \
                          a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,    \
                          a22, a23, a24, a25, a26, a27, a28, a29, a30)         \
  PICOJSON_DEFINE_PACK_ITEM(obj, a31)

#define PICOJSON_DEFINE_UNPACK_31(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,     \
                                  a10, a11, a12, a13, a14, a15, a16, a17, a18, \
                                  a19, a20, a21, a22, a23, a24, a25, a26, a27, \
                                  a28, a29, a30, a31)                          \
  PICOJSON_DEFINE_UNPACK_31_I_((obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,  \
                                a11, a12, a13, a14, a15, a16, a17, a18, a19,   \
                                a20, a21, a22, a23, a24, a25, a26, a27, a28,   \
                                a29, a30, a31))
#define PICOJSON_DEFINE_UNPACK_31_I_(tuple) PICOJSON_DEFINE_UNPACK_31_I tuple
#define PICOJSON_DEFINE_UNPACK_31_I(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9,   \
                                    a10, a11, a12, a13, a14, a15, a16, a17,    \
                                    a18, a19, a20, a21, a22, a23, a24, a25,    \
                                    a26, a27, a28, a29, a30, a31)              \
  PICOJSON_DEFINE_UNPACK_30(obj, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                            a12, a13, a14, a15, a16, a17, a18, a19, a20, a21,  \
                            a22, a23, a24, a25, a26, a27, a28, a29, a30)       \
  PICOJSON_DEFINE_UNPACK_ITEM(obj, a31)

#define PICOJSON_DEFINE_PACK_ITEM(obj, a)                                      \
  obj.insert(std::make_pair(std::string(#a), picojson::value(a)));
#define PICOJSON_DEFINE_UNPACK_ITEM(obj, a) a = obj.at(#a).get<decltype(a)>();

#define PICOJSON_DEFINE_I(N, ...)                                              \
  void picojson_pack(picojson::value &root) const {                            \
    picojson::object obj;                                                      \
    PICOJSON_DEFINE_PACK_##N(obj, __VA_ARGS__)                                 \
        root.swap(picojson::value(obj));                                       \
  }                                                                            \
  void picojson_unpack(picojson::value const &root) {                          \
    picojson::object const &obj = root.get<picojson::object>();                \
    PICOJSON_DEFINE_UNPACK_##N(obj, __VA_ARGS__)                               \
  }

#define PICOJSON_DEFINE_I_(tuple) PICOJSON_DEFINE_I tuple
#define PICOJSON_DEFINE_I__(N, ...) PICOJSON_DEFINE_I_((N, __VA_ARGS__))
#define PICOJSON_DEFINE(...)                                                   \
  PICOJSON_DEFINE_I__(PICOJSON_NUM_VA_ARGS(__VA_ARGS__), __VA_ARGS__)

namespace picojson {

template <typename Type> void pack(value &root, Type const &val) {
  val.picojson_pack(root);
}
template <typename Type> void unpack(value const &root, Type &val) {
  val.picojson_unpack(root);
}

namespace detail {

template <
    bool A1, bool A2 = false, bool A3 = false, bool A4 = false, bool A5 = false,
    bool A6 = false, bool A7 = false, bool A8 = false, bool A9 = false,
    bool A10 = false, bool A11 = false, bool A12 = false, bool A13 = false,
    bool A14 = false, bool A15 = false, bool A16 = false, bool A17 = false,
    bool A18 = false, bool A19 = false, bool A20 = false, bool A21 = false,
    bool A22 = false, bool A23 = false, bool A24 = false, bool A25 = false,
    bool A26 = false, bool A27 = false, bool A28 = false, bool A29 = false,
    bool A30 = false, bool A31 = false>
    struct or {
  static const bool value =
      A1 || A2 || A3 || A4 || A5 || A6 || A7 || A8 || A9 || A10 || A11 || A12 ||
      A13 || A14 || A15 || A16 || A17 || A18 || A19 || A20 || A21 || A22 ||
      A23 || A24 || A25 || A26 || A27 || A28 || A29 || A30 || A31;
};

template <bool A1, bool A2 = true, bool A3 = true, bool A4 = true,
          bool A5 = true, bool A6 = true, bool A7 = true, bool A8 = true,
          bool A9 = true, bool A10 = true, bool A11 = true, bool A12 = true,
          bool A13 = true, bool A14 = true, bool A15 = true, bool A16 = true,
          bool A17 = true, bool A18 = true, bool A19 = true, bool A20 = true,
          bool A21 = true, bool A22 = true, bool A23 = true, bool A24 = true,
          bool A25 = true, bool A26 = true, bool A27 = true, bool A28 = true,
          bool A29 = true, bool A30 = true, bool A31 = true>
struct and {
  static const bool value =
      A1 && A2 && A3 && A4 && A5 && A6 && A7 && A8 && A9 && A10 && A11 && A12 &&
      A13 && A14 && A15 && A16 && A17 && A18 && A19 && A20 && A21 && A22 &&
      A23 && A24 && A25 && A26 && A27 && A28 && A29 && A30 && A31;
};

template <bool A> struct not{ static const bool value = !A; };

template <typename T> struct is_picojson_type {
  static const bool value =
      or <std::is_same<T, picojson::null>::value, std::is_same<T, bool>::value,
          std::is_same<T, double>::value, std::is_same<T, std::string>::value,
          std::is_same<T, picojson::array>::value,
          std::is_same<T, picojson::object>::value>::value;
};
} // namespace detail;

} // namespace picojson;
