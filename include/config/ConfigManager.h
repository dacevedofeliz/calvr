/**
 * @file ConfigManager.h
 */

#ifndef CALVR_CONFIG_MANAGER_H
#define CALVR_CONFIG_MANAGER_H

#include <config/Export.h>

#include <osg/Vec3>
#include <osg/Vec4>
#include <osg/Vec3d>
#include <osg/Vec4d>

#include <string>
#include <map>
#include <vector>

struct mxml_node_s;
typedef struct mxml_node_s mxml_node_t;

/*class ConfigNode
 {
 public:
 ConfigNode(std::string n);
 ~ConfigNode();

 void merge(ConfigNode * node, bool givePriority);

 mxml_node_t * node;
 std::vector<ConfigNode *> children;
 std::string name;
 bool skip;
 };*/

/*#ifdef WIN32
 #ifndef CVRCONFIG_LIBRARY_STATIC
 EXPIMP_TEMPLATE template class CVRCONFIG_EXPORT std::allocator<mxml_node_s *>;
 //EXPIMP_TEMPLATE template class CVRCONFIG_EXPORT std::_Vector_val<mxml_node_s *,std::allocator<mxml_node_s *> >;
 EXPIMP_TEMPLATE template class CVRCONFIG_EXPORT std::vector<mxml_node_s *,std::allocator<mxml_node_s *> >;
 EXPIMP_TEMPLATE template class CVRCONFIG_EXPORT std::vector<mxml_node_t *>;
 EXPIMP_TEMPLATE template class CVRCONFIG_EXPORT std::allocator<char>;
 //EXPIMP_TEMPLATE template class CVRCONFIG_EXPORT std::_String_val<char,std::allocator<char> >;
 EXPIMP_TEMPLATE template class CVRCONFIG_EXPORT std::basic_string<char,std::char_traits<char>,std::allocator<char> >;
 //EXPIMP_TEMPLATE template class CVRCONFIG_EXPORT std::string;
 #endif
 #endif*/

namespace cvr
{

class CalVR;

/**
 * @brief Used to read values from the xml config file
 */
class CVRCONFIG_EXPORT ConfigManager
{
        friend class CalVR;
    public:
        ConfigManager();

        /**
         * @brief Load a given config file
         * @param file File to load
         * @param givePriority Should this file have priority over those already loaded (not currently used)
         */
        bool loadFile(std::string file, bool givePriority = false);

        /**
         * @brief Loads the xml file specified by the CalVR environment variables
         */
        bool init();

