import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    z: -1
    Pane {

        width: parent.width
        padding: 1


        Material.elevation: 1
        Material.background: Material.primary
        leftPadding: 5
        RowLayout {

            Button {
                text: qsTr("Clear")
                Material.background: "#d32f2f"
            }
            CheckBox {
                text: qsTr("Clear on refresh")
            }
        }


    }

    ListModel {
        ListElement {
            name: "Bill Smith"
            number: "555 3264"
        }
        ListElement {
            name: "John Brown"
            number: "555 8426"
        }
        ListElement {
            name: "Sam Wise"
            number: "555 0473"
        }
    }
}
