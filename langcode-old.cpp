/* C++ code produced by gperf version 3.0.4 */
/* Command-line: gperf langmap.gperf  */
/* Computed positions: -k'1-2' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif


#include <cstring>

#include "langcode.h"

namespace qmx {

#ifndef _WIN32
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#pragma GCC diagnostic ignored "-Wunused-macros"
#if defined(__GNUC__) && defined(__clang__)
#pragma GCC diagnostic ignored "-Wdeprecated-register"
#endif
#pragma GCC diagnostic ignored "-Wsign-conversion"
#if defined(__GNUC__) && defined(__clang__)
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#endif
#endif
struct langcode { int stringpool_offset; const char *threecode; };

#define TOTAL_KEYWORDS 184
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 2
#define MIN_HASH_VALUE 0
#define MAX_HASH_VALUE 450
/* maximum key range = 451, duplicates = 0 */

#ifndef GPERF_DOWNCASE
#define GPERF_DOWNCASE 1
static unsigned char gperf_downcase[256] =
  {
      0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,
     15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
     30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,
     45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
     60,  61,  62,  63,  64,  97,  98,  99, 100, 101, 102, 103, 104, 105, 106,
    107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121,
    122,  91,  92,  93,  94,  95,  96,  97,  98,  99, 100, 101, 102, 103, 104,
    105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
    120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134,
    135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149,
    150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164,
    165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
    180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194,
    195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209,
    210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224,
    225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254,
    255
  };
#endif

#ifndef GPERF_CASE_STRCMP
#define GPERF_CASE_STRCMP 1
static int
gperf_case_strcmp (register const char *s1, register const char *s2)
{
  for (;;)
    {
      unsigned char c1 = gperf_downcase[(unsigned char)*s1++];
      unsigned char c2 = gperf_downcase[(unsigned char)*s2++];
      if (c1 != 0 && c1 == c2)
        continue;
      return (int)c1 - (int)c2;
    }
}
#endif

class LangCodeGperf
{
private:
  static inline unsigned int langcode_23_hash (const char *str, unsigned int len);
public:
  static const struct langcode *langcode_from_two (const char *str, unsigned int len);
};

inline /*ARGSUSED*/
unsigned int
LangCodeGperf::langcode_23_hash (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      451, 451, 451, 451, 451, 451, 451, 451, 451, 451,
      451, 451, 451, 451, 451, 451, 451, 451, 451, 451,
      451, 451, 451, 451, 451, 451, 451, 451, 451, 451,
      451, 451, 451, 451, 451, 451, 451, 451, 451, 451,
      451, 451, 451, 451, 451, 451, 451, 451, 451, 451,
      451, 451, 451, 451, 451, 451, 451, 451, 451, 451,
      451, 451, 451, 451, 451, 451, 451, 451, 250,  90,
      184,  48, 209, 193,   8, 234, 190, 210, 100,  64,
       14,   4,   5, 165,  73,   3,   0,  10,  35,  74,
       75, 230, 145,  54, 451, 451, 451, 451, 451, 451,
      250,  90, 184,  48, 209, 193,   8, 234, 190, 210,
      100,  64,  14,   4,   5, 165,  73,   3,   0,  10,
       35,  74,  75, 230, 145,  54,  60,  19,  40, 451,
       14,  20, 200, 124,  94, 179,  18, 451, 164,  65,
      451, 451, 451, 451, 451, 451,   5, 165,  73,   3,
        0,  10,  35,  74,  75, 230, 145,  54,  60,  19,
       40, 451,  14,  20, 200, 124,  94, 179,  18, 451,
      164,  65, 451, 451, 451, 451, 451
    };
  return asso_values[(unsigned char)str[1]+49] + asso_values[(unsigned char)str[0]+3];
}

