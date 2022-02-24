import QtQuick 2.0
import QtQuick.Controls.Fusion as Fus
import QtQuick.Controls
import "qrc:/../../CustomComponents" as Custom
import "qrc:/../../Modules" as Modules
import QtQuick.Layouts


Item {
    id: control
    function addTab(name, module) {
        workspaceBar.loadTab(name)
    }
    height: parent.height
    width: parent.width

    Fus.TabBar {
        implicitHeight: 30
        id: workspaceBar
        contentWidth: parent.width
        width: parent.width
        Custom.CustomTabButton {
            text: qsTr("test")
            width: 100
            host: workspaceBar

        }
        Custom.CustomTabButton {
            text: qsTr("test")
            width:100
            host: workspaceBar

        }
        Custom.CustomTabButton {
            text: qsTr("test")
            width:100
            host: workspaceBar

        }

        Component {
            id: tabButton
            Custom.CustomTabButton {
                text: "test"

                host: workspaceBar
            }
        }

        function loadTab(name) {

            var t = workspaceBar.addItem(tabButton.createObject(workspaceBar, {text: name}))
        }
        function closeTab(tab) {

            workspaceBar.removeItem(tab)

        }
    }
    StackLayout {
        id: workspaceView
        currentIndex: workspaceBar.currentIndex
        Item {

            Modules.MeshEditor {
                anchors.bottom: control.bottom
                y: workspaceBar.height
                height: control.height - workspaceBar.height
                width: control.width / 2
            }
        }



    }
}
