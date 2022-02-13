import QtQuick 2.0
import QtQuick.Controls.Fusion as Fus
import QtQuick.Controls
import "qrc:/../../CustomComponents" as Custom
import QtQuick.Layouts

Item {
    function addTab(name, module) {
        workspaceBar.loadTab(name)
    }

    Fus.TabBar {
        implicitHeight: 30
        id: workspaceBar
        contentWidth: parent.width
        width: parent.width
        Custom.CustomTabButton {
            text: qsTr("test")
            width: 100

        }
        Custom.CustomTabButton {
            text: qsTr("test")
            width:100

        }
        Custom.CustomTabButton {
            text: qsTr("test")
            width:100

        }

        Component {
            id: tabButton
            Custom.CustomTabButton {
                text: "test"
                width: 100
            }
        }

        function loadTab(name) {

            var t = workspaceBar.addItem(tabButton.createObject(workspaceBar, {text: name}))
        }
    }
    StackLayout {
        id: workspaceView
        currentIndex: workspaceBar.currentIndex

    }
}
