#pragma once

// Calculate the count of arguments.
#define PICOJSON_NUM_VA_ARGS_I(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define PICOJSON_NUM_VA_ARGS_I_(tuple) PICOJSON_NUM_VA_ARGS_I tuple
#define PICOJSON_NUM_VA_ARGS(...) PICOJSON_NUM_VA_ARGS_I_((__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))

// definition of pack/unpack method

// pack
#define PICOJSON_DEFINE_PACK_1(clsname, a1) PICOJSON_DEFINE_PACK_ITEM(clsname, a1)
// unpack
#define PICOJSON_DEFINE_UNPACK_1(clsname, a1) PICOJSON_DEFINE_UNPACK_ITEM(clsname, a1)

#define PICOJSON_DEFINE_PACK_2(clsname, a1, a2) \
    PICOJSON_DEFINE_PACK_2_I_((clsname, a1, a2))
#define PICOJSON_DEFINE_PACK_2_I_(tuple) \
    PICOJSON_DEFINE_PACK_2_I tuple
#define PICOJSON_DEFINE_PACK_2_I(clsname, a1, a2) \
    PICOJSON_DEFINE_PACK_1(clsname, a1)           \
    PICOJSON_DEFINE_PACK_ITEM(clsname, a2)

#define PICOJSON_DEFINE_UNPACK_2(clsname, a1, a2) \
    PICOJSON_DEFINE_UNPACK_2_I_((clsname, a1, a2))
#define PICOJSON_DEFINE_UNPACK_2_I_(tuple) \
    PICOJSON_DEFINE_UNPACK_2_I tuple
#define PICOJSON_DEFINE_UNPACK_2_I(clsname, a1, a2) \
    PICOJSON_DEFINE_UNPACK_1(clsname, a1)           \
    PICOJSON_DEFINE_UNPACK_ITEM(clsname, a2)

#define PICOJSON_DEFINE_PACK_3(clsname, a1, a2, a3) \
    PICOJSON_DEFINE_PACK_3_I_((clsname, a1, a2, a3))
#define PICOJSON_DEFINE_PACK_3_I_(tuple) \
    PICOJSON_DEFINE_PACK_3_I tuple
#define PICOJSON_DEFINE_PACK_3_I(clsname, a1, a2, a3) \
    PICOJSON_DEFINE_PACK_2(clsname, a1, a2)           \
    PICOJSON_DEFINE_PACK_ITEM(clsname, a3)

#define PICOJSON_DEFINE_UNPACK_3(clsname, a1, a2, a3) \
    PICOJSON_DEFINE_UNPACK_3_I_((clsname, a1, a2, a3))
#define PICOJSON_DEFINE_UNPACK_3_I_(tuple) \
    PICOJSON_DEFINE_UNPACK_3_I tuple
#define PICOJSON_DEFINE_UNPACK_3_I(clsname, a1, a2, a3) \
    PICOJSON_DEFINE_UNPACK_2(clsname, a1, a2)           \
    PICOJSON_DEFINE_UNPACK_ITEM(clsname, a3)

#define PICOJSON_DEFINE_PACK_4(clsname, a1, a2, a3, a4) \
    PICOJSON_DEFINE_PACK_4_I_((clsname, a1, a2, a3, a4))
#define PICOJSON_DEFINE_PACK_4_I_(tuple) \
    PICOJSON_DEFINE_PACK_4_I tuple
#define PICOJSON_DEFINE_PACK_4_I(clsname, a1, a2, a3, a4) \
    PICOJSON_DEFINE_PACK_3(clsname, a1, a2, a3)           \
    PICOJSON_DEFINE_PACK_ITEM(clsname, a4)

#define PICOJSON_DEFINE_UNPACK_4(clsname, a1, a2, a3, a4) \
    PICOJSON_DEFINE_UNPACK_4_I_((clsname, a1, a2, a3, a4))
#define PICOJSON_DEFINE_UNPACK_4_I_(tuple) \
    PICOJSON_DEFINE_UNPACK_4_I tuple
#define PICOJSON_DEFINE_UNPACK_4_I(clsname, a1, a2, a3, a4) \
    PICOJSON_DEFINE_UNPACK_3(clsname, a1, a2, a3)           \
    PICOJSON_DEFINE_UNPACK_ITEM(clsname, a4)

#define PICOJSON_DEFINE_PACK_5(clsname, a1, a2, a3, a4, a5) \
    PICOJSON_DEFINE_PACK_5_I_((clsname, a1, a2, a3, a4, a5))
#define PICOJSON_DEFINE_PACK_5_I_(tuple) \
    PICOJSON_DEFINE_PACK_5_I tuple