        /**
         * @brief Looks for a text config file value in tag path, with the default attribute
         *        "value"
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static std::string getEntry(std::string path, std::string def = "",
                bool * found = NULL);

        /**
         * @brief Looks for a text config file value in tag path with the specified attribute
         * @param attribute Attribute value within the tag to return
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static std::string getEntry(std::string attribute, std::string path,
                std::string def = "", bool * found = NULL);

        /**
         * @brief Looks for a float config file value in tag path with the default attribute
         *        "value"
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static float getFloat(std::string path, float def = 0.0, bool * found =
                NULL);

        /**
         * @brief Looks for a float config file value in tag path with the specified attribute
         * @param attribute Attribute value within the tag to return
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static float getFloat(std::string attribute, std::string path,
                float def = 0.0, bool * found = NULL);

        /**
         * @brief Looks for a double config file value in tag path with the default attribute
         *        "value"
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static double getDouble(std::string path, double def = 0.0,
                bool * found = NULL);

        /**
         * @brief Looks for a double config file value in tag path with the specified attribute
         * @param attribute Attribute value within the tag to return
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static double getDouble(std::string attribute, std::string path,
                double def = 0.0, bool * found = NULL);

        /**
         * @brief Looks for a integer config file value in tag path with the default attribute
         *        "value"
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static int getInt(std::string path, int def = 0, bool * found = NULL);

        /**
         * @brief Looks for a integer config file value in tag path with the specified attribute
         * @param attribute Attribute value within the tag to return
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static int getInt(std::string attribute, std::string path, int def = 0,
                bool * found = NULL);

        /**
         * @brief Looks for a boolean config file value in tag path with the default attribute
         *        "value"
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static bool getBool(std::string path, bool def = false, bool * found =
                NULL);

        /**
         * @brief Looks for a boolean config file value in tag path with the specified attribute
         * @param attribute Attribute value within the tag to return
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static bool getBool(std::string attribute, std::string path, bool def =
                false, bool * found = NULL);

        /**
         * @brief Looks for a vector of floats in the tag path with default attributes "x","y","z"
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static osg::Vec3 getVec3(std::string path,
                osg::Vec3 def = osg::Vec3(0,0,0), bool * found = NULL);

        /**
         * @brief Looks for a vector of floats in the tag path with the specifed attributes for
         *              each component
         * @param attributeX attribute to read for x value
         * @param attributeY attribute to read for y value
         * @param attributeZ attribute to read for z value
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static osg::Vec3 getVec3(std::string attributeX, std::string attributeY,
                std::string attributeZ, std::string path, osg::Vec3 def =
                        osg::Vec3(0,0,0), bool * found = NULL);

        /**
         * @brief Looks for a vector of floats in the tag path with default attributes "x","y","z","w"
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static osg::Vec4 getVec4(std::string path,
                osg::Vec4 def = osg::Vec4(0,0,0,1), bool * found = NULL);

        /**
         * @brief Looks for a vector of floats in the tag path with the specifed attributes for
         *              each component
         * @param attributeX attribute to read for x value
         * @param attributeY attribute to read for y value
         * @param attributeZ attribute to read for z value
         * @param attributeW attribute to read for w value
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static osg::Vec4 getVec4(std::string attributeX, std::string attributeY,
                std::string attributeZ, std::string attributeW,
                std::string path, osg::Vec4 def = osg::Vec4(0,0,0,1),
                bool * found = NULL);

        /**
         * @brief Looks for a vector of doubles in the tag path with default attributes "x","y","z"
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static osg::Vec3d getVec3d(std::string path, osg::Vec3d def =
                osg::Vec3d(0,0,0), bool * found = NULL);

        /**
         * @brief Looks for a vector of doubles in the tag path with the specifed attributes for
         *              each component
         * @param attributeX attribute to read for x value
         * @param attributeY attribute to read for y value
         * @param attributeZ attribute to read for z value
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static osg::Vec3d getVec3d(std::string attributeX,
                std::string attributeY, std::string attributeZ,
                std::string path, osg::Vec3d def = osg::Vec3d(0,0,0),
                bool * found = NULL);

        /**
         * @brief Looks for a vector of doubles in the tag path with default attributes "x","y","z","w"
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static osg::Vec4d getVec4d(std::string path, osg::Vec4d def =
                osg::Vec4d(0,0,0,1), bool * found = NULL);

        /**
         * @brief Looks for a vector of floats in the tag path with the specifed attributes for
         *              each component
         * @param attributeX attribute to read for x value
         * @param attributeY attribute to read for y value
         * @param attributeZ attribute to read for z value
         * @param attributeW attribute to read for w value
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static osg::Vec4d getVec4d(std::string attributeX,
                std::string attributeY, std::string attributeZ,
                std::string attributeW, std::string path, osg::Vec4d def =
                        osg::Vec4d(0,0,0,1), bool * found = NULL);

        /**
         * @brief Looks for a color vector in the tag path with default attributes "r","g","b","a"
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param def The default value to return if the tag is not found
         * @param found If valid, *found is set to true if the tag existed and false
         *              if the default value was returned
         */
        static osg::Vec4 getColor(std::string path,
                osg::Vec4 def = osg::Vec4(1,1,1,1), bool * found = NULL);

        /**
         * @brief Creates a list of all the children of a tag
         * @param path Tag to search for in the Tag1.Tag2.Tag3.Tag4 format, where Tag3
         *             is the parent of Tag4 and Tag2 is the parent of Tag3 etc.
         * @param destList vector that is filled with the list of names
         *
         * Searches through all loaded xml files for the given tag.  If the tag exists
         * in more then one place, the result is a concatination of all children.
         */
        static void getChildren(std::string path,
                std::vector<std::string> & destList);

    protected:
        virtual ~ConfigManager();

        static std::vector<mxml_node_t *> _configRootList; ///< List of the roots of all loaded xml files
        std::string _configDir; ///< CalVR config file directory

        static bool _debugOutput; ///< should config debug statements be printed
};

}

#endif
