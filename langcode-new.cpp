#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <functional>
#include "langcode.h"

//#if !defined(USING_VECTOR) && !defined(USING_MAP) && !defined(USING_DICT)
//#define USING_MAP
//#endif

#if defined(USING_VECTOR) || defined(USING_VECTOR_SORTED) || defined(USING_MAP) || defined(USING_DICT)

namespace std 
{
template <>
struct hash<const char *>
{
	size_t operator()(const char *str) const
	{
        //__murmur2_or_cityhash<size_t>()(__p, (__e-__p)*sizeof(value_type))
		size_t h = 5381;
		int c = 0;
        const char* s = str;
		while ((c = *s++))
			h = ((h << 5) + h) + c;
        //printf("hash for %s: %zu\n", str, h);
		return h;
	}
};
}

struct EqualCharPtr : std::binary_function<bool, const char*, const char*> {
    bool operator() (const char* a, const char* b) const noexcept {
        return strcmp(a, b) == 0;
    }
};

struct CompareCharPtr : std::binary_function<bool, const char*, const char*> {
    bool operator() (const char* a, const char* b) const noexcept {
        return strcmp(a, b) < 0;
    }
};

struct LangCode {
    const char* alpha_three;
    const char* alpha_two;
    const char* name;
};

#else

struct LangCode {
    std::string alpha_three;
    std::string alpha_two;
    std::string name;
};

#endif


#if defined(USING_VECTOR) || defined(USING_VECTOR_STR)

static std::vector<LangCode> g_langCodes = {
#define LANG_CODE_DEFINE(alpha_three, alpha_two, name) \
        {alpha_three, alpha_two, name},
#define LANG_CODE_LAST_DEFINE(alpha_three, alpha_two, name) \
        {alpha_three, alpha_two, name}
#include "langcode-data.h"
};

#elif defined(USING_VECTOR_SORTED) || defined(USING_VECTOR_STR_SORTED)

static std::vector<LangCode> g_langCodes;

static bool initializeLangCodes() {
    g_langCodes = std::vector<LangCode>{
#define LANG_CODE_DEFINE(alpha_three, alpha_two, name) \
        {alpha_three, alpha_two, name},
#define LANG_CODE_LAST_DEFINE(alpha_three, alpha_two, name) \
        {alpha_three, alpha_two, name}
#include "langcode-data.h"
};
    std::sort(std::begin(g_langCodes), std::end(g_langCodes), [](const LangCode& a, const LangCode& b) {
#if defined(USING_VECTOR_SORTED)
        return strcmp(a.alpha_two, b.alpha_two) < 0;
#else
        return a.alpha_two < b.alpha_two;
#endif
    });
    return true;
}

static const bool g_langCodesInitialized = initializeLangCodes();

static bool isInitialized() {
    return g_langCodesInitialized;
}

#elif defined(USING_MAP) 

static std::map<const char*, LangCode, CompareCharPtr> g_langCodes = {
#define LANG_CODE_DEFINE(alpha_three, alpha_two, name) \
        {alpha_two, {alpha_three, alpha_two, name}},
#define LANG_CODE_LAST_DEFINE(alpha_three, alpha_two, name) \
        {alpha_two, {alpha_three, alpha_two, name}}
#include "langcode-data.h"
};

#elif defined(USING_MAP_STR)

static std::map<std::string, LangCode> g_langCodes = {
#define LANG_CODE_DEFINE(alpha_three, alpha_two, name) \
        {alpha_two, {alpha_three, alpha_two, name}},
#define LANG_CODE_LAST_DEFINE(alpha_three, alpha_two, name) \
        {alpha_two, {alpha_three, alpha_two, name}}
#include "langcode-data.h"
};

#elif defined(USING_DICT)

static std::unordered_map<const char*, LangCode, std::hash<const char*>, EqualCharPtr> g_langCodes = {
#define LANG_CODE_DEFINE(alpha_three, alpha_two, name) \
        {alpha_two, {alpha_three, alpha_two, name}},
#define LANG_CODE_LAST_DEFINE(alpha_three, alpha_two, name) \
        {alpha_two, {alpha_three, alpha_two, name}}
#include "langcode-data.h"
};

#elif defined(USING_DICT_STR)

