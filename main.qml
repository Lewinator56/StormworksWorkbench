import QtQuick
import QtQuick.Controls.Material
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Fusion as Fus
import "qrc:/../Modules" as Modules
import "qrc:/../CustomComponents" as Custom
import QtQuick.Dialogs


ApplicationWindow {
    width: 1200
    height: 800
    visible: true
    title: qsTr("Stormworks Workbench")
    id: mainWindow

    Material.primary: "#263238"
    Material.theme:  Material.Dark
    Material.accent: "#f9a825"
    Material.background: "#000a12"


    menuBar: MenuBar {
        Material.background: Material.primary

        Material.elevation: 6
        implicitHeight: 30


           Menu {

               title: qsTr("&File")
               Action { text: qsTr("&New...") }
               Action { text: qsTr("&Open...") }
               Action { text: qsTr("&Save") }
               Action { text: qsTr("Save &As...") }
               MenuSeparator { }
               Action { text: qsTr("&Quit") }
               Material.background: Material.primary
           }
           Menu {
               title: qsTr("&Edit")
               Action { text: qsTr("Cu&t") }
               Action { text: qsTr("&Copy") }
               Action { text: qsTr("&Paste") }
               Material.background: Material.primary
           }
           Menu {
               title: qsTr("View")
               Action { text: qsTr("Show Start Page") }
               Material.background: Material.primary
           }
           Menu {
               title: qsTr("Project")
               Action { text: qsTr("Publish") }
               MenuSeparator {}
               Action {
                   text: qsTr("Import Mesh")
                   onTriggered: fdg.open()
               }
               Action { text: qsTr("Import OBJ") }
               Material.background: Material.primary
           }
           Menu {
               title: qsTr("Plugins")
               Action { text: qsTr("Load Plugin") }

               Action { text: qsTr("Manage Plugins") }
               MenuSeparator {}
               Material.background: Material.primary
           }

           Menu {
               title: qsTr("&Help")
               Action { text: qsTr("&About") }
               Material.background: Material.primary
           }

           delegate: MenuBarItem {
               id: menuBarItem

               height: parent.height
           }




           background: Rectangle {
                   implicitWidth: 20
                   implicitHeight: 20
                   color: Material.primary
                   Rectangle {
                       color: Material.accent
                       width: parent.width
                       height: 1
                       anchors.bottom: parent.bottom
                   }
               }
       }
    SplitView {
        anchors.fill: parent
        orientation: Qt.Vertical

        handle: Rectangle {
                implicitWidth: 3
                implicitHeight: 3
                color: SplitHandle.pressed ? Material.accent
                    : (SplitHandle.hovered ? Qt.lighter(Material.accent, 1.1) : Qt.lighter(Material.primary, 1.5))
            }



        Item {
                SplitView.minimumHeight: 25
                SplitView.preferredHeight: mainWindow.height/3*2

                SplitView {

                    anchors.fill: parent
                    orientation: Qt.Horizontal

                    handle: Rectangle {
                            implicitWidth: 3
                            implicitHeight: 3
                            color: SplitHandle.pressed ? Material.accent
                                : (SplitHandle.hovered ? Qt.lighter(Material.accent, 1.1) : Qt.lighter(Material.primary, 1.5))

                        }

                    Item {
                        SplitView.minimumWidth: 25
                        SplitView.preferredWidth: mainWindow.width/4

                    }
                    Modules.Workspace {
                        id: workspace
                        SplitView.minimumWidth: 25
                        SplitView.preferredWidth: mainWindow.width/2 * 3
                        height: parent.height



                    }
                }

            }
        Item {
                SplitView.minimumHeight: 25
                SplitView.preferredHeight: mainWindow.height/3
                width: parent.width
                ColumnLayout {
                    Layout.fillWidth: true
                    width: parent.width
                    anchors.fill: parent
                    spacing: 0
                    Pane {
                        Material.elevation: 7
                        Material.background: Material.primary
                        anchors.right: parent.right
                        anchors.left: parent.left
                        spacing: 0
                        padding: 0
                        TabBar {
                            padding: 0
                            width: parent.width
                            id: dbgTabBar



                            TabButton {
                                width: 100
                                height: parent.height
                                text: qsTr("Output")



                            }
                            TabButton {
                                width: 100
                                height: parent.height
                                text: qsTr("Console")

                            }
                        }
                    }




                    StackLayout {
                        width: parent.width
                        currentIndex: dbgTabBar.currentIndex
                        Item {
                            id: outputTab
                            Modules.MOutput {
                                anchors.fill: parent
                            }
                        }
                        Item {
                            id: consoleTab
                        }
                    }
                }



            }


        // ...
    }
    FileDialog {
        id: fdg
        onAccepted: {
            loadMesh(fdg.selectedFile.toString().slice(fdg.selectedFile.toString().lastIndexOf("/")+1))
        }
        selectedNameFilter.index: 0
        nameFilters: [".Mesh Files (*.mesh)"]
    }

    function loadMesh(path) {
        workspace.addTab(path)
    }
}
