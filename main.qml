import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts
import "qrc:/../Modules" as Modules

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Stormworks Workbench")
    id: mainWindow

    Material.primary: "#37474f"
    Material.theme:  Material.Dark
    Material.accent: "#f9a825"

    menuBar: MenuBar {
        background: Rectangle {
            color: Material.primary
            Material.elevation: 6
        }

        Material.elevation: 6
           Menu {
               title: qsTr("&File")
               Action { text: qsTr("&New...") }
               Action { text: qsTr("&Open...") }
               Action { text: qsTr("&Save") }
               Action { text: qsTr("Save &As...") }
               MenuSeparator { }
               Action { text: qsTr("&Quit") }
           }
           Menu {
               title: qsTr("&Edit")
               Action { text: qsTr("Cu&t") }
               Action { text: qsTr("&Copy") }
               Action { text: qsTr("&Paste") }
           }
           Menu {
               title: qsTr("&Help")
               Action { text: qsTr("&About") }
           }
       }
    SplitView {
        anchors.fill: parent
        orientation: Qt.Vertical
        Item {
                SplitView.minimumHeight: 25
                SplitView.preferredHeight: mainWindow.height/4 * 3

                SplitView {
                    anchors.fill: parent
                    orientation: Qt.Horizontal

                    Item {
                        SplitView.minimumWidth: 25
                        SplitView.preferredWidth: mainWindow.width/4
                    }
                    Item {
                        SplitView.minimumWidth: 25
                        SplitView.preferredWidth: mainWindow.width/2 * 3
                    }
                }

            }
        Item {
                SplitView.minimumHeight: 25
                SplitView.preferredHeight: mainWindow.height/4
                width: parent.width
                ColumnLayout {
                    Layout.fillWidth: true
                    width: parent.width
                    anchors.fill: parent
                    TabBar {
                        width: parent.width
                        id: dbgTabBar
                        background: Rectangle {
                            color: Material.primary
                            width: mainWindow.width
                            Material.elevation: 6
                        }

                        TabButton {
                            width: 100
                            text: qsTr("Output")

                        }
                        TabButton {
                            width: 100
                            text: qsTr("Console")

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
}