#define PICOJSON_DEFINE_PACK_5_I(clsname, a1, a2, a3, a4, a5) \
    PICOJSON_DEFINE_PACK_4(clsname, a1, a2, a3, a4)           \
    PICOJSON_DEFINE_PACK_ITEM(clsname, a5)

#define PICOJSON_DEFINE_UNPACK_5(clsname, a1, a2, a3, a4, a5) \
    PICOJSON_DEFINE_UNPACK_5_I_((clsname, a1, a2, a3, a4, a5))
#define PICOJSON_DEFINE_UNPACK_5_I_(tuple) \
    PICOJSON_DEFINE_UNPACK_5_I tuple
#define PICOJSON_DEFINE_UNPACK_5_I(clsname, a1, a2, a3, a4, a5) \
    PICOJSON_DEFINE_UNPACK_4(clsname, a1, a2, a3, a4)           \
    PICOJSON_DEFINE_UNPACK_ITEM(clsname, a5)

#define PICOJSON_DEFINE_PACK_6(clsname, a1, a2, a3, a4, a5, a6) \
    PICOJSON_DEFINE_PACK_6_I_((clsname, a1, a2, a3, a4, a5, a6))
#define PICOJSON_DEFINE_PACK_6_I_(tuple) \
    PICOJSON_DEFINE_PACK_6_I tuple
#define PICOJSON_DEFINE_PACK_6_I(clsname, a1, a2, a3, a4, a5, a6) \
    PICOJSON_DEFINE_PACK_5(clsname, a1, a2, a3, a4, a5)           \
    PICOJSON_DEFINE_PACK_ITEM(clsname, a6)

#define PICOJSON_DEFINE_UNPACK_6(clsname, a1, a2, a3, a4, a5, a6) \
    PICOJSON_DEFINE_UNPACK_6_I_((clsname, a1, a2, a3, a4, a5, a6))
#define PICOJSON_DEFINE_UNPACK_6_I_(tuple) \
    PICOJSON_DEFINE_UNPACK_6_I tuple
#define PICOJSON_DEFINE_UNPACK_6_I(clsname, a1, a2, a3, a4, a5, a6) \
    PICOJSON_DEFINE_UNPACK_5(clsname, a1, a2, a3, a4, a5)           \
    PICOJSON_DEFINE_UNPACK_ITEM(clsname, a6)

#define PICOJSON_DEFINE_PACK_7(clsname, a1, a2, a3, a4, a5, a6, a7) \
    PICOJSON_DEFINE_PACK_7_I_((clsname, a1, a2, a3, a4, a5, a6, a7))
#define PICOJSON_DEFINE_PACK_7_I_(tuple) \
    PICOJSON_DEFINE_PACK_7_I tuple
#define PICOJSON_DEFINE_PACK_7_I(clsname, a1, a2, a3, a4, a5, a6, a7) \
    PICOJSON_DEFINE_PACK_6(clsname, a1, a2, a3, a4, a5, a6)           \
    PICOJSON_DEFINE_PACK_ITEM(clsname, a7)

#define PICOJSON_DEFINE_UNPACK_7(clsname, a1, a2, a3, a4, a5, a6, a7) \
    PICOJSON_DEFINE_UNPACK_7_I_((clsname, a1, a2, a3, a4, a5, a6, a7))
#define PICOJSON_DEFINE_UNPACK_7_I_(tuple) \
    PICOJSON_DEFINE_UNPACK_7_I tuple
#define PICOJSON_DEFINE_UNPACK_7_I(clsname, a1, a2, a3, a4, a5, a6, a7) \
    PICOJSON_DEFINE_UNPACK_6(clsname, a1, a2, a3, a4, a5, a6)           \
    PICOJSON_DEFINE_UNPACK_ITEM(clsname, a7)

#define PICOJSON_DEFINE_PACK_8(clsname, a1, a2, a3, a4, a5, a6, a7, a8) \
    PICOJSON_DEFINE_PACK_8_I_((clsname, a1, a2, a3, a4, a5, a6, a7, a8))
#define PICOJSON_DEFINE_PACK_8_I_(tuple) \
    PICOJSON_DEFINE_PACK_8_I tuple
#define PICOJSON_DEFINE_PACK_8_I(clsname, a1, a2, a3, a4, a5, a6, a7, a8) \
    PICOJSON_DEFINE_PACK_7(clsname, a1, a2, a3, a4, a5, a6, a7)           \
    PICOJSON_DEFINE_PACK_ITEM(clsname, a8)

#define PICOJSON_DEFINE_UNPACK_8(clsname, a1, a2, a3, a4, a5, a6, a7, a8) \
    PICOJSON_DEFINE_UNPACK_8_I_((clsname, a1, a2, a3, a4, a5, a6, a7, a8))
