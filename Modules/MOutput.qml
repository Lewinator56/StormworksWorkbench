import QtQuick
import QtQuick.Controls

Item {
    Rectangle {
        height: 100
        width: 100
        color: "red"
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
