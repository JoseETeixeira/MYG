#include <string>
#include <optional>
#include <map>
#include <set>
#include <list>
#include "../var_wrapper.h"
#include "../byond_types.h"

namespace BYOND {
class Dme {

private:
    std::string absoluteRootPath;

    std::map<std::string, std::string> macroses = {};
    std::map<std::string, DmeItem *> items = {};

    std::list<std::string> includedFiles = std::list<std::string>();
    std::list<std::string> mapFiles = std::list<std::string>();

public:
    public void mergeWithJson(final File jsonFile) {
        try {
            mergeWithJson(new String(Files.readAllBytes(jsonFile.toPath()), Charset.defaultCharset()));
        } catch (IOException e) {
            throw new UncheckedIOException(e);
        }
    }

    public void mergeWithJson(final String json) {
        DmeJsonMerger.merge(json, this);
    }

    public void mergeWithJson(final InputStream is) {
        val bis = new BufferedInputStream(is);
        try (val buf = new ByteArrayOutputStream()) {
            int result;
            while ((result = bis.read()) != -1) {
                byte b = (byte) result;
                buf.write(b);
            }
            mergeWithJson(buf.toString());
        } catch (IOException e) {
            throw new UncheckedIOException(e);
        }
    }

    ///////////////// Macros

    public void addMacros(final String name, final String value) {
        macroses.put(name, value);
    }

    public void addMacros(final String name, final Number value) {
        macroses.put(name, String.valueOf(value));
    }

    public void addMacrosText(final String name, final String value) {
        macroses.put(name, '"' + value + '"');
    }

    public void addMacrosFilePath(final String name, final String value) {
        macroses.put(name, "'" + value + "'");
    }

    public String getMacros(final String name) {
        return VarWrapper.rawValue(macroses.get(name));
    }

    public String getMacrosText(final String name) {
        return VarWrapper.optionalText(macroses.get(name)).get();
    }

    public Optional<String> getMacrosTextSafe(final String name) {
        return VarWrapper.optionalText(macroses.get(name));
    }

    public String getMacrosFilePath(final String name) {
        return VarWrapper.optionalFilePath(macroses.get(name)).get();
    }

    public Optional<String> getMacrosFilePathSafe(final String name) {
        return VarWrapper.optionalFilePath(macroses.get(name));
    }

    public Integer getMacrosInt(final String name) {
        return VarWrapper.optionalInt(macroses.get(name)).get();
    }

    public Optional<Integer> getMacrosIntSafe(final String name) {
        return VarWrapper.optionalInt(macroses.get(name));
    }

    public Double getMacrosDouble(final String name) {
        return VarWrapper.optionalDouble(macroses.get(name)).get();
    }

    public Optional<Double> getMacrosDoubleSafe(final String name) {
        return VarWrapper.optionalDouble(macroses.get(name));
    }

    public Boolean getMacrosBool(final String name) {
        return getMacrosBoolSafe(name).get();
    }

    public Optional<Boolean> getMacrosBoolSafe(final String name) {
        return VarWrapper.optionalBoolean(macroses.get(name));
    }

    ///////////////// Included / Map files

    public void addIncludedFile(final String filePath) {
        includedFiles.add(filePath);
    }

    public void addMapFile(final String filePath) {
        mapFiles.add(filePath);
    }

    ///////////////// Item

    public void addItem(final DmeItem item) {
        items.put(item.getType(), item);
    }

    public DmeItem getItemOrCreate(final String type) {
        return items.computeIfAbsent(type, k -> new DmeItem(type, this));
    }

    DmeItem* getItem(std::string type) {
        return items.at(type);
    }


    ///////////////// Global vars

    public Map<String, String> getGlobalVars() {
        return items.get(ByondTypes.GLOBAL).getVars();
    }

    public String getGlobalVar(final String name) {
        return VarWrapper.rawValue(getGlobalVars().get(name));
    }

    public String getGlobalVarText(final String name) {
        return VarWrapper.optionalText(getGlobalVars().get(name)).get();
    }

    public Optional<String> getGlobalVarTextSafe(final String name) {
        return VarWrapper.optionalText(getGlobalVars().get(name));
    }

    public String getGlobalFilePath(final String name) {
        return VarWrapper.optionalFilePath(getGlobalVars().get(name)).get();
    }

    public Optional<String> getGlobalFilePathSafe(final String name) {
        return VarWrapper.optionalFilePath(getGlobalVars().get(name));
    }

    public Integer getGlobalVarInt(final String name) {
        return VarWrapper.optionalInt(getGlobalVars().get(name)).get();
    }

    public Optional<Integer> getGlobalVarIntSafe(final String name) {
        return VarWrapper.optionalInt(getGlobalVars().get(name));
    }

