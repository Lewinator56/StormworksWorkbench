import QtQuick
import QtQuick.Controls.Material

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Stormworks Workbench")
    id: mainWindow

    Material.theme:  Material.Dark

    menuBar: MenuBar {
        Material.elevation: 1
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
                TabBar {
                    width: parent.width
                    TabButton {
                        text: qsTr("Output")
                    }
                    TabButton {
                        text: qsTr("Console")
                    }
                }
            }

        // ...
    }
}
