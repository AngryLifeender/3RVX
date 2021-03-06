#include "SkinInfo.h"

#include "Error.h"
#include "Logger.h"
#include "Settings.h"
#include "StringUtils.h"

SkinInfo::SkinInfo(std::wstring skinFile) :
_skinFile(skinFile) {
    CLOG(L"Loading skin XML: %s", _skinFile.c_str());

    /* Remove the '/skin.xml' portion from the file name to get the dir name. */
    std::wstring xmlName = std::wstring(SKIN_XML);
    _skinDir = _skinFile.substr(0, _skinFile.length() - (xmlName.length() + 1));

    std::string u8FileName = StringUtils::Narrow(_skinFile);
    tinyxml2::XMLError result = _xml.LoadFile(u8FileName.c_str());
    if (result != tinyxml2::XMLError::XML_SUCCESS) {
        if (result == tinyxml2::XMLError::XML_ERROR_FILE_NOT_FOUND) {
            Error::ErrorMessageDie(SKINERR_INVALID_SKIN);
        }
        throw std::logic_error("Failed to read XML file!");
    }

    _root = _xml.GetDocument()->FirstChildElement("skin");
    if (_root == NULL) {
        throw std::runtime_error("Could not find root XML element");
    }
}

std::wstring SkinInfo::Author() {
    tinyxml2::XMLHandle xmlHandle(_root);
    tinyxml2::XMLElement *author = xmlHandle
        .FirstChildElement("info")
        .FirstChildElement("author")
        .ToElement();

    const char *authorText;
    if (author == NULL || (authorText = author->GetText()) == NULL) {
        return L"";
    }

    return std::wstring(StringUtils::Widen(authorText));
}

std::wstring SkinInfo::URL() {
    tinyxml2::XMLHandle xmlHandle(_root);
    tinyxml2::XMLElement *site = xmlHandle
        .FirstChildElement("info")
        .FirstChildElement("website")
        .ToElement();

    const char *text;
    if (site == NULL || (text = site->GetText()) == NULL) {
        return L"";
    }
    return std::wstring(StringUtils::Widen(text));
}