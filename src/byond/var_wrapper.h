#include <string>
#include <optional>
#include "byond_types.h"
namespace BYOND {

static ByondTypes types;

class VarWrapper {

public:
    
    static std::string rawValue(std::string var) {
        return var.empty() ? types.null : var;
    }

    static std::optional<std::string> optionalText(std::string var) {
        if (isEmptyVar(var)) {
            return std::nullopt;
        }
        if (var.rfind("\"", 0) == 0 && var.rfind("\"", var.length()) == 0) {
            return std::optional<std::string>{var.substr(1, var.length() - 1)};
        }
        return std::optional<std::string>(var);
    }

    static std::optional<std::string> optionalFilePath(std::string var) {
        if (isEmptyVar(var)) {
            return std::nullopt;
        }
        if (var.rfind("'", 0) == 0 && var.rfind("'", var.length()) == 0) {
            return std::optional<std::string>{var.substr(1, var.length() - 1)};
        }
        return std::optional<std::string>(var);
    }

    static std::optional<int> optionalInt(std::string var) {
        return isEmptyVar(var) ? std::nullopt : std::optional<int>(std::stoi(var));

    }

    static std::optional<double> optionalDouble(std::string var) {

        return isEmptyVar(var) ? std::nullopt : std::optional<double>(std::stod(var));

    }

    static std::optional<bool> optionalBoolean(std::string var) {
        if (var.empty()) {
            return std::nullopt;
        }
        if (strcmp(types.null.c_str(),var.c_str()) == 0 || var.empty() || strcmp("\"\"",var.c_str()) == 0 || strcmp("0",var.c_str()) == 0) {
            return std::optional<bool>(false);
        }
        return std::optional<bool>(true);
    }

    static bool isEmptyVar(std::string var) {
        return var.empty() || strcmp(var.c_str(),types.null.c_str()) == 0;
    }

    VarWrapper();
};
};