#define PICOJSON_DEFINE_UNPACK_8_I_(tuple) \
    PICOJSON_DEFINE_UNPACK_8_I tuple
#define PICOJSON_DEFINE_UNPACK_8_I(clsname, a1, a2, a3, a4, a5, a6, a7, a8) \
    PICOJSON_DEFINE_UNPACK_7(clsname, a1, a2, a3, a4, a5, a6, a7)           \
    PICOJSON_DEFINE_UNPACK_ITEM(clsname, a8)

#define PICOJSON_DEFINE_PACK_9(clsname, a1, a2, a3, a4, a5, a6, a7, a8, a9) \
    PICOJSON_DEFINE_PACK_9_I_((clsname, a1, a2, a3, a4, a5, a6, a7, a8, a9))
#define PICOJSON_DEFINE_PACK_9_I_(tuple) \
    PICOJSON_DEFINE_PACK_9_I tuple
#define PICOJSON_DEFINE_PACK_9_I(clsname, a1, a2, a3, a4, a5, a6, a7, a8, a9) \
    PICOJSON_DEFINE_PACK_8(clsname, a1, a2, a3, a4, a5, a6, a7, a8)           \
    PICOJSON_DEFINE_PACK_ITEM(clsname, a9)

#define PICOJSON_DEFINE_UNPACK_9(clsname, a1, a2, a3, a4, a5, a6, a7, a8, a9) \
    PICOJSON_DEFINE_UNPACK_9_I_((clsname, a1, a2, a3, a4, a5, a6, a7, a8, a9))
#define PICOJSON_DEFINE_UNPACK_9_I_(tuple) \
    PICOJSON_DEFINE_UNPACK_9_I tuple
#define PICOJSON_DEFINE_UNPACK_9_I(clsname, a1, a2, a3, a4, a5, a6, a7, a8, a9) \
    PICOJSON_DEFINE_UNPACK_8(clsname, a1, a2, a3, a4, a5, a6, a7, a8)           \
    PICOJSON_DEFINE_UNPACK_ITEM(clsname, a9)

#define PICOJSON_DEFINE_PACK_10(clsname, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
    PICOJSON_DEFINE_PACK_10_I_((clsname, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10))
#define PICOJSON_DEFINE_PACK_10_I_(tuple) \
    PICOJSON_DEFINE_PACK_10_I tuple
#define PICOJSON_DEFINE_PACK_10_I(clsname, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
    PICOJSON_DEFINE_PACK_9(clsname, a1, a2, a3, a4, a5, a6, a7, a8, a9)             \
    PICOJSON_DEFINE_PACK_ITEM(clsname, a10)

#define PICOJSON_DEFINE_UNPACK_10(clsname, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
    PICOJSON_DEFINE_UNPACK_10_I_((clsname, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10))
#define PICOJSON_DEFINE_UNPACK_10_I_(tuple) \
    PICOJSON_DEFINE_UNPACK_10_I tuple
#define PICOJSON_DEFINE_UNPACK_10_I(clsname, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
    PICOJSON_DEFINE_UNPACK_9(clsname, a1, a2, a3, a4, a5, a6, a7, a8, a9)             \
    PICOJSON_DEFINE_UNPACK_ITEM(clsname, a10)

#define PICOJSON_DEFINE_PACK_ITEM(clsname, a) \
    root.insert(std::make_pair(std::string(#a), picojson::value(a)));
#define PICOJSON_DEFINE_UNPACK_ITEM(clsname, a) \
    a = root.at(#a).get<decltype(a)>();

#define PICOJSON_DEFINE_I(clsname, N, ...)               \
    void picojson_pack(picojson::object& root) const     \
    {                                                    \
        PICOJSON_DEFINE_PACK_##N(clsname, __VA_ARGS__)   \
    }                                                    \
    void picojson_unpack(picojson::object const& root)   \
    {                                                    \
        PICOJSON_DEFINE_UNPACK_##N(clsname, __VA_ARGS__) \
    }
#define PICOJSON_DEFINE_I_(tuple) PICOJSON_DEFINE_I tuple
#define PICOJSON_DEFINE_I__(clsname, N, ...) PICOJSON_DEFINE_I_((clsname, N, __VA_ARGS__))
#define PICOJSON_DEFINE(clsname, ...) \
    PICOJSON_DEFINE_I__(clsname, PICOJSON_NUM_VA_ARGS(__VA_ARGS__), __VA_ARGS__)

namespace picojson {

template <typename Type>
void pack(object& root, Type const& val)
{
    val.picojson_pack(root);
}
template <typename Type>
void unpack(object const& root, Type& val)
{
    val.picojson_unpack(root);
}
} //namespace picojson;
