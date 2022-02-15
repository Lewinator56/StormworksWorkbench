QT += quick

SOURCES += \
        MeshData/Common/vector3.cpp \
        MeshData/Common/vertex_color.cpp \
        MeshData/mesh.cpp \
        MeshData/mesh_parser.cpp \
        MeshData/sub_mesh.cpp \
        MeshData/triangle.cpp \
        MeshData/vertex.cpp \
        main.cpp

resources.files = main.qml 
resources.prefix = /$${TARGET}
RESOURCES += resources \
    qml.qrc



# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CustomComponents/CustomTabButton.qml \
    Modules/MOutput.qml \
    Modules/MeshEditor.qml \
    Modules/Workspace.qml \
    qtquickcontrols2.conf

HEADERS += \
    MeshData/Common/vector3.h \
    MeshData/Common/vertex_color.h \
    MeshData/mesh.h \
    MeshData/mesh_parser.h \
    MeshData/sub_mesh.h \
    MeshData/triangle.h \
    MeshData/vertex.h