struct langcode_two_stringpool_t
  {
    char langcode_two_stringpool_str0[sizeof("se")];
    char langcode_two_stringpool_str3[sizeof("sd")];
    char langcode_two_stringpool_str4[sizeof("ne")];
    char langcode_two_stringpool_str5[sizeof("sa")];
    char langcode_two_stringpool_str7[sizeof("nd")];
    char langcode_two_stringpool_str9[sizeof("na")];
    char langcode_two_stringpool_str10[sizeof("te")];
    char langcode_two_stringpool_str11[sizeof("gd")];
    char langcode_two_stringpool_str13[sizeof("ga")];
    char langcode_two_stringpool_str14[sizeof("sq")];
    char langcode_two_stringpool_str15[sizeof("ta")];
    char langcode_two_stringpool_str18[sizeof("sw")];
    char langcode_two_stringpool_str19[sizeof("sn")];
    char langcode_two_stringpool_str20[sizeof("sr")];
    char langcode_two_stringpool_str21[sizeof("rw")];
    char langcode_two_stringpool_str22[sizeof("rn")];
    char langcode_two_stringpool_str23[sizeof("nn")];
    char langcode_two_stringpool_str24[sizeof("nr")];
    char langcode_two_stringpool_str25[sizeof("or")];
    char langcode_two_stringpool_str27[sizeof("gn")];
    char langcode_two_stringpool_str28[sizeof("tw")];
    char langcode_two_stringpool_str29[sizeof("tn")];
    char langcode_two_stringpool_str30[sizeof("tr")];
    char langcode_two_stringpool_str33[sizeof("mn")];
    char langcode_two_stringpool_str34[sizeof("mr")];
    char langcode_two_stringpool_str35[sizeof("sg")];
    char langcode_two_stringpool_str39[sizeof("ng")];
    char langcode_two_stringpool_str40[sizeof("so")];
    char langcode_two_stringpool_str43[sizeof("ro")];
    char langcode_two_stringpool_str44[sizeof("no")];
    char langcode_two_stringpool_str45[sizeof("tg")];
    char langcode_two_stringpool_str48[sizeof("de")];
    char langcode_two_stringpool_str49[sizeof("mg")];
    char langcode_two_stringpool_str50[sizeof("to")];
    char langcode_two_stringpool_str53[sizeof("da")];
    char langcode_two_stringpool_str54[sizeof("sl")];
    char langcode_two_stringpool_str55[sizeof("ur")];
    char langcode_two_stringpool_str58[sizeof("nl")];
    char langcode_two_stringpool_str59[sizeof("za")];
    char langcode_two_stringpool_str60[sizeof("sm")];
    char langcode_two_stringpool_str62[sizeof("gl")];
    char langcode_two_stringpool_str63[sizeof("rm")];
    char langcode_two_stringpool_str64[sizeof("tl")];
    char langcode_two_stringpool_str65[sizeof("om")];
    char langcode_two_stringpool_str68[sizeof("ml")];
    char langcode_two_stringpool_str69[sizeof("la")];
    char langcode_two_stringpool_str70[sizeof("ug")];
    char langcode_two_stringpool_str73[sizeof("sc")];
    char langcode_two_stringpool_str74[sizeof("ve")];
    char langcode_two_stringpool_str75[sizeof("si")];
    char langcode_two_stringpool_str78[sizeof("oc")];
    char langcode_two_stringpool_str80[sizeof("wa")];
    char langcode_two_stringpool_str83[sizeof("ln")];
    char langcode_two_stringpool_str84[sizeof("th")];
    char langcode_two_stringpool_str85[sizeof("ti")];
    char langcode_two_stringpool_str88[sizeof("mh")];
    char langcode_two_stringpool_str89[sizeof("mi")];
    char langcode_two_stringpool_str90[sizeof("be")];
    char langcode_two_stringpool_str94[sizeof("su")];
    char langcode_two_stringpool_str95[sizeof("ba")];
    char langcode_two_stringpool_str97[sizeof("ru")];
    char langcode_two_stringpool_str99[sizeof("lg")];
    char langcode_two_stringpool_str100[sizeof("uz")];
    char langcode_two_stringpool_str102[sizeof("gu")];
    char langcode_two_stringpool_str104[sizeof("lo")];
    char langcode_two_stringpool_str105[sizeof("ka")];
    char langcode_two_stringpool_str109[sizeof("bn")];
    char langcode_two_stringpool_str110[sizeof("br")];
    char langcode_two_stringpool_str113[sizeof("dz")];
    char langcode_two_stringpool_str114[sizeof("vo")];
    char langcode_two_stringpool_str115[sizeof("wo")];
    char langcode_two_stringpool_str118[sizeof("kw")];
    char langcode_two_stringpool_str119[sizeof("kn")];
    char langcode_two_stringpool_str120[sizeof("kr")];
    char langcode_two_stringpool_str124[sizeof("st")];
    char langcode_two_stringpool_str125[sizeof("bg")];
    char langcode_two_stringpool_str128[sizeof("zh")];
    char langcode_two_stringpool_str130[sizeof("bo")];
    char langcode_two_stringpool_str134[sizeof("tt")];
    char langcode_two_stringpool_str135[sizeof("kg")];
    char langcode_two_stringpool_str138[sizeof("mt")];
    char langcode_two_stringpool_str139[sizeof("li")];
    char langcode_two_stringpool_str140[sizeof("ko")];
    char langcode_two_stringpool_str145[sizeof("sk")];
    char langcode_two_stringpool_str148[sizeof("zu")];
    char langcode_two_stringpool_str149[sizeof("vi")];
    char langcode_two_stringpool_str150[sizeof("bm")];
    char langcode_two_stringpool_str154[sizeof("kl")];
    char langcode_two_stringpool_str155[sizeof("tk")];
    char langcode_two_stringpool_str158[sizeof("lu")];
    char langcode_two_stringpool_str159[sizeof("mk")];
    char langcode_two_stringpool_str160[sizeof("km")];
    char langcode_two_stringpool_str164[sizeof("bh")];
    char langcode_two_stringpool_str165[sizeof("bi")];
    char langcode_two_stringpool_str167[sizeof("qu")];
    char langcode_two_stringpool_str168[sizeof("ny")];
    char langcode_two_stringpool_str169[sizeof("nb")];
    char langcode_two_stringpool_str170[sizeof("pa")];
    char langcode_two_stringpool_str174[sizeof("ty")];
    char langcode_two_stringpool_str175[sizeof("ki")];
    char langcode_two_stringpool_str178[sizeof("my")];
    char langcode_two_stringpool_str179[sizeof("sv")];
    char langcode_two_stringpool_str180[sizeof("uk")];
    char langcode_two_stringpool_str183[sizeof("nv")];
    char langcode_two_stringpool_str184[sizeof("ce")];
    char langcode_two_stringpool_str185[sizeof("yo")];
    char langcode_two_stringpool_str187[sizeof("gv")];
    char langcode_two_stringpool_str188[sizeof("lt")];
    char langcode_two_stringpool_str189[sizeof("ca")];
    char langcode_two_stringpool_str190[sizeof("ie")];
    char langcode_two_stringpool_str193[sizeof("id")];
    char langcode_two_stringpool_str194[sizeof("ku")];
    char langcode_two_stringpool_str195[sizeof("ia")];
    char langcode_two_stringpool_str198[sizeof("fa")];
    char langcode_two_stringpool_str200[sizeof("ss")];
    char langcode_two_stringpool_str203[sizeof("ff")];
    char langcode_two_stringpool_str204[sizeof("cr")];
    char langcode_two_stringpool_str205[sizeof("os")];
    char langcode_two_stringpool_str209[sizeof("ee")];
    char langcode_two_stringpool_str210[sizeof("ts")];
    char langcode_two_stringpool_str213[sizeof("fr")];
    char langcode_two_stringpool_str214[sizeof("ms")];
    char langcode_two_stringpool_str215[sizeof("ja")];
    char langcode_two_stringpool_str219[sizeof("pl")];
    char langcode_two_stringpool_str220[sizeof("yi")];
    char langcode_two_stringpool_str224[sizeof("co")];
    char langcode_two_stringpool_str225[sizeof("ig")];
    char langcode_two_stringpool_str227[sizeof("dv")];
    char langcode_two_stringpool_str228[sizeof("en")];
    char langcode_two_stringpool_str229[sizeof("lb")];
    char langcode_two_stringpool_str230[sizeof("io")];
    char langcode_two_stringpool_str233[sizeof("fo")];
    char langcode_two_stringpool_str234[sizeof("he")];
    char langcode_two_stringpool_str235[sizeof("oj")];
    char langcode_two_stringpool_str239[sizeof("ha")];
    char langcode_two_stringpool_str240[sizeof("pi")];
    char langcode_two_stringpool_str243[sizeof("lv")];
    char langcode_two_stringpool_str245[sizeof("kk")];
    char langcode_two_stringpool_str249[sizeof("eo")];
    char langcode_two_stringpool_str250[sizeof("ae")];
    char langcode_two_stringpool_str254[sizeof("hr")];
    char langcode_two_stringpool_str255[sizeof("aa")];
    char langcode_two_stringpool_str258[sizeof("ch")];
    char langcode_two_stringpool_str260[sizeof("af")];
    char langcode_two_stringpool_str263[sizeof("el")];
    char langcode_two_stringpool_str264[sizeof("ky")];
    char langcode_two_stringpool_str265[sizeof("ii")];
    char langcode_two_stringpool_str268[sizeof("fi")];
    char langcode_two_stringpool_str269[sizeof("an")];
    char langcode_two_stringpool_str270[sizeof("ar")];
    char langcode_two_stringpool_str274[sizeof("ho")];
    char langcode_two_stringpool_str278[sizeof("cu")];
    char langcode_two_stringpool_str279[sizeof("kv")];
    char langcode_two_stringpool_str284[sizeof("iu")];
    char langcode_two_stringpool_str289[sizeof("pt")];
    char langcode_two_stringpool_str290[sizeof("bs")];
    char langcode_two_stringpool_str299[sizeof("hz")];
    char langcode_two_stringpool_str300[sizeof("ks")];
    char langcode_two_stringpool_str303[sizeof("eu")];
    char langcode_two_stringpool_str304[sizeof("xh")];
    char langcode_two_stringpool_str309[sizeof("hi")];
    char langcode_two_stringpool_str310[sizeof("am")];
    char langcode_two_stringpool_str314[sizeof("it")];
    char langcode_two_stringpool_str315[sizeof("az")];
    char langcode_two_stringpool_str328[sizeof("hu")];
    char langcode_two_stringpool_str330[sizeof("kj")];
    char langcode_two_stringpool_str333[sizeof("et")];
    char langcode_two_stringpool_str335[sizeof("ik")];
    char langcode_two_stringpool_str348[sizeof("cy")];
    char langcode_two_stringpool_str357[sizeof("fy")];
    char langcode_two_stringpool_str358[sizeof("ht")];
    char langcode_two_stringpool_str363[sizeof("cv")];
    char langcode_two_stringpool_str365[sizeof("ps")];
    char langcode_two_stringpool_str384[sizeof("cs")];
    char langcode_two_stringpool_str389[sizeof("jv")];
    char langcode_two_stringpool_str390[sizeof("is")];
    char langcode_two_stringpool_str395[sizeof("ak")];
    char langcode_two_stringpool_str398[sizeof("hy")];
    char langcode_two_stringpool_str409[sizeof("es")];
    char langcode_two_stringpool_str414[sizeof("ay")];
    char langcode_two_stringpool_str415[sizeof("ab")];
    char langcode_two_stringpool_str423[sizeof("fj")];
    char langcode_two_stringpool_str429[sizeof("av")];
    char langcode_two_stringpool_str450[sizeof("as")];
  };
