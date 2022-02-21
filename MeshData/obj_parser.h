#ifndef OBJPARSER_H
#define OBJPARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <QObject>


/**
 * @brief The ObjParser class
 *
 * Self contained obj to mesh converter, directly copied from swcpmc (hence the duplicated classes in here for triangles etc...)
 */

class ObjParser:public QObject
{
    Q_OBJECT
public:
    ObjParser();
    Q_INVOKABLE static void parseObj(std::string pathToMesh, std::string pathToOutput);

};

#endif // OBJPARSER_H
