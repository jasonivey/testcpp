#pragma once

#include <string>

namespace qmx {

/**
 * Given a two-character language code, return the equivalent
 * three-character language code.
 * ie. ISO-639-1 to ISO-639-2 language code conversion.
 * The returned pointer will either return to a static string with the
 * three-character language code, or it will return the langcode_two
 * pointer that was input, if there was no match.
 */
const char *langcode_three_old(const char *langcode_two);
const char *langcode_three_new(const char *langcode_two);

/**
 * String version of langcode_three().
 */
std::string langcode_three_old(const std::string& langcode_two);
std::string langcode_three_new(const std::string& langcode_two);

} // namespace