static const struct langcode_two_stringpool_t langcode_two_stringpool_contents =
  {
    "se",
    "sd",
    "ne",
    "sa",
    "nd",
    "na",
    "te",
    "gd",
    "ga",
    "sq",
    "ta",
    "sw",
    "sn",
    "sr",
    "rw",
    "rn",
    "nn",
    "nr",
    "or",
    "gn",
    "tw",
    "tn",
    "tr",
    "mn",
    "mr",
    "sg",
    "ng",
    "so",
    "ro",
    "no",
    "tg",
    "de",
    "mg",
    "to",
    "da",
    "sl",
    "ur",
    "nl",
    "za",
    "sm",
    "gl",
    "rm",
    "tl",
    "om",
    "ml",
    "la",
    "ug",
    "sc",
    "ve",
    "si",
    "oc",
    "wa",
    "ln",
    "th",
    "ti",
    "mh",
    "mi",
    "be",
    "su",
    "ba",
    "ru",
    "lg",
    "uz",
    "gu",
    "lo",
    "ka",
    "bn",
    "br",
    "dz",
    "vo",
    "wo",
    "kw",
    "kn",
    "kr",
    "st",
    "bg",
    "zh",
    "bo",
    "tt",
    "kg",
    "mt",
    "li",
    "ko",
    "sk",
    "zu",
    "vi",
    "bm",
    "kl",
    "tk",
    "lu",
    "mk",
    "km",
    "bh",
    "bi",
    "qu",
    "ny",
    "nb",
    "pa",
    "ty",
    "ki",
    "my",
    "sv",
    "uk",
    "nv",
    "ce",
    "yo",
    "gv",
    "lt",
    "ca",
    "ie",
    "id",
    "ku",
    "ia",
    "fa",
    "ss",
    "ff",
    "cr",
    "os",
    "ee",
    "ts",
    "fr",
    "ms",
    "ja",
    "pl",
    "yi",
    "co",
    "ig",
    "dv",
    "en",
    "lb",
    "io",
    "fo",
    "he",
    "oj",
    "ha",
    "pi",
    "lv",
    "kk",
    "eo",
    "ae",
    "hr",
    "aa",
    "ch",
    "af",
    "el",
    "ky",
    "ii",
    "fi",
    "an",
    "ar",
    "ho",
    "cu",
    "kv",
    "iu",
    "pt",
    "bs",
    "hz",
    "ks",
    "eu",
    "xh",
    "hi",
    "am",
    "it",
    "az",
    "hu",
    "kj",
    "et",
    "ik",
    "cy",
    "fy",
    "ht",
    "cv",
    "ps",
    "cs",
    "jv",
    "is",
    "ak",
    "hy",
    "es",
    "ay",
    "ab",
    "fj",
    "av",
    "as"
  };