static std::unordered_map<std::string, LangCode> g_langCodes = {
#define LANG_CODE_DEFINE(alpha_three, alpha_two, name) \
        {alpha_two, {alpha_three, alpha_two, name}},
#define LANG_CODE_LAST_DEFINE(alpha_three, alpha_two, name) \
        {alpha_two, {alpha_three, alpha_two, name}}
#include "langcode-data.h"
};

#endif

namespace qmx {

#ifdef USING_VECTOR

const char *langcode_three_new(const char *langcode_two) {
    auto i = std::find_if(std::begin(g_langCodes), std::end(g_langCodes), [langcode_two](const LangCode& lang_code) {
        return strcmp(langcode_two, lang_code.alpha_two) == 0;
    });
    return i != std::end(g_langCodes) ? i->alpha_three : langcode_two;
}

std::string langcode_three_new(const std::string& langcode_two) {
    return langcode_three_new(langcode_two.c_str());
}

#elif defined(USING_VECTOR_SORTED)

const char *langcode_three_new(const char *langcode_two) {
    auto param_langcode = LangCode{nullptr, langcode_two, nullptr};
    auto i = std::lower_bound(std::begin(g_langCodes), std::end(g_langCodes), param_langcode, [](const LangCode& a, const LangCode& b) {
        return strcmp(a.alpha_two, b.alpha_two) < 0;
    });
    if (i != std::end(g_langCodes) && strcmp(i->alpha_two, langcode_two) == 0)
        return i->alpha_three;
    else
        return langcode_two;
}

std::string langcode_three_new(const std::string& langcode_two) {
    return langcode_three_new(langcode_two.c_str());
}

#elif defined(USING_VECTOR_STR)

const char *langcode_three_new(const char *langcode_two) {
    return langcode_three_new(std::string{langcode_two}).c_str();
}

std::string langcode_three_new(const std::string& langcode_two) {
    auto i = std::find_if(std::begin(g_langCodes), std::end(g_langCodes), [&langcode_two](const LangCode& lang_code) {
        return langcode_two == lang_code.alpha_two;
    });
    return i != std::end(g_langCodes) ? i->alpha_three : langcode_two;
}

#elif defined(USING_VECTOR_STR_SORTED)

const char *langcode_three_new(const char *langcode_two) {
    return langcode_three_new(std::string{langcode_two}).c_str();
}

std::string langcode_three_new(const std::string& langcode_two) {
    const auto& param_langcode = LangCode{std::string{}, langcode_two, std::string{}};
    auto i = std::lower_bound(std::begin(g_langCodes), std::end(g_langCodes), param_langcode, [](const LangCode& a, const LangCode& b) {
        return a.alpha_two < b.alpha_two;
    });
    return i != std::end(g_langCodes) && i->alpha_two == langcode_two ? i->alpha_three : langcode_two;
}

#elif defined(USING_MAP)

const char *langcode_three_new(const char *langcode_two) {
    auto i = g_langCodes.find(langcode_two);
    return i != std::end(g_langCodes) ? i->second.alpha_three : langcode_two;
}

std::string langcode_three_new(const std::string& langcode_two) {
    return langcode_three_new(langcode_two.c_str());
}

#elif defined(USING_MAP_STR)

const char *langcode_three_new(const char *langcode_two) {
    return langcode_three_new(std::string{langcode_two}).c_str();
}

std::string langcode_three_new(const std::string& langcode_two) {
    auto i = g_langCodes.find(langcode_two);
    return i != std::end(g_langCodes) ? i->second.alpha_three : langcode_two;
}

#elif defined(USING_DICT)

const char *langcode_three_new(const char *langcode_two) {
    auto i = g_langCodes.find(langcode_two);
    return i != std::end(g_langCodes) ? i->second.alpha_three : langcode_two;
}

std::string langcode_three_new(const std::string& langcode_two) {
    return langcode_three_new(langcode_two.c_str());
}

#elif defined(USING_DICT_STR)

const char *langcode_three_new(const char *langcode_two) {
    return langcode_three_new(std::string{langcode_two}).c_str();
}

std::string langcode_three_new(const std::string& langcode_two) {
    auto i = g_langCodes.find(langcode_two);
    return i != std::end(g_langCodes) ? i->second.alpha_three : langcode_two;
}

#endif

} // namespace qmx