    public Double getGlobalVarDouble(final String name) {
        return VarWrapper.optionalDouble(getGlobalVars().get(name)).get();
    }

    public Optional<Double> getGlobalVarDoubleSafe(final String name) {
        return VarWrapper.optionalDouble(getGlobalVars().get(name));
    }

    public Boolean getGlobalVarBool(final String name) {
        return getGlobalVarBoolSafe(name).get();
    }

    public Optional<Boolean> getGlobalVarBoolSafe(final String name) {
        return VarWrapper.optionalBoolean(getGlobalVars().get(name));
    }
};


class DmeItem {

private:
    Dme environment;

    std::string type;
    std::string parentPath = "";

    std::map<std::string, std::string> vars = {};
    std::set<std::string> directSubtypes = {};
    std::set<std::string> allSubtypes = {};

    bool varsLookedUp = false;

public:
    DmeItem(std::string type, Dme environment):
        type(type),
        environment(environment)
    {
    }

    ///////////////// Types / Subtypes

    void addToAllSubtype(DmeItem *item) {
        allSubtypes.insert(item->type);
    }

    void addToAllSubtype(std::string subtypePath) {
        allSubtypes.insert(subtypePath);
    }

    void addDirectSubtype(DmeItem *item) {
        directSubtypes.insert(item->type);
    }

    void addDirectSubtype(std::string subtypePath) {
        directSubtypes.insert(subtypePath);
    }

    bool isType(std::string typeToCompare) {
        bool isEqualTypes = type.compare(typeToCompare) == 0;
        if (!isEqualTypes) {
            DmeItem *itemToCompare = environment.getItem(typeToCompare);
            isEqualTypes = (itemToCompare != nullptr && itemToCompare->allSubtypes.count(type) == 1);
        }
        return isEqualTypes;
    }

    bool isType(DmeItem *item) {
        return isType(item->type);
    }

    ///////////////// Variables

    void setVar(std::string name, std::string value) {
        vars.insert(name, value);
    }

    void setVarText(std::string name, std::string value) {
        vars.insert(name, '"' + value + '"');
    }

    void setVarFilePath(std::string name, std::string value) {
        vars.insert(name, "'" + value + "'");
    }

    void setVar(std::string name, double value) {//TODO: CHANGE TO GENERIC NUMBER TYPE
        vars.insert(name,std::to_string(value));
    }

    void setEmptyVar(std::string name) {
        vars.insert(name, types.null);
    }

    std::map<std::string, std::string> getAllVars() {
        if (!varsLookedUp && !parentPath.empty()) {
            std::map<std::string, std::string> varsMap = {};
            lookUpVars(varsMap, environment.getItem(parentPath));
            for(auto var: varsMap){
                if(vars.find(var.first) != vars.end()){
                    vars.insert(var);
                }
            }
            varsLookedUp = true;
        }
        return vars;
    }

    std::string getVar(std::string name) {
        return VarWrapper::rawValue(lookupVar(name));
    }

    std::string getVarText(std::string name) {
        return getVarTextSafe(name).value();
    }

    std::optional<std::string> getVarTextSafe(std::string name) {
        return VarWrapper::optionalText(lookupVar(name));
    }

    std::string getVarFilePath(std::string name) {
        return getVarFilePathSafe(name).value();
    }

    std::optional<std::string> getVarFilePathSafe(std::string name) {
        return VarWrapper::optionalFilePath(lookupVar(name));
    }

    int getVarInt(std::string name) {
        return getVarIntSafe(name).value();
    }

    std::optional<int> getVarIntSafe(std::string name) {
        return VarWrapper::optionalInt(lookupVar(name));
    }

    double getVarDouble(std::string name) {
        return getVarDoubleSafe(name).value();
    }

    std::optional<double> getVarDoubleSafe(std::string name) {
        return VarWrapper::optionalDouble(lookupVar(name));
    }

    bool getVarBool(std::string name) {
        return getVarBoolSafe(name).value();
    }

    std::optional<bool> getVarBoolSafe(std::string name) {
        return VarWrapper::optionalBoolean(lookupVar(name));
    }

private:
    std::string lookupVar(std::string name) {
        if (vars.count(name) == 1 || parentPath.empty()) {
            return vars.at(name);
        }
        std::string parentVarVal = environment.getItem(parentPath)->lookupVar(name);
        vars.insert(name, parentVarVal);
        return parentVarVal;
    }

    void lookUpVars(std::map<std::string, std::string> &varsMap, DmeItem *parent) {
        if (parent != nullptr) {
            for(auto var: parent->vars){
                if(varsMap.find(var.first) != varsMap.end()){
                    varsMap.insert(var);
                }
            }
            if (!parent->varsLookedUp && !parent->parentPath.empty()) {
                lookUpVars(varsMap, environment.getItem(parent->parentPath));
            }
        }
    }
};
};