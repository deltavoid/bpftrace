#pragma once

#include <sstream>

#include "ast.h"
#include "printf_format_types.h"
#include "types.h"

namespace bpftrace {

static const std::string generate_pattern_string()
{
  std::string pattern = "%-?[0-9]*(\\.[0-9]+)?(";
  for (const auto& e : printf_format_types)
  {
    pattern += e.first + "|";
  }
  pattern.pop_back(); // for the last "|"
  pattern += ")";
  return pattern;
}

const std::regex format_specifier_re(generate_pattern_string());

struct Field;

std::string verify_format_string(const std::string& fmt,
                                 std::vector<Field> args);

class IPrintable
{
public:
  virtual ~IPrintable() { };
  virtual uint64_t value() = 0;
};

class PrintableString : public virtual IPrintable
{
public:
  PrintableString(std::string value) : value_(std::move(value)) { }
  uint64_t value();

private:
  std::string value_;
};

class PrintableCString : public virtual IPrintable
{
public:
  PrintableCString(char* value) : value_(value) { }
  uint64_t value();

private:
  char* value_;
};

class PrintableInt : public virtual IPrintable
{
public:
  PrintableInt(uint64_t value) : value_(value) { }
  uint64_t value();

private:
  uint64_t value_;
};

} // namespace bpftrace