#define langcode_two_stringpool ((const char *) &langcode_two_stringpool_contents)
const struct langcode *
LangCodeGperf::langcode_from_two (register const char *str, register unsigned int len)
{
  static const struct langcode wordlist[] =
    {
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str0,"sme"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str3,"snd"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str4,"nep"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str5,"san"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str7,"nde"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str9,"nau"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str10,"tel"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str11,"gla"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str13,"gle"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str14,"alb"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str15,"tam"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str18,"swa"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str19,"sna"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str20,"srp"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str21,"kin"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str22,"run"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str23,"nno"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str24,"nbl"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str25,"ori"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str27,"grn"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str28,"twi"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str29,"tsn"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str30,"tur"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str33,"mon"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str34,"mar"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str35,"sag"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str39,"ndo"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str40,"som"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str43,"rum"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str44,"nor"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str45,"tgk"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str48,"ger"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str49,"mlg"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str50,"ton"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str53,"dan"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str54,"slv"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str55,"urd"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str58,"dut"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str59,"zha"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str60,"smo"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str62,"glg"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str63,"roh"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str64,"tgl"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str65,"orm"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str68,"mal"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str69,"lat"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str70,"uig"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str73,"srd"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str74,"ven"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str75,"sin"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str78,"oci"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str80,"wln"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str83,"lin"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str84,"tha"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str85,"tir"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str88,"mah"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str89,"mao"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str90,"bel"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str94,"sun"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str95,"bak"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str97,"rus"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str99,"lug"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str100,"uzb"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str102,"guj"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str104,"lao"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str105,"geo"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str109,"ben"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str110,"bre"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str113,"dzo"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str114,"vol"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str115,"wol"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str118,"cor"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str119,"kan"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str120,"kau"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str124,"sot"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str125,"bul"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str128,"chi"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str130,"tib"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str134,"tat"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str135,"kon"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str138,"mlt"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str139,"lim"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str140,"kor"},
      {-1}, {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str145,"slo"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str148,"zul"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str149,"vie"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str150,"bam"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str154,"kal"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str155,"tuk"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str158,"lub"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str159,"mac"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str160,"khm"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str164,"bih"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str165,"bis"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str167,"que"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str168,"nya"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str169,"nob"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str170,"pan"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str174,"tah"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str175,"kik"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str178,"bur"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str179,"swe"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str180,"ukr"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str183,"nav"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str184,"che"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str185,"yor"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str187,"glv"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str188,"lit"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str189,"cat"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str190,"ile"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str193,"ind"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str194,"kur"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str195,"ina"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str198,"per"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str200,"ssw"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str203,"ful"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str204,"cre"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str205,"oss"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str209,"ewe"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str210,"tso"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str213,"fre"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str214,"may"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str215,"jpn"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str219,"pol"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str220,"yid"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str224,"cos"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str225,"ibo"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str227,"div"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str228,"eng"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str229,"ltz"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str230,"ido"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str233,"fao"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str234,"heb"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str235,"oji"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str239,"hau"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str240,"pli"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str243,"lav"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str245,"kaz"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str249,"epo"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str250,"ave"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str254,"hrv"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str255,"aar"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str258,"cha"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str260,"afr"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str263,"gre"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str264,"kir"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str265,"iii"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str268,"fin"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str269,"arg"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str270,"ara"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str274,"hmo"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str278,"chu"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str279,"kom"},
      {-1}, {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str284,"iku"},
      {-1}, {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str289,"por"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str290,"bos"},
      {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str299,"her"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str300,"kas"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str303,"baq"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str304,"xho"},
      {-1}, {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str309,"hin"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str310,"amh"},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str314,"ita"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str315,"aze"},
      {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str328,"hun"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str330,"kua"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str333,"est"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str335,"ipk"},
      {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
      {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str348,"wel"},
      {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str357,"fry"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str358,"hat"},
      {-1}, {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str363,"chv"},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str365,"pus"},
      {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
      {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str384,"cze"},
      {-1}, {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str389,"jav"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str390,"ice"},
      {-1}, {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str395,"aka"},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str398,"arm"},
      {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
      {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str409,"spa"},
      {-1}, {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str414,"aym"},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str415,"abk"},
      {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str423,"fij"},
      {-1}, {-1}, {-1}, {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str429,"ava"},
      {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
      {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1},
      {-1}, {-1},
      {(int)(long)&((struct langcode_two_stringpool_t *)0)->langcode_two_stringpool_str450,"asm"}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = langcode_23_hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int o = wordlist[key].stringpool_offset;
          if (o >= 0)
            {
              register const char *s = o + langcode_two_stringpool;

              if ((((unsigned char)*str ^ (unsigned char)*s) & ~32) == 0 && !gperf_case_strcmp (str, s))
                return &wordlist[key];
            }
        }
    }
  return 0;
}

#ifndef _WIN32
#pragma GCC diagnostic pop
#endif

const char *langcode_three_old(const char *langcode_two) {
    const struct langcode *lang = LangCodeGperf::langcode_from_two(langcode_two, static_cast<unsigned int>(strlen(langcode_two)));
    if (lang)
        return lang->threecode;

    return langcode_two;
}

std::string langcode_three_old(const std::string& langcode_two) {
    const struct langcode *lang = LangCodeGperf::langcode_from_two(langcode_two.c_str(), static_cast<unsigned int>(langcode_two.size()));
    if (lang)
        return std::string(lang->threecode);

    return langcode_two;
}

} // namespace qmx
