/**
 * OpenAPI Petstore
 * This spec is mainly for testing Petstore server and contains fake endpoints, models. Please do not use this for any other purpose. Special characters: \" \\
 *
 * The version of the OpenAPI document: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 7.5.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */



#include "ArrayOfNumberOnly.h"

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stdexcept>
#include <regex>
#include <boost/lexical_cast.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "helpers.h"

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

namespace org {
namespace openapitools {
namespace server {
namespace model {

ArrayOfNumberOnly::ArrayOfNumberOnly(boost::property_tree::ptree const& pt)
{
        fromPropertyTree(pt);
}


std::string ArrayOfNumberOnly::toJsonString(bool prettyJson /* = false */) const
{
	std::stringstream ss;
	write_json(ss, this->toPropertyTree(), prettyJson);
    // workaround inspired by: https://stackoverflow.com/a/56395440
    std::regex reg("\\\"([0-9]+\\.{0,1}[0-9]*)\\\"");
    std::string result = std::regex_replace(ss.str(), reg, "$1");
    return result;
}

void ArrayOfNumberOnly::fromJsonString(std::string const& jsonString)
{
	std::stringstream ss(jsonString);
	ptree pt;
	read_json(ss,pt);
	this->fromPropertyTree(pt);
}

ptree ArrayOfNumberOnly::toPropertyTree() const
{
	ptree pt;
	ptree tmp_node;
	// generate tree for ArrayNumber
    tmp_node.clear();
	if (!m_ArrayNumber.empty()) {
        tmp_node = toPt(m_ArrayNumber);
		pt.add_child("ArrayNumber", tmp_node);
		tmp_node.clear();
	}
	return pt;
}

void ArrayOfNumberOnly::fromPropertyTree(ptree const &pt)
{
	ptree tmp_node;
	// push all items of ArrayNumber into member
	if (pt.get_child_optional("ArrayNumber")) {
        m_ArrayNumber = fromPt<std::vector<double>>(pt.get_child("ArrayNumber"));
	}
}

std::vector<double> ArrayOfNumberOnly::getArrayNumber() const
{
    return m_ArrayNumber;
}

void ArrayOfNumberOnly::setArrayNumber(std::vector<double> value)
{
    m_ArrayNumber = value;
}



std::vector<ArrayOfNumberOnly> createArrayOfNumberOnlyVectorFromJsonString(const std::string& json)
{
    std::stringstream sstream(json);
    boost::property_tree::ptree pt;
    boost::property_tree::json_parser::read_json(sstream,pt);

    auto vec = std::vector<ArrayOfNumberOnly>();
    for (const auto& child: pt) {
        vec.emplace_back(ArrayOfNumberOnly(child.second));
    }

    return vec;
}

}
}
}
}

