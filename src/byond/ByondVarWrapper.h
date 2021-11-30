#pragma once
#include <string>
#include <optional>
#include "ByondTypes.h"
#include "utils/string_helper.h"
#include "utils/exception_helper.h"
#include <string.h>

namespace BYOND{
    
    class ByondVarWrapper {

        public:
        
            static std::string rawValue(std::string var) {
                return var.empty() ? ByondTypes::NULLS : var;
            }

            static std::optional<std::string> optionalText(std::string var) {
                if (isEmptyVar(var)) {
                    return std::nullopt;
                }
                if (StringHelper::startsWith(var,"\"") && StringHelper::endsWith(var,"\"")) {
                    return std::optional<std::string>{var.substr(1, var.length() - 1)};
                }
                return std::optional<std::string>{var};
            }

            static std::optional<std::string> optionalFilePath(std::string var) {
                if (isEmptyVar(var)) {
                    return std::nullopt;
                }
                if (StringHelper::startsWith(var,"'") && StringHelper::endsWith(var,"'")) {
                   return std::optional<std::string>{var.substr(1, var.length() - 1)};
                }
                return std::optional<std::string>{var};
            }

            static std::optional<int> optionalInt(std::string var) {
                try {
                    return isEmptyVar(var) ? std::nullopt : std::optional<int>{stoi(var)};
                } catch (NumberFormatException e) {
                    return std::nullopt;
                }
            }

            static std::optional<double> optionalDouble(std::string var) {
                try {
                    return isEmptyVar(var) ? std::nullopt : std::optional<double>{stod(var)};
                } catch (NumberFormatException e) {
                    return std::nullopt;
                }
            }

            static std::optional<bool> optionalBoolean(std::string var) {
                if (var.empty()) {
                    return std::nullopt;
                }
                if (ByondTypes::NULLS.compare(var) == 0 || var.empty() || strcmp("\"\"",var.c_str()) == 0 || strcmp("0",var.c_str()) == 0) {
                    return std::optional<bool>{false};
                }
                return std::optional<bool>{true};
            }

            static bool isEmptyVar(std::string &var) {
                return var.empty() || ByondTypes::NULLS.compare(var) == 0;
            }

            ByondVarWrapper() {}
    };
}

